

#include "vector.h"
namespace VB {
	
	template<typename Item_Type>
	class stack {
	
	private:
		KW::vector<Item_Type> container;
	
	public:
		
		void push(const Item_Type& item) {
			container.push_back(item);
		}

		Item_Type& top() {
			return container.back();
		}

		const Item_Type& top() const {
			return container.back();
		}

		void pop() {
			container.pop_back();
		}

		bool empty() const {
			return container.empty();
		}

		size_t size() const {
			return container.size();
		}

	};
};