	li	$4, 0x0
    li	$5, 0x8
	daddu	$src0, $4
	daddu	$src1, $4
	daddu	$result, $4
    lb	$6, 0x0($src0)
	lb	$7, 0x0($src1)
	daddu	$6, $6, $7
	sb	$6, 0x0($result)
	daddiu	$4, 0x1
	blt	$4, $5, 1b
	nop