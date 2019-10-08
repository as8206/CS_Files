	.data
Prompt1:	.asciiz		"\n Please input an integer: "
Prompt2:	.asciiz		"\n Please input another integer: "
Result:		.asciiz		"\n The sum of the two integers is: "
Bye:		.asciiz		"\n *** Make love, not war. ***\n"

	.text
main:
	li	$v0, 4		# load $v0 with the print_string code.
	la	$a0, Prompt1	# load $a0 with the message to be displayed
	syscall
	
	## Get the first number
	li	$v0, 5		# load $v0 with the read_int code.
	syscall			# read an integer
	move	$t0, $v0	# move the number read from $v0 to $t0.
	
	li	$v0, 4		# load $v0 with the print_string code.
	la 	$a0, Prompt2	# load #a0 with the message to be displayed.
	syscall
	
	## Get the second number
	li	$v0, 5		# load $v0 with the read_int code.
	syscall			# read an integer.
	move	$t1, $v0	# move the number read from $v0 to $t1.
	
	add	$t2, $t0, $t1	# compute the sum of the two integers.
	
	li	$v0, 4		# load $v0 with the print_string code.
	la	$a0, Result	# load $a0 with the message to be displayed.
	syscall
	
	## Print out $t2.
	move	$a0, $t2	# move the sum from #t2 to #a0
	li	$v0, 1		# load syscall print_int into $v0
	syscall
	
	li	$v0, 4
	la	$a0, Bye
	syscall
	
	li	$v0, 10
	syscall
#end of add program