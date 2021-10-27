st:
	addi.w	$t0,$r0,14
	beq		$a0,$t0,.L7		//(a==14)?
	blt		$t0,$a0,.L3		//(a>14)?
	addi.w	$t0,$r0,10
	beq		$a0,$t0,.L4		//(a==10)?
	addi.w	$t0,$r0,12
	beq		$a0,$t0,.L5		//(a==12)?
	jr		$ra				//return a
.L3:
	addi.w	$t0,$r0,15
	beq		$a0,$t0,.L6		//(a==15)?
	addi.w	$t0,$r0,17
	beq		$a0,$t0,.L5		//(a==17)?
	jr		$ra				//return a
.L6:
	andi	$a2,$a1,0xf		//b & 0xf
.L4:
	addi.w	$a0,$a2,50		//c + 50
	jr		$ra
.L5:
	addi.w	$a0,$a1,50		//b + 50
	jr		$ra
.L7:
	or		$a0,$a1,$r0		//return b
	jr		$ra
