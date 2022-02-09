#ifndef _MATH_MATRIX_
#define _MATH_MATRIX_
#include "Vector.hpp"

struct Matrix {
  typedef double S;
  typedef Vector V;
  typedef Matrix M;

  Vector _[3];

  S  at  (int j, int i) { return _[i][j]; }
  S  operator() (int j, int i) { return _[i][j]; }
  V& operator[] (int i) { return _[i]; }
  V  get (int j) { Vector ret; return ret.set(_[0][j], _[1][j], _[2][j]); }
  M& set (int j, int i, const S& _ij) { _[i][j] = _ij; return *this; }
  M& set (
    const S& xx, const S& xy, const S& xz,
    const S& yx, const S& yy, const S& yz,
    const S& zx, const S& zy, const S& zz) {
    _[0].set(xx, yx, zx);
    _[1].set(xy, yy, zy);
    _[2].set(xz, yz, zz);
    return *this;
  }

  explicit Matrix(int unused = 0) {}
  Matrix(M& m) {_[0] = m._[0]; _[1] = m._[1]; _[2] = m._[2]; }
  Matrix (
    const S& xx, const S& xy, const S& xz,
    const S& yx, const S& yy, const S& yz,
    const S& zx, const S& zy, const S& zz) {
    (*this).set(xx, xy, xz, yx, yy, yz, zx, zy, zz);
  }

  /**
   * Math
   */
  S tdotx (V& v) { return (*this).get(0).dot(v); }
  S tdoty (V& v) { return (*this).get(1).dot(v); }
  S tdotz (V& v) { return (*this).get(2).dot(v); }
  M& fill (S& v) { return set(v, v, v, v, v, v, v, v, v); }
  M& operator = (M& m) { _[0] =m[0]; _[1] =m[1]; _[2] =m[2]; return *this; }
  M& operator+= (M& m) { _[0]+=m[0]; _[1]+=m[1]; _[2]+=m[2]; return *this; }
  M& operator-= (M& m) { _[0]-=m[0]; _[1]-=m[1]; _[2]-=m[2]; return *this; }
  M& operator*= (M& m) {
    (*this).set(
        tdotx(m[0]), tdotx(m[1]), tdotx(m[2]),
        tdoty(m[0]), tdoty(m[1]), tdoty(m[2]),
        tdotz(m[0]), tdotz(m[1]), tdotz(m[2]));
    return *this;
  }

  // static M clone (
  //   const S& xx, const S& xy, const S& xz,
  //   const S& yx, const S& yy, const S& yz,
  //   const S& zx, const S& zy, const S& zz) {
  //   Matrix<S> res; return res.set(xx, xy, xz, yx, yy, yz, zx, zy, zz);
  // }
}; // struct Matrix
#endif // _MASH_Matrix_
