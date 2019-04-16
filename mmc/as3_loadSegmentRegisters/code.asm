; Name - Neel Khalade
; Roll No - 203745
; Panel Batch - Panel 1, Batch A-4

%macro rw 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .data
gdtr db  "Register GDTR"
gdtrl equ $-gdtr

idtr db "Register IDTR"
idtrl equ $-idtr

ldtr db "Register LDTR"
ldtrl equ $-ldtr

tr db "Task Register"
trl equ $-tr

msw db "MSW Register"
mswl equ $-msw

limit db "Limit"
limitl equ $-limit

newline db 10

section  .bss
nerdion resb 8
nerd resb 2
temp resb 1

section .text
global  _start
_start:

;GDTR
rw 1,1,gdtr,gdtrl
rw 1,1,newline,1
mov esi,nerdion
sgdt [esi]
mov rax,[esi]
call display64
rw 1,1,newline,1

;GDTRLIMIT
rw 1,1,limit,limitl
rw 1,1,newline,1
mov esi,nerd
mov ax,[esi]
call display16
rw 1,1,newline,1

;IDTR
rw 1,1,idtr,idtrl
rw 1,1,newline,1
mov esi,nerdion
sidt [esi]
mov rax,[esi]
call display64
rw 1,1,newline,1

;IDTRLIMIT
rw 1,1,limit,limitl
rw 1,1,newline,1
mov esi,nerd
mov ax,[esi]
call display16
rw 1,1,newline,1

;TR
rw 1,1,tr,trl
rw 1,1,newline,1
mov esi,nerd
str [esi]
mov ax,[esi]
call display16
rw 1,1,newline,1

;MSW
rw 1,1,msw,mswl
rw 1,1,newline,1
mov esi,nerd
smsw [esi]
mov ax,[esi]
call display16
rw 1,1,newline,1

rw 60,0,0,0

display64:
mov bp,16
up:
rol rax,4
mov rbx,rax
and rax,0FH
cmp rax,09H
jbe down
add rax,07H
down:
add rax,30H
mov byte[temp],al
rw 1,1,temp,1
mov rax,rbx
dec bp
jnz up
ret

display16:
mov bp,4
up2:
rol ax,4
mov bx,ax
and ax,0FH
cmp ax,09H
jbe down2
add ax,07H
down2:
add ax,30H
mov byte[temp],al
rw 1,1,temp,1
mov ax,bx
dec bp
jnz up2
ret

;OUTPUT
;Register GDTR
;FE000002D000007F
;Limit
;FFFF
;Register IDTR
;FE00000000000FFF
;Limit
;FFFF
;Task Register
;0040
;MSW Register
;0033

