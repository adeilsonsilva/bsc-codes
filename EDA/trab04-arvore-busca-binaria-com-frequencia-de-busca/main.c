/* Universidade Federal da Bahia
   Graduação em Ciência da Computação
   MATA40 - Estruturas de Dados e Algoritmos I
   Aluno: Adeilson Silva
*/

#include "libs/funcs_arv.h"

int main()
{
   char entrada[MAXVET]="";
   int num;
   char opcao;
   ArvoreBB_PT raiz;

   inicializa_arvore(&raiz);

   while(entrada[0] != 'e'){
      
       scanf(" %[^\n]s", entrada);

       if(entrada[0] == 'p'){
          if(entrada[2] == 'c'){
            ListaOrdemCrescente(raiz);
	      }
		  
	      else if(entrada[2] == 'd'){
	        ListaOrdemDecrescente(raiz);
	      }   
       }

       else if(entrada[0] == 'd'){
            ImprimeArvore(raiz);
       }
       
       else{
	    sscanf(entrada,"%c %d", &opcao, &num);
	    if(opcao == 'i'){
	       InsereNo(&raiz, num);
	    }
		   
	    else if(opcao == 'c'){
	       ConsultaNo(&raiz, num);
	    }
		   
	    else if(opcao == 'n'){
	       ListaPorNivel(raiz, num, 1);
	    }
		   
            else if(opcao == 'f'){
	       ImprimeFreqc(raiz, num);
	    }
	   
            else if(opcao == 'k'){
	       ListaFreqCrescente(raiz, num);  
	    }
       } 
   }

   return 0;
}
