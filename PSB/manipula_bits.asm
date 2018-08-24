;
; file: manipula_bits.asm
;
; Using Linux and gcc:
; nasm -f elf manipula_bits.asm
; gcc -o manipula_bits manipula_bits.o driver.c asm_io.o
;
; 

%include "asm_io.inc"
;
;
segment .data
;
;
prompt1 db    "Digite o numero: ", 0     
outmsg1 db    "Saida: ", 0
;
;
segment .bss
;
;
input1  resw 1


;
;
segment .text
        global  asm_main
asm_main:

        mov     eax, prompt1      
        call    print_string

        call    read_int         
        mov     ebx, eax    

        mov     ecx, 16
        shl     ebx, 16
        

        
        L1:
          shl  ebx, 1
          jnc   bit0
          jc    bit1
        
            bit1:
              mov eax, 1
              call print_int
              jmp  Ctrl
		
            bit0:
              mov eax, 0
              call print_int
              jmp  Ctrl

         Ctrl:   
          loop L1         
         

        call print_nl
        leave                     
        ret
