#include <iostream>

// template class T
template <class T>
class vector_t{
  // public: constructores, destructor, getters, setter, métodos
  public:
  // constructores 
  vector_t(const int);
  vector_t(const int);
  // destructor
  ~vector_t();
  // getters
  int getval_() const;
  int getsize_() const;
  // setters
  void setval_(const int);
  void setsize_(const int);
// privado: atributos, size (tamaño del vector) 
  private:
    T *val_;
    int size_;
};

// sobre carga de operadores: << y ()
vector_t::operator<<(ostream& os, const int x);
vector_t::operator()(const int size, const *T value,);
