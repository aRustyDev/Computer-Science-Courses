#ifndef BAD_STRUCTURE_H
#define BAD_STRUCTURE_H
#include <stdexcept>
#include <string>
#include "BTNode.h"

/** Class to represent detecting a bad binary search tree structue */
template<typename Item_Type>
class Bad_Structure : public std::logic_error {
public:
	Bad_Structure(BTNode<Item_Type>* the_node, BTNode<Item_Type>* the_parent,
		BTNode<Item_Type>* the_root, const std::string& why) :
		std::logic_error(why), node(the_node), parent(the_parent), root(the_root) {}

	BTNode<Item_Type>* node;
	BTNode<Item_Type>* parent;
	BTNode<Item_Type>* root;
};

#endif