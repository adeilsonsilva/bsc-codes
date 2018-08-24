#include "types.hpp"

void buildDeltaOne()
{
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		deltaOne[alphabet[i]] = patternLength;
	}

	for (int i = 0; i < patternLength; i++) {
		deltaOne[pattern[i]] = patternLength - i - 1;
	}
}

void buildDeltaTwo()
{
	int i, j;
    deltaTwo[patternLength] = 1;
	for (i = patternLength, j = i + 1, border[i] = j; i > 0; border[--i] = --j) {
		while (j <= patternLength && pattern[i - 1] != pattern[j - 1]) {
			if (deltaTwo[j] == 0) {
				deltaTwo[j] = patternLength - i;
			}
			j = border[j];
		}
	}

    for (i = 0, j = border[0]; i <= patternLength; i++) {
        if (deltaTwo[i] == 0) {
            deltaTwo[i] = patternLength + j - i;
        }
        if (i == j) {
            j = border[j];
        }
    }
}

void initialize()
{
	char x;
	int i;

	std::cin >> textLength;
	char textHolder[textLength + 1]; /* +1 == '\0' */
	char patternHolder[textLength + 1]; /* +1 == '\0' */

	std::cin.ignore();
	x = std::cin.get();
	for (i = 0; x != '\n' && i <= textLength; i++) {
		textHolder[i] = x;
		x = std::cin.get();
	}
	textHolder[i] = '\0';

	x = std::cin.get();
	for (i = 0; x != '\n'; i++) {
		patternHolder[i] = x;
		x = std::cin.get();
	}
	patternHolder[i] = '\0';

	text.assign(textHolder, textLength);
	pattern.assign(patternHolder, (unsigned) strlen(patternHolder));
	patternLength = pattern.length();
}

void match()
{
	int i, j;
    for (i = 0, j = patternLength - 1; i <= (textLength - patternLength); j = patternLength - 1) {

        for (; j >= 0 && pattern[j] == text[i + j]; j--);

        if (j < 0) {
            std::cout << i + 1 << std::endl; /* A posição do primeiro caractere é a posição 1. */
            i += deltaTwo[0];
        } else {
            i += std::max(deltaTwo[j + 1], deltaOne[text[i + j]]);
        }
    }
}

void printDeltaOne()
{
	std::cout << "Tabela Delta 1:" << std::endl;
	for (int i = 0; i < ALPHABET_SIZE - 1; i++) {
		std::cout << alphabet[i] << ": " << deltaOne[alphabet[i]] << std::endl;
	}
	std::cout << "'" << alphabet[ALPHABET_SIZE - 1] << "': " << deltaOne[alphabet[ALPHABET_SIZE - 1]] << std::endl; /* Print space char ' ' */
}

void printDeltaTwo()
{
	std::cout << "Tabela Delta 2:" << std::endl;
	for (int i = 0; i < patternLength; i++)	{
		if (pattern[i] == ' ') {
			std::cout << "' ': "; /* Print space char ' ' */
		} else {
			std::cout << pattern[i] << ": ";
		}
		std::cout << deltaTwo[i + 1] << std::endl;
	}
}
