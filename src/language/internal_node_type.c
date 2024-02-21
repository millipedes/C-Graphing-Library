#include "include/internal_node_type.h"

const char * internal_node_type_to_string(internal_node_type int_node_type) {
  switch(int_node_type) {
    case IN_EXPRESSION:        return "in_expression";
    case IN_STAR_NEWLINE_EXPR: return "in_star_newline_expr";
    case IN_PICK_NEWLINE_EXPR: return "in_pick_newline_expr";
    case IN_NEWLINE:           return "in_newline";
    case IN_ENDMARKER:         return "in_endmarker";
    case IN_PROGRAM:           return "in_program";
  }
  return NULL;
}
