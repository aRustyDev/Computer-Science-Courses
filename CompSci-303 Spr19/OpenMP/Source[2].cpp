#include <iostream>
#include <vector>
#include "omp.h"
#include <ctime>
#include <string> 
#include <list>
#include <map>
#include "Binary_Search_Tree.h"
using namespace std;

void merge(std::vector<int>& array, std::vector<int>& result, int lowPointer, int highPointer, int upperBound) {

	int j = 0;
	int lowerBound = lowPointer;
	int mid = highPointer - 1;
	int n = upperBound - lowerBound + 1; //number of items



	while (lowPointer <= mid && highPointer <= upperBound){
		if (array[lowPointer] < array[highPointer])
			result[j++] = array[lowPointer++];
		else
			result[j++] = array[highPointer++];
	}
	while (lowPointer <= mid)
		result[j++] = array[lowPointer++];

	while (highPointer <= upperBound)
		result[j++] = array[highPointer++];


	for (j = 0; j < n; j++) //copy the items from the temporary array to the original array
		array[lowerBound + j] = result[j];
}

void mergesort_serial(std::vector<int>& array, std::vector<int>& result, int lowerBand, int upperBand) {
	int midpoint=-1;//add midpoint, upperBand,lowerBand
	if (lowerBand < upperBand) {
		midpoint = (lowerBand + upperBand) / 2;
		mergesort_serial(array, result, lowerBand, midpoint); //merge sort the left half
		mergesort_serial(array, result, midpoint + 1, upperBand); //merge sort the right half
		merge(array, result, lowerBand, midpoint + 1, upperBand);
	}
	/*int ID = omp_get_thread_num();
	if (midpoint != -1){
		string text = "Thread " + to_string(ID) + ": merging {" + to_string(lowerBand) + "," + to_string(midpoint) + "}  and {" + to_string(midpoint + 1) + "," + to_string(upperBand) + "}\n";
		cout << text;
	}*/
}

/** serial merge sort wrapper **/

void mergeSort(std::vector<int>& array){
	std::vector<int> result = array;
	mergesort_serial(array, result, 0, array.size() - 1);
}

/** parallel merge sort **/

void mergesort_parallel_omp(std::vector<int>& array, std::vector<int>& result, int lowerBand, int upperBand,int threads) {
	int midpoint = (lowerBand + upperBand) / 2;
	if (threads == 1) {
		mergesort_serial(array,result,lowerBand,upperBand);
	}

	else if (threads > 1) {
#pragma omp parallel sections
		{
#pragma omp section
			mergesort_parallel_omp(array, result, lowerBand, midpoint,threads/2); //merge sort the left half
#pragma omp section
			mergesort_parallel_omp(array, result, midpoint + 1, upperBand, threads / 2); //merge sort the right half
		}

		merge(array, result, lowerBand, midpoint + 1, upperBand);
		/*int ID = omp_get_thread_num();

		string text = "Thread "+to_string(ID)+": merging {" + to_string(lowerBand) + "," + to_string(midpoint) + "}  and {" + to_string(midpoint + 1) + "," + to_string(upperBand) + "}\n";
		cout << text;*/
		//printf("thread No (%d) ", ID);
	} // threads > 1
}

/** parallel merge sort wrapper **/
void pmergeSort(std::vector<int>& array,int threads){
	std::vector<int> result = array;
	omp_set_num_threads(threads);
	mergesort_parallel_omp(array, result, 0, array.size() - 1,threads);
}

vector<int> random_vector(size_t size){
	vector<int> v1;
	for (int i = 0; i < size; i++)
		v1.push_back(rand() % size); //put a random number between 0 and size
	return v1;
}


void find_one_item(int low, int high, int target, vector<int>& vec, int& index){
	for (int i = low; i < high ; i++){
		if (index != -1)
			break;
		if (vec[i] == target && index == -1){
			index = i;
			break;
		}
	}
}

/** find one item (two sections) **/
int find_one_item_sections(vector<int>& vec, int target){
	int index = -1;
#pragma omp parallel sections shared(index)
	{
#pragma omp section
		find_one_item(0, vec.size() / 2, target,vec, index);
#pragma omp section
		find_one_item(vec.size() / 2, vec.size(), target, vec, index);
	}
	return index;
}

/** find one item (multiple sections) **/
void find_one_item_msections(vector<int>& vec, int low,int high, int threads,int target, int& index){
	if (threads == 1 || low>=high)
		find_one_item(low, high, target, vec, index);
	else if (threads > 1){
		int midpoint = (high + low) / 2;
#pragma omp parallel sections shared(index)
		{
#pragma omp section
			find_one_item_msections(vec, low, midpoint - 1, threads / 2, target,index);
#pragma omp section
			find_one_item_msections(vec, midpoint, high, threads / 2, target,index);
		}
	}
}

