#include "include/static_feature.h"

/**
 * This function can/should be optimized, only needs to write four rectangles.
 * @param
 * @return
 */
canvas boarder_lines(canvas the_canvas, int width, int offset, pixel color) {
  for(int i = offset; i < the_canvas.height - offset; i++) {
    for(int j = offset; j < the_canvas.width - offset; j++) {
      if(j <= offset + width || i <= offset + width
          || i >= the_canvas.height - width - offset
          || j >= the_canvas.width - width - offset)
        the_canvas.values[i][j] = color;
    }
  }
  return the_canvas;
}

/**
 * Oh how I wish there we functional features in C.
 * N.B. That this is top_left and bottom_right because this will depend on the
 * space which is represented by the graph, not just centered.
 * @param
 * @return
 */
canvas axis_lines(canvas the_canvas, vect2 top_left, vect2 bottom_right,
    pixel color) {
  return draw_rectangle(the_canvas, top_left, bottom_right, color);
}

canvas tic_marks(canvas the_canvas, int qty_tic_marks, int height, int width,
    int offset, pixel color, axis the_axis) {
  int height_incrementor = (the_canvas.height - 2 * offset) / qty_tic_marks;
  int width_incrementor = (the_canvas.width - 2 * offset) / qty_tic_marks;
  for(int i =  (the_axis ? the_canvas.height / 2 : offset);
          i <= (the_axis ? the_canvas.height / 2 : the_canvas.height - offset);
          i += height_incrementor) {
    for(int j =  (the_axis ? offset : the_canvas.width / 2);
            j <= (the_axis ? the_canvas.width - offset : the_canvas.width / 2);
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
    if(i > 0 && i < the_canvas.height) {
      for(int j = top_left.x; j < bottom_right.x; j++) {
        if(j > 0 && j < the_canvas.height) {
          the_canvas.values[i][j] = color;
        }
      }
    }
  }
  return the_canvas;
}
