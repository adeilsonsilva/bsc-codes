#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stack>

#include "types.hpp"

int h1(int key)
{
	return key % TAMANHO_ARQUIVO;
}

int h2(int key)
{
	return std::max(key/TAMANHO_ARQUIVO, 1);
}

void initialize()
{
	Row row;
	Record incomingRecord;

	fileHandler.open(DATABASE_PATH, std::ios::in | std::ios::binary);
	if (!fileHandler.is_open()) {
		fileHandler.close();
		fileHandler.open(DATABASE_PATH, std::ios::out | std::ios::binary  | std::ios::ate);
		incomingRecord.key = -1;
		row.record = incomingRecord;
		row.pseudoLink = NIL;
		for (int i = 1; i <= TAMANHO_ARQUIVO; i++) {
			fileHandler.seekp(sizeof(Row) * i, std::ios::beg);
			fileHandler.write((char *) &row, sizeof(row));
		}
	}
	fileHandler.close();
}

void query()
{
	Row row;
	Record incomingRecord;
	int address, incomingKey, probe;

	std::cin >> incomingKey;

	address = h1(incomingKey);
	probe = address + 1;

	fileHandler.open(DATABASE_PATH, std::ios::in | std::ios::binary);

	if (fileHandler.is_open()) {
		fileHandler.seekg(sizeof(Row) * probe, std::ios::beg);
		while (fileHandler.read((char *) &row, sizeof(Row))) {
			if (row.record.key == incomingKey) {
				std::cout << "chave: " << incomingKey << std::endl;
				std::cout << row.record.name << std::endl;
				std::cout << row.record.age << std::endl;
				fileHandler.close();
				return;
			} else if (row.pseudoLink != NIL) { // Continua busca na cadeia
				probe = probe + (h2(row.record.key) * row.pseudoLink);
				probe -= probe > TAMANHO_ARQUIVO ? TAMANHO_ARQUIVO : 0;
				fileHandler.seekg(sizeof(Row) * probe, std::ios::beg);
			} else { // Fim da cadeia
				std::cout << "chave nao encontrada: " << incomingKey << std::endl;
				fileHandler.close();
				return;
			}
		}
	}
}

int queryRecord(int incomingKey)
{
	Row row;
	Record incomingRecord;
	int address, probe;

	address = h1(incomingKey);
	probe = address + 1;

	fileHandler.open(DATABASE_PATH, std::ios::in | std::ios::binary);

	if (fileHandler.is_open()) {
		fileHandler.seekg(sizeof(Row) * probe, std::ios::beg);
		while (fileHandler.read((char *) &row, sizeof(Row))) {
			if (row.record.key == incomingKey) {
				fileHandler.close();
				return probe;
			} else if (row.pseudoLink != NIL) { // Continua busca na cadeia
				probe = probe + (h2(row.record.key) * row.pseudoLink);
				probe -= probe > TAMANHO_ARQUIVO ? TAMANHO_ARQUIVO : 0;
				fileHandler.seekg(sizeof(Row) * probe, std::ios::beg);
			} else { // Fim da cadeia
				fileHandler.close();
				return NIL;
			}
		}
	}
}

