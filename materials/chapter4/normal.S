normal:                                                                         
    addi.d  $sp,$sp,-32
    addi.w  $t0,$zero,9          # 0x9
    stptr.d $t0,$sp,0
    addi.w  $a7,$zero,8          # 0x8
    addi.w  $a6,$zero,7          # 0x7
    addi.w  $a5,$zero,6           # 0x6
    addi.w  $a4,$zero,5           # 0x5
    addi.w  $a3,$zero,4           # 0x4
    addi.w  $a2,$zero,3           # 0x3
    addi.w  $a1,$zero,2           # 0x2
    addi.w  $a0,$zero,1           # 0x1
    st.d    $ra,$sp,24
    bl  %plt(nested)
    ld.d    $ra,$sp,24
    addi.d  $sp,$sp,32
    jr  $ra
