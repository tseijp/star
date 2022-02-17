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

  inline S  operator()(int j, int i) { return _[i][j]; }
  inline V& operator[](int i) { return _[i]; }
  inline V  get(int j) { Vector ret; ret.set(_[0][j], _[1][j], _[2][j]); return ret; }
  inline M& set(int j, int i, const S& _ij) { _[i][j] = _ij; return *this; }
  inline M& set(V& _0, V& _1, V& _2) {
    _[0].set(_0);
    _[1].set(_1);
    _[2].set(_2);
    return *this;
  }

  inline M& set(
    const S& xx, const S& xy, const S& xz,
    const S& yx, const S& yy, const S& yz,
    const S& zx, const S& zy, const S& zz) {
    _[0].set(xx, yx, zx);
    _[1].set(xy, yy, zy);
    _[2].set(xz, yz, zz);
    return *this;
  }

  explicit Matrix(int unused = 0) {}
  Matrix(M& m) {_[0] = m[0]; _[1] = m[1]; _[2] = m[2]; }
  Matrix(V& v) {_[0] = v; _[1] = v; _[2] = v; }
  Matrix(
    const S& xx, const S& xy, const S& xz,
    const S& yx, const S& yy, const S& yz,
    const S& zx, const S& zy, const S& zz) {
    set(xx, xy, xz, yx, yy, yz, zx, zy, zz);
  }

  inline M& set_rotation_x(S angle) {
    S c = cos(angle);
    S s = sin(angle);
    return set(
      1, 0, 0,
      0, c,-s,
      0, s, c
    );
  }

  inline M& set_rotation_y(S angle) {
    S c = cos(angle);
    S s = sin(angle);
    return set(
      c, 0, s,
      0, 1, 0,
     -s, 0, c
    );
  }

  inline M& set_rotation_z(S angle) {
    S c = cos(angle);
    S s = sin(angle);
    return set(
      c,-s, 0,
      s, c, 0,
      0, 0, 1
    );
  }

  /**
   * Math
   */
  inline S tdotx(V& v) { return get(0).dot(v); }
  inline S tdoty(V& v) { return get(1).dot(v); }
  inline S tdotz(V& v) { return get(2).dot(v); }
  inline M &fill(S& s) { return set(s, s, s, s, s, s, s, s, s); }
  inline M& operator+=(S& s) { _[0]/=s; _[1]/=s; _[2]/=s; return *this; }
  inline M& operator-=(S& s) { _[0]/=s; _[1]/=s; _[2]/=s; return *this; }
  inline M& operator*=(S& s) { _[0]*=s; _[1]*=s; _[2]*=s; return *this; }
  inline M& operator/=(S& s) { _[0]/=s; _[1]/=s; _[2]/=s; return *this; }
  inline M& operator+=(M& m) { _[0]+=m[0]; _[1]+=m[1]; _[2]+=m[2]; return *this; }
  inline M& operator-=(M& m) { _[0]-=m[0]; _[1]-=m[1]; _[2]-=m[2]; return *this; }
  inline M  operator+() { M m; m[0]=+_[0]; m[1]=+_[1]; m[2]=+_[2]; return m; }
  inline M  operator-() { M m; m[0]=-_[0]; m[1]=-_[1]; m[2]=-_[2]; return m; }
  inline V  operator*=(V& v) { V res; return res.set(tdotx(v), tdoty(v), tdotz(v)); } 
  inline M& operator*=(M& m) {
    return set(
        tdotx(m[0]), tdotx(m[1]), tdotx(m[2]),
        tdoty(m[0]), tdoty(m[1]), tdoty(m[2]),
        tdotz(m[0]), tdotz(m[1]), tdotz(m[2]));
  }
}; // struct Matrix

inline Matrix operator+(Matrix& _, Scalar  s) { Matrix res(_); return res+=s; }
inline Matrix operator-(Matrix& _, Scalar  s) { Matrix res(_); return res-=s; }
inline Matrix operator*(Matrix& _, Scalar  s) { Matrix res(_); return res*=s; }
inline Matrix operator/(Matrix& _, Scalar  s) { Matrix res(_); return res/=s; }
inline Matrix operator+(Matrix& _, Matrix& m) { Matrix res(_); return res+=m; }
inline Matrix operator-(Matrix& _, Matrix& m) { Matrix res(_); return res-=m; }
inline Matrix operator*(Matrix& _, Matrix& m) { Matrix res(_); return res*=m; }
inline Vector operator*(Matrix& m, Vector& v) {
  Vector res;
  return res.set(m.tdotx(v), m.tdoty(v), m.tdotz(v));
}
} // namespace STAR
#endif // _MASH_Matrix_
