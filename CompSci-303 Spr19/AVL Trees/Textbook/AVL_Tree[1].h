#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "BST_With_Rotate.h"
#include "AVLNode.h"
#include "Bad_Structure.h"

template<typename Item_Type>
class AVL_Tree : public BST_With_Rotate<Item_Type> {

public:

	AVL_Tree() : BST_With_Rotate<Item_Type>() {}

	virtual bool insert(const Item_Type& item) {
		return insert(this->root, item);
	}

	virtual bool erase(const Item_Type& item) {
		return erase(this->root, item);
	}

	bool verify_structure() {
		verify_structure(this->root, 0);
		return true;
	}

private:

	virtual bool insert(BTNode<Item_Type>*&, const Item_Type&);

	void rebalance_left(BTNode<Item_Type>*& local_root);

	void rebalance_right(BTNode<Item_Type>*& local_root);

	virtual bool erase(BTNode<Item_Type>*& local_root,
		const Item_Type& item);

	virtual void replace_parent(BTNode<Item_Type>*& old_root,
		BTNode<Item_Type>*& local_root);

	void erase_rebalance_left(BTNode<Item_Type>*& local_root);

	void erase_rebalance_right(BTNode<Item_Type>*& local_root);


	int verify_structure(BTNode<Item_Type>* local_root,
		BTNode<Item_Type>* parent);

	bool increase;

	bool decrease;

}; // End of AVL_Tree class definition


template<typename Item_Type>
bool AVL_Tree<Item_Type>::insert(BTNode<Item_Type>*& local_root, const Item_Type& item) {
		if (local_root == NULL) {
			local_root = new AVLNode<Item_Type>(item);
			increase = true;
			return true;
		}
		else {
			if (item < local_root->data) {
				bool return_value = insert(local_root->left, item);
				if (increase) {
					// Height of the left subtree has increased
					AVLNode<Item_Type>* AVL_local_root = dynamic_cast<AVLNode<Item_Type>*>(local_root);
					switch (AVL_local_root->balance) {
					case AVLNode<Item_Type>::BALANCED:
						// local root is now left heavy
						AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
						break;
					case AVLNode<Item_Type>::RIGHT_HEAVY:
						// local root is now right heavy
						AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
						// Overall height of local root remains the same
						increase = false;
						break;
					case AVLNode<Item_Type>::LEFT_HEAVY:
						// local root is now critically unbalanced
						rebalance_left(local_root);
						increase = false;
						break;
					} // End switch
				} // End if (increase)
				return return_value;
			}
			else if (local_root->data < item) {
				bool return_value =
					insert(local_root->right, item);
				if (increase) {
					AVLNode<Item_Type>* AVL_local_root =
						dynamic_cast<AVLNode<Item_Type>*>(local_root);
					// Height of the right subtree has increased
					switch (AVL_local_root->balance) {
					case AVLNode<Item_Type>::BALANCED:
						// local root is now right heavy
						AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
						break;
					case AVLNode<Item_Type>::LEFT_HEAVY:
						// local root is now balanced
						AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
						// Overall height of local root remains the same
						increase = false;
						break;
					case AVLNode<Item_Type>::RIGHT_HEAVY:
						// local root is now critically balanced
						rebalance_right(local_root);
						increase = false;
						break;
					}
				}
				return return_value;
			}
			else {
				increase = false;
				return false;
			}
		}
}

