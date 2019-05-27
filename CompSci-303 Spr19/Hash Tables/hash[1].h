#ifndef HASH_H_
#define HASH_H_

/** Hash Function Objects Template */
template<typename Key_Type>
  struct hash {
    size_t operator()(const Key_Type&);
};

// Specialization for string
#include <string>
template<>
  struct hash<std::string> {
    size_t operator()(const std::string& s) {
      size_t result = 0;
      for (size_t i = 0; i < s.length(); i++) {
        result = result * 31 + s[i];
      }
      return result;
    }
};
// Specialization for int
template<>
  struct hash<int> {
    size_t operator()(int i) {
      return size_t(4262999287U * i);
    }
};
#endif
