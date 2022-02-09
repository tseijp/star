#ifndef _MATH_MATH_
#define _MATH_MATH_
#include <vector>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "Quat.hpp"
// #undef min
// #undef max

struct Math {
  using Index = int;
  using Scalar = Scalar;
  using Vector = Vector3<Scalar>;
  using Matrix = Matrix<Scalar>;
  using Quat = Quat<Scalar>;
}  // struct Math
#endif  //_MATH_MATH_
