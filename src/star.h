#ifndef _STAR_
#define _STAR_
#include <math.h>
#include "math/Vector.hpp"
#include "math/Matrix.hpp"
#include "math/Quater.hpp"
#include "img.h"

static ::STAR::Vector normal[HEIGHT][WIDTH];
static ::STAR::Vector acceler[HEIGHT][WIDTH];
static ::STAR::Vector position = {WIDTH / 2, HEIGHT / 2, 0};
static ::STAR::Vector rotation = {0, 0, 0};
static int isInitialized = 0;
static int timeStamp = 0;
static double radius = 50.0;

void star_init(void) {
  int i, j;
  img_read("world.ppm");
  for (j = 0; j < HEIGHT; ++j) {
    for (i = 0; i < WIDTH; ++i) {
      double phi = 2 * M_PI * j / HEIGHT;
      double tht = 2 * M_PI * i / WIDTH;
      double rgb = buf[j][i][0] + buf[j][i][1] + buf[j][i][2];
      normal[j][i].set_sphere(1, tht, phi);
      acceler[j][i].set(rgb, tht, phi);
    }
  }
}

void star_step(int dt = 0) {
  timeStamp += dt;
}

void star_write(color c1 = {135, 206, 250}, color c2 = {255, 255, 255}) {
  ::STAR::Matrix mat;
  ::STAR::Matrix mry;
  ::STAR::Matrix mrz;
  ::STAR::Vector vec;
  ::STAR::Vector acc;
  mry.set_rotation_y(10 * M_PI * timeStamp / FRAME);
  mrz.set_rotation_z(2 * M_PI * 23.4 / 360);
  mat = mrz * mry;
  int i, j;
  for (j = 0; j < HEIGHT; ++j) {
    for (i = 0; i < WIDTH; ++i) {
      acc = acceler[j][i];
      vec = normal[j][i] * radius;
      vec = mat * vec;
      vec += position;
      if (vec.z() < 0) { break; }
      if (acc.length() > 100)
        img_putpixel(c1, (int)vec.x(), (int)vec.y());
      else
        img_putpixel(c2, (int)vec.x(), (int)vec.y());
    }
  }
} 
// if (++isInitialized == 0)
//   star_init()
#endif // _STAR_
