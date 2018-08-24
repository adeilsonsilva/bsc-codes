#include <stdio.h>

int main()
{
   int prim, seg, a;
   float ter, b, c;

   printf("Digite dois numeros inteiros e um real:\n");
   scanf("%d %d %f", &prim, &seg, &ter);
   a=(2*prim)*(seg/2);
   b=(3*prim)+ter;
   c=(ter*ter*ter);
   printf("\nResultados:\n a)%d\t b)%.2f\t c)%.2f", a, b, c);
   return 0;

}
