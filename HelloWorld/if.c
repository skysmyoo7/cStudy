#include <stdio.h>
#include <time.h>

void main___(void) {

	srand(time(NULL));
	int num = rand() % 100 + 1;
	printf("num: %d\n", num);
	int answer = 0;
	int chance = 5;
	while (chance >0)
	{
		printf("���� ��ȸ %d ��\n", chance--);
		printf("���� ���纸����(1~100) : ");
		scanf_s("%d", &answer);

		if (answer < num) {
			printf("UP\n\n");
		}
		else if (answer > num) {
			printf("DOWN\n\n");
			}
		else {
			printf("Correct!\n\n");
			break;
		}

		if (chance == 0) {
			printf("�й��߽��ϴ�.\n");
			break;
		}
	}
}