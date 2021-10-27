int test_for(int a) {
	int sum = 0;
	int i = 0;

	for (i = 0; i < a; i++) {
		sum += i;
	}

	return sum;
}


int test_while(int a) {
	int sum = 0;
	int i = 0;

	while (i < a) {
		sum += i;
		i++;
	}

	return sum;
}


int test_dowhile(int a) {
	int sum = 0;
	int i = 0;

	do {
		sum += i;
		i++;
	} while (i < a);

	return sum;
}
