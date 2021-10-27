LOOP:
	LDT  fp3=y(r2,0)
	LDT  fp1=x(r1,0)
	MULT fp3=fp3,fp2
	ADDQ r2=r2,8
	MULT fp1=fp1,fp4
	SUBQ r4=r2,r6
	ADDT fp1=fp3,fp1
	STT  x(r1,0)=fp1
	ADDQ r1=r1,8
	BNE  r4,LOOP
