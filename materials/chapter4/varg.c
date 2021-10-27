struct Ss {
	char c1, c2;
} a3 = {3, 4};
int fun (double a1, ...);
int test () {
	return fun (1, (float) 2, a3, (long double) 5, (float) 6,                   
					 (short) 7, (int) 8, (float) 9, (int)10);
}
