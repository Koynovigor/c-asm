global print_fact

section .text

print_fact:

    push ebp
    mov ebp, esp

    push ebx
    push ecx
    push edx
    push edi
    
    mov edi, [ebp+12]

    mov eax, [ebp+8]
    cmp eax, 1
    je .exit
    mov ebx, 2

    .cycle:
        mov ecx, eax
        xor edx, edx
        div ebx
        cmp edx, 0
        je .resume
        
        mov eax, ecx
        inc ebx
        jmp .cycle

    .resume:
        push eax
        push ebx
        call edi
        add esp, 4
        pop eax
        cmp eax, 1
        jne .cycle 

    .exit:
        pop edi
        pop edx
        pop ecx
        pop ebx
        pop ebp
        ret