#include <stdio.h>

int main()
{
  int soma=0,qtd_pares=0, qtd=0, num=1, maior=0, menor=0, soma_pares=0;

     scanf("%d", &num);
     soma=soma+num;
     qtd++;
     maior=menor=num;
     if(num%2 == 0){
       soma_pares=soma_pares+num;
       qtd_pares++;
     }

     while (num !=0){  
       scanf("%d", &num);
      if(num != 0){   
        soma=soma + num;
        qtd++;
       
        if(num > maior)
          maior=num;
        else if(num < menor)
 	  menor=num;

        if(num%2 == 0){
          soma_pares=soma_pares+num; 
	  qtd_pares++;
        }
      }
    }

     printf(" Soma: %d \n Quantidade: %d \n Media: %d \n Maior: %d \n Menor: %d \n Media dos Pares: %d", soma, qtd, soma/qtd, maior, menor, soma_pares/qtd_pares);

    return 0;
}
