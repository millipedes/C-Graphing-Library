%option nounput noinput noyywrap yylineno

%{
#include "parser.tab.h"
#include "language/include/ast.h"

#define IS_UNNECESSARY_TOK(t) ((t == LPAR)         \
                               || (t == RPAR)      \
                               || (t == COMMENT)   \
                               || (t == NEWLINE)   \
                               || (t == ENDMARKER))

int allocate_ast(int category);
%}
%%

<<EOF>>                         { return allocate_ast(ENDMARKER); }
\\[\n][ \t]*

[\n\v\f\r]+                     { return allocate_ast(NEWLINE); }

[ \t]

#.*                             { return allocate_ast(COMMENT); }

[A-Za-z_][A-Za-z0-9_]*          { return allocate_ast(VARIANT); }

[0-9_]+                         |
[0-9_]+(e|E)[-+]?[0-9]*         { return allocate_ast(INTEGER); }

"."[0-9]+                       |
"."[0-9]+(e|E)[-+]?[0-9]*       |
[0-9]+"."[0-9]+                 |
[0-9]+"."[0-9]+(e|E)[-+]?[0-9]* { return allocate_ast(DOUBLE); }

"("                             { return allocate_ast(LPAR); }
")"                             { return allocate_ast(RPAR); }
"+"                             { return allocate_ast(PLUS); }
"-"                             { return allocate_ast(MINUS); }
"*"                             { return allocate_ast(STAR); }
"/"                             { return allocate_ast(SLASH); }
%%

int allocate_ast(int category) {
  if(!IS_UNNECESSARY_TOK(category))
    yylval.the_ast = init_ast(init_token(category, yytext, yylineno), category);
  else
    yylval.the_ast = init_ast(NULL, -1);
  return category;
}
