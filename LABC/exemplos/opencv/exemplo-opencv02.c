/************************************************************
 * Exercicio 2: Carregando imagem atraves de passagem por
 * argumento e posteriormente pegandos as informacoes dela
 ************************************************************/
#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char *argv[]) {
   // declarando os tipos a serem usados
   IplImage *imagem; 
   int altura,largura,canais;

   // testando a quantidade de argumentos
   if (argc != 2){
      printf("Uso: ./exemplo03 <nome do arquivo de imagem>\n");
      return -1;
   }

   // lendo a imagem de um arquivo
   imagem = cvLoadImage(argv[1]);
   if (!imagem) {
      printf("ERRO: Nao foi possivel abrir a imagem\n");
      return -1;
   }

   // pega os dados da imagem
   altura    = imagem->height;
   largura   = imagem->width;
   canais    = imagem->nChannels;
   printf("Processando uma imagem de dimessao %dx%d com %d canais\n", altura,largura,canais); 

   // create image window named "My Image"
   cvNamedWindow("Segundo Exercicio");

   // mostra a imagem na janela
   cvShowImage("Segundo Exercicio", imagem);

   // espera que uma tecla seja apertada por cerca de 5000 ms
   cvWaitKey(5000);

   // desaloca a memoria usada pela imagem
   cvReleaseImage(&imagem);

   return 0;
}
