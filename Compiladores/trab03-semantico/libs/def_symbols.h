#ifndef DEF_SYMBOLS_H_
#define DEF_SYMBOLS_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <strings.h>
#include "types.h"

/* Macros de tamanho de vetores */
#define MAXSTR 4098
#define MAXKW 18
#define MAXAROP 8
#define MAXRELOP 7
#define MAXTERM 5
#define MAXSEP 35
#define MAXKWSTR 25
#define MAXOP 15
#define MAXSCOPE 1000

/* Macros para nomes de tokens específicos */
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
#define DIFF '<>'

/* Algumas flags de erro */
int LEXAN_ERRORS = 0;

/* Vetores com strings constantes para avaliação */
const char keywords[MAXKW][MAXKWSTR] = {"DECLARE", "AS", "NUMBER", "LETTER", "PUT", "IN", "IF", "THEN", "ELSE", "FOREACH", "DO", "FOR", "FROM", "TO", "RESIZE", "READ", "PRINT"};
//const char *aritOperators[MAXAROP] = {"+", "-", "*", "/", "%", "(", ")"};
const char aritOperators[MAXAROP] = {"+-*/%()"};
const char *relatOperators[MAXRELOP] = {"<", ">", "<=", ">=", "=", "<>"};
const char operators[MAXOP] = {"+-*/%()><="};
//const char *terminals[MAXTERM] = {",",  ".", "[", "]"};
const char terminals[MAXTERM] = {",.=[]"};
/* {" ", "!", "#", "$", "&", "-", "/", ":", ";", "?", "@", "^", "_", "`", "{", "}", "|", "~"} - Também são separadores por não fazer parte de nenhum símbolo ou palavra reservada */
//const char *separators[MAXSEP] = {",", ".", "[", "]", "+", "-", "*", "/", "%", "(", ")", "=", "<", ">", "'", "\"", " ", "!", "#", "$", "&", "-", "/", ":", ";", "?", "@", "^", "_", "`", "{", "}", "|", "~"};
const char separators[MAXSEP] = {",.[]+-*/%()=<>'\" !#$&-\\:;?@^_`{}|~	"};

/* Nó onde serão inseridos os tokens para Analise Sintática */
NodePT nodeList = NULL;

/* Raíz da árvore */
TreeNodePT parseTree = NULL, currNode = NULL;

/* Pilha de nós da árvore */
TreeStackPT parseTreeStack = NULL;

/* Vetor de apontadores da Tabela de Símbolos; Cada posição do vetor representa um escopo diferente */
SymbolTablePT symbolTable[MAXSCOPE];

/* Inteiro que guardará o escopo atual */
unsigned int Scope = 0;

/* Pilha temporária pra salvar os Lexemas enquanto passeia pela árvore */
LexStackPT Lex = NULL;

#endif /* DEF_SYMBOLS_H_ */
