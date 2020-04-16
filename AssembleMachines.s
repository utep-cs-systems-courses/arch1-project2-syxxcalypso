	.arch msp430g2553
	.p2align 1,0


	.text
	.global update	;; visible to other object files
jt:
	.word default
	.word case1
	.word case2

update:	
	mov.b &0x0021, r13		;; move s into r12
	cmp #3, r1		;; if state > 3, !borrow 
	jnc default

	add r13, r13		;;index r12 entries. 2 bytes get the offset bytes in table
	mov jt(r13),r0		;;r12: address of the entry, move to program counter

case1:
	mov.b #0, r12		;;led-red
	call #set_red	
	mov.b #1, r12
	call #set_green	
	jmp end		

case2:			
	mov.b #0, r12
	call #set_green
	mov.b #1, r12
	call #set_red
	jmp end	

default:
	mov.b #1, r12
	call #set_green
	jmp end
end:
	pop r0	
