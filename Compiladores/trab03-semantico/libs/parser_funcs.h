#ifndef PARSER_FUNCS_H_
#define PARSER_FUNCS_H_

#include "def_symbols.h"

void maquinaEstados(int estadoAtual, char *entrada, int *proxEstado, _Bool *eReducao){

	*eReducao = false;
	*proxEstado = INT_MIN;	
	
	if(estadoAtual == 0){
		if(!strcasecmp(entrada,  "#S")){
			*proxEstado = 1;	
		}else if(!strcasecmp(entrada,  "#C")){
			*proxEstado = 2;
		}else if(!strcasecmp(entrada,  "#Comando")){ /* Início b0 */
			*proxEstado = 3;
		}else if(!strcasecmp(entrada,  "$") || (!strcasecmp(entrada, "]"))){
			*proxEstado = 3;
			*eReducao = true;
		}else if(!strcasecmp(entrada,  "#Declaracao")){ /* Início b1 */
			*proxEstado = 4;
		}else if(!strcasecmp(entrada,  "#Alocacao")){
			*proxEstado = 5;
		}else if(!strcasecmp(entrada,  "#Atribuicao")){
			*proxEstado = 6;
		}else if(!strcasecmp(entrada,  "#Condicional")){
			*proxEstado = 7;
		}else if(!strcasecmp(entrada,  "#Loop")){
			*proxEstado = 8;
		}else if(!strcasecmp(entrada,  "#Leitura")){
			*proxEstado = 9;
		}else if(!strcasecmp(entrada,  "#Escrita")){ /* Fim b1 */
			*proxEstado = 10;
		}else if(!strcasecmp(entrada, "declare")){ /*Inicio b2 */
			*proxEstado = 11;	
		}else if(!strcasecmp(entrada, "resize")){
			*proxEstado = 26;	
		}else if(!strcasecmp(entrada, "put")){
			*proxEstado = 55;	
		}else if(!strcasecmp(entrada, "if")){
			*proxEstado = 68;	
		}else if(!strcasecmp(entrada, "for")){
			*proxEstado = 87;	
		}else if(!strcasecmp(entrada, "foreach")){
			*proxEstado = 97;	
		}else if(!strcasecmp(entrada, "read")){
			*proxEstado = 105;	
		}else if(!strcasecmp(entrada, "print")){ /* Fim b2 && Fim b0 */
			*proxEstado = 108;	
		}
	}else if(estadoAtual == 1){
		if(!strcasecmp(entrada, "$")){
			*proxEstado = INT_MAX;	
		}
	}else if(estadoAtual == 2){
		if(!strcasecmp(entrada, "$")){
			*proxEstado = 1;
			*eReducao = true;	
		}	
	}else if(estadoAtual == 3){
		if(!strcasecmp(entrada, "#C")){
			*proxEstado = 117;	
		}else if(!strcasecmp(entrada, "#Comando")){ /* Início b0 */
			*proxEstado = 3;	
		}else if(!strcasecmp(entrada, "$") || (!strcasecmp(entrada, "]"))){
			*proxEstado = 3;
			*eReducao = true;
		}else if(!strcasecmp(entrada,  "#Declaracao")){ /* Início b1 */
			*proxEstado = 4;
		}else if(!strcasecmp(entrada,  "#Alocacao")){
			*proxEstado = 5;
		}else if(!strcasecmp(entrada,  "#Atribuicao")){
			*proxEstado = 6;
		}else if(!strcasecmp(entrada,  "#Condicional")){
			*proxEstado = 7;
		}else if(!strcasecmp(entrada,  "#Loop")){
			*proxEstado = 8;
		}else if(!strcasecmp(entrada,  "#Leitura")){
			*proxEstado = 9;
		}else if(!strcasecmp(entrada,  "#Escrita")){ /* Fim b1 */
			*proxEstado = 10;
		}else if(!strcasecmp(entrada, "declare")){ /*Inicio b2 */
			*proxEstado = 11;	
		}else if(!strcasecmp(entrada, "resize")){
			*proxEstado = 26;	
		}else if(!strcasecmp(entrada, "put")){
			*proxEstado = 55;	
		}else if(!strcasecmp(entrada, "if")){
			*proxEstado = 68;	
		}else if(!strcasecmp(entrada, "for")){
			*proxEstado = 87;	
		}else if(!strcasecmp(entrada, "foreach")){
			*proxEstado = 97;	
		}else if(!strcasecmp(entrada, "read")){
			*proxEstado = 105;	
		}else if(!strcasecmp(entrada, "print")){ /* Fim b2 && Fim b0 */
			*proxEstado = 108;	
		}
	}else if(estadoAtual == 4){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 4;
			*eReducao = true;
		}
	}else if(estadoAtual == 5){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 5;
			*eReducao = true;
		}
	}else if(estadoAtual == 6){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 6;
			*eReducao = true;
		}
	}else if(estadoAtual == 7){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 7;
			*eReducao = true;
		}
	}else if(estadoAtual == 8){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 8;
			*eReducao = true;
		}
	}else if(estadoAtual == 9){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 9;
			*eReducao = true;
		}
	}else if(estadoAtual == 10){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 10;
			*eReducao = true;
		}
	}else if(estadoAtual == 11){
		if(!strcasecmp(entrada, "#LIST")){
			*proxEstado = 12;	
		}else if(!strcasecmp(entrada, "id")){ /* b4 */
			*proxEstado = 13;	
		}
	}else if(estadoAtual == 12){
		if(!strcasecmp(entrada, "as")){
			*proxEstado = 16;	
		}	
	}else if(estadoAtual == 13){
		if(!strcasecmp(entrada, "as")){
			*proxEstado = 12;
			*eReducao = true;
		}else if(!strcasecmp(entrada, "[")){
			*proxEstado = 14;	
		}else if(!strcasecmp(entrada, ",")){
			*proxEstado = 15;	
		}
	}else if(estadoAtual == 14){
		if(!strcasecmp(entrada, "]")){
			*proxEstado = 17;	
		}
	}else if(estadoAtual == 15){
		if(!strcasecmp(entrada, "#LIST")){
			*proxEstado = 19;	
		}else if(!strcasecmp(entrada, "id")){ /* b4 */
			*proxEstado = 13;	
		}
	}else if(estadoAtual == 16){
			if(!strcasecmp(entrada, "#TIPO")){
			*proxEstado = 20;	
		}else if(!strcasecmp(entrada, "letter")){
			*proxEstado = 21;	
		}else if(!strcasecmp(entrada, "number")){
			*proxEstado = 22;	
		}	
	}else if(estadoAtual == 17){
		if(!strcasecmp(entrada, "as")){
			*proxEstado = 13;
			*eReducao = true;
		}else if(!strcasecmp(entrada, ",")){
			*proxEstado = 24;	
		}
	}else if(estadoAtual == 19){ /* O estado 18 foi eliminado!!!!! */
		if(!strcasecmp(entrada, "as")){
			*proxEstado = 14;
			*eReducao = true;
		}
	}else if(estadoAtual == 20){
		if(!strcasecmp(entrada, ".")){
			*proxEstado = 23;	
		}	
	}else if(estadoAtual == 21){
		if(!strcasecmp(entrada, ".")){
			*proxEstado = 16;
			*eReducao = true;
		}	
	}else if(estadoAtual == 22){
		if(!strcasecmp(entrada, ".")){
			*proxEstado = 17;
			*eReducao = true;
		}	
	}else if(estadoAtual == 23){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 11;
			*eReducao = true;
		}
	}else if(estadoAtual == 24){
		if(!strcasecmp(entrada, "#LIST")){
			*proxEstado = 25;	
		}else if(!strcasecmp(entrada, "id")){ /* b4 */
			*proxEstado = 13;	
		}		
	}else if(estadoAtual == 25){
		if(!strcasecmp(entrada, "as")){
			*proxEstado = 15;	
			*eReducao = true;
		}	
	}else if(estadoAtual == 26){
		if(!strcasecmp(entrada, "id")){
			*proxEstado = 27;	
		}	
	}else if(estadoAtual == 27){
		if(!strcasecmp(entrada, "to")){
			*proxEstado = 28;	
		}	
	}else if(estadoAtual == 28){
		if(!strcasecmp(entrada, "#EXPARIT")){ /* Inicio b5 */
			*proxEstado = 29;	
		}else if(!strcasecmp(entrada, "#EXP")){ /* Inicio b5 */
			*proxEstado = 31;	
		}else if(!strcasecmp(entrada, "#FATOR")){ 
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#TERMO")){ /* Inicio b6 */
			*proxEstado = 36;	
		}else if(!strcasecmp(entrada, "#FATOR")){ 
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}
	}else if(estadoAtual == 29){
		if(!strcasecmp(entrada, ".")){
			*proxEstado = 30;	
		}	
	}else if(estadoAtual == 30){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 18;
			*eReducao = true;
		}
	}else if(estadoAtual == 31){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")"))){ /* pad1,5 */
			*proxEstado = 30;
			*eReducao = true;
		}else if(!strcasecmp(entrada, "+")){
			*proxEstado = 32;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 33;	
		}
	}else if(estadoAtual == 32){
		if(!strcasecmp(entrada, "#TERMO")){
			*proxEstado = 118;	
		}else if(!strcasecmp(entrada, "#FATOR")){ 
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}	
	}else if(estadoAtual == 33){
		if(!strcasecmp(entrada, "#TERMO")){
			*proxEstado = 119;	
		}else if(!strcasecmp(entrada, "#FATOR")){ 
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}	
	}else if(estadoAtual == 36){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-"))){ /* pad2 */
			*proxEstado = 33;
			*eReducao = true;
		}else if(!strcasecmp(entrada, "*")){
			*proxEstado = 37;	
		}else if(!strcasecmp(entrada, "/")){
			*proxEstado = 38;	
		}else if(!strcasecmp(entrada, "%")){
			*proxEstado = 39;	
		}
	}else if(estadoAtual == 37){
		if(!strcasecmp(entrada, "#FATOR")){
			*proxEstado = 40;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}	
	}else if(estadoAtual == 38){
		if(!strcasecmp(entrada, "#FATOR")){
			*proxEstado = 41;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}	
	}else if(estadoAtual == 39){
		if(!strcasecmp(entrada, "#FATOR")){
			*proxEstado = 42;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}	
	}else if(estadoAtual == 40){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">")) || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-")) || (!strcasecmp(entrada, "*")) || (!strcasecmp(entrada, "/")) || (!strcasecmp(entrada, "%"))){ /* pad3 */
			*proxEstado = 34;
			*eReducao = true;
		}
	}else if(estadoAtual == 41){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-")) || (!strcasecmp(entrada, "*")) || (!strcasecmp(entrada, "/")) || (!strcasecmp(entrada, "%"))){ /* pad3 */
			*proxEstado = 35;
			*eReducao = true;
		}
	}else if(estadoAtual == 42){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-")) || (!strcasecmp(entrada, "*")) || (!strcasecmp(entrada, "/")) || (!strcasecmp(entrada, "%"))){ /* pad3 */
			*proxEstado = 36;
			*eReducao = true;
		}
	}else if(estadoAtual == 43){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-")) || (!strcasecmp(entrada, "*")) || (!strcasecmp(entrada, "/")) || (!strcasecmp(entrada, "%"))){ /* pad3 */
			*proxEstado = 37;
			*eReducao = true;
		}
	}else if(estadoAtual == 44){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-")) || (!strcasecmp(entrada, "*")) || (!strcasecmp(entrada, "/")) || (!strcasecmp(entrada, "%"))){ /* pad3 */
			*proxEstado = 38;
			*eReducao = true;
		}
	}else if(estadoAtual == 45){
		if(!strcasecmp(entrada, "#EXPARIT")){
			*proxEstado = 46;	
		}if(!strcasecmp(entrada, "#EXP")){ /* Inicio b5 */
			*proxEstado = 31;	
		}else if(!strcasecmp(entrada, "#TERMO")){ /* Inicio b6 */
			*proxEstado = 36;	
		}else if(!strcasecmp(entrada, "#FATOR")){ 
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}	
	}else if(estadoAtual == 46){
		if(!strcasecmp(entrada, ")")){
			*proxEstado = 47;	
		}	
	}else if(estadoAtual == 47){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-")) || (!strcasecmp(entrada, "*")) || (!strcasecmp(entrada, "/")) || (!strcasecmp(entrada, "%"))){ /* pad3 */
			*proxEstado = 39;
			*eReducao = true;
		}	
	}else if(estadoAtual == 48){
		if(!strcasecmp(entrada, "#FATOR")){
			*proxEstado = 49;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}	
	}else if(estadoAtual == 49){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-")) || (!strcasecmp(entrada, "*")) || (!strcasecmp(entrada, "/")) || (!strcasecmp(entrada, "%"))){ /* pad3 */
			*proxEstado = 40;
			*eReducao = true;
		}
	}else if(estadoAtual == 50){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-")) || (!strcasecmp(entrada, "*")) || (!strcasecmp(entrada, "/")) || (!strcasecmp(entrada, "%"))){ /* pad3 */
			*proxEstado = 41;
			*eReducao = true;
		}else if(!strcasecmp(entrada, "[")){
			*proxEstado = 51;	
		}	
	}else if(estadoAtual == 51){
		if(!strcasecmp(entrada, "#EXPARIT")){
			*proxEstado = 52;	
		}else if(!strcasecmp(entrada, "#EXP")){ /* Inicio b5 */
			*proxEstado = 31;	
		}else if(!strcasecmp(entrada, "#TERMO")){ /* Inicio b6 */
			*proxEstado = 36;	
		}else if(!strcasecmp(entrada, "#FATOR")){ 
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}	
	}else if(estadoAtual == 52){
		if(!strcasecmp(entrada, "]")){
			*proxEstado = 53;	
		}	
	}else if(estadoAtual == 53){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-")) || (!strcasecmp(entrada, "*")) || (!strcasecmp(entrada, "/")) || (!strcasecmp(entrada, "%"))){ /* pad3 */
			*proxEstado = 42;
			*eReducao = true;
		}
	}else if(estadoAtual == 54){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-")) || (!strcasecmp(entrada, "*")) || (!strcasecmp(entrada, "/")) || (!strcasecmp(entrada, "%"))){ /* pad3 */
			*proxEstado = 43;
			*eReducao = true;
		}
	}else if(estadoAtual == 55){
		if(!strcasecmp(entrada, "#EXPARIT")){
			*proxEstado = 56;	
		}else if(!strcasecmp(entrada, "conststr")){
			*proxEstado = 64;	
		}else if(!strcasecmp(entrada, "#EXP")){ /* Inicio b5 */
			*proxEstado = 31;	
		}else if(!strcasecmp(entrada, "#FATOR")){ 
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#TERMO")){ /* Inicio b6 */
			*proxEstado = 36;	
		}else if(!strcasecmp(entrada, "#FATOR")){
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}	
	}else if(estadoAtual == 56){
		if(!strcasecmp(entrada, "in")){
			*proxEstado = 57;
		}	
	}else if(estadoAtual == 57){
		if(!strcasecmp(entrada, "#ID")){
			*proxEstado = 62;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 58;	
		}
	}else if(estadoAtual == 58){
		if(!strcasecmp(entrada, "from") || !strcasecmp(entrada, "in") || !strcasecmp(entrada, ".")){
			*proxEstado = 52;	
			*eReducao = true;
		}else if(!strcasecmp(entrada, "[")){
			*proxEstado = 59;	
		}
	}else if(estadoAtual == 59){
		if(!strcasecmp(entrada, "#EXPARIT")){
			*proxEstado = 60;	
		}else if(!strcasecmp(entrada, "#EXP")){ /* Inicio b5 */
			*proxEstado = 31;	
		}else if(!strcasecmp(entrada, "#FATOR")){ 
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#TERMO")){ /* Inicio b6 */
			*proxEstado = 36;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}	
	}else if(estadoAtual == 60){
		if(!strcasecmp(entrada, "]")){
			*proxEstado = 61;
		}	
	}else if(estadoAtual == 61){
		if(!strcasecmp(entrada, "from") || !strcasecmp(entrada, "in") || !strcasecmp(entrada, ".")){
			*proxEstado = 53;	
			*eReducao = true;
		}
	}else if(estadoAtual == 62){
		if(!strcasecmp(entrada, ".")){
			*proxEstado = 63;
		}
	}else if(estadoAtual == 63){	
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 19;
			*eReducao = true;
		}
	}else if(estadoAtual == 64){
		if(!strcasecmp(entrada, "in")){
			*proxEstado = 65;
		}		
	}else if(estadoAtual == 65){
		if(!strcasecmp(entrada, "id")){
			*proxEstado = 66;
		}
	}else if(estadoAtual == 66){
		if(!strcasecmp(entrada, ".")){
			*proxEstado = 67;
		}	
	}else if(estadoAtual == 67){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 20;
			*eReducao = true;
		}	
	}else if(estadoAtual == 68){
		if(!strcasecmp(entrada, "#EXPREL")){
			*proxEstado = 78;
		}else if(!strcasecmp(entrada, "#EXPARIT")){
			*proxEstado = 69;
		}else if(!strcasecmp(entrada, "#EXP")){ /* Inicio b5 */
			*proxEstado = 31;	
		}else if(!strcasecmp(entrada, "#FATOR")){ 
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#TERMO")){ /* Inicio b6 */
			*proxEstado = 36;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}
	}else if(estadoAtual == 69){
		if(!strcasecmp(entrada, "#OPREL")){
			*proxEstado = 76;
		}else if(!strcasecmp(entrada, ">")){
			*proxEstado = 70;
		}else if(!strcasecmp(entrada, "<")){
			*proxEstado = 71;
		}else if(!strcasecmp(entrada, "<>")){
			*proxEstado = 72;
		}else if(!strcasecmp(entrada, ">=")){
			*proxEstado = 73;
		}else if(!strcasecmp(entrada, "<=")){
			*proxEstado = 74;
		}else if(!strcasecmp(entrada, "=")){
			*proxEstado = 75;
		}	
	}else if(estadoAtual == 70){
		if(!strcasecmp(entrada, "constnum") || !strcasecmp(entrada, "(") || !strcasecmp(entrada, "id") || !strcasecmp(entrada, "-") ){
			*proxEstado = 46;
			*eReducao = true;
		}	
	}else if(estadoAtual == 71){
		if(!strcasecmp(entrada, "constnum") || !strcasecmp(entrada, "(") || !strcasecmp(entrada, "id") || !strcasecmp(entrada, "-") ){
			*proxEstado = 47;
			*eReducao = true;
		}	
	}else if(estadoAtual == 72){
		if(!strcasecmp(entrada, "constnum") || !strcasecmp(entrada, "(") || !strcasecmp(entrada, "id") || !strcasecmp(entrada, "-") ){
			*proxEstado = 48;
			*eReducao = true;
		}	
	}else if(estadoAtual == 73){
		if(!strcasecmp(entrada, "constnum") || !strcasecmp(entrada, "(") || !strcasecmp(entrada, "id") || !strcasecmp(entrada, "-") ){
			*proxEstado = 49;
			*eReducao = true;
		}	
	}else if(estadoAtual == 74){
		if(!strcasecmp(entrada, "constnum") || !strcasecmp(entrada, "(") || !strcasecmp(entrada, "id") || !strcasecmp(entrada, "-") ){
			*proxEstado = 50;
			*eReducao = true;
		}	
	}else if(estadoAtual == 75){
		if(!strcasecmp(entrada, "constnum") || !strcasecmp(entrada, "(") || !strcasecmp(entrada, "id") || !strcasecmp(entrada, "-") ){
			*proxEstado = 51;
			*eReducao = true;
		}	
	}else if(estadoAtual == 76){
		if(!strcasecmp(entrada, "#EXPARIT")){
			*proxEstado = 77;
		}else if(!strcasecmp(entrada, "#EXP")){ /* Inicio b5 */
			*proxEstado = 31;	
		}else if(!strcasecmp(entrada, "#FATOR")){ 
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#TERMO")){ /* Inicio b6 */
			*proxEstado = 36;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}	
	}else if(estadoAtual == 77){
		if(!strcasecmp(entrada, "then")){
			*proxEstado = 45;
			*eReducao = true;
		}	
	}else if(estadoAtual == 78){
		if(!strcasecmp(entrada, "then")){
			*proxEstado = 79;
		}		
	}else if(estadoAtual == 79){
		if(!strcasecmp(entrada, "[")){
			*proxEstado = 80;
		}		
	}else if(estadoAtual == 80){
		if(!strcasecmp(entrada, "#C")){
			*proxEstado = 81;
		}else if(!strcasecmp(entrada, "#Comando")){
			*proxEstado = 3;	
		}else if(!strcasecmp(entrada, "$") || (!strcasecmp(entrada, "]"))){
			*proxEstado = 3;
			*eReducao = true;
		}else if(!strcasecmp(entrada,  "#Declaracao")){ /* Início b1 */
			*proxEstado = 4;
		}else if(!strcasecmp(entrada,  "#Alocacao")){
			*proxEstado = 5;
		}else if(!strcasecmp(entrada,  "#Atribuicao")){
			*proxEstado = 6;
		}else if(!strcasecmp(entrada,  "#Condicional")){
			*proxEstado = 7;
		}else if(!strcasecmp(entrada,  "#Loop")){
			*proxEstado = 8;
		}else if(!strcasecmp(entrada,  "#Leitura")){
			*proxEstado = 9;
		}else if(!strcasecmp(entrada,  "#Escrita")){ /* Fim b1 */
			*proxEstado = 10;
		}else if(!strcasecmp(entrada, "declare")){ /*Inicio b2 */
			*proxEstado = 11;	
		}else if(!strcasecmp(entrada, "resize")){
			*proxEstado = 26;	
		}else if(!strcasecmp(entrada, "put")){
			*proxEstado = 55;	
		}else if(!strcasecmp(entrada, "if")){
			*proxEstado = 68;	
		}else if(!strcasecmp(entrada, "for")){
			*proxEstado = 87;	
		}else if(!strcasecmp(entrada, "foreach")){
			*proxEstado = 97;	
		}else if(!strcasecmp(entrada, "read")){
			*proxEstado = 105;	
		}else if(!strcasecmp(entrada, "print")){ /* Fim b2 && Fim b0 */
			*proxEstado = 108;	
		}		
	}else if(estadoAtual == 81){
		if(!strcasecmp(entrada, "]")){
			*proxEstado = 82;
		}
	}else if(estadoAtual == 82){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 21;
			*eReducao = true;
		}else if(!strcasecmp(entrada, "else")){
			*proxEstado = 83;
		}
	}else if(estadoAtual == 83){
		if(!strcasecmp(entrada, "[")){
			*proxEstado = 84;
		}
	}else if(estadoAtual == 84){
		if(!strcasecmp(entrada, "#C")){
			*proxEstado = 85;
		}else if(!strcasecmp(entrada, "#Comando")){
			*proxEstado = 3;	
		}else if(!strcasecmp(entrada, "$") || (!strcasecmp(entrada, "]"))){
			*proxEstado = 3;
			*eReducao = true;
		}else if(!strcasecmp(entrada,  "#Declaracao")){ /* Início b1 */
			*proxEstado = 4;
		}else if(!strcasecmp(entrada,  "#Alocacao")){
			*proxEstado = 5;
		}else if(!strcasecmp(entrada,  "#Atribuicao")){
			*proxEstado = 6;
		}else if(!strcasecmp(entrada,  "#Condicional")){
			*proxEstado = 7;
		}else if(!strcasecmp(entrada,  "#Loop")){
			*proxEstado = 8;
		}else if(!strcasecmp(entrada,  "#Leitura")){
			*proxEstado = 9;
		}else if(!strcasecmp(entrada,  "#Escrita")){ /* Fim b1 */
			*proxEstado = 10;
		}else if(!strcasecmp(entrada, "declare")){ /*Inicio b2 */
			*proxEstado = 11;	
		}else if(!strcasecmp(entrada, "resize")){
			*proxEstado = 26;	
		}else if(!strcasecmp(entrada, "put")){
			*proxEstado = 55;	
		}else if(!strcasecmp(entrada, "if")){
			*proxEstado = 68;	
		}else if(!strcasecmp(entrada, "for")){
			*proxEstado = 87;	
		}else if(!strcasecmp(entrada, "foreach")){
			*proxEstado = 97;	
		}else if(!strcasecmp(entrada, "read")){
			*proxEstado = 105;	
		}else if(!strcasecmp(entrada, "print")){ /* Fim b2 && Fim b0 */
			*proxEstado = 108;	
		}		
	}else if(estadoAtual == 85){
		if(!strcasecmp(entrada, "]")){
			*proxEstado = 86;
		}
	}else if(estadoAtual == 86){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 22;
			*eReducao = true;
		}
	}else if(estadoAtual == 87){
		if(!strcasecmp(entrada, "#ID")){
			*proxEstado = 88;
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 58; 	
		}
	}else if(estadoAtual == 88){
		if(!strcasecmp(entrada, "from")){
			*proxEstado = 89;
		}
	}else if(estadoAtual == 89){
		if(!strcasecmp(entrada, "#EXPARIT")){
			*proxEstado = 90;
		}else if(!strcasecmp(entrada, "#EXP")){ /* Inicio b5 */
			*proxEstado = 31;	
		}else if(!strcasecmp(entrada, "#FATOR")){ 
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#TERMO")){ /* Inicio b6 */
			*proxEstado = 36;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}
	}else if(estadoAtual == 90){
		if(!strcasecmp(entrada, "to")){
			*proxEstado = 91;
		}
	}else if(estadoAtual == 91){
		if(!strcasecmp(entrada, "#EXPARIT")){
			*proxEstado = 92;
		}else if(!strcasecmp(entrada, "#EXP")){ /* Inicio b5 */
			*proxEstado = 31;	
		}else if(!strcasecmp(entrada, "#FATOR")){ 
			*proxEstado = 43;	
		}else if(!strcasecmp(entrada, "#TERMO")){ /* Inicio b6 */
			*proxEstado = 36;	
		}else if(!strcasecmp(entrada, "#OPERANDO")){ /* Inicio b7 */
			*proxEstado = 44;	
		}else if(!strcasecmp(entrada, "(")){
			*proxEstado = 45;	
		}else if(!strcasecmp(entrada, "-")){
			*proxEstado = 48;	
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 50;	
		}else if(!strcasecmp(entrada, "constnum")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 54;	
		}else if(!strcasecmp(entrada, "constchar")){ /* Fim b7 && b6 && b5 */
			*proxEstado = 120;	
		}
	}else if(estadoAtual == 92){
		if(!strcasecmp(entrada, "do")){
			*proxEstado = 93;
		}
	}else if(estadoAtual == 93){
		if(!strcasecmp(entrada, "[")){
			*proxEstado = 94;
		}
	}else if(estadoAtual == 94){
		if(!strcasecmp(entrada, "#C")){
			*proxEstado = 95;
		}else if(!strcasecmp(entrada, "#Comando")){
			*proxEstado = 3;	
		}else if(!strcasecmp(entrada, "$") || (!strcasecmp(entrada, "]"))){
			*proxEstado = 3;
			*eReducao = true;
		}else if(!strcasecmp(entrada,  "#Declaracao")){ /* Início b1 */
			*proxEstado = 4;
		}else if(!strcasecmp(entrada,  "#Alocacao")){
			*proxEstado = 5;
		}else if(!strcasecmp(entrada,  "#Atribuicao")){
			*proxEstado = 6;
		}else if(!strcasecmp(entrada,  "#Condicional")){
			*proxEstado = 7;
		}else if(!strcasecmp(entrada,  "#Loop")){
			*proxEstado = 8;
		}else if(!strcasecmp(entrada,  "#Leitura")){
			*proxEstado = 9;
		}else if(!strcasecmp(entrada,  "#Escrita")){ /* Fim b1 */
			*proxEstado = 10;
		}else if(!strcasecmp(entrada, "declare")){ /*Inicio b2 */
			*proxEstado = 11;	
		}else if(!strcasecmp(entrada, "resize")){
			*proxEstado = 26;	
		}else if(!strcasecmp(entrada, "put")){
			*proxEstado = 55;	
		}else if(!strcasecmp(entrada, "if")){
			*proxEstado = 68;	
		}else if(!strcasecmp(entrada, "for")){
			*proxEstado = 87;	
		}else if(!strcasecmp(entrada, "foreach")){
			*proxEstado = 97;	
		}else if(!strcasecmp(entrada, "read")){
			*proxEstado = 105;	
		}else if(!strcasecmp(entrada, "print")){ /* Fim b2 && Fim b0 */
			*proxEstado = 108;	
		}
	}else if(estadoAtual == 95){
		if(!strcasecmp(entrada, "]")){
			*proxEstado = 96;
		}
	}else if(estadoAtual == 96){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 23;
			*eReducao = true;
		}
	}else if(estadoAtual == 97){
		if(!strcasecmp(entrada, "#ID")){
			*proxEstado = 98;
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 58; 	
		}
	}else if(estadoAtual == 98){
		if(!strcasecmp(entrada, "in")){
			*proxEstado = 99;
		}
	}else if(estadoAtual == 99){
		if(!strcasecmp(entrada, "id")){
			*proxEstado = 100;
		}
	}else if(estadoAtual == 100){
		if(!strcasecmp(entrada, "do")){
			*proxEstado = 101;
		}
	}else if(estadoAtual == 101){
		if(!strcasecmp(entrada, "[")){
			*proxEstado = 102;
		}
	}else if(estadoAtual == 102){
		if(!strcasecmp(entrada, "#C")){
			*proxEstado = 103;
		}else if(!strcasecmp(entrada, "#Comando")){
			*proxEstado = 3;	
		}else if(!strcasecmp(entrada, "$") || (!strcasecmp(entrada, "]"))){
			*proxEstado = 3;
			*eReducao = true;
		}else if(!strcasecmp(entrada,  "#Declaracao")){ /* Início b1 */
			*proxEstado = 4;
		}else if(!strcasecmp(entrada,  "#Alocacao")){
			*proxEstado = 5;
		}else if(!strcasecmp(entrada,  "#Atribuicao")){
			*proxEstado = 6;
		}else if(!strcasecmp(entrada,  "#Condicional")){
			*proxEstado = 7;
		}else if(!strcasecmp(entrada,  "#Loop")){
			*proxEstado = 8;
		}else if(!strcasecmp(entrada,  "#Leitura")){
			*proxEstado = 9;
		}else if(!strcasecmp(entrada,  "#Escrita")){ /* Fim b1 */
			*proxEstado = 10;
		}else if(!strcasecmp(entrada, "declare")){ /*Inicio b2 */
			*proxEstado = 11;	
		}else if(!strcasecmp(entrada, "resize")){
			*proxEstado = 26;	
		}else if(!strcasecmp(entrada, "put")){
			*proxEstado = 55;	
		}else if(!strcasecmp(entrada, "if")){
			*proxEstado = 68;	
		}else if(!strcasecmp(entrada, "for")){
			*proxEstado = 87;	
		}else if(!strcasecmp(entrada, "foreach")){
			*proxEstado = 97;	
		}else if(!strcasecmp(entrada, "read")){
			*proxEstado = 105;	
		}else if(!strcasecmp(entrada, "print")){ /* Fim b2 && Fim b0 */
			*proxEstado = 108;	
		}
	}else if(estadoAtual == 103){
		if(!strcasecmp(entrada, "]")){
			*proxEstado = 104;
		}
	}else if(estadoAtual == 104){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 24;
			*eReducao = true;
		}
	}else if(estadoAtual == 105){
		if(!strcasecmp(entrada, "#ID")){
			*proxEstado = 106;
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 58; 	
		}
	}else if(estadoAtual == 106){
		if(!strcasecmp(entrada, ".")){
			*proxEstado = 107;
		}
	}else if(estadoAtual == 107){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 25;
			*eReducao = true;
		}
	}else if(estadoAtual == 108){
		if(!strcasecmp(entrada, "#ID")){
			*proxEstado = 109;
		}else if(!strcasecmp(entrada, "id")){
			*proxEstado = 58; 	
		}else if(!strcasecmp(entrada, "constchar")){
			*proxEstado = 111; 	
		}else if(!strcasecmp(entrada, "conststr")){
			*proxEstado = 113; 	
		}else if(!strcasecmp(entrada, "constnum")){
			*proxEstado = 115; 	
		}
	}else if(estadoAtual == 109){
		if(!strcasecmp(entrada, ".")){
			*proxEstado = 110;
		}
	}else if(estadoAtual == 110){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 26;
			*eReducao = true;
		}
	}else if(estadoAtual == 111){
		if(!strcasecmp(entrada, ".")){
			*proxEstado = 112;
		}
	}else if(estadoAtual == 112){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 28;
			*eReducao = true;
		}
	}else if(estadoAtual == 113){
		if(!strcasecmp(entrada, ".")){
			*proxEstado = 114;
		}
	}else if(estadoAtual == 114){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 27;
			*eReducao = true;
		}
	}else if(estadoAtual == 115){
		if(!strcasecmp(entrada, ".")){
			*proxEstado = 116;
		}
	}else if(estadoAtual == 116){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 28;
			*eReducao = true;
		}
	}else if(estadoAtual == 117){
		if((!strcasecmp(entrada, "$")) || (!strcasecmp(entrada, "declare")) || (!strcasecmp(entrada, "resize")) || (!strcasecmp(entrada, "put")) || (!strcasecmp(entrada, "if")) || (!strcasecmp(entrada, "for")) || (!strcasecmp(entrada, "foreach")) || (!strcasecmp(entrada, "read")) || (!strcasecmp(entrada, "print")) || (!strcasecmp(entrada, "]"))){ /* pad1 */
			*proxEstado = 2;
			*eReducao = true;
		}
	}else if(estadoAtual == 118){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-"))){ /* pad2 */
			*proxEstado = 31;
			*eReducao = true;
		}else if(!strcasecmp(entrada, "*")){
			*proxEstado = 37;
		}else if(!strcasecmp(entrada, "/")){
			*proxEstado = 38;
		}else if(!strcasecmp(entrada, "%")){
			*proxEstado = 39;
		}
	}else if(estadoAtual == 119){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-"))){ /* pad2 */
			*proxEstado = 32;
			*eReducao = true;
		}else if(!strcasecmp(entrada, "*")){
			*proxEstado = 37;	
		}else if(!strcasecmp(entrada, "/")){
			*proxEstado = 38;	
		}else if(!strcasecmp(entrada, "%")){
			*proxEstado = 39;	
		}
	}else if(estadoAtual == 120){
		if((!strcasecmp(entrada, "then")) || (!strcasecmp(entrada, "to")) || (!strcasecmp(entrada, "]")) || (!strcasecmp(entrada, "in")) || (!strcasecmp(entrada, ".")) || (!strcasecmp(entrada, ">"))  || (!strcasecmp(entrada, "<")) || (!strcasecmp(entrada, "=")) || (!strcasecmp(entrada, ">=")) || (!strcasecmp(entrada, "<=")) || (!strcasecmp(entrada, "<>")) || (!strcasecmp(entrada, "do")) || (!strcasecmp(entrada, ")")) || (!strcasecmp(entrada, "+")) || (!strcasecmp(entrada, "-")) || (!strcasecmp(entrada, "*")) || (!strcasecmp(entrada, "/")) || (!strcasecmp(entrada, "%"))){ /* pad3 */
			*proxEstado = 44;
			*eReducao = true;
		}	
	}
}

