BITS 64
SECTION .text
GLOBAL memcpy

; memcpy(void *rdi, const void *rsi, size_t rdx)

memcpy:
	xor rcx, rcx ; emptying rcx

copy:
	cmp rdx, rcx ; compare rdx and rcx
	jle decrement_rdi ; if less or equal jump to decrement_rdi
 	mov r10b, BYTE [rsi + rcx] ; move [rsi + rcx] in r10b
 	mov [rdi], r10b ; move r10b in [rdi]
	inc rdi ; increment rdi
	inc rcx ; increment rcx
	jmp copy ; jump to copy

decrement_rdi:
	cmp rcx, 0 ; compare rcx and 0 (null terminator)
	je end ; if equal jump to end
	dec rdi ; decrement rdi
	dec rcx ; decrement rcx
	jmp decrement_rdi ; jump to decrement rdi

end:
	mov rax, rdi ; move rdi in rax
	ret ; return rax