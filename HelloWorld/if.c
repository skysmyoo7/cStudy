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
		printf("남은 기회 %d 번\n", chance--);
		printf("답을 맞춰보세요(1~100) : ");
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
			printf("패배했습니다.\n");
			break;
		}
	}
}