int find_one_item_msections(vector<int>& vec,int target, int threads){
	int index = -1;
	find_one_item_msections(vec, 0, vec.size(), threads, target, index);
	return index;
}


void serial_average(BTNode<int>* local_root, int& sum, int& count){

	if (local_root != NULL){
        #pragma omp critical //only one thread at a time updates count and sum
        {
	        count++;
			sum += local_root->data;
		}

			if (local_root->left != NULL)
				serial_average(local_root->left, sum, count);

			if (local_root->right != NULL)
				serial_average(local_root->right, sum, count);
	}
}

void parallel_average(BTNode<int>* local_root, int& sum, int& count){

	if (local_root != NULL){
		count++;
		sum += local_root->data;
#pragma omp parallel sections shared(count,sum)
		{
#pragma omp section
			serial_average(local_root->left, sum, count); //left subtree will be run by a thread independantly
#pragma omp section
			serial_average(local_root->right, sum, count); //right subtree will be run by a thread independantly
		}
	}
}

//parallel average wrapper function
int parallel_average(BTNode<int>* local_root){
	int sum = 0; int count = 0;
	parallel_average(local_root, sum, count);
	if (count == 0)
		return 0;
	return sum / count;
}

void print_thread_info(string section_num){
	int ID = omp_get_thread_num();
	string result = "section " + section_num + ": thread No " + to_string(ID)+"\n";
	cout << result << endl;
}

//basic sections example
void section_basic_example(){
	omp_set_num_threads(3); //create three threads

#pragma omp parallel sections 
	{
#pragma omp section
		print_thread_info("1");
#pragma omp section
		print_thread_info("2");
#pragma omp section
		print_thread_info("3");
	}
}



Binary_Search_Tree<int> unique_values(vector<int>& vec){

	Binary_Search_Tree<int> all_items_tree;
	Binary_Search_Tree<int> unique_tree;

#pragma omp parallel for
	for (int i = 0; i < vec.size(); ++i){
		if (all_items_tree.find(vec[i]) == NULL){//if we haven't seen the item before
			all_items_tree.insert(vec[i]);
			unique_tree.insert(vec[i]);
		}
		else{ // we have seen the item before
			unique_tree.erase(vec[i]); //delete it
		}
	}

	return unique_tree;
}



//finding all the occurances of an item with parallel for
list<int> find(vector<int>& vec, int target){
	list<int> list; 
	omp_set_num_threads(4);

#pragma omp parallel for
	for (int i = 0; i < vec.size(); ++i){
		if (vec[i] == target){
			list.push_back(i);
		}
	}
	return list;
}

/** finding min with parallel for */
int min(vector<int>& vec){

	int min_value = -1;
	if (vec.size()>1)
		min_value = vec[0];

#pragma omp parallel for
	for (int i = 0; i < vec.size(); ++i){
#pragma omp critical //make sure only one thread at a time accesses this block
{
		if (vec[i] < min_value){
			min_value = vec[i];
		}
}
	}
	return min_value;
}


/** n-queen problem */


/** basic settings for n-queen problem */
int QUEENS = 9;

int row[9] = {};
int numsolutions = 0;


bool is_solution() {
	for (int i = 0; i < QUEENS - 1; i++) {
		for (int j = i + 1; j < QUEENS; j++) {
			if (row[i] == row[j])
				return false;
			if (row[i] - row[j] == (i - j))
				return false;
			if (row[i] - row[j] == (j - i))
				return false;
		}
	}
	return true;
}

void print_board(){
	for (int i = 0; i < QUEENS; i++)
		cout << row[i] << " ";
}


/** Try to place the ith queen on a row */
bool place_queen_serial(int i, int& counter) {
	++counter;
	if (i == QUEENS) {
		if (is_solution()) {
			cout << "Solution # " << (++numsolutions)
				<< endl;
			print_board();
			cout << endl;
			return true;
		}
		else
			return false;
	}

		for (int j = 0; j < QUEENS; j++) {
			row[i] = j;
			place_queen_serial(i + 1, counter);
		}

	return false;
}

bool place_queen_serial(){
	int count = 0;
	int i = 0; //first queen
	return place_queen_serial(i, count);

}

/** Try to place the ith queen on a row */
bool place_queen_parallel(int i, int& counter) {
	++counter;
	if (i == QUEENS) {
		if (is_solution()) {
			cout << "Solution # " << (++numsolutions)
				<< endl;
			print_board();
			cout << endl;
			return true;
		}
		else
			return false;
	}
	if (i == 0){ /** only parallelize the allocation of first queen */
#pragma omp parallel for
		for (int j = 0; j < QUEENS; j++) {
			row[0] = j;
			place_queen_parallel(1, counter);
		}
	}
	else
		for (int j = 0; j < QUEENS; j++) {
			row[i] = j;
			place_queen_parallel(i + 1, counter);
		}

	return false;
}

