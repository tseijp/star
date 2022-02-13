#ifndef _MATH_MATRIX_
#define _MATH_MATRIX_

#include "Vector.hpp"
#include <stdio.h>
#include <string>
#include <math.h>

namespace STAR {
typedef double Scalar;
struct Matrix {
  typedef Scalar S;
  typedef Vector V;
  typedef Matrix M;
  Vector _[3];

  void print() {
    _[0].print();
    _[1].print();
    _[2].print();
  }

  S  operator() (int j, int i) { return _[i][j]; }
  V& operator[] (int i) { return _[i]; }
  V  get (int j) { Vector ret; ret.set(_[0][j], _[1][j], _[2][j]); return ret; }
  M& set (int j, int i, const S& _ij) { _[i][j] = _ij; return *this; }
  M& set (V& _0, V& _1, V& _2) {
    _[0].set(_0);
    _[1].set(_1);
    _[2].set(_2);
    return *this;
  }
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
  Matrix (M& m) {_[0] = m[0]; _[1] = m[1]; _[2] = m[2]; }
  Matrix (V& v) {_[0] = v   ; _[1] = v   ; _[2] = v   ; }
  Matrix (
    const S& xx, const S& xy, const S& xz,
    const S& yx, const S& yy, const S& yz,
    const S& zx, const S& zy, const S& zz) {
    set(xx, xy, xz, yx, yy, yz, zx, zy, zz);
  }

  M& set_rotation_x(S angle) {
    S c = cos(angle);
    S s = sin(angle);
    return set(
      1, 0, 0,
      0, c,-s,
      0, s, c
    );
  }

  M& set_rotation_y(S angle) {
    S c = cos(angle);
    S s = sin(angle);
    return set(
      c, 0, s,
      0, 1, 0,
     -s, 0, c
    );
  }

  M& set_rotation_z(S angle) {
    S c = cos(angle);
    S s = sin(angle);
    return set(
      c,-s, 0,
   s   , c, 0,
      0, 0, 1
    );
  }

  /**
   * Math
   */
  S tdotx(V &v) { return get(0).dot(v); }
  S tdoty(V &v) { return get(1).dot(v); }
  S tdotz(V &v) { return get(2).dot(v); }
  M& fill (S& v) { return set(v, v, v, v, v, v, v, v, v); }
  M  operator+ () { Matrix r; r[0]=+_[0]; r[1]=+_[1]; r[2]=+_[2]; return r; }
  M  operator- () { Matrix r; r[0]=-_[0]; r[1]=-_[1]; r[2]=-_[2]; return r; }
  M& operator+= (S& s) { _[0]/=s   ; _[1]/=s   ; _[2]/=s   ; return *this; }
  M& operator-= (S& s) { _[0]/=s   ; _[1]/=s   ; _[2]/=s   ; return *this; }
  M& operator*= (S& s) { _[0]*=s   ; _[1]*=s   ; _[2]*=s   ; return *this; }
  M& operator/= (S& s) { _[0]/=s   ; _[1]/=s   ; _[2]/=s   ; return *this; }
  M& operator+= (M& m) { _[0]+=m[0]; _[1]+=m[1]; _[2]+=m[2]; return *this; }
  M& operator-= (M& m) { _[0]-=m[0]; _[1]-=m[1]; _[2]-=m[2]; return *this; }
  V& operator*= (V& v) { V r; return r.set(tdotx(v), tdoty(v), tdotz(v)); } 
  M& operator*= (M& m) {
    return set(
        tdotx(m[0]), tdotx(m[1]), tdotx(m[2]),
        tdoty(m[0]), tdoty(m[1]), tdoty(m[2]),
        tdotz(m[0]), tdotz(m[1]), tdotz(m[2]));
  }
}; // struct Matrix

Matrix operator+ (Matrix& _, Scalar  s) { Matrix r {_}; return r += s; }
Matrix operator- (Matrix& _, Scalar  s) { Matrix r {_}; return r -= s; }
Matrix operator* (Matrix& _, Scalar  s) { Matrix r {_}; return r *= s; }
Matrix operator/ (Matrix& _, Scalar  s) { Matrix r {_}; return r /= s; }
Matrix operator+ (Matrix& _, Matrix& m) { Matrix r {_}; return r += m; }
Matrix operator- (Matrix& _, Matrix& m) { Matrix r {_}; return r -= m; }
Matrix operator* (Matrix& _, Matrix& m) { Matrix r {_}; return r *= m; }
Vector operator* (Matrix& m, Vector& v) {
  Vector res;
  return res.set(m.tdotx(v), m.tdoty(v), m.tdotz(v));
}
} // namespace STAR
#endif // _MASH_Matrix_
