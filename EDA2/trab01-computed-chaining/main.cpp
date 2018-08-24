#include "libs/functions.hpp"

int main(int argc, char const *argv[])
{
	char option;

	initialize();

	while (std::cin >> option) {
		switch (option) {
			/* insere registro */
			case 'i':
				insert();
				break;
			/* consulta registro */
			case 'c':
				query();
				break;
			/* remove registro */
			case 'r':
				remove();
				break;
			/* imprime arquivo */
			case 'p':
				print();
				break;
			/* média de acessos a registros do arquivo */
			case 'm':
				break;
			/* término da sequência de comandos */
			case 'e':
				return 0;
				break;
		}
	}

	return 0;
}
