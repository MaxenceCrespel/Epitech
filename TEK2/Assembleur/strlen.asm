BITS 64
SECTION .text
GLOBAL strlen

; strlen(const char *rdi)

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