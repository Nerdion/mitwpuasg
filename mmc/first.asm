section .data
arr1 db 15h,03h,05h,35h,50h


section .bss


section .text
global _start
_start:


mov ch,05h
outer:
mov esi,arr1
mov cl,04h

inner :
mov al,byte[esi]
cmp al,byte[esi+1]
jbe down

xchg al,byte[esi+1]
mov byte[esi],al
down:
inc esi
dec cl
jnz inner

dec ch
jnz outer

mov rax,60
mov rdi,0
syscall


