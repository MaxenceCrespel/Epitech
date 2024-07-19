BITS 64
SECTION .text
GLOBAL memmove

; memmove(void *rdi, const void *rsi, size_t rdx)

memmove:
    xor rcx, rcx; emptying rcx
    mov r13, rsi ; move rsi in r13

copy:
    cmp rdx, rcx ; compare rdx and rcx
    je end ; if equal jump to end
    mov al, [r13 + rcx] ; move [r13 + rcx] in al
    mov [rdi + rcx], al ; move al in [rdi + rcx]
    inc rcx ; inc rcx
    jmp copy ; jump to copy

end:
    mov rax, rdi ; move rdi in rax
    ret ; return rax