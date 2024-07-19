BITS 64
SECTION .text
GLOBAL strstr

; strstr(const char *rdi, const char *rsi)

strstr:
push rbp ; push rbp to stack
mov rbp, rsp ; move rsp in rbp
jmp check_start ; jump to check_start

loop_start:
inc rdi ; increment rdi

check_start:
mov al, [rdi] ; move [rdi] in al
cmp al, 0 ; compare al to 0 (null terminator)
je fail ; if equal jump to fail
mov al, [rsi] ; move [rsi] in al
xor rcx, rcx ; emptying rcx
jmp check ; jump to check

check:
mov al, [rdi + rcx] ; move [rdi + rcx] in al
mov r8b, [rsi + rcx] ; move [rsi + rcx] in r8b
cmp r8b, 0 ; compare r8b with 0 (null terminator)
jz success ; if equal to zero jump to success
cmp al, r8b ; compare al with r8b
jne loop_start ; if not equal jump to loop_start
inc rcx ; increment rcx
jmp check ; jump back to check

success:
mov rax, rdi ; move rdi in rax
jmp finish ; jump to finish

fail:
xor rax, rax ; emptying rax

finish:
mov rsp, rbp ; move rbp in rsp
pop rbp ; pop back rbp from stack
ret ; return rax