// AUTOR: Fernando Manuel González Perdomo 
// FECHA: 22/02/2022
// EMAIL: alu0101506371@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"
#include <iostream>

#include <cmath>

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
// getter: devuelve el valor del numerador (atributo privado)
int
rational_t::get_num() const
{
  return num_;
}


// getter: devuelve el valor del denominador (atributo privado) 
int
rational_t::get_den() const
{
  return den_;
}


// setter: cambia el valor del numerador (atributo privado)
void
rational_t::set_num(const int n)
{
  num_ = n;
}


// setter: cambia el valor del denominador (atributo privado)
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}


// método: devuelve el valor double de la división numerador / denominador.
double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}


// comparaciones
// método: compara dos números racionales para comprobar si son iguales 
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{
  if (fabs(value() - r.value()) < precision) {
    return true;
  }
  return false;
}
  
// método: compara dos números reales para comprobar si el segundo es mayor que el primero 
bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  if (r.value() - value() > precision) {
    return true;
  }
  return false;
}


// método: compara dos números reales para comprobar si el segundo es menor que el primero
bool
rational_t::is_less(const rational_t& r, const double precision) const
{
  if (value() - r.value() > precision) {
    return true;
  }
  return false;
}


// operaciones
// método: suma dos números racionales
rational_t
rational_t::add(const rational_t& r)
{
  return rational_t ((get_num() * r.get_den()) + (get_den() * r.get_num()), (get_den() * r.get_den()));
}


// método: resta dos números racionales
rational_t
rational_t::substract(const rational_t& r)
{
  return rational_t ((get_num() * r.get_den()) - (get_den() * r.get_num()), (get_den() * r.get_den()));
}


// método: multiplica dos números racionales
rational_t
rational_t::multiply(const rational_t& r)
{
  return rational_t ((get_num() * r.get_num()), (get_den() * r.get_den()));
}


// método: divide dos números racionales
rational_t
rational_t::divide(const rational_t& r)
{
  return rational_t ((get_num() * r.get_den()), (get_den() * r.get_num()));
}



// E/S
// Imprime por pantalla el número racional
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


// Lee desde teclado un número racional
void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}

// Modificación
bool rational_t sign() {
  if (get_num() < 0 && get_den() < 0) {
    return true;
  }
  else if ( get_num() >= 0 && get_den() >= 0) {
    return true;
  }
  return false;
}