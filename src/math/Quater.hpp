#ifndef _MATH_QUATER_
#define _MATH_QUATER_
#include <assert.h>
#include "Quater.hpp"
#include "Matrix.hpp"

namespace STAR {
typedef double Scalar;
struct Quater {
  typedef ::STAR::Scalar S;
  typedef ::STAR::Quater V;
  typedef ::STAR::Quater Q;

  S _x;
  S _y;
  S _z;
  S _w;
  S& x() { return _x; }
  S& y() { return _y; }
  S& z() { return _z; }
  S& w() { return _w; }

  inline S& operator[](int i) {
    switch (i) {
      case 0: { return _x; }
      case 1: { return _y; }
      case 2: { return _z; }
      case 3: { return _w; }
      default: { }
    }
    assert(0);
    return _x;
  }

  void print() {
    printf("%f, ", _x);
    printf("%f, ", _y);
    printf("%f, ", _z);
    printf("%f, ", _w);
    printf("\n");
  }
 
  explicit Quater(int unused = 0) {}
  Quater(Q& _) { set(_.x(), _.y(), _.z(), _.w()); }
  Quater(S x, S y, S z, S w) { set(x, y, z, w); }
                                  
  inline Q& setX(S x) { _x = x; return *this; }
  inline Q& setY(S y) { _y = y; return *this; }
  inline Q& setZ(S z) { _z = z; return *this; }
  inline Q& setW(S w) { _w = w; return *this; }
  inline Q& set(S s) { return (*this).setX(s).setY(s).setZ(s); }
  inline Q& set(S x, S y, S z, S w) { return (*this).setX(x).setY(y).setZ(z); }

  /**
   * Math
   */
  inline S length() { return dot(*this); }
  inline S dot (Q& _) { return _x*_.x() + _y*_.y() + _z*_.z() + _w*_.w(); }
  inline Q& operator+=(S& s) { _x+=s; _y+=s; _z+=s; _w+=s; return *this; }
  inline Q& operator-=(S& s) { _x-=s; _y-=s; _z-=s; _w-=s; return *this; }
  inline Q& operator*=(S& s) { _x*=s; _y*=s; _z*=s; _w*=s; return *this; }
  inline Q& operator/=(S& s) { _x/=s; _y/=s; _z/=s; _w/=s; return *this; }
  inline Q& operator+=(Q& _) { _x+=_.x(); _y+=_.y(); _z+=_.z(); _w+=_.w(); return *this; }
  inline Q& operator-=(Q& _) { _x-=_.x(); _y-=_.y(); _z-=_.z(); _w-=_.w(); return *this; }
  inline Q& operator*=(Q& _) {
    return set(_w*_.x() + _x*_.w() + _y*_.z() - _z*_.y(),
               _w*_.y() + _y*_.w() + _z*_.x() - _x*_.z(),
               _w*_.z() + _z*_.w() + _x*_.y() - _y*_.x(),
               _w*_.w() - _x*_.x() - _y*_.y() - _z*_.z());
  }
}; // struct Quater
inline Quater operator+(Quater& _, Scalar& s) { Quater r(_); return r+=s; }
inline Quater operator-(Quater& _, Scalar& s) { Quater r(_); return r-=s; }
inline Quater operator/(Quater& _, Scalar& s) { Quater r(_); return r/=s; }
inline Quater operator*(Quater& _, Scalar& s) { Quater r(_); return r*=s; }
inline Quater operator+(Quater& _, Quater& q) { Quater r(_); return r+=q; }
inline Quater operator-(Quater& _, Quater& q) { Quater r(_); return r-=q; }
inline Quater operator*(Quater& _, Quater& q) { Quater r(_); return r*=q; }
} // namespace STAR
#endif  //_MATH_QUATER_
