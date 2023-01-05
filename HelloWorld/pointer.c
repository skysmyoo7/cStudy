#include <stdio.h>


void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);
void main01(void) {

	/*int a = 1;
	int b = 2;
	int c = 3;

	printf("address : %d, pwd: %d \n", &a, a);
	printf("address : %d, pwd: %d \n", &b, b);
	printf("address : %d, pwd: %d \n", &c, c);


	int * mission;
	mission = &a;
	printf("missonAddress : %d, pwd : %d \n", mission, *mission);
	*mission *= 3;
	printf("missonAddress : %d, changedPwd : %d \n", mission, *mission);

	mission = &b;
	printf("missonAddress : %d, pwd : %d \n", mission, *mission);
	*mission *= 3;
	printf("missonAddress : %d, changedPwd : %d \n", mission, *mission);

	mission = &c;
	printf("missonAddress : %d, pwd : %d \n", mission, *mission);
	*mission *= 3;
	printf("missonAddress : %d, changedPwd : %d \n", mission, *mission);

	int* spy = mission;
	
	printf("\n ... spying....\n\n");
	spy = &a;
	*spy -= 2;
	printf("spyAddress : %d, pwd :%d\n", spy, *spy);
	spy = &b;
	*spy -= 2;
	printf("spyAddress : %d, pwd :%d\n", spy, *spy);
	spy = &c;
	*spy -= 2;
	printf("spyAddress : %d, pwd :%d\n", spy, *spy);

	printf("\n\n ... come admin... \n\n");

	printf("address : %d, pwd: %d \n", &a, a);
	printf("address : %d, pwd: %d \n", &b, b);
	printf("address : %d, pwd: %d \n", &c, c);

	printf("missionAddress : %d\n", &mission);
	printf("spyAddress : %d\n", &spy);*/

	/*int arr[3] = { 5,10,15 };
	int* ptr = arr;
	
	for (int i = 0; i < 3; i++) {
		printf("arr[%d] : %d\n", i, *(arr+i));
	}

	for (int i = 0; i < 3; i++) {
		printf("ptr[%d] : %d\n", i, ptr[i]);
	}*/

	/*int a = 10;
	int b = 20;
	printf("aAddress : %d\n", &a);
	printf("bAddress : %d\n", &b);


	printf("a: %d, b: %d\n", a, b);
	swap(a, b);
	printf("a: %d, b: %d\n", a, b);

	printf("----------주소 전달 -----------\n");
	printf("a: %d, b: %d\n", a, b);
	swap_addr(&a, &b);
	printf("a: %d, b: %d\n", a, b);*/

	int arr[3] = { 10,20,30 };
	changeArray(arr);
	for (int i = 0; i < 3; i++) {
		printf("%d \n", arr[i]);
	}

}

void swap(int a, int b) {
	printf("===========함수===========\n");
	printf("aAddress : %d\n", &a);
	printf("bAddress : %d\n", &b);
	int temp = a;
	a = b;
	b = temp;
	printf("a: %d, b: %d\n", a, b);

	printf("===========함수===========\n");
}

void swap_addr(int* a, int* b) {
	printf("===========함수===========\n");
	printf("aAddress : %d\n", &a);
	printf("bAddress : %d\n", &b);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("a: %d, b: %d\n", *a, *b);

	printf("===========함수===========\n");
}

void changeArray(int* ptr) {
	ptr[2] = 50;
}