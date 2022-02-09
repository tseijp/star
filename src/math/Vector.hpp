#ifndef _MATH_VECTOR_
#define _MATH_VECTOR_
#include <assert.h>

struct Vector {
  typedef double S;
  typedef Vector V;
  S _x;
  S _y;
  S _z;
  S x() { return _x; }
  S y() { return _y; }
  S z() { return _z; }

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

  explicit Vector(int unused = 0) {}
  Vector (V& _) { set(_.x(), _.y(), _.z()); }
  Vector (S x, S y, S z) { set(x, y, z); }

  V& set (S x, S y, S z) { _x = x; _y = y; _z = z; return *this; }
  V& setX (S x) { _x = x; return *this; }
  V& setY (S y) { _y = y; return *this; }
  V& setZ (S z) { _z = z; return *this; }
  V& fill (S s) { _x = _y = _z = s; return *this; }

  /**
   * Math
   */
  V& operator =(V& _) { _x =_.x(); _y =_.y(); _z =_.z(); return *this; }
  V& operator+=(V& _) { _x+=_.x(); _y+=_.y(); _z+=_.z(); return *this; }
  V& operator-=(V& _) { _x-=_.x(); _y-=_.y(); _z-=_.z(); return *this; }
  V& operator*=(V& _) { return cross(_); }
  S dot (V& _) { return _x*_.x() + _y*_.y() + _z*_.z(); }
  S length () { return dot(*this); }
  S triple(V& _, V& __) {
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
  // static V clone(const S x, const S y, const S z) {
  //   Vector res; return res.set(x, y, z);
  // }
};  // struct V
#endif // _MATH_VECTOR_
