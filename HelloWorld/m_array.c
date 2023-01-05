#include <stdio.h>
#include <time.h>

int arrayAnimal[4][5];
int checkAnimal[4][5];
char* strAnimal[10];


void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_y(int y);
int conv_pos_x(int x);
void printAnimals();
void printQuestion();
int foundAllAnimals();

void array_main(void) {

	srand(time(NULL));

	initAnimalArray();

	initAnimalName();

	shuffleAnimal();

	int failCount = 0;

	while (1) {
		int select1 = 0;
		int select2 = 0;

		printAnimals();
		printQuestion();
		printf("뒤집을 카드를 2개 고르세요 : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) {
			continue;
		}

		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);
		if (failCount == 30) {
			printf("오답 카운트가 초과되어 패배하셨습니다.");
			break;
		}
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)
			&&
			(arrayAnimal[firstSelect_x][firstSelect_y]
				== arrayAnimal[secondSelect_x][secondSelect_y])
			)
		{
			printf("\n\n 빙고!!: %s 발견!\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("\n\n 오답 : %d / 30 \n\n", failCount);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		else {
			printf("\n\n 땡!! (틀렸거나 이미 뒤집힌 카드입니다.)\n");
			printf("\n\n 오답 : %d / 30 \n\n", failCount);
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		if (foundAllAnimals() == 1) {
			printf("\n\n 축하합니다. 모든 동물을 다 찾았습니다!\n");
			switch (failCount)
			{
			case 0:
				printf("\n\n지금까지 %d 번 실수하셨습니다. Rank : S\n\n", failCount);
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				printf("\n\n지금까지 %d 번 실수하셨습니다. Rank : A\n\n", failCount);
				break;
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
				printf("\n\n지금까지 %d 번 실수하셨습니다. Rank : B\n\n", failCount);
				break;
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
				printf("\n\n지금까지 %d 번 실수하셨습니다. Rank : C\n\n", failCount);
				break;
			default:
				printf("\n\n지금까지 %d 번 실수하셨습니다. Rank : F\n\n", failCount);
				break;
			}
			
			break;
		}

	}

}


void initAnimalArray() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalName() {
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";
	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";
}

void shuffleAnimal() {
	for (int i = 0; i < 10; i++) {
		
		for (int j = 0; j < 2; j++) {

			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;

		}

	}
}


int getEmptyPosition() {
	
	while (1) {
		
		int randPos = rand() % 20;
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) {
			return randPos;
		}


	}
	return 0;
}

int conv_pos_x(int x) {
	
	return x / 5;

}

int conv_pos_y(int y) {

	return y % 5;

}

void printAnimals() {

	printf("\n======================================\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j ++ ) {
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n======================================\n\n");

}

void printQuestion() {

	printf("\n\n(문제)\n");
	int seq = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {

			if (checkAnimal[i][j] != 0) {
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			else {
				printf("%8d", seq);
			}
			seq++;

		}
		printf("\n");
	}
}

int foundAllAnimals() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (checkAnimal[i][j] == 0) {
				return 0;
			}
		}
	}

	return 1;
}


