st:
	addi.w	$t0,$a0, -10	//a-10
	sltui	$t1,$t0, 8
	beqz	$t1, default	//if (a-10)>=8 
							//goto default
	la		$t2, jr_table
	alsl.d	$t1, $t0, $t2, 3
							//(a-10)*8+jr_table
	ld.d	$t0, $t1, 0
	jr		$t0
default:
	or		$a1,$a0,$r0
case_14:
	or		$a0,$a1,$r0
	jr		$ra		//return b for case_14,
					//return a for default
case_15:
	andi	$a2,$a1,0xf		//b & 0xf
case_10:
	addi.w	$a1,$a2,50		//c+50
	b		case_14
case_12_17:
	addi.w	$a1,$a1,50		//b+50
	b		case_14
							# jump table
	.section	.rodata
	.align	3
jr_table:
	.dword	case_10
	.dword	default
	.dword	case_12_17
	.dword	default
	.dword	case_14
	.dword	case_15
	.dword	default
	.dword	case_12_17
