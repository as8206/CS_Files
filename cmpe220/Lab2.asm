## Reads in two integers and adds all the even integers inclusively between them
## Andrew Stake

	.data
Prompt:		.asciiz		"Please enter the values for X and Y\n"
End:		.asciiz		"The sum of the even integers between X and Y is: "
	.text
main:
	li	$v0, 4		# load $v0 with the print_string code
	la	$a0, Prompt	# load $a0 with Prompt string
	syscall
	
	li	$v0, 5		# load $v0 with the read_int code
	syscall
	move	$s0, $v0	# transfers the integer to $t0
	
	li	$v0, 5		# load $v0 with the read_int code
	syscall
	move	$s1, $v0	# transfers the integer to $t1
	
	li	$s2, 0		# intializes $s0 to zero
	
	andi	$t8, $s0, 1	# sets $t8 to 1 if $t0 is odd, otherwise 0
	beq	$t8, 1, Odd	# brances to Odd if $t8 is odd
	b	Skip
	
Odd:
	addi 	$s0, $s0, 1	# if the lower bound is odd, adds 1 to make it even while keeping it within the boundaries
Skip:
	andi	$t8, $s1, 1	# sets $t8 to 1 if $t1 is odd, otherwise 0
	beq	$t8, 1, Odd2	# brances to Odd if $t8 is odd
	b	While
Odd2:
	addi	$s1, $s1, -1	# if the upper bound is odd, subtracts 1 to make it even while keeping it within the boundaries
While:
	blt	$s1, $s0, Done	# branches to done if $t0 is greater than $t1
	add	$s2, $s2, $s0	# adds $t0 to the running sum in $s0
	addi	$s0, $s0, 2	# increments $t0 by 2 to go to the next even number
	b	While		# branches back to while
Done:
	li	$v0, 4		# load $v0 with the print_string code
	la	$a0, End	# load $a0 with the message
	syscall
	
	li	$v0, 1		
	move	$a0, $s2
	syscall	
