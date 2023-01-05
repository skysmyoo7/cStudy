#include <stdio.h>

void main__(void) {

	/*int a = 10;
	printf("a = %d\n", a);
	a++;
	++a;
	printf("a = %d\n", a);*/

	/*for (int a = 1; a < 10; a++) {
		for (int b = 1; b < 10; b++) {
			printf("%d x %d = %d \n", a, b, a * b);
		}
	}*/
	int a;
	printf("number?\n");
	scanf_s("%d", &a);
	for (int i = 0; i < a; i++) {
		for (int k = i; k < a - 1; k++) {
			printf(" ");
		}
		for (int j = 0; j < i * 2 +1; j++) {
			printf("*");
		}
		printf("\n");
	}

}