template<typename Item_Type>
void AVL_Tree<Item_Type>::rebalance_left(BTNode<Item_Type>*& local_root) {

	AVLNode<Item_Type>* AVL_local_root =
		dynamic_cast<AVLNode<Item_Type>*>(local_root);
	// Obtain reference to the left child
	AVLNode<Item_Type>* left_child =
		dynamic_cast<AVLNode<Item_Type>*>(local_root->left);
	// See whether left-right-heavy
	if (left_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY) {
		// Obtain a reference to the left-right child
		AVLNode<Item_Type>* left_right_child =
			dynamic_cast<AVLNode<Item_Type>*>(left_child->right);
		// Adjust the balances to be the new values after rotations are 
		// performed
		if (left_right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
			left_child->balance = AVLNode<Item_Type>::BALANCED;
			left_right_child->balance = AVLNode<Item_Type>::BALANCED;
			AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
		}
		else if (left_right_child->balance
			== AVLNode<Item_Type>::BALANCED) {
				left_child->balance = AVLNode<Item_Type>::BALANCED;
				left_right_child->balance = AVLNode<Item_Type>::BALANCED;
				AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
		}
		else {
			left_child->balance = AVLNode<Item_Type>::LEFT_HEAVY;
			left_right_child->balance = AVLNode<Item_Type>::BALANCED;
			AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
		}
		// Perform left rotation
		rotate_left(local_root->left);
	}
	else {
		left_child->balance = AVLNode<Item_Type>::BALANCED;
		AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
	}
	// Finally rotate right
	rotate_right(local_root);
}

template<typename Item_Type>
void
	AVL_Tree<Item_Type>::rebalance_right(BTNode<Item_Type>*& local_root) {
		AVLNode<Item_Type>* AVL_local_root =
			dynamic_cast<AVLNode<Item_Type>*>(local_root);
		// Obtain reference to the right_child
		AVLNode<Item_Type>* right_child =
			dynamic_cast<AVLNode<Item_Type>*>(local_root->right);
		// See whether right-left heavy
		if (right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
			// Obtain a reference to the right-left child
			AVLNode<Item_Type>* right_left_child =
				dynamic_cast<AVLNode<Item_Type>*>(right_child->left);
			// Adjust the balances to be the new values after rotations are performed
			if (right_left_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY) {
				right_child->balance = AVLNode<Item_Type>::BALANCED;
				right_left_child->balance = AVLNode<Item_Type>::BALANCED;
				AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
			}
			else if (right_left_child->balance == AVLNode<Item_Type>::BALANCED) {
				right_child->balance = AVLNode<Item_Type>::BALANCED;
				right_left_child->balance = AVLNode<Item_Type>::BALANCED;
				AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
			}
			else {
				right_child->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
				right_left_child->balance = AVLNode<Item_Type>::BALANCED;
				AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
			}
			// Perform right rotation
			rotate_right(local_root->right);
		}
		else {
			right_child->balance = AVLNode<Item_Type>::BALANCED;
			AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
		}
		// Finally rotate left
		rotate_left(local_root);
}

template<typename Item_Type>
bool AVL_Tree<Item_Type>::erase(BTNode<Item_Type>*& local_root, const Item_Type& item) {
		if (local_root == NULL) {
			decrease = false;
			return false;
		}
		else {
			if (item < local_root->data) {
				bool return_value =
					erase(local_root->left, item);
				if (decrease) {
					// Height of left sub-tree has decreased
					AVLNode<Item_Type>* AVL_local_root =
						dynamic_cast<AVLNode<Item_Type>*>(local_root);
					switch (AVL_local_root->balance) {
					case AVLNode<Item_Type>::BALANCED:
						// local root is now right heavy
						AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
						// Overall height of local root remains the same
						decrease = false;
						break;
					case AVLNode<Item_Type>::LEFT_HEAVY:
						// local root is now balanced
						AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
						break;
					case AVLNode<Item_Type>::RIGHT_HEAVY:
						// local root is critical
						erase_rebalance_right(local_root);
					}
				}
				return return_value;
			}
			else if (local_root->data < item) {
				bool return_value =
					erase(local_root->right, item);
				if (decrease) {
					AVLNode<Item_Type>* AVL_local_root =
						dynamic_cast<AVLNode<Item_Type>*>(local_root);
					// Height of right sub-tree has decreased
					switch (AVL_local_root->balance) {
					case AVLNode<Item_Type>::BALANCED:
						// local root is now left heavy
						AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
						// Overall height of local root remains the same
						decrease = false;
						break;
					case AVLNode<Item_Type>::RIGHT_HEAVY:
						// local root is now balanced
						AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
						break;
					case AVLNode<Item_Type>::LEFT_HEAVY:
						// local root is critical
						erase_rebalance_left(local_root);
					}
				}
				return return_value;
			}
			else {
				// Found item
				BTNode<Item_Type>* old_root = local_root;
				if (local_root->left == NULL) {
					local_root = local_root->right;
					decrease = true;
				}
				else if (local_root->right == NULL) {
					local_root = local_root->left;
					decrease = true;
				}
				else {
					replace_parent(old_root, old_root->left);
					if (decrease) {
						// Height of left sub-tree has decreased
						AVLNode<Item_Type>* AVL_local_root =
							dynamic_cast<AVLNode<Item_Type>*>(local_root);
						switch (AVL_local_root->balance) {
						case AVLNode<Item_Type>::BALANCED:
							// local root is now right heavy
							AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
							// Overall height of local root remains the same
							decrease = false;
							break;
						case AVLNode<Item_Type>::LEFT_HEAVY:
							// local root is now balanced
							AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
							break;
						case AVLNode<Item_Type>::RIGHT_HEAVY:
							// local root is critical
							erase_rebalance_right(local_root);
						}
					}
				}
				delete old_root;
				return true;
			}
		}
}

