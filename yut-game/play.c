#include "header.h"

void gamePlaying() {
	for (int i = 0; i < 2; i++) {
		gotoxy(51, 1 + (i * 4));
		printf("%s", i == 0 ? "○" : "●");
		gotoxy(57, 1 + (i * 4));
		printf("%s", userName[i]);
	}

	int userTurnCheck = selectTurn();

	for (int i = 0; i < 2; i++) {
		stoneX[i] = 42; //시작지점 초기화
		stoneY[i] = 21;

		YutMoCheck[i] = 0; //윷모확인 초기화
	}

	while (1) {
		for (int i = 0; i < 2; i++) {
			gotoxy(51, 1 + (i * 4));
			printf("%s", i == 0 ? "○" : "●");
			gotoxy(57, 1 + (i * 4));
			printf("%s", userName[i]);
			gotoxy(51, 3 + (i * 4));
			printf("Score : %d", userScore[i]);

			gotoxy(2, 26 + i);
			printf("%s %s > ", i == 0 ? "○" : "●",  userName[i]);
		}

		if (userTurnCheck == 0) {
			moveStone(0);
			userTurnCheck++;
		}
		else {
			moveStone(1);
			userTurnCheck--;
		}
		
	}
}