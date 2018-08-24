#include <stdio.h>
#include <string.h>
#define MAX 16

int main ()
{
	char TELEFONE[MAX];
	int i=0;

	for (i=0;i<MAX;i++)
	 {
	 TELEFONE[i]=0;
     }
	gets(TELEFONE);
	  for (i=0;i<MAX;i++)
	   {
		  if(TELEFONE[i]>='A' && TELEFONE[i]<='Z') 
		   {
		     if(TELEFONE[i]>='A' && TELEFONE[i]<='C')
		      TELEFONE[i]='2';           
             else if(TELEFONE[i]>='D'&& TELEFONE[i]<='F')
		      TELEFONE[i]='3';
		     else if(TELEFONE[i]>='G' && TELEFONE[i]<='I')
		      TELEFONE[i]='4';
		     else if(TELEFONE[i]>='J' && TELEFONE[i]<='L')
		      TELEFONE[i]='5';
	  	     else if(TELEFONE[i]>='M' && TELEFONE[i]<='O')
		      TELEFONE[i]='6';
		     else if(TELEFONE[i]>='P' && TELEFONE[i]<='S')
		      TELEFONE[i]='7';
		     else if(TELEFONE[i]>='T' && TELEFONE[i]<='V')
		      TELEFONE[i]='8';
		     else if(TELEFONE[i]>='W' && TELEFONE[i]<='Z')
		      TELEFONE[i]='9';
		   } 		    	    		    		    		    		    		    
	   }
	   
       puts(TELEFONE);
       return 0;	    
}
