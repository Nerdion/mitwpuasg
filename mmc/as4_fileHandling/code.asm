%macro rw 4
    mov rax,%1
    mov rdi,%2
    mov rsi,%3
    mov rdx,%4
    syscall
%endmacro

section .data
     newl db 10

section .bss                                 
    buff resb 512
    buff_len resq 1
    fhandle resq 1
    temp resb 1
    fname1 resb 15
    fname2 resb 15

section .text
    global _start
    _start:
;DISPLAY  SOURCE
    pop r8
    pop r8
    pop r8
    mov esi,fname1
up1:mov al,[r8]
    cmp al , 00
    je next1
    mov [esi],al
    inc r8
    inc esi
    jmp up1

    

next1: 
    rw 1,1,fname1,15
    rw 1,1,newl,1
					;displaying file on monitor
    
    rw 2,fname1,000000q,0777q       	;open
    
    mov [fhandle],rax
    mov rbx,rax
    rw 0,rbx,buff ,511                  ;read
    
    mov [buff_len],rax
    rw 1,1,buff,[buff_len]              ;display
    rw 3,[fhandle],0,0

;DISPLAY  DEST  FILE 
    pop r8
    mov edi,fname2
up2:mov al,[r8]
    cmp al , 00
    je next2
    mov [edi],al
    inc r8
    inc edi
    jmp up2
next2: 
    rw 1,1,fname2,15
    rw 2,fname2,40h,0777q    	       ;create
    rw 2,fname2,2,0777q                ;open des file
    mov [fhandle],rax
    mov rbx,rax
    rw 1,rbx,buff ,[buff_len]
    rw 1,1,newl,1
    rw 1,1,buff,[buff_len]             ;display
    rw 3,[fhandle],0,0



rw 60,0,0,0

