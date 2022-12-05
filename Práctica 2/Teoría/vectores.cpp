#include <iostream>

#include "vectores_t.hpp"

template <class T>
vector_t::vector_t(const int)  {

}

template <class T>
vector_t::vector_t(const int) {

}

// destructor
template <class T>
vector_t::~vector_t() {

}

// getters
template <class T>
vector_t::int getval_() const {
  return *val_;
}

template <class T>
vector_t::int getsize_() const {
    return size_;
}

// setters
template <class T>
vector_t::void setval_(const int value) {
  val_ = value;
}

template <class T>
vector_t::void setsize_(const int size) {
  size_ = size;
}

// sobre carga de operadores: << y ()
vector_t::operator<<(ostream& os, const *T vector) {
  os << "[" << vector.getsize() << ", " << vector.getvalue() << "]" << std::endl;
  return 0s;
}
vector_t::operator()(const int size, const *T vector) {
  return *T vector[size];
}