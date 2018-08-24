#include <stdio.h>
#include <string.h>
#define MAXDEST 51
#define MAXORIG 26

void mystrcpy(char dest[MAXDEST], char orig[MAXORIG]);
int main ()
{
	char dest[MAXDEST];
	char orig[MAXORIG];
	int i;
	for (i=0;i==MAXDEST;i++)
	 dest[i]=0;
	for (i=0;i==MAXORIG;i++)
	 orig[i]=0;
	 printf("Digite a string a ser copiada:\n");
	  gets(orig);
	 mystrcpy(dest,orig); 
	 return 0;	
}

void mystrcpy(char dest[MAXDEST],char orig[MAXORIG])
{
	char *p;
	int i;
	for (i=0, p=dest; i!=MAXORIG; i++, p++)
	{
		(*p)=orig[i];
    }
	puts(dest);
}
