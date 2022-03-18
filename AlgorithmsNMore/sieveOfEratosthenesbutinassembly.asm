section .data
    array dd 2, 3, 4 ,5 ,6 ,7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 , 23, 24, 25, 26, 27, 28, 29
section .text
global _start
_start:
    mov esi, 28
    mov ecx, 0
mainLoop:
    cmp ecx, esi
    je exit
    mov edx, [array+4*ecx]
    cmp edx, 0
    je continue
    mov eax, edx
    push edx
    mul eax
    cmp eax, esi
    jg exit
    pop edx
    mov eax, edx
    call iprint
    sub eax, 2
removeMultiplies:
    cmp eax, esi
    jge continue
    mov dword[array+eax*4], 0
    add eax, edx
    jmp removeMultiplies
continue:
    inc ecx
    jmp mainLoop

exit:
    mov ecx, 0
printEl:
    cmp ecx, esi
    je quit
    mov eax, [array+4*ecx]
    cmp eax, 0
    je continuePrinting
    call iprint
continuePrinting:
    inc ecx
    jmp printEl

quit:
    mov eax, 10
    push eax
    mov eax, esp
    call print
    mov eax, 1
    mov ebx, 0
    int 0x80


print:
    push eax
    push ebx
    push ecx
    push edx

    mov ecx, eax
    call strlen
    mov edx, eax
    mov eax, 4
    mov ebx, 2
    int 0x80

    pop edx
    pop ecx
    pop ebx
    pop eax
    ret

strlen:
    push ebx
    mov ebx, eax
.looop:
    cmp byte[eax], 0
    je .finish
    inc eax
    jmp .looop
.finish:
    sub eax, ebx
    pop ebx
    ret

iprint:
    push eax
    push ecx
    push edx
    push esi
    mov ecx, 0
.divide:
    inc ecx
    mov edx, 0
    mov esi, 10
    idiv esi
    add edx, 48
    push edx
    cmp eax, 0
    jne .divide
.print:
    dec ecx
    mov eax, esp
    call print
    pop eax
    cmp ecx,0
    je .finish
    jmp .print
.finish:
    mov eax, 32
    push eax
    mov ecx, esp
    mov edx, 1
    mov eax, 4
    mov ebx, 1
    int 0x80
    pop eax
    
    pop esi
    pop edx
    pop ecx
    pop eax
    ret
