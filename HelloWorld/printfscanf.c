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
	//printf("�¾ �⵵ : %d\n", YEAR);

	/*int add = 3 + 6;
	printf("%d\n", add);*/

	/*int input;
	printf("���� �Է��ϼ��� :");
	scanf_s("%d", &input);

	int one, two, three;
	printf("3���� ���� : ");
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

	printf("\n\n -- ������ ���� --\n\n");
	printf("�̸� : %s\n", name);
	printf("���� : %d\n",age);
	printf("������ : %2f\n", weight);
	printf("Ű : %2lf\n", height);
	printf("what : %s\n", what);


}