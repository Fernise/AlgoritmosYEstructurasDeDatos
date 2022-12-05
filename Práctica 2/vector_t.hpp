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


// constructor por defecto
template<class T>
vector_t<T>::vector_t(const int n)
{ sz_ = n;
  build();
}


// destructor
template<class T>
vector_t<T>::~vector_t()
{
  destroy();
}


// método: construye un vector dinámico
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


// método: destruye un vector dinámico
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


// método: reajusta el tamaño del vector
template<class T>
void
vector_t<T>::resize(const int n)
{
  destroy();
  sz_ = n;
  build();
}


// método: devuelve el valor del vector en la posición 'i'
template<class T>
inline T
vector_t<T>::get_val(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}


// método: devuelve el tamaño del vector 
template<class T>
inline int
vector_t<T>::get_size() const
{
  return sz_;
}


// método: modifica el valor del vector en la posición 'i'
template<class T>
void
vector_t<T>::set_val(const int i, const T d)
{
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}


// método: devuelve el valor del vector en la posición 'i'
template<class T>
T&
vector_t<T>::at(const int i)
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}

// ¿Para qué se sobrecarga el operator[] en la clase vector_t? 
// Se sobrecarga para poder acceder al índice del vector mediante [].

// método: devuelve el valor del vector en la posición 'i'
template<class T>
T&
vector_t<T>::operator[](const int i)
{
  return at(i);
}


// método const: devuelve el valor del vector en la posición 'i'
template<class T>
const T&
vector_t<T>::at(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}


// método const: devuelve el valor del vector en la posición 'i'
template<class T>
const T&
vector_t<T>::operator[](const int i) const
{
  return at(i);
}


// método: imprime en pantalla el vector
template<class T>
void
vector_t<T>::write(ostream& os) const
{ 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}


// método: lee por teclado un vector
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
// método: implementación del producto escalar entre vectores tipo rational_t
template<class T>
T
scal_prod(const vector_t<T>& v, const vector_t<T>& w)
{
  assert(v.get_size() == w.get_size());
  T scal_prod_result;   
  for (int i = 0; i < v.get_size(); ++i) {
    scal_prod_result = scal_prod_result + (v.at(i) * w.at(i)), (v.at(i) * w.at(i));
  } 
  return scal_prod_result;
}


// método: implementación del producto escalar entre vectores tipo double
double
scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w)
{
  assert(v.get_size() == w.get_size());
  rational_t aux = 0;
  double scal_prod_result = 0.0;
  for (int i = 0; i < v.get_size(); ++i) {
    aux = v.at(i) * w.at(i);
    scal_prod_result = scal_prod_result + aux.value();
  } 
  return scal_prod_result;
}
