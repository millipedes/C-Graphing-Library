#include "include/token.h"

token init_token(int category, void * literal, int line_no) {
  token the_token = calloc(1, sizeof(struct TOKEN_T));
  if(category == 6) { // DOUBLE bad solution need to figure out extern
    the_token->literal = calloc(1, sizeof(double));
    *((double *)(the_token->literal)) = atof(literal);
  } else if(category == 5) { // INTEGER bad solution need to figure out extern
    the_token->literal = calloc(1, sizeof(int));
    *((double *)(the_token->literal)) = atoi(literal);
  } else {
    size_t literal_len = strnlen(literal, LITERAL_LEN);
    the_token->literal = calloc(literal_len + 1, sizeof(char));
    strncpy(the_token->literal, literal, literal_len);
  }
  the_token->category = category;
  the_token->line_no = line_no;
  return the_token;
}

void free_token(token the_token) {
  if(the_token) {
    if(the_token->literal)
      free(the_token->literal);
    free(the_token);
  }
}
