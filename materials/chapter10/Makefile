# 注意：为了保持生成的文件宽度相同，每个源文件最长的行应该都保持为80，不够的可以在某一行末尾添空格
# 理论上各种Mono的字体应该都可以满足，但实际测试发现很多字体并不能保证生成的字符宽度一致。

%.c.png:%.c
	pygmentize -f png -O encoding=utf8,font_name='SimSun-ExtB',line_numbers=False -o $@ $< 
#	pygmentize -f png -O encoding=utf8,font_name='Noto Sans Mono CJK SC',line_numbers=False $< -o $@

%.S.png:%.S
	pygmentize -f png -O encoding=utf8,font_name='SimSun-ExtB',line_numbers=False -o $@ $< 
#	pygmentize -f png -O encoding=utf8,font_name='Noto Sans Mono CJK SC',line_numbers=False $< -o $@

%.txt.png:%.txt
	pygmentize -f png -O encoding=utf8,font_name='noto',line_numbers=False -o $@ $< 

all:atomic.c.png barrier.c.png critical.c.png dataprallel.c.png for.c.png loongsonSIMD.S.png Makefile maritx_OpenMP.c.png martix_MPI.c.png master.c.png MPI.c.png  paralle.c.png parallel_for.c.png parallel_sections.c.png pi_C.c.png pi_MPI.c.png pi_OpenMP.c.png pi_Pthreads.c.png Pthreads.c.png sections.c.png SIMD.S.png single.c.png taskparllel.c.png test4.c.png threadprivate.c.png tra_SIMD.c.png  OpenMP_struct.c.png
	@echo 'done'

clean:
	rm -f *.png
