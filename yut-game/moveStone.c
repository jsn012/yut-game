#include "header.h"

void moveStone(int user) {
	for (int j = 0; j < 2; j++) {
		gotoxy(66, 3 + (j * 4));
		printf("          ");
		for (int i = 0; i < 5; i++) {
			gotoxy(66 + (i * 2), 3 + (j * 4));
			if (i == 5 - userScore[j]) {
				break;
			}
			if (i == 4 - userScore[j]) {
				if (stoneX[j] == 42 && stoneY[j] == 21) {

				}
				else {
					break;
				}
			}
			printf("%s", j == 0 ? "○" : "●");
		}
	}

	displayUserTurn(user);

	gotoxy(2, 26 + user);
	printf("                                                         ");
	gotoxy(2, 26 + user);
	printf("%s %s > 엔터(ENTER)키를 눌러 윷을 던지세요.", user == 0 ? "○" : "●", userName[user]);
	gotoxy(2, 28);

	char throwCheck;
	throwYut = 0;
	
	while (1) {
		throwCheck = _getch();
		if (throwCheck == ENTER) {
			throwYut = randomYut();
			break;
		}
		else if (throwCheck == ESC) {
			exitMenu();
			displayUserTurn(user);
		}
	}

	//scanf_s("%d", &throwYut); //테스트용

	displayYut();

	gotoxy(2, 26 + user);
	printf("                                                         ");
	gotoxy(2, 26 + user);
	printf("%s %s > [ %s%d ]만큼 이동합니다. ", user == 0 ? "○" : "●", userName[user], throwYut == 0 ? "-" : "+", throwYut == 0 ? 1 : throwYut);

	Sleep(100);

	if (throwYut == 0) { //백도
		Sleep(100);
		gotoxy(stoneX[user], stoneY[user]);
		printf("  ");


		//
		if (stoneX[user] == 42 && stoneY[user] == 21) {
			stoneX[user] -= 8;
		}
		else if (stoneX[user] == 42 && stoneY[user] == 1) {
			stoneY[user] += 4;
		}
		else if (stoneX[user] == 10 && stoneY[user] == 17 || stoneX[user] == 28 && stoneY[user] == 8 || stoneX[user] == 16 && stoneY[user] == 14) {
			stoneX[user] += 6;
			stoneY[user] -= 3;
		}
		else if (stoneX[user] == 22 && stoneY[user] == 11) {
			if (leftCheck[user] == 0) {
				stoneX[user] += 6;
				stoneY[user] -= 3;
			}
			else {
				stoneX[user] -= 6;
				stoneY[user] -= 3;
			}
		}
		else if (stoneX[user] == 34 && stoneY[user] == 5) {
			stoneX[user] += 8;
			stoneY[user] -= 4;
		}
		else if (stoneX[user] == 2 && stoneY[user] == 1) {
			stoneX[user] += 8;
		}
		else if (stoneX[user] == 16 && stoneY[user] == 8 || stoneX[user] == 28 && stoneY[user] == 14 || stoneX[user] == 34 && stoneY[user] == 17) {
			stoneX[user] -= 6;
			stoneY[user] -= 3;
		}
		else if (stoneX[user] == 10 && stoneY[user] == 5) {
			stoneX[user] -= 8;
			stoneY[user] -= 4;
		}

		//
		else if (stoneX[user] == 2 && stoneY[user] == 21) {
			stoneY[user] -= 4;
		}
	
		//
		else if (stoneX[user] == 42 && stoneY[user] != 1) {
			stoneY[user] += 4;
		}
		else if (stoneX[user] != 2 && stoneY[user] == 1) {
			stoneX[user] += 8;
		}
		else if (stoneX[user] == 2 && stoneY[user] != 21) {
			stoneY[user] -= 4;
		}
		else if (stoneX[user] != 42 && stoneY[user] == 21) {
			stoneX[user] -= 8;
		}

		//
		if (user == 0) {
			gotoxy(stoneX[1], stoneY[1]);
			printf("●");
			gotoxy(stoneX[0], stoneY[0]);
			printf("○");
		}
		else {
			gotoxy(stoneX[0], stoneY[0]);
			printf("○");
			gotoxy(stoneX[1], stoneY[1]);
			printf("●");
		}

		//
		if (stoneX[user] == 42 && stoneY[user] == 21) {
			Sleep(400);
			gotoxy(stoneX[user], stoneY[user]);
			printf("  ");
			userScore[user]++;
			leftCheck[user] = 0;
		}

		//
		if (stoneX[0] == 42 && stoneY[0] == 21) {
			gotoxy(stoneX[0], stoneY[0]);
			printf("  ");
		}
		else if (stoneX[1] == 42 && stoneY[1] == 21) {
			gotoxy(stoneX[1], stoneY[1]);
			printf("  ");
		}

	}

	else { //도-1, 개-2, 걸-3, 윷-4, 모-5
		for (int i = 0; i < throwYut; i++) {
			Sleep(100);
			gotoxy(stoneX[user], stoneY[user]);
			printf("  ");

			//
			if (stoneX[user] == 42 && stoneY[user] == 1) {
				if (i == 0) {
					stoneX[user] -= 8;
					stoneY[user] += 4;
					rightCheck[user] ++;
					leftCheck[user] = 0;
				}
				else {
					stoneX[user] -= 8;
				}
			}
			else if (stoneX[user] == 34 && stoneY[user] == 5 || stoneX[user] == 28 && stoneY[user] == 8 || stoneX[user] == 16 && stoneY[user] == 14) {
				stoneX[user] -= 6;
				stoneY[user] += 3;
			}
			else if (stoneX[user] == 22 && stoneY[user] == 11) {
				if (i == 0) {
					stoneX[user] += 6;
					stoneY[user] += 3;
				}
				else if (leftCheck[user] != 0) {
					stoneX[user] += 6;
					stoneY[user] += 3;
				}
				else {
					stoneX[user] -= 6;
					stoneY[user] += 3;
				}
			}
			else if (stoneX[user] == 10 && stoneY[user] == 17) {
				stoneX[user] -= 8;
				stoneY[user] += 4;
			}
			else if (stoneX[user] == 34 && stoneY[user] == 17) {
				stoneX[user] += 8;
				stoneY[user] += 4;
			}

			//
			else if (stoneX[user] == 2 && stoneY[user] == 1) {
				if (i == 0) {
					stoneX[user] += 8;
					stoneY[user] += 4;
					leftCheck[user]++;
					rightCheck[user] = 0;
				}
				else {
					stoneY[user] += 4;
				}
			}
			else if (stoneX[user] == 10 && stoneY[user] == 5 || stoneX[user] == 16 && stoneY[user] == 8 || stoneX[user] == 22 && stoneY[user] == 11 || stoneX[user] == 28 && stoneY[user] == 14) {
				stoneX[user] += 6;
				stoneY[user] += 3;
			}
			
			//
			else if (stoneX[user] == 42 && stoneY[user] != 1) {
				stoneY[user] -= 4;
			}
			else if (stoneX[user] != 2 && stoneY[user] == 1) {
				stoneX[user] -= 8;
			}
			else if (stoneX[user] == 2 && stoneY[user] != 21) {
				stoneY[user] += 4;
			}
			else if (stoneX[user] != 42 && stoneY[user] == 21) {
				stoneX[user] += 8;
			}

			//
			if (user == 0) {
				gotoxy(stoneX[1], stoneY[1]);
				printf("●");
				gotoxy(stoneX[0], stoneY[0]);
				printf("○");
			}
			else {
				gotoxy(stoneX[0], stoneY[0]);
				printf("○");
				gotoxy(stoneX[1], stoneY[1]);
				printf("●");
			}

			//
			if (stoneX[user] == 42 && stoneY[user] == 21) {
				Sleep(400);
				gotoxy(stoneX[user], stoneY[user]);
				printf("  ");
				userScore[user]++;
				leftCheck[user] = 0;
				break;
			}

			//
			if (stoneX[0] == 42 && stoneY[0] == 21) {
				gotoxy(stoneX[0], stoneY[0]);
				printf("  ");
			}
			else if (stoneX[1] == 42 && stoneY[1] == 21) {
				gotoxy(stoneX[1], stoneY[1]);
				printf("  ");
			}
		}

	}

	if (stoneX[0] == stoneX[1] && stoneY[0] == stoneY[1]) { //상대 돌 잡기
		if (user == 0) {
			stoneX[1] = 42;
			stoneY[1] = 21;
		}
		else {
			stoneX[0] = 42;
			stoneY[0] = 21;
		}
	}

	for (int j = 0; j < 2; j++) { //남은 돌 갯수
		gotoxy(66, 3 + (j * 4));
		printf("          ");
		for (int i = 0; i < 5; i++) {
			gotoxy(66 + (i * 2), 3 + (j * 4));
			if (i == 5 - userScore[j]) {
				break;
			}
			if (i == 4 - userScore[j]) {
				if (stoneX[j] == 42 && stoneY[j] == 21) {

				}
				else {
					break;
				}
			}
			printf("%s", j == 0 ? "○" : "●");
		}
	}

	if (userScore[user] == 5) { //승자 확인
		system("cls");
		gotoxy(10, 4);
		printf("%s [ %s ]님이 승리하였습니다!", user == 0 ? "○ 흑돌" : "● 백돌", userName[user]);
		for (int i = 5; i > 0; i--) {
			gotoxy(10, 6);
			printf("홈 화면으로 돌아가기까지 %d초", i);
			Sleep(1000);
		}

		for (int i = 0; i < 2; i++) {
			userScore[i] = 0;
			stoneX[i] = 42;
			stoneY[i] = 21;
			leftCheck[i] = 0;
			rightCheck[i] = 0;
			throwYut = 0;
		}

		intro();
	}

	if (throwYut == 4 || throwYut == 5) { //윷or모면 한번 더 던지기
		if (YutMoCheck[user] == 0) { //최대 한번만
			YutMoCheck[user]++;
			moveStone(user);
		}
		else {
			YutMoCheck[user] = 0;
		}
	}
	else {
		YutMoCheck[user] = 0;
	}

	Sleep(100);
	displayUserTurn(user);

}