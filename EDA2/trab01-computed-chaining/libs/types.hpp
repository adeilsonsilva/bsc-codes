#define NIL 9999
#define MAX_NAME 20
#define TAMANHO_ARQUIVO 11
#define MAXIMO_VALOR_APONTADOR 10

#define DATABASE_PATH "misc/database"

typedef struct Record
{
	int key;
	int age;
	char name[21];
} Record;

typedef struct Row
{
	Record record;
	int pseudoLink;
} Row;

std::fstream fileHandler;
