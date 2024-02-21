%{
#include "language/include/ast.h"

extern int yylex();
ast head;

int yyerror(char * s);
char * category_to_string(int category);
%}

%debug

%left PLUS MINUS
%left STAR SLASH

%code requires {
  #include "language/include/ast.h"
}

%union {
  ast the_ast;
}

%token <the_ast> ENDMARKER NEWLINE COMMENT VARIANT INTEGER DOUBLE LPAR RPAR PLUS
%token <the_ast> MINUS STAR SLASH

%type <the_ast> program star_NEWLINE_expr pick_NEWLINE_expr expression

%%

program
  : star_NEWLINE_expr ENDMARKER {
    $$ = init_ast(NULL, IN_PROGRAM);
    $$ = add_child($$, $1);
    $2 = init_ast(NULL, IN_ENDMARKER);
    $$ = add_child($$, $2);
    head = $$;
    return ENDMARKER;
  }
  ;

star_NEWLINE_expr
  : pick_NEWLINE_expr star_NEWLINE_expr {
    $$ = init_ast(NULL, IN_STAR_NEWLINE_EXPR);
    $$ = add_child($$, $1);
    $$ = add_child($$, $2);
  }
  | NEWLINE { $$ = init_ast(NULL, IN_NEWLINE); }
  ;

pick_NEWLINE_expr
  : expression {
    $$ = init_ast(NULL, IN_PICK_NEWLINE_EXPR);
    $$ = add_child($$, $1);
  }
  | NEWLINE { $$ = init_ast(NULL, IN_NEWLINE); }
  ;

expression
  : DOUBLE
  | INTEGER
  | VARIANT
  | expression PLUS expression {
    $$ = init_ast(NULL, IN_EXPRESSION);
    $$ = add_child($$, $1);
    $$ = add_child($$, $2);
    $$ = add_child($$, $3);
  }
  | expression MINUS expression {
    $$ = init_ast(NULL, IN_EXPRESSION);
    $$ = add_child($$, $1);
    $$ = add_child($$, $2);
    $$ = add_child($$, $3);
  }
  | expression STAR expression {
    $$ = init_ast(NULL, IN_EXPRESSION);
    $$ = add_child($$, $1);
    $$ = add_child($$, $2);
    $$ = add_child($$, $3);
  }
  | expression SLASH expression {
    $$ = init_ast(NULL, IN_EXPRESSION);
    $$ = add_child($$, $1);
    $$ = add_child($$, $2);
    $$ = add_child($$, $3);
  }
  | MINUS expression {
    $$ = init_ast(NULL, IN_EXPRESSION);
    $$ = add_child($$, $1);
    $$ = add_child($$, $2);
  }
  | LPAR expression RPAR {
    $$ = init_ast(NULL, IN_EXPRESSION);
    $$ = add_child($$, $2);
  }
  | COMMENT { $$ = init_ast(NULL, -1); }
  ;

%%

int yyerror(char * s) {
  fprintf(stderr, "Error: `%s`\n", s);
  exit(1);
}

char * category_to_string(int category) {
  switch(category) {
    case ENDMARKER:     return "endmarker";
    case NEWLINE:       return "newline";
    case COMMENT:       return "comment";
    case VARIANT:       return "variant";
    case INTEGER:       return "integer";
    case DOUBLE:        return "double";
    case LPAR:          return "lpar";
    case RPAR:          return "rpar";
    case PLUS:          return "plus";
    case MINUS:         return "minus";
    case STAR:          return "star";
    case SLASH:         return "slash";
  }
  return NULL;
}
