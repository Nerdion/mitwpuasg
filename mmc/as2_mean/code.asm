%macro rw 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .data
divisor dd 5.0
arr dd 12.32,15.66,33.12,45.43,76.34
mean dt 0.0
mult dd 10000.0
count1 db 10
count2 db 2
mydot db '.'

section .bss
temp resb 1

section .text
global _start
_start:

;initializing array and counter
mov cl,5
mov esi,arr
;loading stack
FLDZ

;addition of elements
addnext:
FADD dword[esi]
add esi,4
dec cl
jnz addnext

;dividing with top stack, i.e. sum with 5
FDIV dword[divisor]

FMUL dword[mult]

;getting the mean
FBSTP tword[mean]

mov rbp,mean
add rbp,9h

upmain:
mov bh,byte[rbp]
mov byte[count2],2
cmp byte[count1],2
 
jne notdot
rw 1,1,mydot,1
notdot:
up:
rol bh,4
mov bl,bh

and bh,0Fh

cmp bh,09h
jbe down
add bh,07h
down:
add bh,30h

mov byte[temp],bh
rw 1,1,temp,1

mov bh,bl
dec byte[count2]
jnz up


dec rbp
dec byte[count1]

jnz upmain

mov rax,60
mov rdx,0
syscall


