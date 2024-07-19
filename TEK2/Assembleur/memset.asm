BITS 64
SECTION .text
GLOBAL memset

; memset(void *rdi, int rsi, size_t rdx)

memset:
    xor rcx, rcx ; emptying rcx
    mov rax, rdi ; compare rdx and rcx

set:
    cmp rcx, rdx ; compare rcx and rdx
    je end ; if equal jump to end
    mov [rax + rcx], sil ; move sil in [rax + rcx]
    inc rcx ; increment rcx
    jmp set ; jump to set

end:
    ret ; return rax