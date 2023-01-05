#include <stdio.h>
#include<time.h>

void main00(void) {

	srand(time(NULL));
	printf("\n\n ===아빠는 대머리 게임 ===\n\n");

	int answer;
	int treatment = rand() % 4;

	int cntShowBottle = 0;
	int prevCntShowBottle = 0;

	for (int i = 1; i <= 3; i++) {
		int bottle[4] = { 0,0,0,0 };
		do {
			cntShowBottle = rand() % 2 + 2;
		} while (cntShowBottle == prevCntShowBottle);
		prevCntShowBottle = cntShowBottle;

		int isIncluded = 0;
		printf(">%d번째 시도 : ", i);

		for (int j = 0; j < cntShowBottle; j++) {
			int randBottle = rand() % 4;

			if (bottle[randBottle] == 0) {
				bottle[randBottle] = 1;
				if (randBottle == treatment) {
					isIncluded = 1;
				}
			}
			else {
				j--;
			}
		}

		for (int k = 0; k < 4; k++) {
			if (bottle[k] == 1) {
				printf(" %d,", k + 1);
			}
		}
		printf("물약을 머리에 바릅니다. \n\n");
		if (isIncluded == 1) {
			printf("succeed!!\n");
		}
		else {
			printf("fail!!\n");
		}

		printf("\n ... 계속 하려면 'Enter'키를 누르세요...\n");
		getchar();
	}

	printf("\n\n 발모제는 몇번인가요?");
	scanf_s("%d", &answer);

	if (answer == treatment+1) {
		printf("\n >> 정답!!");
	}
	else {
		printf("\n >> 오답!! 정답은 %d 입니다!\n", treatment +1);
	}

}