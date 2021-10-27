fun:
    daddiu  $sp,$sp,-16
    ldc1    $f1,16($sp)                                #a9从$sp + 16获得        
    ldc1    $f0,32($sp)                                #a11从$sp + 32获得
    sd  $28,0($sp)
    lui $28,%hi(%neg(%gp_rel(fun)))
    c.eq.d  $fcc0,$f1,$f0
    daddiu  $28,$28,%lo(%neg(%gp_rel(fun)))
    sd  $31,8($sp)
    bc1f    $fcc0,.L5
    daddu   $28,$28,$25
    ld  $31,8($sp)
    ld  $28,0($sp)
    move    $2,$0
    jr  $31
    daddiu  $sp,$sp,16

.L5:
    ld  $25,%call16(abort)($28)
    .reloc  1f,R_MIPS_JALR,abort
1:  jalr    $25
    nop