void insert()
{
	char x;
	Row row;
	Record incomingRecord;
	int pseudoLink, address, position, probe, probeCounter, i;

	std::cin >> incomingRecord.key;
	std::cin.ignore();
	x = std::cin.get();
	for (i = 0; x != '\n'; i++) {
		incomingRecord.name[i] = x;
		x = std::cin.get();
	}
	incomingRecord.name[i] = '\0';
	std::cin >> incomingRecord.age;

	address = h1(incomingRecord.key);

	fileHandler.open(DATABASE_PATH, std::ios::in | std::ios::binary);

	fileHandler.seekg(sizeof(Row) * (address + 1), std::ios::beg);

	if (!fileHandler.read((char *) &row, sizeof(Row)) || row.record.key == -1) { // posição original vazia
		row.record = incomingRecord;
		row.pseudoLink = NIL;
		fileHandler.close();
		fileHandler.open(DATABASE_PATH, std::ios::out | std::ios::in | std::ios::binary);
		fileHandler.seekp(sizeof(Row) * (address + 1), std::ios::beg);
		fileHandler.write((char *) &row, sizeof(row));
		fileHandler.close();
		return;
	} else if (row.record.key == incomingRecord.key) { // chave duplicada
		std::cout << "chave ja existente: " << incomingRecord.key << std::endl;
		fileHandler.close();
		return;
	} else if (h1(row.record.key) != address) { // chave fora de seu endereço original
		// move the item
		fileHandler.close();
		return;
	}

	/* Busca registro na lista */
	probe = address + 1;
	while (row.pseudoLink != NIL) {
		probe = probe + (h2(row.record.key) * row.pseudoLink);
		fileHandler.seekg(sizeof(Row) * probe, std::ios::beg);
		fileHandler.read((char *) &row, sizeof(Row));
		if (row.record.key == incomingRecord.key) {
			std::cout << "chave ja existente: " << incomingRecord.key << std::endl;
			fileHandler.close();
			return;
		}
	}

	int tempProbe = probe;
	Row tempRow = row;

	probeCounter = 1;
	probe = h2(row.record.key);

	position = (tempProbe + (probe * probeCounter));
	position -= position > TAMANHO_ARQUIVO ? TAMANHO_ARQUIVO : 0;
	fileHandler.seekg(sizeof(Row) * position, std::ios::beg);
	fileHandler.read((char *) &tempRow, sizeof(Row));

	while (tempRow.record.key != -1) {
		probeCounter++;
		if (probeCounter > MAXIMO_VALOR_APONTADOR) { return; } // Não há mais espaço no arquivo
		position = (position + (probe * probeCounter));
		position -= position > TAMANHO_ARQUIVO ? TAMANHO_ARQUIVO : 0;
		fileHandler.seekg(sizeof(Row) * position, std::ios::beg);
		fileHandler.read((char *) &tempRow, sizeof(Row));
	}
	fileHandler.close();

	fileHandler.open(DATABASE_PATH, std::ios::out | std::ios::in | std::ios::binary);

	/* Insere novo registro no fim da cadeia */
	position = (tempProbe + (probe * probeCounter));
	position -= position > TAMANHO_ARQUIVO ? TAMANHO_ARQUIVO : 0;
	fileHandler.seekp(sizeof(Row) * position, std::ios::beg);
	tempRow.record = incomingRecord;
	tempRow.pseudoLink = NIL;
	fileHandler.write((char *) &tempRow, sizeof(tempRow));

	/* Atualiza campo de pseudoLink do antecessor do registro adicionado acima */
	row.pseudoLink = probeCounter;
	fileHandler.seekp(sizeof(Row) * tempProbe, std::ios::beg);
	fileHandler.write((char *) &row, sizeof(row));
	fileHandler.close();
	return;
}

void insertRecord(Record incomingRecord)
{
	char x;
	Row row;
	int pseudoLink, address, position, probe, probeCounter, i;

	address = h1(incomingRecord.key);

	fileHandler.open(DATABASE_PATH, std::ios::in | std::ios::binary);

	fileHandler.seekg(sizeof(Row) * (address + 1), std::ios::beg);

	if (!fileHandler.read((char *) &row, sizeof(Row)) || row.record.key == -1) { // posição original vazia
		row.record = incomingRecord;
		row.pseudoLink = NIL;
		fileHandler.close();
		fileHandler.open(DATABASE_PATH, std::ios::out | std::ios::in | std::ios::binary);
		fileHandler.seekp(sizeof(Row) * (address + 1), std::ios::beg);
		fileHandler.write((char *) &row, sizeof(row));
		fileHandler.close();
		return;
	} else if (row.record.key == incomingRecord.key) { // chave duplicada
		std::cout << "chave ja existente: " << incomingRecord.key << std::endl;
		fileHandler.close();
		return;
	} else if (h1(row.record.key) != address) { // chave fora de seu endereço original
		// move the item
		fileHandler.close();
		return;
	}

	/* Busca registro na lista */
	probe = address + 1;
	while (row.pseudoLink != NIL) {
		probe = probe + (h2(row.record.key) * row.pseudoLink);
		fileHandler.seekg(sizeof(Row) * probe, std::ios::beg);
		fileHandler.read((char *) &row, sizeof(Row));
		if (row.record.key == incomingRecord.key) {
			std::cout << "chave ja existente: " << incomingRecord.key << std::endl;
			fileHandler.close();
			return;
		}
	}

	int tempProbe = probe;
	Row tempRow = row;

	probeCounter = 1;
	probe = h2(row.record.key);

	position = (tempProbe + (probe * probeCounter));
	position -= position > TAMANHO_ARQUIVO ? TAMANHO_ARQUIVO : 0;
	fileHandler.seekg(sizeof(Row) * position, std::ios::beg);
	fileHandler.read((char *) &tempRow, sizeof(Row));

	while (tempRow.record.key != -1) {
		probeCounter++;
		if (probeCounter > MAXIMO_VALOR_APONTADOR) { return; } // Não há mais espaço no arquivo
		position = (position + (probe * probeCounter));
		position -= position > TAMANHO_ARQUIVO ? TAMANHO_ARQUIVO : 0;
		fileHandler.seekg(sizeof(Row) * position, std::ios::beg);
		fileHandler.read((char *) &tempRow, sizeof(Row));
	}
	fileHandler.close();

	fileHandler.open(DATABASE_PATH, std::ios::out | std::ios::in | std::ios::binary);

	/* Insere novo registro no fim da cadeia */
	position = (tempProbe + (probe * probeCounter));
	position -= position > TAMANHO_ARQUIVO ? TAMANHO_ARQUIVO : 0;
	fileHandler.seekp(sizeof(Row) * position, std::ios::beg);
	tempRow.record = incomingRecord;
	tempRow.pseudoLink = NIL;
	fileHandler.write((char *) &tempRow, sizeof(tempRow));

	/* Atualiza campo de pseudoLink do antecessor do registro adicionado acima */
	row.pseudoLink = probeCounter;
	fileHandler.seekp(sizeof(Row) * tempProbe, std::ios::beg);
	fileHandler.write((char *) &row, sizeof(row));
	fileHandler.close();
	return;
}