template<typename Item_Type>
void AVL_Tree<Item_Type>::replace_parent(BTNode<Item_Type>*& old_root, BTNode<Item_Type>*& local_root) {
		if (local_root->right != NULL) {
			replace_parent(old_root, local_root->right);
			if (decrease) {
				AVLNode<Item_Type>* AVL_local_root =
					dynamic_cast<AVLNode<Item_Type>*>(local_root);
				switch (AVL_local_root->balance) {
				case AVLNode<Item_Type>::RIGHT_HEAVY:
					AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
					break;
				case AVLNode<Item_Type>::BALANCED:
					AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
					decrease = false;
					break;
				case AVLNode<Item_Type>::LEFT_HEAVY:
					erase_rebalance_left(local_root);
					break;
				}
			}
		}
		else {
			old_root->data = local_root->data;
			old_root = local_root;
			local_root = local_root->left;
			decrease = true;
		}
}

template<typename Item_Type>
void
	AVL_Tree<Item_Type>::erase_rebalance_left(BTNode<Item_Type>*& local_root) {
		// Cast local_root to AVLNode pointer
		AVLNode<Item_Type>* AVL_local_root =
			dynamic_cast<AVLNode<Item_Type>*>(local_root);
		// Obtain reference to the left_child
		AVLNode<Item_Type>* left_child =
			dynamic_cast<AVLNode<Item_Type>*>(local_root->left);
		// See whether left-right heavy
		if (left_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY) {
			// Obtain a reference to the left-right child
			AVLNode<Item_Type>* left_right_child =
				dynamic_cast<AVLNode<Item_Type>*>(left_child->right);
			// Adjust the balances to be the new values after rotations are performed
			if (left_right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
				left_child->balance = AVLNode<Item_Type>::BALANCED;
				left_right_child->balance = AVLNode<Item_Type>::BALANCED;
				AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
			}
			else if (left_right_child->balance == AVLNode<Item_Type>::BALANCED) {
				left_child->balance = AVLNode<Item_Type>::BALANCED;
				left_right_child->balance = AVLNode<Item_Type>::BALANCED;
				AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
			}
			else {
				left_child->balance = AVLNode<Item_Type>::LEFT_HEAVY;
				left_right_child->balance = AVLNode<Item_Type>::BALANCED;
				AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
			}
			// Perform left rotation
			rotate_left(local_root->left);
		}
		else {
			// Left-Left case
			if (left_child->balance == AVLNode<Item_Type>::BALANCED) {
				left_child->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
				AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
				decrease = false;
			}
			else {
				left_child->balance = AVLNode<Item_Type>::BALANCED;
				AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
			}
		}
		// Finally rotate right
		rotate_right(local_root);
}

