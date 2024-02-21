#ifndef EVALUATE_H
#define EVALUATE_H

#include "ast.h"
#include "parser.tab.h"

double evaluate_program(ast head, double variant);
double evaluate_star_newline_expr(ast head, double variant);

#endif
