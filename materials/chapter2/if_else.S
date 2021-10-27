	move	$t0, cond_exp
	beqz	$t0, .L1
	<then_statement>
	b		.L2
.L1:
	<else_statement>
.L2:

