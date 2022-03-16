// animate1 --- create animation using img lib.
#include "img.h"
#include "star.h"
#include "math/Vector.hpp"
#include "math/Matrix.hpp"

int main(void) {
  star_init();
  for(int i = 0; i < 90; i++) {
    img_clear();
    star_step(1);
    star_write();
    img_write();
  }
  for(int i = 0; i < 90; i++) {
    img_clear();
    star_step(1);
    star_write();
    img_write();
  }
  return 0;
}