bool place_queen_parallel(){
	int count = 0;
	int i = 0; //first queen
	return place_queen_parallel(i, count);

}



int main()
{




	/** basic parallel program **/
omp_set_num_threads(3);
#pragma omp parallel
{
	int ID = omp_get_thread_num();
	printf("Hello(%d) ", ID);
	printf("World(%d) \n", ID);
}

int count = 0;
int MAX = 1000000;

for (int i = 0; i < MAX; ++i)
	count++;

cout << "serial count is: " << count << endl;

//basic parallel for example with 3 threads
omp_set_num_threads(3);


#pragma omp parallel for
for (int i = 0; i < 10; ++i){
	int ID = omp_get_thread_num();
	string result = "i: " + to_string(i) + ": thread No " + to_string(ID) + "\n";
	cout << result;
}



//counting to 1000000 without synchronization
omp_set_num_threads(3);
count = 0;

#pragma omp parallel for shared(MAX,count)
for (int i = 0; i < MAX; ++i)
	count++;
cout << "parallel count is: " << count << endl;


//counting to 1000000 with atomic
omp_set_num_threads(3);
count = 0;

#pragma omp parallel for shared(MAX)
for (int i = 0; i < MAX; ++i){
   #pragma omp atomic 
	 count++;
}

cout << "parallel count (atomic) is: " << count << endl;

//counting to 1000000 with critical
omp_set_num_threads(3);
count = 0;

#pragma omp parallel for shared(MAX)
for (int i = 0; i < MAX; ++i){
#pragma omp critical
{
 count++;
}
}

cout << "parallel count (critical) is: " << count << endl;

//counting to 1000000 with locks
count = 0;
omp_lock_t writelock;

omp_init_lock(&writelock);

#pragma omp parallel for shared(MAX)
for (int i = 0; i < MAX; ++i){
	omp_set_lock(&writelock); 
	count++;
	omp_unset_lock(&writelock);
}

cout << "parallel count (locks) is: " << count << endl;
omp_destroy_lock(&writelock);

//counting to 1000000 with reduction

count = 0;
#pragma omp parallel for shared(MAX) reduction(+:count)
for (int i = 0; i < MAX; ++i){
	count += 1;
}

cout << "parallel count (reduction) is: " << count << endl;


section_basic_example();




vector<int> v1; int start = 0; int result = 0;
v1 = random_vector(1000000);
int target = 5;
v1[7789] = target; //just making sure we have the target

/** finding all the occurances of a target with parallel code */
list<int> matches = find(v1,target);

/** finding one occurance of a target with parallel code (two sections) */
int match = find_one_item_sections(v1, target);

cout << "match index :" << v1[match] << endl; 

/** finding one occurance of a target with parallel code (nested sections) */
omp_set_num_threads(4);
match = find_one_item_msections(v1, target, 4);

v1 = { 20, 5, 1, 9, 18, 4, -5, -10, 7, 5,19,13,99,77};
int min_val = min(v1);

/** finding unique values in an array with parallel for */
Binary_Search_Tree<int> tree = unique_values(v1);

int avg = parallel_average(tree.getRoot());


int counter = 0;



/** serial merge sort **/
v1 = random_vector(1000000);
start = clock();
mergeSort(v1);
result = clock() - start;
std::cout << "Time taken in millisecs: " << result<<endl;
std::cout << "Time taken in seconds: " << result/1000<<endl;

/** parallel merge sort **/
omp_set_nested(1);  //making sure openmp supports nested parallelism
v1 = random_vector(1000000);
start = clock();
pmergeSort(v1,2);
result = clock() - start;
std::cout << "Time taken in millisecs: " << result << endl;
std::cout << "Time taken in seconds: " << result / 1000 << endl;

/** serial n-queen program (9 queens) **/
start = clock();
place_queen_serial();
result = clock() - start;
std::cout << "S Queen: Time taken in millisecs: " << result << endl;
std::cout << "S Queen: Time taken in seconds: " << result / 1000 << endl;
std::cout << "S Queen: Time taken in minutes: " << result / 60000 << endl;

/** parallel n-queen program (9 queens) **/
omp_set_num_threads(4);
start = clock();
place_queen_parallel();
result = clock() - start;
std::cout << "P Queen: Time taken in millisecs: " << result << endl;
std::cout << "P Queen: Time taken in seconds: " << result / 1000 << endl;


}
