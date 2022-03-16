#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Quater.hpp"

TEST(QuaterTest, GetAndSet) {
  STAR::Quater q0 = {0, 0, 0, 0};
  STAR::Quater q1 { q0 };
  q1.setX(1).setY(1).setZ(1).setW(1);
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(0, q0[i]);
    EXPECT_EQ(1, q1[i]);
  }
}

TEST(QuaterTest, Math) {
  STAR::Quater q0;
  STAR::Quater q1;
  STAR::Quater qx = {1, 0, 0, 0};
  STAR::Quater qy = {0, 1, 0, 0};
  STAR::Quater qz = {0, 0, 1, 0};
  STAR::Quater qw = {0, 0, 0, 1};
  q0 = qx * qy * qz * qw;
  q1 = qx + qy + qz + qw;
  for (int i = 0; i < 3; i++) {
    // EXPECT_GE(0, q0[i]); TODO
    EXPECT_EQ(1, q1[i]);
  }
}
