BITS 64
SECTION .text
GLOBAL strcspn

; strcspn(const char *rdi, const char *rsi)

strcspn:
    xor rax, rax ; emptying rax
    xor rcx, rcx ; emptying rcx
    xor rdx, rdx ; emptying rdx

loop:
    xor rdx, rdx ; emptying rdx
    movzx r10d, BYTE [rdi + rcx] ; move [rdi + rcx] in r10d
    inc rcx ; increment rcx
    cmp r10d, 0 ; compare r10d with 0(null terminator)
    je not_found ; if equal jump to not_found

search:
    movzx r11d, BYTE [rsi + rdx] ; move [rsi + rdx] in r11d
    cmp r11d, 0 ; compare r11d with 0(null terminator)
    je loop ; if equal jump to loop
    cmp r10d, r11d ; compare r10d with r11d
    je found ; if equal jump to found
    inc rdx ; increment rdx
    jmp search ; jump to search

found:
    sub rcx, 1 ; sub 1 to rcx
    mov rax, rcx ; move rdi in rax
    ret ; return rax

not_found:
    call strlen ; execute strlen
    ret ; return rax

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