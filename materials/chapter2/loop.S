test_for:
	or		$t0,$r0,$r0
	or		$t1,$r0,$r0
.L2:
	blt		$t0,$a0,.L3
	or		$a0,$t1,$r0
	jr		$ra
.L3:
	add.w	$t1,$t1,$t0
	addi.w	$t0,$t0,1
	b		.L2


test_while:
	or		$t0,$r0,$r0
	or		$t1,$r0,$r0
.L2:
	blt		$t0,$a0,.L3
	or		$a0,$t1,$r0
	jr		$ra
.L3:
	add.w	$t1,$t1,$t0
	addi.w	$t0,$t0,1
	b		.L2


test_dowhile:
	or		$t0,$r0,$r0 
	or		$t3,$r0,$r0
.L2:
	add.w	$t1,$t3,$t0
	addi.w	$t2,$t0,1
	or		$t3,$t1,$r0
	or		$t0,$t2,$r0
	blt		$t2,$a0,.L2
	or		$a0,$t1,$r0
	jr		$ra

