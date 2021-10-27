fun:
    movgr2fr.d  $f0,$a0                 # 注意这两行, $f0是参数a9，从$a0获得）  
    movgr2fr.d  $f1,$a2                 # $f1从$a2获得，即参数a11
    fcmp.ceq.d  $fcc0,$f1,$f0           # 比较a9和a11
    bceqz   $fcc0,.L8
    move    $a0,zero
    jr  $ra
.L8:
    addi.d  $sp,$sp,-16
    st.d    $ra,$sp,8
    bl  %plt(abort)
    ld.d    $ra,$sp,8
