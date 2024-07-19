BITS 64
SECTION .text
GLOBAL strncmp

; strncmp(const char *rdi, const char *rsi, size_t rdx)

strncmp:
    xor rcx, rcx ; emptying rcx

compare:
    mov al, [rdi + rcx] ; move [rdi + rcx] in al
    mov bl, [rsi + rcx] ; move [rsi + rcx] in bl
    cmp al, 0 ; compare al to 0 (null terminator)
    je end ; if equal jump to end 
    cmp bl, 0 ; compare bl to 0 (null terminator)
    je end ; if equal jump to end
    cmp al, bl ; compare al to bl
    jne end ; if not equal jump to end
    inc rcx ; increment rcx
    jmp compare ; jump to compare

end:
    sub al, bl ; sub bl to al
    movsx rax, al ; move al in a bigger memory (64) rax
    ret ; return rax