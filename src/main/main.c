#include "graph_feature/include/static_feature.h"

int main(void) {
  canvas the_canvas = init_canvas(1000, 1000, MIN_COL, MIN_COL, MIN_COL);

  // the_canvas  = draw_rectangle(the_canvas, (vect2){250, 250}, (vect2){1100, 1100},
  //     (pixel){255, 255, 255});
  the_canvas = tic_marks(the_canvas, 10, 7, 25, 15, (pixel){255, 255, 255}, X);
  the_canvas = tic_marks(the_canvas, 10, 25, 7, 15, (pixel){255, 255, 255}, Y);

  the_canvas = axis_lines(the_canvas,
      (vect2){15,                    (the_canvas.height / 2) - (7 / 2)},
      (vect2){the_canvas.width - 15, (the_canvas.height / 2) + (7 / 2)},
      (pixel){255, 255, 255});
  the_canvas = axis_lines(the_canvas,
      (vect2){(the_canvas.width / 2) - (7 / 2), 15},
      (vect2){(the_canvas.width / 2) + (7 / 2), the_canvas.height - 15},
      (pixel){255, 255, 255});
  the_canvas = boarder_lines(the_canvas, 5, 10, (pixel){255, 255, 255});

  write_canvas_png(the_canvas, "test_out.png");
  free_canvas(the_canvas);
  return 0;
}
