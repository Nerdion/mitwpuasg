%macro opr 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .data

section .bss

buff resb 512
buff_len resq 1
fhandle resq 1
temp resb 1
fname1 resb 15
fname2 resb 15

section .text
global  _start
_start:

pop r8
pop r8
pop r8

mov esi,fname1
up:
mov al,[r8]
cmp al,00
je next
mov [esi],al
inc r8
inc esi
jmp up
next:
opr 1,1,fname1,15

pop r8

mov esi,fname2
up2:
mov al,[r8]
cmp al,00
je next2
mov [esi],al
inc r8
inc esi
jmp up2
next2:
opr 1,1,fname2,15

mov rax,60
mov rdi,0
syscall

