#ifndef _STAR_
#define _STAR_
#define LATITUDE 100
#define LONGITUDE 100
#include <math.h>
#include "math/Vector.hpp"
// #include "math/Quater.hpp"
// #include "math/Matrix.hpp"
#include "img.h"

static Vector tensor[LATITUDE][LONGITUDE];
static int timeStamp = 0;
static double radius = 100.0;

void star_step(int dt = 0.0) {
  timeStamp += dt;
  int i, j;
  for (j = 0; j < LONGITUDE; ++j) {
    for (i = 0; i < LATITUDE; ++i) {
      double tht = 2 * M_PI * i / LATITUDE * timeStamp / FRAME;
      double phi = 2 * M_PI * j / LONGITUDE * timeStamp / FRAME;
      Vector vector;
      tensor[j][i] = vector.set(
        radius * sin(tht) * cos(phi) + WIDTH / 2,
        radius * cos(tht) + HEIGHT / 2,
        radius * sin(tht) * sin(phi)
      );
    }
  }
}

void star_write(color c) {
  int i, j;
  for (j = 0; j < LONGITUDE; ++j) {
    for (i = 0; i < LATITUDE; ++i) {
      Vector v = tensor[j][i];
      // printf("x: %i\ty: %i\tz: %i\n", (int)v.x(), (int)v.y(), (int)v.z());
      if (v.z() > 0) {
        img_putpixel(c, (int)v.x(), (int)v.y());
      }
    }
  }
} 

#endif // _STAR_
