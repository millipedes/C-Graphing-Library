#include "include/evaluate.h"

double evaluate_program(ast head, double variant) {
  if(head.leaf) {
    if(head.leaf->category == VARIANT) {
      return variant;
    } else if(head.leaf->category == DOUBLE) {
      return *((double *)(head.leaf->literal));
    } else if(head.leaf->category == INTEGER) {
      return (double)(*((int *)(head.leaf->literal)));
    }
  } else {
    switch(head.category) {
      case IN_STAR_NEWLINE_EXPR:
        return evaluate_star_newline_expr(head, variant);
      case IN_ENDMARKER:
        return 0.0;
      default:
        fprintf(stderr, "[EVALUATE_PROGRAM]: Something went wrong\nExiting\n");
        exit(1);
    }
  }
  fprintf(stderr, "[EVALUATE_PROGRAM]: Something went wrong\nExiting\n");
  exit(1);
}

// double evaluate_star_newline_expr(ast head, double variant) {
// }
