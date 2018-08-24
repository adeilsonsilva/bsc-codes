/* Universidade Federal da Bahia
   Graduação em Ciência da Computação
   MATA40 - Estruturas de Dados e Algoritmos I
   Aluno: Adeilson Silva
*/

#include "libs/funcs_expr.h"

int main()
{
  char cmd, tipo_expr;
  char expr[MAXEXPRINF]="";
  char expr_pos[MAXEXPRPOS]="";

  scanf(" %c", &tipo_expr);
  scanf(" %[^\n]s", expr);

  while(cmd != 'e'){
      
      scanf(" %c", &cmd);

      if(cmd == 'a'){
         if(tipo_expr == 'p')
            avalia_expr_pos(expr);
         
         if(tipo_expr == 'i')
            avalia_expr_inf(expr);
      }
      else if((cmd == 'c') && (tipo_expr == 'i')){ 
        ConverteInfixaPosfixa(expr, expr_pos);
        printf("%s\n", expr_pos);
      }
  }

  return 0;

}
