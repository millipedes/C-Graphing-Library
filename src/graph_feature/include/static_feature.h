#ifndef STATIC_FEATURE_H
#define STATIC_FEATURE_H

#include "canvas/include/canvas.h"

typedef struct VEC2_T {
  int x;
  int y;
} vect2;

typedef enum {
  X,
  Y,
} axis;

canvas tic_marks(canvas the_canvas, int qty_tic_marks, int height, int width,
    pixel color, axis the_axis);
canvas draw_rectangle(canvas the_canvas, vect2 top_left, vect2 bottom_right,
    pixel color);

#endif