void translateReduction(int reductionNumber, int *consume, char *generate){

	switch(reductionNumber){
		case 0:
			*consume = 1;
			strcpy(generate, "#SS");
			break;
		case 1:
			*consume = 1;
			strcpy(generate, "#S");
			break;
		case 2:
			*consume = 2;
			strcpy(generate,  "#C");
			break;
		case 3:
			*consume = 0;
			strcpy(generate,  "#C");
			break;
		case 4:
			*consume = 1;
			strcpy(generate,  "#Comando");
			break;
		case 5:
			*consume = 1; 
			strcpy(generate,  "#Comando");
			break;
		case 6:
			*consume = 1; 
			strcpy(generate,  "#Comando");
			break;
		case 7:
			*consume = 1; 
			strcpy(generate,  "#Comando");
			break;
		case 8:
			*consume = 1; 
			strcpy(generate,  "#Comando");
			break;
		case 9:
			*consume = 1; 
			strcpy(generate,  "#Comando");
			break;
		case 10:
			*consume = 1; 
			strcpy(generate,  "#Comando");
			break;
		case 11:
			*consume = 5; 
			strcpy(generate,  "#Declaracao");
			break;
		case 12:
			*consume = 1; 
			strcpy(generate,  "#LIST");
			break;
		case 13:
			*consume = 3; 
			strcpy(generate,  "#LIST");
			break;
		case 14:
			*consume = 3; 
			strcpy(generate,  "#LIST");
			break;
		case 15:
			*consume = 5; 
			strcpy(generate,  "#LIST");
			break;
		case 16:
			*consume = 1; 
			strcpy(generate,  "#TIPO");
			break;
		case 17:
			*consume = 1; 
			strcpy(generate,  "#TIPO");
			break;
		case 18:
			*consume = 5; 
			strcpy(generate,  "#Alocacao");
			break;
		case 19:
			*consume = 5; 
			strcpy(generate,  "#Atribuicao");
			break;
		case 20:
			*consume = 5; 
			strcpy(generate,  "#Atribuicao");
			break;
		case 21:
			*consume = 6; 
			strcpy(generate,  "#Condicional");
			break;
		case 22:
			*consume = 10; 
			strcpy(generate,  "#Condicional");
			break;
		case 23:
			*consume = 10; 
			strcpy(generate,  "#Loop");
			break;
		case 24:
			*consume = 8; 
			strcpy(generate,  "#Loop");
			break;
		case 25:
			*consume = 3; 
			strcpy(generate,  "#Leitura");
			break;
		case 26:
			*consume = 3; 
			strcpy(generate,  "#Escrita");
			break;
		case 27:
			*consume = 3;
			strcpy(generate, "#Escrita");
			break;
		case 28:
			*consume = 3;
			strcpy(generate, "#Escrita");
			break;
		case 29:
			*consume = 3;
			strcpy(generate, "#Escrita");
			break;
		case 30:
			*consume = 1;
			strcpy(generate, "#EXPARIT");
			break;
		case 31:
			*consume = 3;
			strcpy(generate, "#EXP");
			break;
		case 32:
			*consume = 3;
			strcpy(generate, "#EXP");
			break;
		case 33:
			*consume = 1;
			strcpy(generate, "#EXP");
			break;
		case 34:
			*consume = 3;
			strcpy(generate, "#TERMO");
			break;
		case 35:
			*consume = 3;
			strcpy(generate, "#TERMO");
			break;
		case 36:
			*consume = 3;
			strcpy(generate, "#TERMO");
			break;
		case 37:
			*consume = 1;
			strcpy(generate, "#TERMO");
			break;
		case 38:
			*consume = 1;
			strcpy(generate, "#FATOR");
			break;
		case 39:
			*consume = 3;
			strcpy(generate, "#FATOR");
			break;
		case 40:
			*consume = 2;
			strcpy(generate, "#FATOR");
			break;
		case 41:
			*consume = 1;
			strcpy(generate, "#OPERANDO");
			break;
		case 42:
			*consume = 4;
			strcpy(generate, "#OPERANDO");
			break;
		case 43:
			*consume = 1;
			strcpy(generate, "#OPERANDO");
			break;
		case 44:
			*consume = 1;
			strcpy(generate, "#OPERANDO");
			break;
		case 45:
			*consume = 3;
			strcpy(generate, "#EXPREL");
			break;
		case 46:
			*consume = 1;
			strcpy(generate, "#OPREL");
			break;
		case 47:
			*consume = 1;
			strcpy(generate, "#OPREL");
			break;
		case 48:
			*consume = 1;
			strcpy(generate, "#OPREL");
			break;
		case 49:
			*consume = 1;
			strcpy(generate, "#OPREL");
			break;
		case 50:
			*consume = 1;
			strcpy(generate, "#OPREL");
			break;
		case 51:
			*consume = 1;
			strcpy(generate, "#OPREL");
			break;
		case 52:
			*consume = 1;
			strcpy(generate, "#ID");
			break;
		case 53:
			*consume = 4;
			strcpy(generate, "#ID");
			break;
		default:
			*consume = -1;
			break;
	}
}

_Bool isNonTerminal(char *Token){    
    if(Token[0] == '#')
        return true;

    return false;
}

#endif /* PARSER_FUNCS_H_ */
