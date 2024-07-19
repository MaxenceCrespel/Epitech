BITS 64
SECTION .text
GLOBAL strrchr

; strrchr(const char *rdi, int sil)

strlen:
    xor rcx, rcx ; emptying rcx

check_char:
    mov al, [rdi + rcx] ; move [rdi + rcx] in al
    cmp al, 0 ; compare al to 0 (null terminator)
    je strlen_end ; if equal jump to end
    inc rcx ; increment rcx
    jmp check_char ; jump to compare

strlen_end:
    mov rax, rcx ; move rcx in rax
    ret ; return rax

strrchr:
    xor rax, rax ; emptying rax
    mov rcx, -1 ; move -1 in rcx
    call strlen ; call strlen function
    dec rcx ; decrement rcx

find:
    mov r11b, [rdi + rcx] ; move [rdi + rcx] in r11b
    cmp r11b, sil ; compare r11b with sil
    je found ; if equal jump to found
    dec rcx ; decrement rcx
    cmp rcx, -1 ; compare rcx to -1 (start of string)
    jge find ; if greater than or equal jump to find

not_found:
    xor rax, rax ; set rax to 0
    ret ; return rax

found:
    cmp rcx, -1 ; compare rcx and -1
    je not_found ; if equal jump to not_found
    add rdi, rcx ; add rcx to rdi
    mov rax, rdi ; move rdi in rax
    ret ; return rax