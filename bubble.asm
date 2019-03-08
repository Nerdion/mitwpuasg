section .data

arr db 9ch,8dh,75h,64h,23h;


section .text
global _start
_start:

mov cl,5
outer:
mov bl,4
mov esi,arr

inner: 
mov al,[esi]
cmp al,[esi+1]
jbe next

xchg al,[esi+1]
mov [esi],al

next:
dec bl
inc esi
jnz inner

dec cl
jnz outer

mov rax,1
mov rdi,0
syscall
