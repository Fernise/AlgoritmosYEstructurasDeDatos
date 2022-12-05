// AUTOR: Fernando Manuel González Perdomo
// FECHA: 2022-03-15
// EMAIL: alu0101506371@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

// plantilla "class T"
template<class T>
class vector_t
{
public:
  // Constructor con parámetros
  vector_t(const int = 0);
  // Destructor
  ~vector_t();
  
  // método: Reajusta el vector
  void resize(const int);
  
  // getters

  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  // método: sobrecarga del operador <<. Escitura en pantalla
  void write(ostream& = cout) const;
  // método: sobrecarga del operador >>. Entrada de datos desde teclado
  void read(istream& = cin);

private:
  T *v_; // puntero de tipo "T"
  int sz_; // tamaño de la matriz
  
  // método: construye un nuevo vector
  void build(void);
  // método: destruye un vector
  void destroy(void);
};


// método:
template<class T>
vector_t<T>::vector_t(const int n)
{ sz_ = n;
  build();
}


// método:
template<class T>
vector_t<T>::~vector_t()
{
  destroy();
}


// método:
template<class T>
void
vector_t<T>::build()
{
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}


// método:
template<class T>
void
vector_t<T>::destroy()
{
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}


// método:
template<class T>
void
vector_t<T>::resize(const int n)
{
  destroy();
  sz_ = n;
  build();
}


// método:
template<class T>
inline T
vector_t<T>::get_val(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}


// método:
template<class T>
inline int
vector_t<T>::get_size() const
{
  return sz_;
}


// método:
template<class T>
void
vector_t<T>::set_val(const int i, const T d)
{
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}


// método:
template<class T>
T&
vector_t<T>::at(const int i)
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}


// método:
template<class T>
T&
vector_t<T>::operator[](const int i)
{
  return at(i);
}


// método:
template<class T>
const T&
vector_t<T>::at(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}


// método:
template<class T>
const T&
vector_t<T>::operator[](const int i) const
{
  return at(i);
}


// método:
template<class T>
void
vector_t<T>::write(ostream& os) const
{ 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}


// método:
template<class T>
void
vector_t<T>::read(istream& is)
{
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: producto escalar
// método: implementación del producto escalar entre vectores tipo double
template<class T>
T
scal_prod(const vector_t<T>& v, const vector_t<T>& w)
{
  // calcular modulo de cada vector
  // calcular cos(alpha)
  // modulo(v) * modulo(w) * cos(alpha)  
  for (int i = 1; i <= v.get_size; ++i) {
  
  } 
  return;
}


// método: implementación del producto escalar entre vectores tipo rational_t
double
scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w)
{

}
