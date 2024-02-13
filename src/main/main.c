#include "graph_feature/include/static_feature.h"
#include "language/include/ast.h"
#include "parser.tab.h"

extern ast head;

extern FILE * yyin;
extern int yylex_destroy();

int main(void) {
  canvas the_canvas = init_canvas(1000, 1000, MIN_COL, MIN_COL, MIN_COL);
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
  yyin = fopen("test.p", "r");
  yyparse();
  debug_ast(head, 0);
  free_ast(head);
  fclose(yyin);
  yylex_destroy();
  return 0;
}
