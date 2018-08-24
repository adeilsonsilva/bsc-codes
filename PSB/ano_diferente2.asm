; file: ano_diferente2.asm
;
; Using Linux and gcc:
; nasm -f elf ano_diferente2.asm
; gcc -o ano_diferente2 ano_diferente2.o driver.c asm_io.o

%include "asm_io.inc"
;
; initialized data is put in the .data segment
;
segment .data
;
;
prompt1 db    "Digite um numero: ", 0       ; don't forget nul terminator
vet dd 0, 0, 0, 0
pos dd 0
;
; uninitialized data is put in the .bss segment
;
segment .bss
;
; These labels refer to double words used to store the inputs
;
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
	dec	dword [num]


      LP1:
	mov	eax, [num]
	jmp	DIVISOES
      FIMLOOP:
	mov	ecx, [num]
	dec	dword [num]
	loop	LP1


      DIVISOES:
	mov	ecx, 4
	mov	ebx, 10
	mov	[pos], ebx
	mov	ebx, 0
      LP2:	
	mov	edx, 0
	div	dword [pos]
	mov	[vet + 4*ebx], edx
	inc	ebx
	loop	LP2	
	

      CMPOS1:
	mov	eax, [vet]
	mov	ecx, 3
	mov	ebx, 1
      LP3:
	cmp	eax, [vet + 4*ebx]
	jz	FIMLOOP
	inc	ebx
	loop	LP3 

      CMPOS2:
	mov	eax, [vet + 4]
	mov	ecx, 2
	mov	ebx, 2
      LP4:
	cmp	eax, [vet + 4*ebx]
	jz	FIMLOOP
	inc	ebx
	loop	LP4

      CMPOS3:
	mov	eax, [vet + 8]
	cmp	eax, [vet + 12]
	jz	FIMLOOP


      ACHOU:
	mov	eax, [vet + 12]
	call	print_int
	mov	eax, [vet + 8]
	call	print_int
	mov	eax, [vet + 4]
	call	print_int
	mov	eax, [vet]
	call	print_int
	call	print_nl

        leave                     
        ret
