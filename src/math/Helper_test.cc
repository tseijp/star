#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "helper.hpp"

TEST(FindTest, BasicAssertions) {
  int _[] = {1, 2, 3, 4, 5};
  EXPECT_EQ(3, STAR::find(_, 0, 5, [](int v, int i, int s[]){ return v == 3 ;}));
}

TEST(EveryTest, BasicAssertions) {
  int _[] = {1, 2, 3, 4, 5};
  EXPECT_EQ(true, STAR::every(_, 0, 5, [](int v, int i, int s[]){ return v > 0;  }));
  EXPECT_EQ(false, STAR::every(_, 0, 5, [](int v, int i, int s[]){ return v > 3;  }));
}

TEST(SomeTest, BasicAssertions) {
  int _[] = {1, 2, 3, 4, 5};
  EXPECT_EQ(true, STAR::some(_, 0, 5, [](int v, int i, int s[]){ return v > 3;  }));
  EXPECT_EQ(false, STAR::some(_, 0, 5, [](int v, int i, int s[]){ return v > 5;  }));
}
