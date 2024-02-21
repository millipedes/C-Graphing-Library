#include "include/ast.h"

ast init_ast(token the_token, int category) {
  ast the_ast = {0};
  the_ast.children = NULL;
  the_ast.leaf = the_token;
  the_ast.category = category;
  the_ast.qty_children = 0;
  return the_ast;
}

void debug_ast(ast head, int level) {
  PRINT_C_N(' ', level)
  if(head.leaf) {
    printf("[AST] %s ", category_to_string(head.category));
    if(head.leaf->category == 6)
      printf("%f\n", *((double *)head.leaf->literal));
    else if(head.leaf->category == 5)
      printf("%d\n", *((int *)head.leaf->literal));
    else
      printf("%s\n", (char *)head.leaf->literal);
  } else {
    printf("[AST] %s\n", internal_node_type_to_string(head.category));
  }
  if(head.children) {
    for(int i = 0; i < head.qty_children; i++) {
      debug_ast(head.children[i], level + 1);
    }
  }
}

ast add_child(ast parent, ast child) {
  parent.qty_children++;
  if(parent.children) {
    parent.children = realloc(parent.children, parent.qty_children
        * sizeof(struct AST_T));
  } else {
    parent.children = calloc(1, sizeof(struct AST_T));
  }
  parent.children[parent.qty_children - 1] = child;
  return parent;
}

void free_ast(ast head) {
  if(head.children) {
    for(int i = 0; i < head.qty_children; i++)
      free_ast(head.children[i]);
    free(head.children);
  }
  if(head.leaf)
    free_token(head.leaf);
}
