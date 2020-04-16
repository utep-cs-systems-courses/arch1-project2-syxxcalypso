	.arch msp430g2553
	.p2align 1,0

	.data
s:
	.word 0

.text
	.global update	;; visible to other object files
jt:
	.word default
	.word case1
	.word case2

update:	
				;;mov.b &0x0021, r13	
	mov.b s, r13
	;;cmp #3, r13		 
	jnc default

	add r13, r13		
	mov jt(r13),r0		

case1:
	mov.b #0, r12		;;led-red
	call #set_green	
	mov.b #1, r12
	call #set_red
	mov.b #2, s
	jmp end		

case2:		
	mov.b #1, r12
	call #set_green
	mov.b #0, r12
	call #set_red
	mov.b #1, s
	jmp end	

default:

	mov.b #1, r12
	call #set_green
	mov.b #1, r13
	mov.b r13, s
	jmp end

end:
	pop r0	
