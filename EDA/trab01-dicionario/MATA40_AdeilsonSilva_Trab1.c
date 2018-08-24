/* Universidade Federal da Bahia
   Graduação em Ciência da Computação
   MATA40 - Estruturas de Dados e Algoritmos I
   Aluno: Adeilson Silva
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NTABHASH 11

typedef struct NoLista
{
	char palavra[30];
	struct NoListaTrad *Ltrad;
	struct NoLista *proxorig;
	char classe;
	int nacessos;
} NoLista;

typedef struct NoListaTrad
{
	struct NoListaTrad *proxtrad;
	char traducao[50];
}NoListaTrad;
	
NoLista *Lorig[NTABHASH];

int hash(int nltrs, char palavra[30]);
void inicializar(NoLista *Lorig[NTABHASH]);
NoLista *Ordena(NoLista *p);
NoListaTrad *InserePalavra(char palavra [30], char classe);
void InsereTraducao(NoListaTrad *trad, char traducao[50]);
void ConsultaDados(char palavra[30]);
void ListaPorClasse(char tipo);
void ListaPorIndice(int i);
void RemovePalavra(char palavra[30]);
void ListaTraducoes(char palavra[30]);
void ListaIdiOrig(char modo);


int main (int argc, char *argv[])
{
	int npalavras, ntrads, n, m;
	char tclasse,sair, tplvr[30], ttrad[50], opr[35], tp[30];
	char *str;
	NoListaTrad *P_Trad;
	
	inicializar(&Lorig[NTABHASH]);
	
	scanf("%d", &npalavras);
	for(n=0; n<npalavras; n++)
	 {
		scanf(" %s %c %d", tplvr, &tclasse, &ntrads);
		P_Trad=InserePalavra(tplvr, tclasse);
		 for(m=0; m<ntrads; m++)
		  {
			 scanf(" %[^\n]s", ttrad);
			 InsereTraducao(P_Trad,ttrad);  
		  }
	 }
	 
	do
	 {
	   scanf(" %[^\n]s", opr);
	   if((strlen(opr)) > 3)
	    {
			
			strtok(opr, " ");
			str=strtok(NULL, " ");
			strcpy(tp, str);
			
			if(opr[0]=='t')
			  ListaTraducoes(tp);
			  
			else if(opr[0]=='c')
			  ConsultaDados(tp);
			  
			else if(opr[0]=='r')
			  RemovePalavra(tp);    
		}
		
	   if((strlen(opr)) == 3)
	    {
			if(opr[0]=='l')
	          ListaIdiOrig(opr[2]);
	          
	        else if(opr[0]=='a')
	          ListaPorClasse(opr[2]); 
	          
	        else if(opr[0]=='i')
	          ListaPorIndice(opr[2]-'0');  
		}
		
	   if((strlen(opr)) < 3)
	    {
		  sair=opr[0];
		}
		
				
	 }while(sair != 'e'); 
	 
    return 0;
	 
}


void inicializar(NoLista *Lorig[NTABHASH])
{
	int i;
	for(i=0; i<NTABHASH; i++)
	 {
		Lorig[i]=NULL; 
	 }
}

int hash(int nltrs, char palavra[30])
{
	int tam=0, soma=0,i;
	int valor_letra;
	for(i=0; i<nltrs; i++)
	 {
	  valor_letra=palavra[i]-96;
	  tam=valor_letra%NTABHASH;
	  soma=soma+tam; 
	 }
	return soma; 
}

NoListaTrad *InserePalavra(char palavra[30], char classe)
{
	NoLista *p, *t;
	NoListaTrad *q;
	int n=0;
	
	n=hash(strlen(palavra), palavra);
	p=(NoLista *) malloc(sizeof(NoLista));
	q=(NoListaTrad *) malloc(sizeof(NoListaTrad));
	
	if((p) && (q))
	 {
		if((Lorig[n]))
		 {
		   for(t=Lorig[n]; (t->proxorig); t=t->proxorig);
		   t->proxorig=p;
		   strcpy(p->palavra, palavra);
		   p->classe=classe;
		   p->nacessos=0;
		   p->proxorig=NULL;
		   p->Ltrad=q;
		   return p->Ltrad; 
		 }
		
		else
		 {
		   Lorig[n]=p;
		   strcpy(Lorig[n]->palavra, palavra);
		   Lorig[n]->classe=classe;
		   Lorig[n]->nacessos=0;
		   Lorig[n]->proxorig=NULL;
		   Lorig[n]->Ltrad=q;
		   return Lorig[n]->Ltrad;
		 } 
		 
	 }
	return NULL;
}

void InsereTraducao(NoListaTrad *trad, char traducao[50])
{
	NoListaTrad *p,*q;
	
	if(!(trad))
	 {
	   strcpy(trad->traducao, traducao);
	   trad->proxtrad=NULL;		
	 }
	
	else
	 {
	   for(q=trad;(q->proxtrad);q=q->proxtrad);
	   p=(NoListaTrad *) malloc(sizeof(NoListaTrad));
	     if((p))
	      {
	        q->proxtrad=p;
	        strcpy(p->traducao, traducao);
            p->proxtrad=NULL;
          }
	 }
	
}

void ConsultaDados(char palavra[30])
{
	int i;
	NoLista *p;
	i=hash(strlen(palavra), palavra);
	for(p=Lorig[i];(p) && (strcmp(p->palavra, palavra));p=p->proxorig);
    if((p))
     {
	   if(p->classe=='s')
	    {
		  printf("substantivo %d\n", p->nacessos);
	    }
	   if(p->classe=='a')
	    {
		  printf("adjetivo %d\n", p->nacessos);
	    }
	   if(p->classe=='v')
	    {
		  printf("verbo %d\n", p->nacessos);
	    } 
	 }
}

void ListaPorClasse(char tipo)
{
	NoLista *p;
	int i;
    for(i=0;i<NTABHASH;i++)
     {
	   if((Lorig[i]))
	    {
	      for(p=Lorig[i];(p);p=p->proxorig)
	       {
		     if(p->classe==tipo)
		      {
		 	    printf("%s\n", p->palavra);  
		      }
	       } 
	    }
	 }
}

void ListaPorIndice(int i)
{
	NoLista *p;
    if((Lorig[i]))
     {
       for(p=Lorig[i];(p);p=p->proxorig)
        {
		  printf("%s\n", p->palavra); 
	    }
	 }
}

void RemovePalavra(char *palavra)
{
	NoLista *p, *q;
	int i;
	i=hash(strlen(palavra), palavra);
	for(q=NULL,p=Lorig[i];(strcmp(p->palavra, palavra));q=p,p=p->proxorig);
	if((p))
	 {
		 if((q))
		  {
			  q->proxorig=p->proxorig;
			  free(p);
		  }
		  
		 else
		  {
			  q=Lorig[i];
			  q->proxorig=p->proxorig;
			  free(p);
		  } 
	 }
	 
}

void ListaTraducoes(char *palavra)
{
	NoLista *p;
	NoListaTrad *q;
	int i;
	i=hash(strlen(palavra), palavra);
	for(p=Lorig[i];(strcmp(p->palavra, palavra));p=p->proxorig);
	p->nacessos=p->nacessos+1;
	q=p->Ltrad->proxtrad;
    if((q))
     {
		 do
		  {
			 printf("%s\n", q->traducao);
			 q=q->proxtrad; 
		  }while((q));
	 }
	Ordena(Lorig[i]); 
}

NoLista *Ordena(NoLista *p) 
{

if((p) == NULL || (p)->proxorig == NULL)
    return p;
 
NoLista *atual, *ant, *maior, *antmaior;
atual = p;
maior = p;
ant = p;
antmaior = p;
while(atual != NULL) 
{
  if(atual->nacessos > maior->nacessos) 
   {
     antmaior = ant;
     maior = atual;
   }
  ant = atual;
  atual = atual->proxorig;

}

NoLista *aux;

if(maior != p)
{
    if((maior->proxorig))
     {
	   aux=antmaior;
	   p=maior;
	   aux->proxorig=maior->proxorig;
	   maior->proxorig=aux; 
	 }
	 
	if((maior->proxorig) == NULL)
	 {
		aux=maior;
		antmaior->proxorig=maior->proxorig;
		maior->proxorig=p;
		p=maior; 
	 } 
    
}

maior->proxorig = Ordena(maior->proxorig);

return maior;

}

void ListaIdiOrig(char modo)
{
	NoLista *p;
	int i;

	if(modo=='c')
	 {
		for(i=0; i<NTABHASH; i++)
		 {
			if((Lorig[i]))
			 {
			   for(p=Lorig[i]; (p) ; p=p->proxorig)
			    {
				 printf("%s\n", p->palavra);
			    } 
			 }
		 } 
	 }
	 
	if(modo=='d')
	 {
		for(i=NTABHASH-1; i!=0; i--)
		 {
			if((Lorig[i]))
			 {
			  for(p=Lorig[i]; (p) ; p=p->proxorig)
			   {
				  printf("%s\n", p->palavra);
			   }
		     }
		 } 
	 } 
}
