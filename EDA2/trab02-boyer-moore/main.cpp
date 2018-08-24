#include "libs/functions.hpp"

int main(int argc, char const *argv[])
{
	char option;

	initialize();
	buildDeltaOne();
	buildDeltaTwo();

	while (std::cin >> option && option != 'e') { /* option == e sinaliza o fim da sequência de comandos */
		switch (option) {
			/* busca padrão */
			case 's':
				match();
				break;
			/* impressão da tabela delta1 */
			case 'u':
				printDeltaOne();
				break;
			/* impressão da tabela delta2 */
			case 'd':
				printDeltaTwo();
				break;
		}
	}

	return 0;
}
