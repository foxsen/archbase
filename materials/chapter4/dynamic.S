dynamic:                                                                        
    addi.d  $sp,$sp,-32
    st.d    $fp,$sp,16           #保存fp
    st.d    $ra,$sp,24           #保存ra
    addi.d  $fp,$sp,32           # fp指向入口时的sp
    addi.d  $sp,$sp,-64          # alloca
    addi.d  $a0,$sp,16         # 从sp+16到sp+80为分配的alloca空间
    addi.w  $t0,$zero,291         # 0x123
    stptr.d  $t0,$a0,0
    addi.w  $t0,$zero,9           # 0x9
    stptr.d  $t0,$sp,0             # sp到sp+16为调子函数的参数区
    addi.w  $a7,$zero,8           # 0x8
    addi.w  $a6,$zero,7           # 0x7
    addi.w  $a5,$zero,6           # 0x6
    addi.w  $a4,$zero,5           # 0x5
    addi.w  $a3,$zero,4           # 0x4
    addi.w  $a2,$zero,3           # 0x3
    addi.w  $a1,$zero,291         # 0x123
    bl  %plt(nested)
    addi.d  $sp,$fp,-32
    ld.d    $ra,$sp,24
    ld.d    $fp,$sp,16
    addi.d  $sp,$sp,32
    jr  $ra
