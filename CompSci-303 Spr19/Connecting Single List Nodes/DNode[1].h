#include <cstddef>

template <typename Item_Type>
struct DNode {
	// Data Fields
	/** The data */
	Item_Type data;
	/** The pointer to the next node. */
	DNode* next;

	/** The pointer to the previous node. */
	DNode* prev;

	// Constructor
	DNode(const Item_Type& data_item, DNode* prev_val =NULL, DNode* next_val = NULL) :
		data(data_item), prev(prev_val), next(next_val) {}
};
