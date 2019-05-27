#ifndef HASH_TABLE_OPEN_H_
#define HASH_TABLE_OPEN_H_

/** Implementaion of the hash_map class using open hashing */

#include <stdexcept>
#include <cstddef>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <ostream>
#include "hash.h"

namespace KW
{
/** Definition of the hash_map class. This definition is similar
    to the unordered_map that has been proposed for the next
    version of the C++ standard.
    @param Key_Type The type of the keys
    @param Value_Type The type of the values
*/
template<typename Key_Type, typename Value_Type>
  class hash_map {
    
    public:

		
    
    // Typedefs
    typedef std::pair<const Key_Type, Value_Type> Entry_Type;

    // Forward declaration of iterator
    class iterator;
    class const_iterator;
    
    /** Construct an empty hash_map. */
    hash_map(int capacity) :
      hash_fcn(hash<Key_Type>()), num_keys(0), 
      the_table(capacity, NULL),
      LOAD_THRESHOLD(0.75), 
      num_deletes(0) 

      , num_probes(0), num_locates(0)

      {}
    /** Copy Constructor.
	@param other The other map to be copied
    */
    hash_map(const hash_map<Key_Type, Value_Type>& other) :
      hash_fcn(hash<Key_Type>()), num_keys(0), 
      the_table(other.the_table.size(), NULL),
      LOAD_THRESHOLD(0.75), 
      num_deletes(0) 
      , num_probes(0), num_locates(0)
      {
	for (size_t i = 0; i < other.the_table.size(); i++) {
	  if (other.the_table[i] != NULL && other.the_table[i] != DELETED)
	    insert(Entry_Type(other.the_table[i]->first, 
			      other.the_table[i]->second));
	}
      }
    /** Assignment operator 
	@param other The other map to be assigned
	@return This map after assignment
    */
    hash_map<Key_Type, Value_Type>& 
      operator=(const hash_map<Key_Type, Value_Type>& other) {

      hash_map<Key_Type, Value_Type> temp(other);
      swap(temp);

      return *this;
    }
    /** Destructor */
    ~hash_map() {
      for (size_t i = 0; i < the_table.size(); i++) {
	if (the_table[i] != NULL && the_table[i] != DELETED) 
	  delete the_table[i];
      }
    }
    /** Swap this hash_map with another */
    void swap(hash_map<Key_Type, Value_Type>& other) {
      std::swap(hash_fcn, other.hash_fcn); 
      std::swap(num_keys, other.num_keys); 
      the_table.swap(other.the_table);
      std::swap(num_deletes, other.num_deletes);
    }
    /** Inserts an item into the map.
	post: The key is associated with the value in the map.
	@param entry The key, value pair to be inserted
	@return An iterator to the inserted item and true
	if the entry was inserted; an iterator to the existing
	item and false if the item is already present
    */
    std::pair<iterator, bool> insert(const Entry_Type& entry) {
      double load_factor = double(num_keys + num_deletes) / the_table.size();
      if (load_factor > LOAD_THRESHOLD) {
	rehash(); // Double the size of the table.
      }
      // Find the position in the table.
      size_t index = locate(entry.first);
      // See whether it is empty.
      if (the_table[index] == NULL) {
	// Create a new entry.
	the_table[index] = new Entry_Type(entry);
	num_keys++;
	return std::make_pair(iterator(this, index), true);
      } else {
	// Item is already in the table.
	return std::make_pair(iterator(this, index), false);
      }
    }
    
    /** Lookup an item in the map
	@param key The key of the item being sought
	@return An iterator that references a 
	pair<const Key_Type, Value_Type> that
	contains the key and the associated value sought,
	or end() if the key is not in the map.
    */
    iterator find(const Key_Type& key) {
      size_t index = locate(key);
      if (the_table[index] == NULL) {
	return iterator(this, the_table.size());
      } else {
	return iterator(this, index);
      }
    }
    
    const_iterator find(const Key_Type& key) const {
      size_t index = locate(key);
      if (the_table[index] == NULL) {
	return const_iterator(this, the_table.size());
      } else {
	return const_iterator(this, index);
      }
    }
    
    /** Accesses a value in the map, using the key as an index.
	@param key The key of the item being sought
	@return A reference to the associated value. If the
	key was not in the map, a default value is inserted and
	a reference to this value is returned.
    */
    Value_Type& operator[](const Key_Type& key) {
      // Try to insert a dummy item.
      std::pair<iterator, bool> ret = insert(Entry_Type(key, Value_Type()));
      // Return a reference to the value found or inserted.
      return ret.first->second;
    }
    
