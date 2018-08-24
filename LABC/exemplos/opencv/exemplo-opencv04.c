/************************************************************
 * Exercicio 4: Eventos de teclado e mudanca de modo
 * cinza ou colorido
 ************************************************************/
#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char *argv[]) {
   // declarando os tipos a serem usados
   IplImage *imagem, *cinza_imagem;
   int altura, largura, canais, tecla;

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
   printf("Processando uma imagem de dimessao %dx%d com %d canais\n", altura, largura, canais);

   // converte para tons de cinza
   cinza_imagem = cvCreateImage(cvSize(altura,largura), IPL_DEPTH_8U, 1);
   cvCvtColor(imagem, cinza_imagem, CV_BGR2GRAY);

   // create image window named "My Image"
   cvNamedWindow("Terceiro Exercicio");

   // mostra a imagem na janela
   cvShowImage("Terceiro Exercicio", imagem);

   // loop principal
   while (1) {
      // espera por uma tecla idefinidamente
      tecla = cvWaitKey(0);

      if (tecla == 27)
         break;
      switch(tecla){
         // mostra a imagem em tons de cinza
         case 'p':
            cvShowImage("Quarto Exercicio", cinza_imagem);
            break;
         // mostra a imagem colorida
         case 'c':
            cvShowImage("Quarto Exercicio", imagem);
            break;
      }
   }


   // desaloca a memoria usada pela imagem
   cvReleaseImage(&imagem);

   return 1;
}
