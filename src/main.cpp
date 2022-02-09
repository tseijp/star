// animate1 --- create animation using img lib.
#include "img.h"
#include "star.h"

int main(void) {
  struct color c1 = { 30, 255, 0 };
  struct color c2 = { 255, 0, 0 };
  for(int i = 0; i < 50; ++i) {
    img_clear();
    star_step(1);
    star_write(c1);
    img_write();
  }
  for(int i = 0; i < 50; ++i) {
    img_clear();
    star_step(-1);
    star_write(c2);
    img_write();
  }
  return 0;
}