    /** Remove an item from the map based on a key
	@param key The key of the item to be removed
	@return true if the item removed, false if the item
	was not already in the map
    */
    void erase(const Key_Type& key) {
      size_t index = locate(key);
      if (the_table[index] == NULL) {
	return;
      } else {
	delete the_table[index];
	the_table[index] = DELETED;
	num_keys--;
	num_deletes++;
      }
    }
    
    /** Return an iterator to the beginning of the map */
    iterator begin() {
      iterator return_value(this, 0);
      return_value.advance();
      return return_value;
    }
    
    /** Return a const_iterator to the beginning of the map */
    const_iterator begin() const {
      const_iterator return_value(this, 0);
      return_value.advance();
      return return_value;
    }
    
    /** Return an iterator to the end of the map */
    iterator end() {
      return iterator(this, the_table.size());
    }
    
    /** Return an iterator to the end of the map */
    const_iterator end() const {
      return const_iterator(this, the_table.size());
    }
    
    /*<exercise chapter="9" section="4" type="programming" number="5">*/
    /** Return the size of the map */
    size_t size() const {return num_keys;}

    
    /** Determine if the map is empty */
    bool empty() const {return num_keys == 0;}
    
    /*</exercise chapter="9" section="4" type="programming" number="4">*/
    /** Return a string representation of the hash map 
	@return A string that contains each pair enclosed in "[" and "]"
	with the key and value separated by a comma. The whole string
	is enclosed in "{" and "}" 
    */
    std::string to_string() const {
      std::ostringstream result;
      result << "{";
      const_iterator itr = begin();
      if (itr != end()) {
	result << "[" << itr->first << ", " << itr->second << "]";
	while (++itr != end()) {
	  result << ", [" << itr->first << ", " << itr->second << "]";
	}
      }
      result << "}";
      return result.str();
    }

    double average_probes() const {
      return double(num_probes)/double(num_locates);
    }

    /** The iterator class */
    class iterator {

    public:
      
      /** De-reference an iterator */
      Entry_Type& operator*() const {
	if (the_index == the_parent->the_table.size()) {
	  throw std::invalid_argument("Attemt to de-reference end()");
	}
	if (the_parent->the_table[the_index] == NULL) {
	  throw std::invalid_argument("Attemp to dereference invalid iterator");
	}
	return the_parent->the_table[the_index]->second;
      }
      
      /** De-reference an iterator */
      Entry_Type* operator->() const {
	if (the_index == the_parent->the_table.size()) {
	  throw std::invalid_argument("Attemt to de-reference end()");
	}
	if (the_parent->the_table[the_index] == NULL) {
	  throw std::invalid_argument("Attemp to dereference invalid iterator");
	}
	return the_parent->the_table[the_index];
      }
      
      /** Prefix increment operator */
      iterator& operator++() {
	++the_index;
	advance();
	return *this;
      }
      
      /** Postfix increment operator */
      iterator operator++(int) {
	typename hash_map<Key_Type, Value_Type>::iterator temp(*this);
	++(*this);
	return temp;
      }
      
      /** Equality operator */
      bool operator==(const iterator& other) const {
	return the_index == other.the_index;
      }
      
    private:
      
      // Allow the map to access the private constructor and data fields
      friend class hash_map<Key_Type, Value_Type>;
      
      // Allow const_iterators to access private data fields
      friend class const_iterator;
      
      /** Advance the iterator to the next position */
      void advance() {
	while (the_index < the_parent->the_table.size()
	       && (the_parent->the_table[the_index] == NULL
		   || the_parent->the_table[the_index] == the_parent->DELETED))
	  ++the_index;
      }
      
      /** Construct an iterator starting at a given position
	  in the hash table */
      iterator (hash_map<Key_Type, Value_Type>* parent,
		size_t index) : 
	the_parent(parent), the_index(index) {}
      
      /** Pointer the the map containing this iterator */
      hash_map<Key_Type, Value_Type>* the_parent;
      
      /** The index of the current position */
      size_t the_index;
      
    }; // End iterator
    
    /** The const_iterator class */
    class const_iterator {

    public:
      
      /** Convert from an iterator to a const_iterator */
      const_iterator(const typename hash_map<Key_Type, 
		     Value_Type>::iterator& other)
	: the_parent(other.the_parent), the_index(other.the_index) {}
      /** De-reference an const_iterator */
      Entry_Type& operator*() const {
	if (the_index == the_parent->the_table.size()) {
	  throw std::invalid_argument("Attemt to de-reference end()");
	}
	if (the_parent->the_table[the_index] == NULL) {
	  throw std::invalid_argument("Attemp to dereference invalid iterator");
	}
	return the_parent->the_table[the_index]->second;
      }
      
