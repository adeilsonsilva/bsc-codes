/* Universidade Federal da Bahia
   Graduação em Ciência da Computação
   MATA40 - Estruturas de Dados e Algoritmos I
   Aluno: Adeilson Silva
*/

#include "funcs_pilha.h"

//Função que avalia precedência
int avalia_prec(char p)
{
  if(p == 'r')
      return 3;
 
  if((p == '*') || (p == '/'))
     return 2;

  if((p == '+') || (p == '-'))
     return 1;

  return 0;
}

//Função de conversão Infixa -> Posfixa
void ConverteInfixaPosfixa(char *expr_infixa, char *expr_pos)
{
  PilhaPT p;
  char *t, t1, s, pos[MAXEXPRPOS]="";
  size_t len;

  inicializa(&p);

  
    for(t=&expr_infixa[0]; *t != '\0' ; t++){
	    s=*t;
            if((s == 'r') || (s == '*') || (s == '/') || (s == '+') || (s == '-')){ //s é um operador
                  while((Topo(&p, &t1)) && (t1 != '(') && ((avalia_prec(s)) <= (avalia_prec(t1))) ){
                       desempilha(&p, &t1);
                       len=strlen(pos);
                       if((len+2) < MAXEXPRPOS){
                           pos[len++]=' ';
                           pos[len++]=t1;
                           pos[len]='\0';
	               }
                  }
                
                  empilha(&p, s);
                  len=strlen(pos);
                  if((len+1) < MAXEXPRPOS){
                        pos[len++]=' ';
                        pos[len]='\0';
		  }
             }
       
            else if((s == '(')){
                empilha(&p, s);
            }

            else if((s == ')')){
                while((desempilha(&p, &t1)) && (t1 != '(')){
                     len=strlen(pos);
                     if((len+2) < MAXEXPRPOS){
                         pos[len++]=' ';
                         pos[len++]=t1;
                         pos[len]='\0';
                     }
                }
            }

            else{		//s é um operando		 
              len=strlen(pos);
              if((len+1) < MAXEXPRPOS){
                  pos[len++]=s;
                  pos[len]='\0';
			 }
            }

         }      

    while((desempilha(&p, &t1))){
       len=strlen(pos);
       if((len+2) < MAXEXPRPOS){
            pos[len++]=' ';
            pos[len++]=t1;
            pos[len]='\0';
	  }
    }
    
    strcpy(expr_pos, pos);

}

//Função de aplicar operador
float aplica_operador(char op, float a1, float a2)
{
    
    if(op == '*')
       return a1*a2;
       
    if(op == '/')
       return a1/a2;
	   
    if(op == '+')
       return a1+a2;
		
     if(op == '-')
       return a1-a2;

     return 0;
}

//Função de avaliar expressão Posfixa
void avalia_expr_pos(char expr_pos[])
{
   int i;
   float k=0, w1=0, w2=0, res=0;
   char num[MAXEXPRINF],*t=NULL, *n=NULL, *l=NULL;
   PilhaNum p;

  p=(PilhaNum) malloc(sizeof(NoPilhaNum));
  strcat(expr_pos, " ");

  if((p)){
	num[0]='\0';
	inicializa_num(p);
	t=expr_pos;
	
	while(*t != '\0'){
		for(i=0, n=t; (*n != ' ') && (*n != '\0'); n++, i++){
		   num[i]=*n; 
		}
		num[i]='\0';
		n++;
		k=strtof(num, &l);

          if(num[0] != '\0'){
	     if(((num[0] == 'r') || (num[0] == '*') || (num[0] == '/') || (num[0] == '+') || (num[0] == '-')) ){
	        if((num[0] == 'r')){
	          desempilha_num(p, &w1); 
                  res=sqrt(w1);
                }

                else{
                  desempilha_num(p, &w2);
                  desempilha_num(p, &w1);
                  res=aplica_operador(num[0], w1, w2);        
                }

             empilha_num(p, res);
            } 

          else{ //termo lido é um operando
            empilha_num(p, k);     
          }
      }
      t=n;
      }  

     desempilha_num(p, &res);
     printf("%.2f\n", res);
     free(p);
   }
}

//Função de avaliar expressão Infixa
void avalia_expr_inf(char *expr)
{
    char s[MAXEXPRPOS]="";
    ConverteInfixaPosfixa(expr, s);
    avalia_expr_pos(s);
}

