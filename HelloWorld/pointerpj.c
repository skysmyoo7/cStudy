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
		printf("몇 번 어항에 물을 주시겠어요?");
		scanf_s("%d", &num);
		if (num < 1 || num > 6) {
			printf("\n입력값이 잘못되었습니다.\n");
			continue;
		}

		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과 시간 : %ld 초 \n", totalElapsedTime);

		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간 : %ld초 \n", prevElapsedTime);

		decreaseWater(prevElapsedTime);

		if (cursor[num - 1] <= 0) {
			printf("%d 번 물고기는 이미 죽었습니다. \n", num);
		}
		else if (cursor[num - 1] + 1 <= 100) {
			printf("%d 번 어항에 물을 줍니다. \n\n", num);
			cursor[num - 1] += 1;
		}

		if (totalElapsedTime / 5 > level - 1) {
			level++;
			printf("--- 축 레벨업!  기존 %d 레벨에서 %d 레벨로 업그레이드!--- \n\n", level - 1, level);

			if (level == 5) {
				printf("\n\n 축하합니다. 최고 레벨을 달성하였습니다. 게임을 종료합니다. \n\n");
				if (checkFishAlive() > 0 &&checkFishAlive() <3) {
					printf("물고기가 %d 마리 살았습니다.  Rank : C",checkFishAlive());
					exit(0);
				}
				else if (checkFishAlive() > 2 && checkFishAlive() < 5) {
					printf("물고기가 %d 마리 살았습니다.  Rank : B", checkFishAlive());
					exit(0);
				}
				else if (checkFishAlive() == 5) {
					printf("물고기가 5마리 살았습니다.  Rank : A");
					exit(0);
				}
				else {
					printf("물고기가 모두 살았습니다.  Rank : S");
					exit(0);
				}
			}
		}

		if (checkFishAlive() == 0) {
			printf("모든 물고기가 죽었습니다. Rank : F");
			exit(0);
		}
		else {
			printf("물고기가 아직 살아있어요! \n");
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
	
	printf("%3d번 %4d번 %4d번 %4d번 %4d번 %4d번\n", 1, 2, 3, 4, 5, 6);
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