      Entry_Type* operator->() const {
	if (the_index == the_parent->the_table.size()) {
	  throw std::invalid_argument("Attemt to de-reference end()");
	}
	if (the_parent->the_table[the_index] == NULL) {
	  throw std::invalid_argument("Attemp to dereference invalid iterator");
	}
	return the_parent->the_table[the_index];
      }
      
      
      /** Prefix increment operator */
      const_iterator& operator++() {
	++the_index;
	advance();
	return *this;
      }
      
      /** Postfix increment operator */
      const_iterator operator++(int) {
	typename hash_map<Key_Type, Value_Type>::const_iterator temp(*this);
	++(*this);
	return temp;
      }
      
      /** Equality operator */
      bool operator==(const const_iterator& other) const {
	return the_index == other.the_index;
      }
      /** Inequality operator */
      bool operator!=(const const_iterator& other) const {
	return !operator==(other);
      }
      
    private:
      
      // The Map is our friend
      friend class hash_map<Key_Type, Value_Type>;
      
      /** Advance the iterator to the next position */
      void advance() {
	while (the_index < the_parent->the_table.size()
	       && (the_parent->the_table[the_index] == NULL
		   || the_parent->the_table[the_index] == the_parent->DELETED))
	  ++the_index;
      }
      
      /** Construct an const_iterator starting at a given position
	  in the hash table */
      const_iterator (const hash_map<Key_Type, Value_Type>* const parent,
		      size_t index) : 
	the_parent(parent), the_index(index) {}
      
      /** Pointer to the map containing the iterator */
      const hash_map<Key_Type, Value_Type>* const the_parent;
      
      /** The index of the current position */
      size_t the_index;
      
    }; // End const_iterator
    
  private:
    /** Expand the table size when load_factor exceeds LOAD_THRESHOLD.
	post: The size of the table is doubled.
	Each nondeleted entry from the original table is
	reinserted into the expanded table.
	The value of num_keys is reset to the number of items
	actually inserted; num_deletes is reset to 0.
    */
    void rehash() {
      // Create a new table whose size is double the current table.
      std::vector<Entry_Type*> other_table(the_table.size() * 2, NULL);
      
      // Swap this table with the current table.
      the_table.swap(other_table);
      
      // Reinsert all items from old table to new.
      num_deletes = 0;
      for (size_t i = 0; i < other_table.size(); i++) {
	if ((other_table[i] != NULL) && (other_table[i] != DELETED)) {
	  size_t index = locate(other_table[i]->first);
	  the_table[index] = other_table[i];
	}
      }
    }
    /** Locates the entry in the hash table that contains the target key
	or finds the next free entry.
	@param key The key being sought    
	@return The position of the key or the first empty slot if
	the key is not in the table
    */
    size_t locate(const Key_Type& key) {

      ++num_locates;
      ++num_probes;

      size_t index = hash_fcn(key) % the_table.size();
      while (the_table[index] != NULL
	     && (the_table[index] == DELETED
		 || the_table[index]->first != key)){
		  ++num_probes;
		  index = (index + 1) % the_table.size();
      }
      return index;
    }
    
    
    /** The hash function object */
    hash<Key_Type> hash_fcn;
    
    /** The number of items currently in the map */
    size_t num_keys;
    
    /** The vector containing the hash_table */
    std::vector<Entry_Type*> the_table;
    
    /** The initial capacity */
    static const size_t INITIAL_CAPACITY = 100;
    
    /** The maximum load factor */
    const double LOAD_THRESHOLD;
    
    /** The number of deleted keys */
    size_t num_deletes;
    
    /** The number of probes */
    size_t num_probes;
    
    /** The number of calls to locate */
    size_t num_locates;
    
    /** A dummy entry and a pointer to it */
    static Entry_Type dummy;
    static Entry_Type* const DELETED;
    
}; // End hash_map
 
 template<typename Key_Type, typename Value_Type>
   typename hash_map<Key_Type, Value_Type>::Entry_Type
   hash_map<Key_Type, Value_Type>::dummy = 
   std::pair<const Key_Type, Value_Type>(
					 Key_Type(), Value_Type());
 
 template<typename Key_Type, typename Value_Type>
   typename hash_map<Key_Type, Value_Type>::Entry_Type* const 
   hash_map<Key_Type, Value_Type>::DELETED = 
   &hash_map<Key_Type, Value_Type>::dummy;
} // end namespace KW

#endif
