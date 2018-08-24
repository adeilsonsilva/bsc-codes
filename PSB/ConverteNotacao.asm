;file: ConverteNotacao.asm
;
;Converte expressão de notação infixa para posfixa
;
; Using Linux and gcc:
; nasm -f elf ConverteNotacao.asm
; gcc -o ConverteNotacao ConverteNotacao.o driver.c asm_io.o
;
;
%include "asm_io.inc"
;
;
segment .data
;
atual	db '0'
tmp	dd 0
cont	dd 0
;
segment .bss
;
vetor	resb 20
vetor2	resb 20
;
segment .text
;
        global  asm_main
asm_main:
	mov	edi, vetor
	mov	ecx, 20
	cld
      LP1:
	call	read_char
	cmp	al, '0'
	je	INICIO_CONVERSAO
	stosb
	inc	dword [cont]
	loop LP1

INICIO_CONVERSAO:

	mov	ecx, 20
	mov	esi, vetor
	mov	edi, vetor2
	cld
      LP2:
	mov	[tmp], ecx
	lodsb
	cmp	al, '('
	jne	nao_parenteses
	movzx	eax, al
	push	eax
	jmp	FIM_LOOP

      nao_parenteses:
	cmp	al, '+'
	jne	nao_soma
	movzx	eax, al
	push	eax
	jmp	FIM_LOOP

      nao_soma:
	cmp	al, '-'
	jne	nao_subtracao
	movzx	eax, al
	push	eax
	jmp	FIM_LOOP

      nao_subtracao:
	cmp	al, ')'
	jne	letra
	mov	ecx, 10
	  LP4:
		pop	eax
		cmp	al, '('
		je	FIM_LOOP
		stosb
		loop	LP4
      letra:
	stosb

      FIM_LOOP:
	mov	ecx, [tmp]
	loop	LP2	

	mov	ecx, [cont]
	mov	esi, vetor2
	cld
      LP3:
	lodsb
	call	print_char
	loop	LP3

	call	print_nl


	leave
	ret	
