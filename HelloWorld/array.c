#include <stdio.h>
#include<time.h>

void main00(void) {

	srand(time(NULL));
	printf("\n\n ===�ƺ��� ��Ӹ� ���� ===\n\n");

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
		printf(">%d��° �õ� : ", i);

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
		printf("������ �Ӹ��� �ٸ��ϴ�. \n\n");
		if (isIncluded == 1) {
			printf("succeed!!\n");
		}
		else {
			printf("fail!!\n");
		}

		printf("\n ... ��� �Ϸ��� 'Enter'Ű�� ��������...\n");
		getchar();
	}

	printf("\n\n �߸����� ����ΰ���?");
	scanf_s("%d", &answer);

	if (answer == treatment+1) {
		printf("\n >> ����!!");
	}
	else {
		printf("\n >> ����!! ������ %d �Դϴ�!\n", treatment +1);
	}

}