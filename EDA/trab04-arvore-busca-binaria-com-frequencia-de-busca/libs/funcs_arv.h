/* Universidade Federal da Bahia
   Graduação em Ciência da Computação
   MATA40 - Estruturas de Dados e Algoritmos I
   Aluno: Adeilson Silva
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXVET 10 

typedef struct ArvoreBB{
      int chave;
      int freqc;
      struct ArvoreBB *esq;
      struct ArvoreBB *dir;
}ArvoreBB, *ArvoreBB_PT;

//Função de Rotação à direita
ArvoreBB_PT RotacaoDireita(ArvoreBB_PT *y, ArvoreBB_PT *x){
	 (*y)->esq=(*x)->dir;
	 (*x)->dir=(*y);
	 return (*x);
}

//Função de rotação à esquerda
ArvoreBB_PT RotacaoEsquerda(ArvoreBB_PT *x, ArvoreBB_PT *y){     
      (*y)->esq=(*x);
      (*x)->dir=(*y)->esq;
      return (*y);
}

//Função de inicialização da Árvore
void inicializa_arvore(ArvoreBB_PT *raiz){
     (*raiz)=NULL;
}

//Função de inserção na Árvore
void InsereNo(ArvoreBB_PT *raiz, int i){
    ArvoreBB_PT no;
    
    if(!(*raiz)){
      no=(ArvoreBB_PT) malloc(sizeof(ArvoreBB));
      if(no){
        no->chave=i;
        no->freqc=0;
        no->dir=no->esq=NULL;
        (*raiz)=no;
      }
    }

    else{
      if(i >  (*raiz)->chave){
        InsereNo(&((*raiz)->dir), i);
      }

      if(i < (*raiz)->chave){
        InsereNo(&((*raiz)->esq), i);
      }
    }
}

//Função de consulta na árvore
void ConsultaNo(ArvoreBB_PT *raiz, int i){
    
    if(!(*raiz)){
      printf("nao existe no com chave: %d\n", i);
    }
    
    else{
      if((*raiz)->chave == i){
        printf("existe no com chave: %d\n", (*raiz)->chave);
        (*raiz)->freqc++;
      }

      else if(i < ((*raiz)->chave)){
        ConsultaNo(&(*raiz)->esq, i);
      }
 
      else if(i > ((*raiz)->chave)){
        ConsultaNo(&(*raiz)->dir, i);
      }   

    } 
      
  /*  if(((*raiz)->dir) && (((*raiz)->dir->freqc) > ((*raiz)->freqc))){
		RotacaoEsquerda(&(*raiz), &(*raiz)->dir);
	}
	
	if(((*raiz)->esq) && (((*raiz)->esq->freqc) > ((*raiz)->freqc))){
		(*raiz)=RotacaoDireita(raiz, &(*raiz)->esq);
	}    */  
        
}

//Função de listar chave e frequência em ordem CRESCENTE
void ListaOrdemCrescente(ArvoreBB_PT raiz){

    if(raiz){
       ListaOrdemCrescente(raiz->esq);
       printf("%d %d\n", raiz->chave, raiz->freqc);
       ListaOrdemCrescente(raiz->dir);
    }
}

//Função de listar chave e frequência em ordem DECRESCENTE
void ListaOrdemDecrescente(ArvoreBB_PT raiz){

    if(raiz){
       ListaOrdemDecrescente(raiz->dir);
       printf("%d %d\n", raiz->chave, raiz->freqc);
       ListaOrdemDecrescente(raiz->esq);
    }
}

//Função de impressão da frequência de um nó da árvore
void ImprimeFreqc(ArvoreBB_PT raiz, int i){
    
  if(raiz){
     if(raiz->chave == i){
        printf("%d\n", raiz->freqc);
      }

      else if(i < raiz->chave){
        ImprimeFreqc(raiz->esq, i);
      }
 
      else if(i > raiz->chave){
        ImprimeFreqc(raiz->dir, i);
      }
  }
}

//Função de listar chaves com frequência maior ou igual um certo k em ordem CRESCENTE
void ListaFreqCrescente(ArvoreBB_PT raiz, int k){

    if(raiz){
       ListaFreqCrescente(raiz->esq, k);
       if(raiz->freqc >= k){
         printf("%d\n", raiz->chave);
       }
       ListaFreqCrescente(raiz->dir, k);
    }
}

//Função de impressão da Árvore em ordem CRESCENTE
void ImprimeArvore(ArvoreBB_PT raiz){

    if(raiz){
        ImprimeArvore(raiz->esq);
	if((raiz->esq) && (raiz->dir)){
          printf("chave: %d filho esquerdo: %d filho direito: %d\n", raiz->chave, raiz->esq->chave, raiz->dir->chave);
        }
	
        else if((raiz->esq) && !(raiz->dir)){
	  printf("chave: %d filho esquerdo: %d filho direito: nil\n", raiz->chave, raiz->esq->chave);
        }
	
        else if(!(raiz->esq) && (raiz->dir)){
          printf("chave: %d filho esquerdo: nil filho direito: %d\n", raiz->chave, raiz->dir->chave);
        }
	
        else if(!(raiz->esq) && !(raiz->dir)){
          printf("chave: %d filho esquerdo: nil filho direito: nil\n", raiz->chave);
        }
	ImprimeArvore(raiz->dir); 
    }
}

//Função de impressão por nível da Árvore
void ListaPorNivel(ArvoreBB_PT raiz, int nivel_proc, int nivel_atual){
    
     if((raiz) && (nivel_atual == nivel_proc)){ 
        printf("%d %d\n", raiz->chave, raiz->freqc);
     }

     if((raiz->esq)){
        ListaPorNivel(raiz->esq, nivel_proc, nivel_atual+1);
     }
     
     if((raiz->dir)){
        ListaPorNivel(raiz->dir, nivel_proc, nivel_atual+1);
     }
}
