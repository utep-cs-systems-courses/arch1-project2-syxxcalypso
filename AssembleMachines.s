	.arch msp430g2553
	.p2align 1,0


	.text
	.global update_leds	;; visible to other object files
JT:
	.word default
	.word case1
	.word case2

update_leds:	
	mov.b &0x0021, r12		;; move s into r12
	cmp #3, r1		;; if state > 3, !borrow 
	jnc default

	add r12, r12		;;index r12 entries. 2 bytes get the offset bytes in table
	mov jt(r12),r0		;;r12: address of the entry, move to program counter

case1:				;;led-red
	call #set_red(0)	;;call to set_red(0)
	call #set_green(1)	;;call to set_green(1)
	jmp end			;;break

case2:				;;Current state is green
	call #set_green(0)	;;call to set_green(0)
	call #set_red(1)	;;call to set_red(1)    ;; transition to red
	jmp end			;;break

default:
	call #set_green(1)	;;call to set_green(1), state is off
	jmp end
end:
	pop r0			;;return
