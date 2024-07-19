BITS 64
SECTION .text
GLOBAL strpbrk

; strpbrk(const char *rdi, const char *rsi)

strpbrk:
    xor rax, rax ; emptying rax
    xor rcx, rcx ; emptying rcx
    xor rdx, rdx ; emptying rdx

loop:
    xor rdx, rdx ; emptying rdx
    movzx r10d, BYTE [rdi + rcx] ; move [rdi + rcx] in r10d
    inc rcx ; increment rcx
    cmp r10d, 0 ; compare r10d with 0(null terminator)
    je not_found ; if not equal jump to not_found

search:
    movzx r11d, BYTE [rsi + rdx] ; move [rsi + rdx] in r11d
    cmp r11d, 0 ; compare r11d with 0(null terminator)
    je loop ; if equal jump to loop
    cmp r10d, r11d ; comapre r10d with r11d
    je found ; if equal jump to found
    inc rdx ; increment rdx
    jmp search ; jump back to search

found:
    sub rcx, 1 ; sub 1 to rcx
    add rdi, rcx ; add rcx to rdi
    mov rax, rdi ; move rdi in rax
    ret ; return rax

not_found:
    xor rax, rax ; set rax to 0
    ret ; return rax