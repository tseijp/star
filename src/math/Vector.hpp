#ifndef _MATH_VECTOR_
#define _MATH_VECTOR_

#include <assert.h>
#include <stdio.h>
#include <string>
#include <math.h>

namespace STAR {
typedef double Scalar;
struct Vector {
  using S = Scalar;
  using V = Vector;
  S _x;
  S _y;
  S _z;
  S x () { return _x; }
  S y () { return _y; }
  S z () { return _z; }

  S& operator[](int i) {
    switch (i) {
      case 0: { return _x; }
      case 1: { return _y; }
      case 2: { return _z; }
      default: { }
    };
    assert(0);
    return _x;
  }

  void print() {
    printf("%f, ", _x);
    printf("%f, ", _y);
    printf("%f, ", _z);
    printf("\n");
  }

  explicit Vector(int unused = 0) {}
  Vector (V& v) { set(v); }
  Vector (S x, S y, S z) { set(x, y, z); }

  V& set (V& _) { _x = _.x(); _y = _.y(); _z = _.z(); return *this; }
  V& set (S x, S y, S z) { _x = x; _y = y; _z = z; return *this; }
  V& fill (S s) { _x = _y = _z = s; return *this; }
  V& setX (S x) { _x = x; return *this; }
  V& setY (S y) { _y = y; return *this; }
  V& setZ (S z) { _z = z; return *this; }
  V& set_sphere(S rad, S tht, S phi) {
    return set(
        rad * sin(tht) * cos(phi),
        rad * cos(tht),
        rad * sin(tht) * sin(phi));    
  }
  /**
   * Math
   */
  V  operator+ () { Vector r; r.set( _x, _y, _z); return r; }
  V  operator- () { Vector r; r.set(-_x,-_y,-_z); return r; }
  V& operator+= (S& s) { _x+=s; _y+=s; _z+=s; return *this; }
  V& operator-= (S& s) { _x-=s; _y-=s; _z-=s; return *this; }
  V& operator*= (S& s) { _x*=s; _y*=s; _z*=s; return *this; }
  V& operator/= (S& s) { _x/=s; _y/=s; _z/=s; return *this; }
  V& operator+= (V& _) { _x+=_.x(); _y+=_.y(); _z+=_.z(); return *this; }
  V& operator-= (V& _) { _x-=_.x(); _y-=_.y(); _z-=_.z(); return *this; }
  V& operator*= (V& v) { return cross(v); }
  S dot (V& _) { return _x*_.x() + _y*_.y() + _z*_.z(); }
  S length () { return dot(*this); }
  S triple (V& _, V& __) {
    return _x * (_.y() * __.z() - _.z() * __.y()) +
           _y * (_.z() * __.x() - _.x() * __.z()) +
           _z * (_.x() * __.y() - _.y() * __.x());
  }
  V& cross(V& _) {
    return set(
      _y * _.z() - _z * _.y(),
      _z * _.x() - _x * _.z(),
      _x * _.y() - _y * _.x()
    );
  }
};  // struct Vector

Vector operator+ (Vector& _, Scalar& s) { Vector r {_}; return r += s; }
Vector operator- (Vector& _, Scalar& s) { Vector r {_}; return r -= s; }
Vector operator/ (Vector& _, Scalar& s) { Vector r {_}; return r /= s; }
Vector operator* (Vector& _, Scalar& s) { Vector r {_}; return r *= s; }
Vector operator+ (Vector& _, Vector& v) { Vector r {_}; return r += v; }
Vector operator- (Vector& _, Vector& v) { Vector r {_}; return r -= v; }
Vector operator* (Vector& _, Vector& v) { Vector r {_}; return r *= v; }
} // namespace STAR
#endif // _MATH_VECTOR_
