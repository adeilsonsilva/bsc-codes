/************************************************************
 * Exercicio 1: Carregar imagem de um arquivo
 ************************************************************/
#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char *argv[]) {
   // declarando a imagem
   IplImage *imagem;

   // carregando a imagem
   imagem = cvLoadImage("../imagens/lena_std.ppm");

   // verificando o numero de argumentos
   if (argc != 2 || !imagem) {
       printf("ERRO: nao foi possivel abrir a imagem\n");
       return -1;
   }

   // criando a janela
   cvNamedWindow("Nome da Janela", CV_WINDOW_AUTOSIZE );

   // mostrando a imagem carregada
   cvShowImage("Mostra Imagem", imagem);

   // esperando ate que seja digitada alguma tecla
   cvWaitKey(0);

   return 0;
}
