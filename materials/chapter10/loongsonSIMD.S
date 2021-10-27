    gsldxc1 $f0, 0x0($src0, $0)
    gsldxc1 $f2, 0x0($src1, $0)
    paddb   $f0, $f0, $f2
    gssdxc1 $f0, 0x0($result, $0)