void print()
{
	Row row;
	Record incomingRecord;

	fileHandler.open(DATABASE_PATH, std::ios::in | std::ios::binary);

	if (fileHandler.is_open()) {
		for (int count = 0; count < TAMANHO_ARQUIVO; count++) {
			fileHandler.seekg(sizeof(Row) * (count + 1), std::ios::beg);

			std::cout << count << ": ";
			if (!fileHandler.read((char *) &row, sizeof(Row)) || row.record.key == -1) {
				std::cout << "vazio" << std::endl;
			} else {
				std::cout << row.record.key << " " << row.record.name << " " << row.record.age << " ";
				if (row.pseudoLink == NIL) {
					std::cout << "nulo";
				} else {
					std::cout << row.pseudoLink;
				}
				std::cout << std::endl;
			}
		}
	}

	fileHandler.close();
}

bool removeRecord(int incomingKey)
{
	Row originalRow, row;
	Record incomingRecord, tmpRecord;
	std::stack<Record> recordStack;
	int homeAddress, tmpPseudoLink, tmpKey, removedKey;

	homeAddress = queryRecord(incomingKey);

	if (homeAddress == NIL)	{
		return false;
	} else {
		fileHandler.open(DATABASE_PATH, std::ios::out | std::ios::in | std::ios::binary);
		if (fileHandler.is_open()) {
			/* Remover todos os sucessores da cadeia da incomingKey */
			fileHandler.seekp(sizeof(Row) * homeAddress, std::ios::beg);
			fileHandler.read((char *) &row, sizeof(Row));
			tmpKey = removedKey = row.record.key;
			tmpPseudoLink = row.pseudoLink;
			row.record.key = -1;
			row.pseudoLink = NIL;

			int oldProbe = homeAddress;
			while (true) {
				if (row.record.key != removedKey && row.record.key != -1) {
					recordStack.push(row.record);
				}
				row.record.key = -1;
				row.pseudoLink = NIL;
				fileHandler.seekp(sizeof(Row) * oldProbe, std::ios::beg);
				fileHandler.write((char *) &row, sizeof(row));
				if (tmpPseudoLink == NIL) {
					break;
				}
				int newProbe = homeAddress + (h2(tmpKey) * tmpPseudoLink);
				newProbe -= newProbe > TAMANHO_ARQUIVO ? TAMANHO_ARQUIVO : 0;
				fileHandler.seekp(sizeof(Row) * newProbe, std::ios::beg);
				fileHandler.read((char *) &row, sizeof(Row));
				tmpPseudoLink = row.pseudoLink;
				tmpKey = row.record.key;
				oldProbe = newProbe;
			}
			fileHandler.close();
			while (!recordStack.empty()) {
				incomingRecord = recordStack.top();
				recordStack.pop();
				insertRecord(incomingRecord);
			}
			return true;
		}
	}
}

void remove()
{
	Row originalRow, row;
	Record incomingRecord, tmpRecord;
	std::stack<Record> recordStack;
	int incomingKey, homeAddress, tmpPseudoLink, tmpKey, removedKey;

	std::cin >> incomingKey;

	if (!removeRecord(incomingKey))	{
		std::cout << "chave nao encontrada: " << incomingKey << std::endl;
	}
	return;
}
