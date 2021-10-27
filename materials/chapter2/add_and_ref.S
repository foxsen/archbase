add:
	add.w    $a0, $a0, $a1    //a+b
	jr       $ra              //return
ref:
	addi.d    $sp, $sp, -16   //stack allocate
	addi.w    $a1, $r0, 34    //t2=34
	addi.w    $a0, $r0, 12    //t1=12
	st.d      $ra, $sp, 8     //save $ra
	bl        add             //call add()
	ld.d      $ra, $sp, 8     //restore $ra
	addi.d    $sp, $sp, 16    //stack release
	jr        $ra             //return

