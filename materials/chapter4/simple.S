simple:                                                                         
    addi.d  $sp,$sp,-16
    st.d    $fp,$sp,8
    addi.d  $fp,$sp,16
    ld.d    $fp,$sp,8
    bstrpick.w  $a0,$a0,7,0
    add.w   $a0,$a0,$a1
    addi.d  $sp,$sp,16
    jr  $ra
