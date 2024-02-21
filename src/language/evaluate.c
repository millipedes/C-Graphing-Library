#include "include/evaluate.h"

double evaluate_program(ast head, double variant) {
  if(head.leaf) {
  } else {
    switch(head.category) {
      case IN_STAR_NEWLINE_EXPR:
        break;
      case IN_ENDMARKER:
        break;
      default:
        fprintf(stderr, "[EVALUATE_PROGRAM]: Something went wrong\nExiting\n");
        exit(1);
    }
  }
}
