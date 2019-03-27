section .data						;data section
arr1 db 9bh,03h,05h,35h,50h		;source array


section .bss						;dynamic section
arr2 resb 15						;destination array

section .text						;coding section
global _start
_start:

									; logic for sorting the array
mov ch,05h						;doing it by bubble sort
outer:								; outer bubble sort loop
mov esi,arr1
mov cl,04h

inner :								; inner bubble sort loop
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


mov esi,arr1						;logic for unpacking the values
mov edi,arr2


mov bh,05

ott:								; lopping through the next value in array
mov al,byte[esi]
mov cx,02

inn:								; checking the next digit in the array
rol al,4h
mov bl,al
and al,0fh
cmp al,09h
jbe greater
add al,07h
greater:
add al,30h
mov byte[edi],al
inc edi
mov al,bl
dec cx
jnz inn

mov byte[edi],20h
inc esi
inc edi
dec bh
jnz ott



mov rax,1						; displaying the data
mov rdi,1
mov rsi,arr2
mov rdx,15
syscall

mov rax,60					;ending the program
mov rdi,0
syscall



