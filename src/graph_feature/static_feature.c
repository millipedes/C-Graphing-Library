#include "include/static_feature.h"

canvas tic_marks(canvas the_canvas, int qty_tic_marks, int height, int width,
    pixel color, axis the_axis) {
  int height_incrementor = the_canvas.height / qty_tic_marks;
  int width_incrementor = the_canvas.width / qty_tic_marks;
  for(int i =  (the_axis ? the_canvas.height / 2 : 0);
          i <= (the_axis ? the_canvas.height / 2 : the_canvas.height);
          i += height_incrementor) {
    for(int j =  (the_axis ? 0 : the_canvas.width / 2);
            j <= (the_axis ? the_canvas.width : the_canvas.width / 2);
            j += width_incrementor) {
      the_canvas = draw_rectangle(the_canvas,
          (vect2){i - (height / 2), j - (width / 2)},
          (vect2){i + (height / 2), j + (width / 2)}, color);
    }
  }
  return the_canvas;
}

canvas draw_rectangle(canvas the_canvas, vect2 top_left, vect2 bottom_right,
    pixel color) {
  for(int i = top_left.y; i < bottom_right.y; i++) {
    if(i < 0 || i >= the_canvas.height) {
      fprintf(stderr, "[DRAW_RECTANGLE]: Warning rectangle out of bounds (y)."
          "Ignoring\n");
    } else {
      for(int j = top_left.x; j < bottom_right.x; j++) {
        if(j < 0 || j >= the_canvas.height) {
          fprintf(stderr, "[DRAW_RECTANGLE]: Warning rectangle out of bounds "
              "(x). Ignoring\n");
        } else {
          the_canvas.values[i][j] = color;
        }
      }
    }
  }
  return the_canvas;
}
