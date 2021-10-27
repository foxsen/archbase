LOOP:
	LFU	fp0=y(r4=r4+8)
	FMUL	fp0=fp0,fp1
	LF	fp2=x(r3,8)
	FMADD	fp0=fp0,fp2,fp3
	STFU	x(r3=r3+8)=fp0
	BC	LOOP,CTR>0
