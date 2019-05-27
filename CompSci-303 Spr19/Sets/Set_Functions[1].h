#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace  std;




template <typename Key_Type, typename Compare>
std::set<Key_Type, Compare> operator+(const std::set<Key_Type, Compare>& left, const std::set<Key_Type, Compare>& right){
		typename std::set<Key_Type, Compare> result(left);

		result.insert(right.begin(), right.end());
		return result;
}

template <typename Key_Type, typename Compare>
std::set<Key_Type, Compare> operator-(
	const std::set<Key_Type, Compare>& left,
	const std::set<Key_Type, Compare>& right) {

		typename std::set<Key_Type, Compare> result(left);
		for (typename std::set<Key_Type, Compare>::const_iterator itr = right.begin();
			itr != right.end(); ++itr)
				result.erase(*itr);
		return result;
}


template <typename Key_Type, typename Compare>
std::set<Key_Type, Compare> operator*(const std::set<Key_Type, Compare>& left,
	const std::set<Key_Type, Compare>& right)
{
	return left - (left - right);
}

// Overloading the ostream insertion operator
template<typename Item_Type>
std::ostream& operator<<(std::ostream& out, const std::set<Item_Type>& a_set) {
	out << "{";
	bool first = true;
	for (typename std::set<Item_Type>::const_iterator itr = a_set.begin(); itr != a_set.end(); ++itr) {
		if (first)
			out << *itr;
		else
			out << ", " << *itr;
		first = false;
	}
	return out << "}";
}

	