;
; file: fibonacci.asm
; 
; Using Linux and gcc:
; nasm -f elf fibonacci.asm
; gcc -o fibonacci fibonacci.o driver.c asm_io.o
;
%include "asm_io.inc"
;
segment .data
;
saida1 db    "Digite um numero: ", 0
saida2 db    "Resposta: ", 0   
;
segment .bss
;
num1 resd 1
;
;
;
;
segment .text
        global asm_main
asm_main:

   mov eax, saida1
   call print_string
   call read_int
   mov [num1], eax
   mov ecx, [num1]
   mov eax, 0
   mov ebx, 1

   cmp eax, ecx
   jz SAIDA

   CALC:
     mov edx, eax
     add eax, ebx
     mov ebx, edx
     loop CALC

   SAIDA:
     mov ecx, eax
     mov eax, saida2
     call print_string
     mov eax, ecx
     call print_int
     call print_nl

   leave
   ret
