#include <stdio.h>
#include <math.h>


int main ()
{
	int L=0,A=0,P=0,R=0,dq=0,dc=0,h2=0;
	float pi=0;
	
	 scanf("%d %d %d %d", &L,&A,&P,&R);
	  pi=3,14;
	  h2=(L*L)+(A*A);
	  dq=sqrt(h2);
	  dc=2*R;
	   if(dq<dc && L<dc && A<dc)
	    printf("S");
	   else if(dq>=dc || L>=dc || A>=dc)
	    printf("N"); 
	  return 0;  
}