template<typename Item_Type>
void AVL_Tree<Item_Type>::erase_rebalance_right(BTNode<Item_Type>*& local_root) {
		// Cast local_root to AVLNode pointer
		AVLNode<Item_Type>* AVL_local_root =
			dynamic_cast<AVLNode<Item_Type>*>(local_root);
		// Obtain reference to the right_child
		AVLNode<Item_Type>* right_child =
			dynamic_cast<AVLNode<Item_Type>*>(local_root->right);
		// See whether right-left heavy
		if (right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
			// Obtain a reference to the right-left child
			AVLNode<Item_Type>* right_left_child =
				dynamic_cast<AVLNode<Item_Type>*>(right_child->left);
			// Adjust the balances to be the new values after rotations are performed
			if (right_left_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY) {
				right_child->balance = AVLNode<Item_Type>::BALANCED;
				right_left_child->balance = AVLNode<Item_Type>::BALANCED;
				AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
			}
			else if (right_left_child->balance == AVLNode<Item_Type>::BALANCED) {
				right_child->balance = AVLNode<Item_Type>::BALANCED;
				right_left_child->balance = AVLNode<Item_Type>::BALANCED;
				AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
			}
			else {
				right_child->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
				right_left_child->balance = AVLNode<Item_Type>::BALANCED;
				AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
			}
			// Perform right rotation
			rotate_right(local_root->right);
		}
		else {
			// Right-Right case
			if (right_child->balance == AVLNode<Item_Type>::BALANCED) {
				right_child->balance = AVLNode<Item_Type>::LEFT_HEAVY;
				AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
				decrease = false;
			}
			else {
				right_child->balance = AVLNode<Item_Type>::BALANCED;
				AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
			}
		}
		// Finally rotate left
		rotate_left(local_root);
}

template<typename Item_Type>
int AVL_Tree<Item_Type>::verify_structure(BTNode<Item_Type>* local_root, BTNode<Item_Type>* parent) {
		if (local_root == 0) return 0;
		AVLNode<Item_Type>* avl_root =
			dynamic_cast<AVLNode<Item_Type>*>(local_root);
		if (avl_root == 0) {
			throw Bad_Structure<Item_Type>(local_root, parent, this->root,
				"Node not AVLNode");
		}
		if (avl_root->left == 0 && avl_root->right == 0) {
			if (avl_root->balance != AVLNode<Item_Type>::BALANCED) {
				throw Bad_Structure<Item_Type>(local_root, parent, this->root,
					"Leaf node not balanced");
			}
			return 1;
		}
		else {
			int left_height = verify_structure(avl_root->left, local_root);
			int right_height = verify_structure(avl_root->right, local_root);
			int delta = right_height - left_height;
			if (delta < -1) {
				throw Bad_Structure<Item_Type>(local_root, parent, this->root,
					"Balance < -1");
			}
			if (delta > 1) {
				throw Bad_Structure<Item_Type>(local_root, parent, this->root,
					"Balance > +1");
			}
			switch (delta) {
			case - 1:
				if (avl_root->balance != AVLNode<Item_Type>::LEFT_HEAVY) {
					throw Bad_Structure<Item_Type>(local_root, parent, this->root,
						"Balance value not correct, should be -1");
				}
				break;
			case 0:
				if (avl_root->balance != AVLNode<Item_Type>::BALANCED) {
					throw Bad_Structure<Item_Type>(local_root, parent, this->root,
						"Balance value not correct, should be 0");
				}
				break;
			case + 1:
				if (avl_root->balance != AVLNode<Item_Type>::RIGHT_HEAVY) {
					throw Bad_Structure<Item_Type>(local_root, parent, this->root,
						"Balance value not correct, should be +1");
				}
				break;
			}
			if (avl_root->left != 0) {
				if (avl_root->left->data >= avl_root->data) {
					throw Bad_Structure<Item_Type>(local_root, parent, this->root,
						"Left child >= parent");
				}
			}
			if (avl_root->right != 0) {
				if (avl_root->right->data <= avl_root->data) {
					throw Bad_Structure<Item_Type>(local_root, parent, this->root,
						"Right child <= parent");
				}
			}
			return (left_height > right_height ? left_height : right_height) + 1;
		}
}

#endif
