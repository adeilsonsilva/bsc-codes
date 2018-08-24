

;
; file: ano_diferente.asm
; First assembly program. This program asks for two integers as
; input and prints out their sum.
;
; Using Linux and gcc:
; nasm -f elf ano_diferente.asm
; gcc -o ano_diferente ano_diferente.o driver.c asm_io.o

%include "asm_io.inc"
;
; initialized data is put in the .data segment
;
segment .data
;
;
prompt1 db    "Digite um numero: ", 0       ; don't forget nul terminator
;
; uninitialized data is put in the .bss segment
;
segment .bss
;
; These labels refer to double words used to store the inputs
;
vet  resd 4
num  resd 1

;
; code is put in the .text segment
;
segment .text
        global  asm_main
asm_main:
      
        mov     eax, prompt1
        call    print_string
        
	call	read_int
	mov	[num], eax

	cmp	eax, 10000
	jz	DEZMIL
	

      CMP_MAIN:
	cmp	eax, 1000
	jnc     DIVMIL
	cmp	eax, 100
	jnc	DIVCEM
	cmp	eax, 10
	jnc	DIVDEZ

       

      DEZMIL:
	sub 	eax, 1
	jmp 	CMP_MAIN

      DIVMIL:
	div 	eax, 1000
	mov 	[vet], eax
	mov	eax, edx
	jmp 	CMP_MAIN

      DIVCEM:
	div 	eax, 100
	mov 	[vet + 4], eax
	mov	eax, edx
	jmp 	CMP_MAIN

      DIVDEZ:
	div 	eax, 10
	mov	[vet + 8], eax
	mov	[vet + 12], edx
	jmp 	CMP_MAIN

      CMPOS1:

      CMPOS2:

      CMPOS3:
            


        leave                     
        ret

