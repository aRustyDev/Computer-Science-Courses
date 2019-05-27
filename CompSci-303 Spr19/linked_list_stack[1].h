

namespace SLL {
	
	
	template<typename Item_Type>
	class stack {
	private:
		// Data fields
		// Insert definition of class Node here
#include "Node.h"

		/** A pointer to the top of the stack. */
		Node* top_of_stack;
		size_t num_items;
	
	public:
		
		void push(const Item_Type& item) {
			top_of_stack = new Node(item, top_of_stack);
			++num_items;
		}
		
		
		Item_Type& top() {
			return top_of_stack->data;
		}

		const Item_Type& top() const {
			return top_of_stack->data;
		}

		void pop() {
			if (!empty()){
				Node* old_top = top_of_stack;
				top_of_stack = top_of_stack->next;
				delete old_top;

				--num_items;
			}
		}

		bool empty() const {
			return top_of_stack == NULL;
		}

		size_t size(){
			return num_items;
		}
	
	}; // End class stack
};
