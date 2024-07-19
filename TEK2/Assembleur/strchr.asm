BITS 64
SECTION .text
GLOBAL strchr

; strchr(const char *rdi, int sil)

strchr:
    xor rax, rax ; emptying rax
    xor rbx, rbx ; emptying rbx

search:
    mov al, [rdi + rbx] ; move [rdi + rbx] in al
    cmp al, sil ; compare al and sil
    je found ; if equal jump to found
    cmp al, 0 ; compare al and 0 (null terminator)
    je not_found ; if equal jump to not_found
    inc rbx ; increment rbx
    jmp search ; jump to search

found:
    add rdi, rbx ; add rbx to rdi
    mov rax, rdi ; move rdi in rax
    ret ; return rax

not_found:
    xor rax, rax ; set rax to 0
    ret ; return rax