#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXSTR 1000
#define LPAREN '('
#define RPAREN ')'
#define LBRACKET '['
#define RBRACKET ']'
#define COMMA ','
#define DOT '.'
#define PLUS_OP '+'
#define LESS_OP '-'
#define TIMES_OP '*'
#define DIVISION_OP '/'
#define MOD_OP '%'
#define LESST '<'
#define GREATERT '>'
#define EQLESST "<="
#define EQGREATERT ">="
#define EQUAL '='
#define DIFF "<>"

const char *keywords[] = {"DECLARE", "AS", "NUMBER", "LETTER", "PUT", "IN", "IF", "THEN", "ELSE", "FOREACH", "DO", "FOR", "FROM", "TO", "RESIZE", "READ", "PRINT"};
const char *aritOperators[] = {"+", "-", "*", "/", "%", "(", ")"};
const char *relatOperators[] = {"<", ">", "<=", ">=", "=", "<>"};
const char *terminals[] = {",",  ".", "[", "]"};
