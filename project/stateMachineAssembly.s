;;; assembly for stateMachine.c sm_update_led method 

	Msp430g2553

	.p2align 1,0





	.data			; for ledMode?

ledMode:
	.word 0



Jt:	        .text
	.word op0		;case0
	
	.word op1		;case1

	.word op2		;case2

	.word op3		;case3

	.word op4		;case4

	.global sm_update_led
;;;name of function
sm_update_led:



;;; range check

	cmp #4,&ledMode



;;; index into jt

	mov &s,r12

	add r12,r12

	mov jt(r12),r0


;;; if given input is more than case constants go to end of sm
	ledMode>4

	jmp end


;;; case 0

op0:	 mov #1,new_red_on

	mov #1,new_green_on

	jmp end


;;; case 1
op1:	 mov #0,new_red_on

	mov #0,new_green_on

	call buzzer_set_period(6000)

	jmp end

;;; case 2
op2:

	mov #0, new_red_on

	mov#1,new_green_on

	jmp end


;;; case 3
op3:	 mov #0, new_red_on

	mov #1,new_green_on

	call buzzer_set_period(8000)



	jmp end



;;; case 4
op4:	 mov #1,new_red_on

	mov #0,new_green_on

	call buzzer_set_period(9000)

	jmp end


;;; end of switch
end:	 pop r0

	
