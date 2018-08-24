; UNIVERSIDADE FEDERAL DA BAHIA
; INSTITUTO DE MATEMÁTICA
; DEPARTAMENTO DE CIÊNCIA DA COMPUTAÇÃO
; MATA49 - PROGRAMAÇÃO DE SOFTWARE BÁSICO, TURMA 01
; PROFESSOR: LEANDRO ANDRADE
; ALUNO: ADEILSON SILVA
; TRABALHO PRÁTICO 01
;
;
; File: trab01.asm
;
;
; Using Linux and gcc:
; nasm -f elf trab01.asm
; gcc -o trab01 trab01.o driver.c asm_io.o
;
;
%include "asm_io.inc"
;
segment .data
;
menorNumBuracos dd	300
;
segment .bss
;
numPilares	resd	1
numPontes	resd	1
vetorEntrada	resd	300
;
segment .text
        global  asm_main
asm_main:
;
;Início do programa
;;;Leitura do número de Pilares e Pontes
;
	call	read_int
	mov	[numPilares], eax
	call	read_int
	mov	[numPontes], eax
;
;;;Leitura das conexões entre Pilares e Pontes
;
	mov	ecx, [numPontes]  ;Controle do Loop (quantidade de linhas a serem lidas)
	inc	dword [numPilares];O número da folha da árvore (último pilar) é nº de pilares+1
	mov	edi, vetorEntrada ;Vetor que armazenará cada linha da entrada
	cld
      LE_CONEXAO:
	call	read_int   	  ;Lê o nº do pilar
	stosd		   	  ;Armazena no vetor
	call	read_int   	  ;Lê o nº do próximo pilar
	stosd		   	  ;Armazena no vetor
	call	read_int   	  ;Lê o número de buracos
	stosd		   	  ;Armazena no vetor
	loop	LE_CONEXAO
;
;;;Percurso pelo vetor pra achar a resposta
;
	mov	esi, vetorEntrada	
	mov	ebx, 0		  ;O numero de buracos começa com 0
	mov	edx, 0		  ;Primeiro pilar a ser pesquisado
	mov	ecx, 300
	push	esi
	push	ebx
	call 	percorreCaminho
	pop	ebx
	pop	esi

	mov	eax, [menorNumBuracos]
	call	print_nl
	call	print_int	  ;Saída com a resposta do número de buracos
	call	print_nl	
;
;
;Fim do programa
;
	leave
	ret
;
;;;;;;;;;;;;;;;;;;;;;; SUBROTINAS ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
percorreCaminho:
	enter 0,0
	mov	ebx, [ebp+8]	  ;Move pra ebx o numero de buracos	
	mov	esi, [ebp+12]	  ;Move pra esi o endereço da posição atual
	cld

      INICIO:
	cmp	esi, edi	  ;Verifica se o vetor
	jz FIM			  ;está no final
	push	edx
	push	ecx
	lodsd
	cmp	eax, edx	  ;Compara o valor que estava no vetor com o do registrador que guarda o numero do pilar pesquisado
	jne	FIM_LOOP

	lodsd	
	mov	edx, eax	  ;Move para edx o numero do próximo pilar a ser pesquisado	
	lodsd			  ;Move para registrador o numero de buracos a ser adicionado	  
	add	ebx, eax	  ;Incrementa numero de buracos

	push	esi
	push	ebx

      TESTE_FOLHA:
	cmp	edx, [numPilares] ;Compara o valor do pilar com o numero da folha
	jz	FOLHA

	call	percorreCaminho
	pop	ebx		  ;Controle da volta da recursão, pra que ele passe por todas as possibilidades
	pop	esi
	jmp	FIM_LOOP_NAO_ATUALIZA

      FIM_LOOP:	
	add	esi, 8		  ;Atualiza o valor de esi(lembre-se que a cada três posições do vetor, temos uma linha da entrada)
      FIM_LOOP_NAO_ATUALIZA:	
	pop	ecx
	pop	edx
	loop	INICIO
	jmp	FIM

      FOLHA:
	pop	ebx		  ;Desempilha número de buracos
	pop	esi		  ;Desempilha endereço de memoria da posição que devemos ir
	pop	ecx
	pop	edx
	cmp	ebx, [menorNumBuracos]
	jnc	FIM
	mov	[menorNumBuracos], ebx	

      FIM:
	leave
	ret
;
