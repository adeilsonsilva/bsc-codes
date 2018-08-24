/************************************************************
 * Exercicio 2: Desenhar um objeto do OpenGL
 ************************************************************/
#include <GL/glew.h>
#include <GL/glut.h>

void display(void) {
   glClear(GL_COLOR_BUFFER_BIT);
  
   // indicando a cor do poligono 
   glColor3f (1.0, 1.0, 1.0);

   // desenhando o poligono
   glBegin(GL_POLYGON);
      glVertex3f (0.0, 0.0, 0.0);
      glVertex3f (0.0, 0.5, 0.0);
      glVertex3f (0.5, 0.5, 0.0);
      glVertex3f (0.5, 0.0, 0.0);
   glEnd();

   glFlush();
}

void init(void) {
   // modificando a cor do fundo
   glClearColor(0.0, 0.0, 0.0, 0.0);
}

int main(int argc, char *argv[]) {
   // inicia o glut
   glutInit(&argc, argv);

   // configuracao do display (cor e modo)
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

   // tamanho da janela
   glutInitWindowSize(512, 512);

   // posicao da janela
   glutInitWindowPosition(100, 100);

   // cria uma janela
   glutCreateWindow("Primeira Atividade OpenGL");

   // inicializa o glew
   glewInit();

   // indica a funcao de display, fazendo bind
   glutDisplayFunc(display);
   
   // inicializa algumas variaveis do OpenGL
   init();

   // dispara o inicio do loop do glut
   glutMainLoop();

}
