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

#include "vector_t.hpp"

using namespace std;

// plantilla "class T" 
template<class T>
class matrix_t
{
public:
  // Constructor con parámetros
  matrix_t(const int = 0, const int = 0);
  // Destructor
  ~matrix_t();
  
  // método: reajusta la matriz 
  void resize(const int, const int);
  
  // getters
  int get_m(void) const;
  int get_n(void) const;
  
  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  
  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&);

  // método: sobrecarga del operador <<. Escitura en pantalla
  void write(ostream& = cout) const;
  // método: sobrecarga del operador >>. Entrada de datos desde teclado
  void read(istream& = cin);

private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_; // vector
  // método privado: indica una posición de la matriz 
  int pos(const int, const int) const;
};


// constructor con parámetros
template<class T>
matrix_t<T>::matrix_t(const int m, const int n)
{ 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}


// destructor
template<class T>
matrix_t<T>::~matrix_t()
{}


// método: reajusta el tamaño de una matriz
template<class T>
void
matrix_t<T>::resize(const int m, const int n)
{
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}


// getter: devuelve la cantidad de filas de una matriz 
template<class T>
inline int
matrix_t<T>::get_m() const
{
  return m_;
}


// getter: devuelve la cantidad de columnas de una matriz 
template<class T>
inline int
matrix_t<T>::get_n() const
{
  return n_;
}


// método: devuelve el valor de una posición de la matriz (llamando al método privado pos)
// param1: fila (i) 
// param2: columna (j)
template<class T>
T&
matrix_t<T>::at(const int i, const int j)
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}

// ¿Qué hace y cómo funciona la sobrecarga del operator() en la clase matrix_t?
// La sobrecarga del operador () permite acceder a los índices de la matriz

// método: sobrecarga del operador (). Devuelve el valor de una posición de la matriz
// param1: fila (i) 
// param2: columna (j)
template<class T>
T&
matrix_t<T>::operator()(const int i, const int j)
{
  return at(i, j);
}


// método constante: devuelve el valor de una posición de la matriz (llamando al método privado pos)
// param1: fila (i) 
// param2: columna (j)
template<class T>
const T&
matrix_t<T>::at(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}


// método constante: sobrecarga del operador (). Devuelve el valor de una posición de la matriz
// param1: fila (i) 
// param2: columna (j)
template<class T>
const T&
matrix_t<T>::operator()(const int i, const int j) const
{
  return at(i, j);
}


// método: imprime en pantalla la matriz
template<class T>
void
matrix_t<T>::write(ostream& os) const
{ 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}


// método: lee por teclado el tamaño y el contenido de la matriz
template<class T>
void
matrix_t<T>::read(istream& is)
{
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}

// método: devuelve una posición en el vector de la matriz
template<class T>
inline
int
matrix_t<T>::pos(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
// método: prodcuto de dos matrices
template<class T>
void
matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B)
{
  assert((A.get_n() == B.get_m()));
  resize(A.get_m(), B.get_n());
  T total = 0;
  for (int i = 1; i <= A.get_m(); ++i) {
    for (int j = 1; j <= B.get_n(); ++j) {
      for (int k = 1; k <= A.get_n(); ++k) {
        total = total + (A(i, k) * B(k, j));
      }
      at(i, j) = total; 
      total = 0;
    }  
  }
}