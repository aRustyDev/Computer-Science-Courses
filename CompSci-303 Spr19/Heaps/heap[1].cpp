// heap.cpp : Defines the entry point for the console application.
//

#include "Heap.h"
#include <vector>
#include "Priority_Queue.h"


int main()
{
	std::vector<int> heap_vector { 89, 76, 74, 37, 32, 39, 66, 20, 26, 18, 28, 29, 6 };
	std::vector<int> heap_vector_2{ 89, 76, 80, 37, 32, 39, 74, 20, 26, 18, 28, 29, 6, 66 };
	std::vector<std::string> heap_vectors3{};


	HeapTree<int> heap(heap_vector);
	HeapTree<int> heap_2(heap_vector_2);
	heap.Insert(80);
	
	heap.HeapSort();

	heap_2.Remove();
	
	HeapTree<std::string> heap_3(heap_vectors3);
	heap_3.Insert("this");
	heap_3.Insert("is");
	heap_3.Insert("the");
	heap_3.Insert("house");
	heap_3.Insert("that");
	heap_3.Insert("jack");
	heap_3.Insert("built");






	priority_queue<int> pQ;
	pQ.push(1);
	pQ.push(1);
	pQ.push(5);
	pQ.push(3);
	
	return 0;
}

