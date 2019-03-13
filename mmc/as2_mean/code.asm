section .data
divisor dd 5.0
arr dd 12.32,15.66,33.12,45.43,76.34
mean dd 0

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

;getting the mean
;FBSTP dword[mean]

mov rax,60
mov rdx,0
syscall

