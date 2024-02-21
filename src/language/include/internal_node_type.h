#ifndef INT_NODE_TYPE_H
#define INT_NODE_TYPE_H

#include <stdlib.h>

typedef enum {
  IN_EXPRESSION,
  IN_STAR_NEWLINE_EXPR,
  IN_PICK_NEWLINE_EXPR,
  IN_NEWLINE,
  IN_ENDMARKER,
  IN_PROGRAM,
} internal_node_type;

const char * internal_node_type_to_string(internal_node_type int_node_type);

#endif
