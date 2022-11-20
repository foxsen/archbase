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
	// a   : $a0
	// sum : $t0
	// i   : $t1
	or      $t0,$r0,$r0
	or      $t1,$r0,$r0
.L1:
	add.w   $t0,$t0,$t1
	addi.w  $t1,$t1,1
	blt     $t1,$a0,.L1
	or      $a0,$t1,$r0
	jr      $ra
