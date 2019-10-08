Prompt1:	.asciiz		"\n Please input an integer: "
Prompt2:	.asciiz		"\n Please input another integer: "
Result:		.asciiz		"\n The sum of the two integers is: "
Bye:		.asciiz		"\n *** Make love, not war. ***\n"

	.text
main:
	li	$v0, 4
	la	$a0, Prompt1
	syscall
	
	## Get the first number
	li	$v0, 5
	syscall
	move	$t0, $v0
	
	li	$v0, 4
	la 	$a0, Prompt2
	syscall
	
	## Get the second number
	li	$v0, 5
	syscall
	move	$t1, $v0
	
	add	$t2, $t0, $t1
	
	li	$v0, 4
	la	$a0, Result
	syscall
	
	## Print out $t2.
	move	$a0, $t2
	li	$v0, 1
	syscall
	
	li	$v0, 4
	la	$a0, Bye
	syscall
	
	li	$v0, 10
	syscall
#end of add program