#include "include/evaluate.h"

// double evaluate_program(ast head, double variant) {
//   if(head.leaf) {
//     if(head.leaf->category == VARIANT) {
//       return variant;
//     } else if(head.leaf->category == DOUBLE) {
//       return *((double *)(head.leaf->category));
//     }
//   } else {
//     switch(head.category) {
//       case IN_STAR_NEWLINE_EXPR:
//         break;
//       case IN_ENDMARKER:
//         break;
//       default:
//         fprintf(stderr, "[EVALUATE_PROGRAM]: Something went wrong\nExiting\n");
//         exit(1);
//     }
//   }
// }
