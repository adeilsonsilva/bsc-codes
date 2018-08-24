;file: soma_int.asm
;Soma de dois inteiros utilizando interrupções
;Para compilar:
; nasm -f elf soma_int.asm
; ld -s -o soma_int soma_int.o
;
;
segment .bss 
;
num resb 4
num2 resb 4
aux1 resw 1
aux2 resw 1
resp resb 4
;
segment .text
	global _start
	_start:

;Leitura dos numeros      
	mov	eax, 3
	mov	ebx, 0
	mov	ecx, num
	mov	edx, 4
	int	0x80
	
	mov	eax, 3
	mov	ebx, 0
	mov	ecx, num2
	mov	edx, 4
	int	0x80

;Conversão para inteiro	
	mov	esi, num
	lodsb
	sub	eax, 48
       	imul	eax, 100
	mov	[aux1], eax

	lodsb
	sub	eax, 48
	imul	eax, 10
	add	[aux1], eax

	lodsb
	sub	eax, 48
	add 	[aux1], eax	
	
	mov	esi, num2
	lodsb
	sub	eax, 48
	imul	eax, 100
	mov	[aux2], eax

	lodsb
	sub	eax, 48
	imul	eax, 10
	add	[aux2], eax

	lodsb
	sub	eax, 48
	add 	[aux2], eax

;Soma dos números
	mov	eax,[aux1]
	add	eax, [aux2]
	mov	[resp], eax

;Conversão para string

	mov	eax, 4
	mov	ebx, 1
	mov	ecx, resp
	mov	edx, 1
	int	80h

;Fim do programa
	mov	eax, 1
	mov	ebx, 0
	int 	80h		
