BITS 64
SECTION .text
GLOBAL strcasecmp

; strcasecmp(const char *rdi, const char *rsi)

strcasecmp:
    xor rcx, rcx ; empty rcx

compare:
    mov al, [rdi + rcx] ; move the value at [rdi + rcx] to al
    mov bl, [rsi + rcx] ; move the value at [rsi + rcx] to bl
    cmp al, 0 ; compare al to 0 (null terminator)
    je end ; if equal, jump to end
    cmp bl, 0 ; compare bl to 0 (null terminator)
    je end ; if equal, jump to end
    or al, 32 ; convert the character in al to lowercase if it is uppercase
    or bl, 32 ; convert the character in bl to lowercase if it is uppercase
    cmp al, bl ; compare the two characters
    jne end ; if not equal, jump to end
    inc rcx ; increment rcx
    jmp compare ; jump back to compare

end:
    sub al, bl ; subtract bl from al
    movsx rax, al ; move the result to a larger register rax
    ret ; return rax
