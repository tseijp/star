#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Vector.hpp"

TEST(VectorTest, GetAndSet) {
  STAR::Vector v0 = {0, 0, 0};
  STAR::Vector v1 { v0 };
  v1.setX(1).setY(1).setZ(1);
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(0, v0[i]);
    EXPECT_EQ(1, v1[i]);
  }
}

TEST(VectorTest, Math) {
  STAR::Vector v0;
  STAR::Vector v1;
  STAR::Vector vx {1, 0, 0};
  STAR::Vector vy {0, 1, 0};
  STAR::Vector vz {0, 0, 1};
  v0 = vx * vy * vz;
  v1 = vx + vy + vz;
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(0, v0[i]);
    EXPECT_EQ(1, v1[i]); 
  }
  EXPECT_EQ(0, v0.dot(vx));
  EXPECT_EQ(1, v1.dot(vx));
  EXPECT_EQ(2, v1.dot(vx + vy));
}
