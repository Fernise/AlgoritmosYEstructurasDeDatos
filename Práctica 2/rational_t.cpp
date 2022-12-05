// AUTOR: Fernando Manuel González Perdomo
// FECHA: 2022-03-15
// EMAIL: alu0101506371@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
// getter: devuelve el valor del numerador (atributo privado)
inline
int
rational_t::get_num() const
{
  return num_;
}


// getter: devuelve el valor del denominador (atributo privado) 
inline
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


  
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}


// setter: cambia el valor del denominador (atributo privado)
inline
double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}


// método: devuelve el número racional opuesto de otro
rational_t 
rational_t::opposite() const
{ 
  return rational_t((-1)*get_num(), get_den());
}


// método: devuelve el número recíproco de otro
rational_t
rational_t::reciprocal() const
{ 
  return rational_t(get_den(), get_num());
}



// comparaciones
// método: compara dos números racionales para comprobar si son iguales 
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{ 
  return fabs(value() - r.value()) < precision;
}


// método: compara dos números reales para comprobar si el segundo es mayor que el primero 
bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  return (value() - r.value()) > precision;
}


// método: compara dos números reales para comprobar si el segundo es menor que el primero

bool
rational_t::is_less(const rational_t& r, const double precision) const
{
  return r.is_greater(*this, precision);
}


// operaciones
// método: suma dos números racionales
rational_t
rational_t::add(const rational_t& r) const
{
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                    get_den() * r.get_den());
}


// método: resta dos números racionales
rational_t
rational_t::substract(const rational_t& r) const
{
  return add(r.opposite());
}


// método: multiplica dos números racionales
rational_t
rational_t::multiply(const rational_t& r) const
{
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}


// método: divide dos números racionales
rational_t
rational_t::divide(const rational_t& r) const
{
  return multiply(r.reciprocal());
}


// FASE I: operadores
// método: sobrecarga del operador '+'
rational_t
operator+(const rational_t& a, const rational_t& b)
{
  return a.add(b);
}


// método: sobrecarga del operador '-'
rational_t
operator-(const rational_t& a, const rational_t& b)
{
  return a.substract(b);
}


// método: sobrecarga del operador '*'
rational_t
operator*(const rational_t& a, const rational_t& b)
{
  return a.multiply(b);
}


// método: sobrecarga del operador '/'
rational_t
operator/(const rational_t& a, const rational_t& b)
{
  return a.divide(b);
}



// E/S
// método: imprime por pantalla un número racional
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


// método: lee desde teclado un número racional
void
rational_t::read(istream& is)
{
  is >> num_ >> den_;
  assert(den_ != 0);
}


// método: sobrecarga del operador '<<'
ostream&
operator<<(ostream& os, const rational_t& r)
{
  r.write(os);
  return os;
}

// método: sobrecarga del operador '>>'
istream&
operator>>(istream& is, rational_t& r)
{
  r.read(is);
  return is;
}