.section .rodata                                                                
    .align 3
.hello:
	.ascii	"Hello World!\n\000"

    .text
    .align 3
    .global main
main:
    li $a7, 64            #write的系统调用号
    li $a0, 1             #  fd == 1是stdout的文件描述符号
    la.local $a1, .hello     # 字符串地址
    li $a2, 14            # 字符串长度
    syscall 0x0            
    jr  $ra              # 返回
