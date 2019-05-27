#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <string>
#include <iostream>
#include "Binary_Tree.h"
#include <vector>;

template<typename Item_Type>
class Binary_Search_Tree : public Binary_Tree<Item_Type>
{
public:
	// Constructor
	Binary_Search_Tree() : Binary_Tree<Item_Type>() {}
	void print_code(const Item_Type& target){ print_code(root, target, ""); }
	
	void print_code(BTNode<Item_Type>* local_root, const Item_Type& target, std::string code){
		if (local_root != NULL){
			if (local_root->data < target)
				std::cout << code<<endl;
			else {
				print_code(local_root->left, target, code + "*");
				print_code(local_root->right, target, code + "-");
			}
		}
	}

	std::vector<Item_Type> to_max_heap(){
		std::vector<Item_Type> heap;
		to_max_heap(heap, root);
		return heap;
	}

	void to_max_heap(std::vector<Item_Type>& heap, BTNode<Item_Type>* local_root){
		if (local_root != NULL){
			if (local_root->right != NULL)
				to_max_heap(heap, local_root->right);
			heap.push_back(local_root->data);

			if (local_root->left != NULL)
				to_max_heap(heap, local_root->left);
		}
	}
	
	// Public Member Functions
	virtual bool insert(const Item_Type& item);

	virtual bool erase(const Item_Type& item);

	const Item_Type* min() const;

	const Item_Type* min(BTNode<Item_Type>* local_root) const;

	const Item_Type* max() const;

	const Item_Type* max(BTNode<Item_Type>* local_root) const;

	const Item_Type* find(const Item_Type& target) const;



private:

	// Private Member Functions
	virtual bool insert(BTNode<Item_Type>*& local_root,
		const Item_Type& item);

	virtual bool erase(BTNode<Item_Type>*& local_root,
		const Item_Type& item);

	const Item_Type* find(BTNode<Item_Type>* local_root,
		const Item_Type& target) const;

	virtual void replace_parent(
		BTNode<Item_Type>*& old_root,
		BTNode<Item_Type>*& local_root);

}; // End binary search tree




template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::min() const {
	return min(this->root);
		
}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::min(BTNode<Item_Type>* local_root) const{
	if (local_root == NULL)
		return NULL;

		if (local_root->left == NULL)
			return &(local_root->data);
		 return min(local_root->left);
}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::max() const {
	return max(this->root);

}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::max(BTNode<Item_Type>* local_root) const{
	if (local_root == NULL)
		return NULL;

		if (local_root->right == NULL)
			return &(local_root->data);
		return max(local_root->right);
}



template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::find(
	const Item_Type& item) const {
		return find(this->root, item);
}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::find(BTNode<Item_Type>* local_root, const Item_Type& target) const {
		if (local_root == NULL)
			return NULL;
		if (target < local_root->data)
			return find(local_root->left, target);
		else if (local_root->data < target)
			return find(local_root->right, target);
		else
			return &(local_root->data);
}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::insert(const Item_Type& item) {
		return insert(this->root, item);
}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::insert(BTNode<Item_Type>*& local_root,const Item_Type& item) {
		if (local_root == NULL) {
			local_root = new BTNode<Item_Type>(item);
			return true;
		}
		else {
			if (item < local_root->data)
				return insert(local_root->left, item);
			else if (local_root->data < item)
				return insert(local_root->right, item);
			else
				return false;
		}
}


template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::erase(const Item_Type& item) {
		return erase(this->root, item);
}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::erase(BTNode<Item_Type>*& local_root, const Item_Type& item) {
	if (local_root == NULL) {
		return false;
	}
	else {
		if (item < local_root->data)
			return erase(local_root->left, item);
		else if (local_root->data < item)
			return erase(local_root->right, item);
		else {
			BTNode<Item_Type>* old_root = local_root;
			if (local_root->left == NULL) {
				local_root = local_root->right;
			}
			else if (local_root->right == NULL) {
				local_root = local_root->left;
			}
			else {
				replace_parent(old_root, old_root->left);
			}
			delete old_root;
			return true;
		}
	}
}

template<typename Item_Type>
void Binary_Search_Tree<Item_Type>::replace_parent(BTNode<Item_Type>*& old_root, BTNode<Item_Type>*& local_root) {
		if (local_root->right != NULL) {
			replace_parent(old_root, local_root->right);
		}
		else {
			old_root->data = local_root->data;
			old_root = local_root;
			local_root = local_root->left;
		}
}


#endif