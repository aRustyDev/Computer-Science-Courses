
#ifndef __HeapTreeClassH__
#define __HeapTreeClassH__

#include <assert.h>    // For error-checking purposes
#include <vector>
using std::vector;



template<typename Item_Type>
class HeapTree
{
public:
	HeapTree(int MaxSize = 500);
	HeapTree(const HeapTree<Item_Type> &OtherTree);
	HeapTree(std::vector<Item_Type>& Array);
	std::vector<Item_Type> Sort(); // Built-in HeapSort Algorithm
	void HeapSort();

	void Insert(const Item_Type &Item);  // Add the Item to Heap
	Item_Type Remove();           // Remove and return Item from Heap
	inline int size();    // Returns the number of nodes in the Heap

	int max(int index_1, int index_2){
		if (index_2 > size() - 1 || Data[index_1] >= Data[index_2])
			return index_1;
		return index_2;
	}

protected:
	vector<Item_Type>  Data;              // Actual Data array

};





template<typename Item_Type>
HeapTree <Item_Type>::HeapTree(const HeapTree<Item_Type> &OtherTree){
	
	Data = new std::vector<Item_Type>(OtherTree.Data.size());
	CurrentNum = OtherTree.CurrentNum;

	// Copy the array
	for (int i = 0; i < OtherTree.CurrentNum; ++i)
		Data[i] = OtherTree.Data[i];
}

// HeapTree vector constructor
template<typename Item_Type>
HeapTree<Item_Type>::HeapTree(std::vector<Item_Type>& Array) {
	Data = Array;

}

// Built-in Heap Sort algorithm
template<typename Item_Type>
std::vector<Item_Type> HeapTree<Item_Type>::Sort() {
	// This is the array that will be returned
	std::vector<Item_Type> NewArray(Data);


	for (int ElemNum = size() - 1; ElemNum >= 0; --ElemNum) {
		Item_Type item = Remove();
		NewArray[ElemNum] = item;
	}
	return NewArray;
}



template<typename Item_Type>
void HeapTree<Item_Type>::HeapSort() {
	for (int n = size(); n > 0; --n) {
		std::swap(Data[0], Data[n - 1]);
		int parent = 0, left_child = 2 * parent + 1;

		while (true) {
			left_child = 2 * parent + 1;
			if (left_child >= (n-1)) break; // out of heap
			int right_child = left_child + 1;
			int max_child = left_child;
			if (right_child < (n-1) && Data[left_child] < Data[right_child])
				max_child = right_child;
			if (Data[parent] < Data[max_child]) {
				std::swap(Data[max_child], Data[parent]);
				parent = max_child;
			}
			else break;
		}
	}
}



template<typename Item_Type>
void HeapTree<Item_Type>::Insert(const Item_Type &Item)
{
	Data.push_back(Item);
	
	int  child = Data.size() - 1, Parent = (child - 1) / 2;
	
	while ((child > 0) && (Data[Parent] < Item))  {
		std::swap(Data[child], Data[Parent]);
			child = Parent;
			Parent = (child - 1) / 2;

	}

}


// Remove() function
template<typename Item_Type>
Item_Type HeapTree<Item_Type>::Remove() {

	Item_Type item = size() > 0 ? Data[0] : NULL;
	if (Data.size() == 1) { Data.pop_back(); return item; }
	std::swap(Data[0], Data[Data.size() - 1]);
	Data.pop_back();
	int parent = 0, left_child = 2 * parent + 1;

	while (true) {
		left_child = 2 * parent + 1;
		if (left_child >= size()) break; // out of heap
		int right_child = left_child + 1;
		int max_child = max(left_child, right_child);
		if ( Data[parent] < Data[max_child]) {
			std::swap(Data[max_child], Data[parent]);
			parent = max_child;
		}
		else break;
	}
	
	return item;
}

// GetSize() function
template<typename Item_Type>
inline int HeapTree<Item_Type>::size()
{
	return Data.size();
}


#endif /*__HeapTreeClassH__*/