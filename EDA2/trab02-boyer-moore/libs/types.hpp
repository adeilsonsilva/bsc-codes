#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

#define ALPHABET_SIZE 29

char alphabet[] = {
	'a', 'b', 'c', 'd', 'e',
	'f', 'g', 'h', 'i', 'j',
	'k', 'l', 'm', 'n', 'o',
	'p', 'q', 'r', 's', 't',
	'u', 'v', 'w', 'x', 'y',
	'z', '.', ',', ' '
};

std::string text, pattern;
std::map <int, int> border, deltaTwo;
std::map <char, int> deltaOne;
std::map <char, int>::iterator deltaIterator;
unsigned int textLength = 0, patternLength = 0;
