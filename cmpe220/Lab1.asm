## Read in an integer and calculate the sum from 1 to that integer
## Andrew Stake

	.data
Prompt1:	.asciiz		"\n Please input a value for N = "
Result:		.asciiz		"\n The sum of the integers from 1 to N is "
Bye:		.asciiz		"\n *** Have a nice day ***"

	.text
main:
	li 	$v0, 4				# load $v0 with the print_string code
	la	$a0, Prompt1			# load $a0 with the message to be displayed
	syscall
	
	## Get the number
	li	$v0, 5				# load $v0 with the read_int code
	syscall
	
	blez	$v0, Else			# branch to Else if $v0 is less than or equal to 0
	li	$t0, 0				# load $t0 with 0
	
	while:
		blez	$v0, done		# branch to done if $v0 is less than or equal to 0
		add	$t0, $t0, $v0		# add $t0 and $v0, store in $t0
		addi	$v0, $v0, -1		# subtract 1 from $v0
		b	while			# branch back to while
	done:
		li	$v0, 4			# load $v0 with the print_string code
		la 	$a0, Result		# load $a0 with the message to be displayed
		syscall
		
		li	$v0, 1			# load $v0 with the print_int code
		move	$a0, $t0		# load $a0 with the int stored in $t0
		syscall
		
		li	$v0, 10			# load $v0 with the exit code
		syscall				# exit program
	Else:
		li 	$v0, 4			# load $v0 with the print_string code
		la	$a0, Bye		# load $a0 with the message to be displayed
		syscall
		
		li	$v0, 10			# load $v0 with the exit code
		syscall				# exit program
	
	 