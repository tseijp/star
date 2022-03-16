#ifndef _MATH_SCALAR_
#define _MATH_SCALAR_

#include <assert.h>
#include <stdio.h>
#include <string>
#include <math.h>

namespace STAR {
typedef double Scalar;
struct Scalar {
  typedef double T;
  typedef ::STAR::Scalar S;
  T _;

  inline T operator() () { return _ }
  inline void print() { printf("%f, \n", _); }

  explicit Scalar(int unused = 0) {}
  Scalar (S s) { set(s); }

  inline S& set(S& s) { _ = s(); return *this; }

  /**
   * Math
   */
  inline S one() { S res(1.0); return res; }
  inline S zero() { S res(0.0); return res; }
  inline S cos(S s) { S res(cos(s())); return res; }
  inline S sin(S s) { S res(sin(s())); return res; }
  inline V  operator+() { S res(+_); return res; }
  inline V  operator-() { S res(-_); return res; }
  inline V& operator+=(S& s) { _+=s(); return *this; }
  inline V& operator-=(S& s) { _-=s(); return *this; }
  inline V& operator*=(S& s) { _*=s(); return *this; }
  inline V& operator/=(S& s) { _/=s(); return *this; }
};  // struct Scalar

inline Scalar operator+(Scalar& _, Scalar& s) { Scalar res(_); return res+=s; }
inline Scalar operator-(Scalar& _, Scalar& s) { Scalar res(_); return res-=s; }
inline Scalar operator/(Scalar& _, Scalar& s) { Scalar res(_); return res/=s; }
inline Scalar operator*(Scalar& _, Scalar& s) { Scalar res(_); return res*=s; }
} // namespace STAR
#endif // _MATH_SCALAR_
