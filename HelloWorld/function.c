#include <stdio.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

void main_1(void) {

	srand(time(NULL));
	int count = 0;
	for (int i = 1; i <= 5; i++) {
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		showQuestion(i, num1, num2);

		int answer = -1;
		scanf_s("%d", &answer);
		if (answer == 1) {
			printf("프로그램을 종료합니다. \n");
			exit(0);
		}
		else if (answer == num1 * num2) {
			success();
			count++;
		}
		else {
			fail();
		}
	}

	if (count == 5) {
		printf("\n\n전부 맞추셨습니다! 탈출 성공!!\n\n");
	}
	else {
		printf("\n\n 점수 : %d / 5 \n\n 탈출 실패!! \n\n", count);
	}


}

int getRandomNumber(int level) {
	return rand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2) {
	printf("\n\n\n############# %d번째 비밀번호 ##########\n", level);
	printf("\n\t%d X %d = ?\n\n", num1, num2);
	printf("####################################\n");
	printf("\n 비밀번호를 입력하세요. (종료: -1) >> ");
}

void success() {
	
	printf("\n correct!! \n");

}
void fail() {
	printf("\n fail!!\n");
}