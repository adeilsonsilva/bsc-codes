#include "libs/base.h"

int main(int argc, char *argv[])
{

	time(&start);
	//seedArrays();
	menu();
	time(&stop);

	printf("Foram usados %0.2f segundos do tempo da CPU.\n", (double)ticks/CLOCKS_PER_SEC);
	printf("Programa finalizado em aproximadamente %.0f segundos. \n", difftime(stop, start));

	return 0;
}
