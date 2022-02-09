#ifndef _MATH_QUATER_
#define _MATH_QUATER_
#include <assert.h>
#include "Vector.hpp"
#include "Matrix.hpp"

struct Quater {
  // typedef double S;
  // typedef Vector V;
  // typedef Quater Q;

  // S _x;
  // S _y;
  // S _z;
  // S _w;
  // S& x() { return _x; }
  // S& y() { return _y; }
  // S& z() { return _z; }
  // S& w() { return _w; }
  // S& operator[](int i) {
  //   switch (i) {
  //     case 0: { return _x; }
  //     case 1: { return _y; }
  //     case 2: { return _z; }
  //     case 3: { return _w; }
  //     default: { }
  //   };
  //   assert(0);
  //   return _x;
  // }

  // explicit Quater(int unused = 0) {}
  // Quater (Q& _) { set(_.x(), _.y(), _.z(), _.w()); }
  // Quater (S x, S y, S z, S w) { set(x, y, z, w); }
                                  
  // Q& setX (S x) { _x = x; return *this; }
  // Q& setY (S y) { _y = y; return *this; }
  // Q& setZ (S z) { _z = z; return *this; }
  // Q& setW (S w) { _w = w; return *this; }
  // Q& set (S s) { return (*this).setX(s).setY(s).setZ(s); }
  // Q& set (S x, S y, S z, S w) { return (*this).setX(x).setY(y).setZ(z); }

  /**
   * Math
   */
  // S length() { return dot(*this); }
  // S dot (Q& _) { return _x*_.x() + _y*_.y() + _z*_.z() + _w*_.w(); }
  // Q& operator/=(S s) { return (*this) *= (1.0 / s); }
  // Q& operator*=(S s) { _x*=s; _y*=s; _z*=s; _w*=s; return *this; }
  // Q& operator+=(Q& _) { _x+=_.x(); _y+=_.y(); _z+=_.z(); _w+=_.w(); return *this; }
  // Q& operator*=(Q& _) {
  //   set(_w*_.x() + _x*_.w() + _y*_.z() - _z*_.y(),
  //       _w*_.y() + _y*_.w() + _z*_.x() - _x*_.z(),
  //       _w*_.z() + _z*_.w() + _x*_.y() - _y*_.x(),
  //       _w*_.w() - _x*_.x() - _y*_.y() - _z*_.z());
  //   return *this;
  // }
  // static Q clone (const S& _x, const S& _y, const S& _z, const S& _w) {
  //   Quat res; return res.set(_x, _y, _z, _w);
  // }
}  // struct Quater
#endif  //_MATH_QUATER_
