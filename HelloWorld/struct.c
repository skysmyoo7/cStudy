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
		printf("어느 고양이가 나올까요? \n 아무키나 눌러서 확인해주세요.\n");
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
	cats[0].name = "깜냥이";
	cats[0].character = "온순";
	cats[0].level = 1;

	cats[1].age = 3;
	cats[1].name = "귀요미";
	cats[1].character = "날카롭";
	cats[1].level = 2;

	cats[2].age = 7;
	cats[2].name = "수줍이";
	cats[2].character = "수줍";
	cats[2].level = 3;

	cats[3].age = 2;
	cats[3].name = "까꿍이";
	cats[3].character = "메롱";
	cats[3].level = 4;

	cats[4].age = 1;
	cats[4].name = "꿀꿀이";
	cats[4].character = "난폭";
	cats[4].level = 5;
}

void printCat(int selected) {

	printf(" \n\n == 당신의 고양이 ====\n\n");
	printf("이름 : %s\n", cats[selected].name);
	printf("나이 : %d\n", cats[selected].age);
	printf("성격 : %s\n", cats[selected].character);
	printf("레벨 :    ");

	for (int i = 0; i < cats[selected].level; i++) {
		printf("%s", " O ");
	}
	printf("\n\n");
}

int checkCollection() {

	int collectAll = 1;

	printf("\n\n보유한 고양이 목록\n\n");

	for (int i = 0; i < 5; i++) {

		if (collection[i] == 0) {
			printf("%10s", "(빈 박스)");
			collectAll = 0;
		}
		else {
			printf("%10s", cats[i].name);
		}

	}

	printf("\n--------------------------\n\n");
	
	if (collectAll) {
		printf("\n\n 축하합니다! 모든 고양이를 다 모았어요!\n\n");
	}


	return collectAll;

}