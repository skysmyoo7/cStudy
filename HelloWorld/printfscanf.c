#include <stdio.h>

void main_(void)
{
	/*
	* int age = 12;
	printf("%d\n", age);
	age = 13;
	printf("%d\n", age);
	*/

	/*float f = 46.5f;
	printf("%.2f\n", f);
	double d = 4.426;
	printf("%.2lf\n", d);*/
	//const int YEAR = 2000;
	//printf("태어난 년도 : %d\n", YEAR);

	/*int add = 3 + 6;
	printf("%d\n", add);*/

	/*int input;
	printf("값을 입력하세요 :");
	scanf_s("%d", &input);

	int one, two, three;
	printf("3개의 정수 : ");
	scanf_s("%d %d %d ", &one, &two, &three);
	printf("%d %d %d\n", one, two, three);*/

	/*char str[256];
	scanf_s("%s", str,sizeof(str));
	printf("%s\n", str);*/

	char name[256];
	printf("name?");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("age?");
	scanf_s("%d", &age);

	float weight;
	printf("weight?");
	scanf_s("%f", &weight);

	double height;
	printf("height?");
	scanf_s("%lf", &height);

	char what[256];
	printf("what?");
	scanf_s("%s", &what,sizeof(what));

	printf("\n\n -- 범죄자 정보 --\n\n");
	printf("이름 : %s\n", name);
	printf("나이 : %d\n",age);
	printf("몸무게 : %2f\n", weight);
	printf("키 : %2lf\n", height);
	printf("what : %s\n", what);


}