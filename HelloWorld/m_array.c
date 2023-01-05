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
		printf("������ ī�带 2�� ������ : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) {
			continue;
		}

		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);
		if (failCount == 30) {
			printf("���� ī��Ʈ�� �ʰ��Ǿ� �й��ϼ̽��ϴ�.");
			break;
		}
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)
			&&
			(arrayAnimal[firstSelect_x][firstSelect_y]
				== arrayAnimal[secondSelect_x][secondSelect_y])
			)
		{
			printf("\n\n ����!!: %s �߰�!\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("\n\n ���� : %d / 30 \n\n", failCount);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		else {
			printf("\n\n ��!! (Ʋ�Ȱų� �̹� ������ ī���Դϴ�.)\n");
			printf("\n\n ���� : %d / 30 \n\n", failCount);
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		if (foundAllAnimals() == 1) {
			printf("\n\n �����մϴ�. ��� ������ �� ã�ҽ��ϴ�!\n");
			switch (failCount)
			{
			case 0:
				printf("\n\n���ݱ��� %d �� �Ǽ��ϼ̽��ϴ�. Rank : S\n\n", failCount);
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				printf("\n\n���ݱ��� %d �� �Ǽ��ϼ̽��ϴ�. Rank : A\n\n", failCount);
				break;
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
				printf("\n\n���ݱ��� %d �� �Ǽ��ϼ̽��ϴ�. Rank : B\n\n", failCount);
				break;
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
				printf("\n\n���ݱ��� %d �� �Ǽ��ϼ̽��ϴ�. Rank : C\n\n", failCount);
				break;
			default:
				printf("\n\n���ݱ��� %d �� �Ǽ��ϼ̽��ϴ�. Rank : F\n\n", failCount);
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
	strAnimal[0] = "������";
	strAnimal[1] = "�ϸ�";
	strAnimal[2] = "������";
	strAnimal[3] = "�����";
	strAnimal[4] = "����";
	strAnimal[5] = "�ڳ���";
	strAnimal[6] = "�⸰";
	strAnimal[7] = "��Ÿ";
	strAnimal[8] = "Ÿ��";
	strAnimal[9] = "ȣ����";
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

	printf("\n\n(����)\n");
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


