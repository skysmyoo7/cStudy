#include <stdio.h>
#include <time.h>

typedef struct {
	char* name;
	int age;
	char* character;
	int level;
} CAT;

int collection[5] = { 0,0,0,0,0 };

CAT cats[5];

void printCat(int selected);
void initCats();
int checkCollection();


void mainCat(void) {

	srand(time(NULL));

	initCats();

	while (1)
	{
		printf("��� ����̰� ���ñ��? \n �ƹ�Ű�� ������ Ȯ�����ּ���.\n");
		getchar();

		int selected = rand() % 5;

		printCat(selected);
		collection[selected] = 1;

		int collectAll = checkCollection();
		if (collectAll == 1) {
			break;
		}


	}

}

void initCats() {
	cats[0].age = 5;
	cats[0].name = "������";
	cats[0].character = "�¼�";
	cats[0].level = 1;

	cats[1].age = 3;
	cats[1].name = "�Ϳ��";
	cats[1].character = "��ī��";
	cats[1].level = 2;

	cats[2].age = 7;
	cats[2].name = "������";
	cats[2].character = "����";
	cats[2].level = 3;

	cats[3].age = 2;
	cats[3].name = "�����";
	cats[3].character = "�޷�";
	cats[3].level = 4;

	cats[4].age = 1;
	cats[4].name = "�ܲ���";
	cats[4].character = "����";
	cats[4].level = 5;
}

void printCat(int selected) {

	printf(" \n\n == ����� ����� ====\n\n");
	printf("�̸� : %s\n", cats[selected].name);
	printf("���� : %d\n", cats[selected].age);
	printf("���� : %s\n", cats[selected].character);
	printf("���� :    ");

	for (int i = 0; i < cats[selected].level; i++) {
		printf("%s", " O ");
	}
	printf("\n\n");
}

int checkCollection() {

	int collectAll = 1;

	printf("\n\n������ ����� ���\n\n");

	for (int i = 0; i < 5; i++) {

		if (collection[i] == 0) {
			printf("%10s", "(�� �ڽ�)");
			collectAll = 0;
		}
		else {
			printf("%10s", cats[i].name);
		}

	}

	printf("\n--------------------------\n\n");
	
	if (collectAll) {
		printf("\n\n �����մϴ�! ��� ����̸� �� ��Ҿ��!\n\n");
	}


	return collectAll;

}