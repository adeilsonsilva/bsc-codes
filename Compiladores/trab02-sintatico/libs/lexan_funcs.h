#ifndef LEXAN_FUNCS_H_
#define LEXAN_FUNCS_H_

#include "def_symbols.h"

/*FUNÇÕES DE AVALIAÇÃO DE VALIDADE DO ARQUIVO*/

/* Avalia validade de um caracter, baseado na especificação da linguagem*/
_Bool isValidChar(char c){

	if(((c >= ' ') && (c <= '~')) || (c == '\t') || (c == '\n')){
		return true;
	}

	return false;
}

/* Busca por caracteres inválidos na linha */
_Bool isValidLine(char *line){
	char *c;
	int i;

	for(i = 0, c = line; *c != '\0'; i++, c++){
		if(!isValidChar(*c)){
			return false;
		}
	}
	return true;
}

/* Verifica se o arquivo passado é válido (contém somente os caracteres especificados) */
_Bool isArqValid (FILE *arq){
	int i;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	/*rewind(arq);
	while(!feof(arq)){
		fscanf(arq, "%s", line);
		if(!isValidLine(line)){
			return false;
		}
	}
	return true; */

	/* Seta ponteiro para início do arquivo*/
	rewind(arq);
	for(i = 1; !feof(arq); i++){
		/* Lê uma linha do arquivo*/
		read = getline(&line, &len, arq);

		if(line[strlen(line) - 2] == 13){
			line[strlen(line) - 2] = '\0';	
		}else{
			line[strlen(line) - 1] = '\0';
		}

		/* Passa a linha lida para o analisador*/
		if(read != -1){
			if(!isValidLine(line)){
				return false;
			}
		}
	}
	free(line);
	return true;
}

/* FUNÇÕES DE RECONHECIMENTO DE TOKENS */

/* Verifica se caracter passado é Letra */
_Bool isLetter(char c){
	if(((c <= 'Z') && (c >= 'A')) || ((c <= 'z') && (c >= 'a'))){
		return true;
	}
	return false;
}

/* Verifica se caracter passado é Numero */
_Bool isNumber(char c){
	if((c <= '9') && (c >= '0')){
		return true;
	}
	return false;
}

/* Verifica se a string passada corresponde a um OPERADOR */
_Bool isOperator(char *op){
	int i;
	char *tmp;

	if(strlen(op) <= 2){
		for(i = 0, tmp = op; i < MAXOP; i++){
			if(*tmp == operators[i]){
				addNodeToken(&nodeList, op);
				return true;
			}
		}
	}
	return false;
}

/* Verifica se a string passada corresponde a uma PALAVRA-CHAVE */
_Bool isKeyword(char *kw){
	int i;

	for(i = 0; i < MAXKW; i++){
		if(!strcasecmp(kw, keywords[i])){
			return true; 
		}
	}
	return false;
}

/* Verifica se o caracter passado é válido para uma string */
_Bool isValidForString(char c){

	if((c >= 32) && (c <= 126)){
		return true;
	}

	return false;
}

/* Verifica se a string passada corresponde a um IDENTIFICADOR VÁLIDO
 * Se o primeiro caracter da string não é uma letra, retorna falso.
 * Se o primeiro caracter da string é uma letra e todos os caracteres subsequentes
 * são letra ou número, retorna verdadeiro. Se encontra um caracter invalido, retorna falso. */
_Bool isValidID(char *id){
	char *tmp;

	tmp = id;

	if(isLetter(*tmp)){
		for(; *tmp != '\0'; tmp++){
			if((!(isLetter(*tmp)) && !(isNumber(*tmp)))){
				return false;
			}
		}
		if(!isKeyword(id)){
			return addNodeToken(&nodeList, "id");
		}
		return addNodeToken(&nodeList, id);
	}
	return false;
}

/*Verifica se caracter passado é Terminal */
_Bool isTerminal(char c){
	int i;
	char carac[2];

	for(i = 0; i < MAXTERM; i++){
		if(c == terminals[i]){
			carac[0] = c;
			carac[1] = '\0';
			addNodeToken(&nodeList, carac);
			return true;
		}
	}
	return false;
}

/* Verifica se caracter passado é Separador */
_Bool isSeparator(char c){
	int i;

	for(i = 0; i < MAXSEP; i++){
		if(separators[i] == c){
			return true;
		}
	}
	return false;
}

/* Verifica se é string ou não
 * Retorna VERDADEIRO se o primeiro e o último caracter são aspas duplas
 * e o tamanho é menor ou igual a 258 (256 + as duas aspas)*/
_Bool isConstantString(char *str){
	int count = 0, aspas = 0;
	char *c, *nextC;

	nextC = str;
	++nextC;

	for(c = str, count = 0; *c != '\0' && *c != '\n' && *c != '\t' &&*c != EOF; c++, nextC++){
		if(*c == '\"'){
			aspas++;
		}else if(((*c == '\\') && (*nextC == 'n' || *nextC == 't' || *nextC == '\"' || *nextC == '\\' || *nextC == '\''))){
			count++;
			c++;
			nextC++;
			//continue;
		}else if(((*c == '\\') && !(*nextC == 'n' || *nextC == 't' || *nextC == '\"' || *nextC == '\\' || *nextC == '\''))){
			return false;
		}else if(*c == '\''){
			return false;		
		}else if(isValidForString(*c)){
			count++;
		}else if((*c == '\t' || *c == '\n' || *c == '\a' || *c == '\b' || *c == '\r' || *c == '\v' || *c == '\f' || *c == '\e') || ((*c == '\\') && (*nextC == 'a' || *nextC == 'b' || *nextC == 'v' || *nextC == 'f' || *nextC == 'r' || *nextC == 'e'))){
			return false;
		}
	}
	if((count > 0 && count <= 256) && aspas == 2){
		addNodeToken(&nodeList, "conststr");
		return true;
	}
	return false;
}

