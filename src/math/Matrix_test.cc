#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Matrix.hpp"
#include "Vector.hpp"

TEST(MatrixTest, GetAndSet) {
  STAR::Matrix m0 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  STAR::Matrix m1 { m0 };
  m1.set(0, 0, 1).set(1, 1, 1).set(2, 2, 1);
  EXPECT_EQ(0, m0[0][0]);
  EXPECT_EQ(1, m1[1][1]);
}

TEST(MatrixTest, Math) {
  STAR::Matrix mx = {1, 1, 1, 0, 1, 1, 0, 0, 1};
  STAR::Matrix my = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  STAR::Matrix mz = {1, 0, 0, 1, 1, 0, 1, 1, 1};
  STAR::Matrix m0;
  STAR::Matrix m1;
  m1 = mx - my + mz;
  m0 = mx * my + mz * my - mx - mz;
  int i, j;
  for (j = 0; j < 3; j++) {
    for (i = 0; i < 3; i++) {
      EXPECT_EQ(0, m0[i][j]);
      EXPECT_EQ(1, m1[i][j]);
    }
  }
  STAR::Vector vx = {1, 0, 0};
  STAR::Vector vz = {0, 0, 1};
  STAR::Vector v0 = mx * vx - vx;
  STAR::Vector v1 = mz * vx;
  for (i = 0; i < 3; i++) {
    EXPECT_EQ(0, v0[i]);
    EXPECT_EQ(1, v1[i]);
  }
}
