/************************************************************
 * Exercicio 5: Transformacoes com a imagem, flip horizontal
 * e vertical
 ************************************************************/
#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char *argv[]) {
   // declarando os tipos a serem usados
   IplImage **imagem, *colorida_imagem, *cinza_imagem;
   int altura, largura, canais, tecla;

   // testando a quantidade de argumentos
   if (argc != 2){
      printf("Uso: ./exemplo03 <nome do arquivo de imagem>\n");
      return -1;
   }

   // lendo a imagem de um arquivo
   colorida_imagem = cvLoadImage(argv[1]);
   if (!colorida_imagem) {
      printf("ERRO: Nao foi possivel abrir a imagem\n");
      return -1;
   }

   // pega os dados da imagem
   altura    = colorida_imagem->height;
   largura   = colorida_imagem->width;
   canais    = colorida_imagem->nChannels;
   printf("Processando uma imagem de dimessao %dx%d com %d canais\n", altura, largura, canais);

   // converte para tons de cinza
   cinza_imagem = cvCreateImage(cvSize(altura,largura), IPL_DEPTH_8U, 1);
   cvCvtColor(colorida_imagem, cinza_imagem, CV_BGR2GRAY);

   // create image window named "My Image"
   cvNamedWindow("Terceiro Exercicio");

   // indica a imagem de exibicao inicial
   imagem = &colorida_imagem;

   // loop principal
   while (1) {
      // mostra a imagem na janela
      cvShowImage("Terceiro Exercicio", *imagem);

      // espera por uma tecla idefinidamente
      tecla = cvWaitKey(0);

      // testa se foi a tecla ESC
      if (tecla == 27)
         break;

      switch(tecla){
         // mostra a imagem em tons de cinza
         case 'p':
            imagem = &cinza_imagem;
            break;
         // mostra a imagem colorida
         case 'c':
            imagem = &colorida_imagem;
            break;
         // rotaciona a imagem
         case 'h':
            cvFlip(*imagem, NULL, 1);
            break;
         case 'v':
            cvFlip(*imagem, NULL, 0);

      }
   }


   // desaloca a memoria usada pela imagem
   cvReleaseImage(&colorida_imagem);
   cvReleaseImage(&cinza_imagem);

   return 1;
}
