#include <stdio.h>

int main()
{
   int a=0, maior=0, menor=0;

   scanf("%d", &a);
   menor=maior=a;

   while(a>=0){

    scanf("%d", &a);

    if (a>maior)
      maior=a;
    if((a>=0) && (a<menor))
      menor=a;
      
  }
  
   printf("Maior: %d \nMenor: %d", maior,menor);
   return 0;   
}