/* Verifica se é constante numérica ou não */
_Bool isConstantNumber(char *num){
	int count = 0;
	char *str;

	for(str = num; *str != '\0'; str++){
		if(!isNumber(*str)){
			return false;	
		}
		count++;
	}
	
	if((count > 0) && (count <= 10)){
		addNodeToken(&nodeList, "constnum");
		return true;	
	}
	return false;
}

/* Verifica se é espaço */
_Bool isSpace(char c){
	if(c == 32 || c == 9){
		return true;
	}
	return false;
}

/* Verifica se é constante de caracter */
_Bool isConstantChar(char *str){
	int count = 0, aspas = 0;
	char *c, *nextC;

	nextC = str;
	++nextC;

	for(c = str, count = 0; *c != '\0' && *c != '\n' && *c != EOF; c++, nextC++){
		if(*c == '\''){
			//count--;
			aspas++;
		}else if(((*c == '\\') && (*nextC == 'n' || *nextC == 't' || *nextC == '\"' || *nextC == '\\' || *nextC == '\''))){
			count++;
			c++;
			nextC++;
			continue;
		}else if(((*c == '\\') && !(*nextC == 'n' || *nextC == 't' || *nextC == '\"' || *nextC == '\\' || *nextC == '\''))){
			//count--;
			return false;
		}else if(*c == '\"'){
			return false;	
		}else if(isValidForString(*c)){
			count++;
		}else if((*c == '\t' || *c == '\n' || *c == '\a' || *c == '\b' || *c == '\r' || *c == '\v' || *c == '\f' || *c == '\e') || ((*c == '\\') && (*nextC == 'a' || *nextC == 'b' || *nextC == 'v' || *nextC == 'f' || *nextC == 'r' || *nextC == 'e'))){

			return false;
		}
	}
	if(((count < 2) && (count > 0)) && aspas == 2){
			addNodeToken(&nodeList, "CONSTCHAR");
			return true;
	}
	return false;
}

/* Busca pelo próximo Token, retorna a próxima posição a ser buscada */
char* getNextToken(char *lineActualPos, char *token){
	char *pos, *tmp;
	int i,j;

	for(i = 0, pos = lineActualPos; *pos != '\0' && *pos != '\n'; pos++, i++){
		if(isSeparator(*pos)){
			if(i > 0){ //Leu vários caracteres antes de encontrar um separador
				token[i] = '\0';
				return pos;
			}else{ //O separador foi o primeiro caractere lido nessa iteração
				tmp = pos;
				++tmp;
				if(((*pos == '<') && ((*tmp == '>') || (*tmp == '='))) || ((*pos == '>') && (*tmp == '='))){
					token[i++] = *pos;
					token[i++] = *tmp;
					token[i] = '\0';
					return ++tmp;
				}else if(*pos == '\''){ //Constante de caracter
					tmp = pos;
					tmp++;
					token[0] = *pos;
					for(j = 1; (*tmp != 9) && (*tmp != '\n') && (*tmp != '\0') && (*tmp != '\'') && (*tmp != EOF); j++, tmp++){
						token[j] = *tmp;
						if(*tmp == '\\'){
							//aux = tmp;
							//aux++;
							tmp++;
							if(*tmp == '\''){
								token[++j] = *tmp;
								//tmp++;
								continue;
							}else{
								tmp--;	
							}
						}
					}
					if(*tmp == '\''){
						token[j++] = *tmp;
					}
					token[j] = '\0';
					return ++tmp;
				}else if(*pos == '\"'){ // Constante String
					tmp = pos;
					tmp++;
					token[0] = *pos;
					for(j = 1; (*tmp != 9) && (*tmp != 10) && (*tmp != '\0') && (*tmp != '\"') && (*tmp != EOF); j++, tmp++){
						token[j] = *tmp;
						if(*tmp == '\\'){
							//aux = tmp;
							//aux++;
							tmp++;
							if(*tmp == '\"'){
								token[++j] = *tmp;
								//tmp++;
								continue;
							}else{
								tmp--;	
							}
						}
					}
					if(*tmp == '\"'){
						token[j++] = *tmp;
					}
					token[j] = '\0';
					return ++tmp;
				}else{ //Qualquer outro separador único encontrado
					token[i++] = *pos;
					token[i] = '\0';
					return ++pos;
				}
			}
		}
		token[i] = *pos;
	}
	token[i] = '\0';
	return pos;
}

/* Função de análise da linha */
_Bool analyseLine(char *line, int lineNumber){
	char token[MAXSTR];
	char *lineActualPos;


	for(lineActualPos = line; *lineActualPos != '\0' && *lineActualPos != '\n' && *lineActualPos != EOF;){
		lineActualPos = getNextToken(lineActualPos, &token[0]);
		if((!isValidID(token) && !isTerminal(*token) && !isOperator(token) && !isConstantString(token) && !isConstantNumber(token) && !isConstantChar(token) && !isSpace(*token))){ //Se não é Keyword, identificador, terminal ou operador é erro léxico
			printf("LINE %d: %s\n", lineNumber, token);
			LEXAN_ERRORS++;
		}
	}
	return false;
}

#endif /* LEXAN_FUNCS_H_ */
