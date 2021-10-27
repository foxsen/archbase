# 注意：为了保持生成的文件宽度相同，每个源文件最长的行应该都保持为80，不够的可以在某一行末尾添空格
# 理论上各种Mono的字体应该都可以满足，但实际测试发现很多字体并不能保证生成的字符宽度一致。

%.c.png:%.c
	pygmentize -f png -O encoding=utf8,font_name='SimSun',line_numbers=False $< -o $@
#	pygmentize -f png -O encoding=utf8,font_name='Noto Sans Mono CJK SC',line_numbers=False $< -o $@

%.S.png:%.S
	pygmentize -f png -O encoding=utf8,font_name='SimSun',line_numbers=False $< -o $@
#	pygmentize -f png -O encoding=utf8,font_name='Noto Sans Mono CJK SC',line_numbers=False $< -o $@

%.txt.png:%.txt
	pygmentize -f png -O encoding=utf8,font_name='SimSun',line_numbers=False $< -o $@

all: fun.c.png fun_mips.S.png fun_la.S.png varg.c.png simple.c.png simple.S.png simple_nofp.S.png normal.c.png normal.S.png dynamic.c.png dynamic.S.png keyboard_interrupt.txt.png syscall_write.S.png
	@echo 'done'

clean:
	rm -f *.png
