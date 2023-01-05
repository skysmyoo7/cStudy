#include <stdio.h>
#include <time.h>


int level;
int arrayFish[6];
int* cursor;


void initData();
void printFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();
void main02(void) {

	long startTime = 0;
	long totalElapsedTime = 0;
	long prevElapsedTime = 0;

	int num;
	initData();

	cursor = arrayFish;

	startTime = clock();
	while (1) {
		printFishes();
		printf("�� �� ���׿� ���� �ֽðھ��?");
		scanf_s("%d", &num);
		if (num < 1 || num > 6) {
			printf("\n�Է°��� �߸��Ǿ����ϴ�.\n");
			continue;
		}

		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("�� ��� �ð� : %ld �� \n", totalElapsedTime);

		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("�ֱ� ��� �ð� : %ld�� \n", prevElapsedTime);

		decreaseWater(prevElapsedTime);

		if (cursor[num - 1] <= 0) {
			printf("%d �� ������ �̹� �׾����ϴ�. \n", num);
		}
		else if (cursor[num - 1] + 1 <= 100) {
			printf("%d �� ���׿� ���� �ݴϴ�. \n\n", num);
			cursor[num - 1] += 1;
		}

		if (totalElapsedTime / 5 > level - 1) {
			level++;
			printf("--- �� ������!  ���� %d �������� %d ������ ���׷��̵�!--- \n\n", level - 1, level);

			if (level == 5) {
				printf("\n\n �����մϴ�. �ְ� ������ �޼��Ͽ����ϴ�. ������ �����մϴ�. \n\n");
				if (checkFishAlive() > 0 &&checkFishAlive() <3) {
					printf("����Ⱑ %d ���� ��ҽ��ϴ�.  Rank : C",checkFishAlive());
					exit(0);
				}
				else if (checkFishAlive() > 2 && checkFishAlive() < 5) {
					printf("����Ⱑ %d ���� ��ҽ��ϴ�.  Rank : B", checkFishAlive());
					exit(0);
				}
				else if (checkFishAlive() == 5) {
					printf("����Ⱑ 5���� ��ҽ��ϴ�.  Rank : A");
					exit(0);
				}
				else {
					printf("����Ⱑ ��� ��ҽ��ϴ�.  Rank : S");
					exit(0);
				}
			}
		}

		if (checkFishAlive() == 0) {
			printf("��� ����Ⱑ �׾����ϴ�. Rank : F");
			exit(0);
		}
		else {
			printf("����Ⱑ ���� ����־��! \n");
		}

		prevElapsedTime = totalElapsedTime;


	}

}

void initData() {
	level = 1;
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100;
	}
}

void printFishes() {
	
	printf("%3d�� %4d�� %4d�� %4d�� %4d�� %4d��\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf("  %3d  ", arrayFish[i]);
	}
	printf("\n\n");

}

void decreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime);
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive() {
	int count = 0;
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0)
			count++;
	}
	return count;
}