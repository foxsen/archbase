int st(int a, int b, int c)
{
	switch (a) {
		case 15:
			c = b & 0xf;
		case 10:
			return c + 50;
		case 12:
		case 17:
			return b + 50;
		case 14:
			return b;
		default:
			return a;
	}
}

