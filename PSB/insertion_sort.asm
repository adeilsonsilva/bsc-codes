; file: is.asm
; Insertion Sort;
;
; Using Linux and gcc:
; nasm -f elf is.asm
; gcc -o is is.o driver.c asm_io.o
;
%include "asm_io.inc"
;
;
;
segment .data
;
cont	dd 1
espaco	db " ", 0
;
segment .bss
;
num	resd 1
vetor	resd 10
;
segment .text
        global  asm_main	
asm_main:

;leitura dos dados e preenchimento do vetor

	mov	ecx, 10
	mov	esi, vetor
	mov	edi, vetor
	cld
      LP1:
	call	read_int
	stosd
	loop LP1

;inicio das comparações

	mov	ecx, 10
	mov	esi, vetor
	mov	edi, vetor
	cld
      LOOP_POS:                ;loop crescente
	cld		       ;
	mov	edi, esi       ;
	lodsd		       ;
	push	edi	       ;não sei se é necessário empilhar o edi
	push	esi 	       ;
	sub	esi, 4	       ;voltar o esi à posição antes da leitura com o lodsd
	push	ecx            ;
	mov	ecx, [cont]    ;
	  		       ;
          LOOP_CMP:            ;loop decrescente, comparando cada posição com seus anteriores
	    std 	       ;
            scasd	       ;
	    jnc	   MAIOR_IGUAL ; 
	    mov	   ebx, eax    ; Não entendi exatamente o porquê
	    add    edi, 4      ; mas fazendo essas substituições
	    mov    esi, edi    ; o programa funciona e não dá segmentation fault
	    lodsd	       ;
	    add    edi, 4      ; 
	    stosd              ; A movimentação dos ponteiros está confusa
	    mov    eax, ebx    ; mas a troca dos dados está funcionando
	    stosd              ;
	   MAIOR_IGUAL:        ;
	     loop   LOOP_CMP   ;
	
        pusha
	call   printa_vetor
	popa

	pop	ecx  
	pop	esi
	pop	edi  
	inc	dword [cont]
        loop	LOOP_POS 

	leave                     
        ret

	global printa_vetor
printa_vetor:
	mov	esi, vetor
	cld
	mov	ecx, 10
      
      LOOP5:
	lodsd
	call	print_int
	mov	eax, espaco
	call	print_string
	loop	LOOP5

	call	print_nl

	ret