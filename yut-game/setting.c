#include "header.h"

void userSetting() {
	system("cls");
	CursorShow();
	for (int i = 0; i < 2; i++) {
		gotoxy(16, 6 + (i * 3));
		printf("%s 사용자의 이름을 입력하세요 : ", i == 0 ? "○ 흑돌" : "● 백돌");
		gets_s(userName[i], 30);
		gotoxy(16, 6 + (i * 3) + 1);
		printf("%s 사용자의 이름은 [ %s ] 입니다.", i == 0 ? "○ 흑돌" : "● 백돌", userName[i]);
	}
	CursorHide();

	gotoxy(16, 12);
	for (int i = 0; i < 47; i++) {
		printf("%c%c", 0xa6, 0xa1);
	}

	gotoxy(16, 14);
	printf("ENTER - 게임 시작");
	gotoxy(16, 15);
	printf("SPACE - 이름 재설정");
	gotoxy(16, 16);
	printf("ESC - 홈");

	gotoxy(16, 18);
	for (int i = 0; i < 47; i++) {
		printf("%c%c", 0xa6, 0xa1);
	}

	char ch;
	while (1) {
		ch = _getch();
		gotoxy(16, 20);
		if (ch == ENTER) {
			printf("> 게임을 시작합니다...");
			Sleep(1000);
			break;
		}
		else if (ch == SPACE) {
			printf("> 이름을 재설정합니다...");
			Sleep(1000);
			userSetting();
		}
		else if (ch == ESC) {
			printf("> 홈으로 이동합니다...");
			Sleep(1000);
			intro();
		}
	}
}

void gameSetting() {
	system("cls");

	for (int i = 0; i < 6; i++) {
		if (i == 0 || i == 5) {
			for (int j = 0; j < 6; j++) {
				boardSqureTop();
				printf("\t");
			}
			printf("\n");
			for (int j = 0; j < 6; j++) {
				boardSqureMiddle();
				if (j == 5) {
					break;
				}
				printf(" %c%c ", 0xa6, 0xa1);
			}
			printf("\n");
			for (int j = 0; j < 6; j++) {
				boardSqureBottom();
				printf("\t");
			}
			printf("\n");
			for (int j = 0; j < 6; j++) {
				if (i == 5) {
					break;
				}
				if (j == 0 || j == 5) {
					printf("  %c%c\t", 0xa6, 0xa2);
				}
				else {
					printf("\t");
				}
			}
			printf("\n");
		}
		else {
			for (int j = 0; j < 6; j++) {
				if (j == 0 || j == 5) {
					boardSqureTop();
				}
				else {
					printf("     ");
				}
				printf("\t");
			}
			printf("\n");
			for (int j = 0; j < 6; j++) {
				if (j == 0 || j == 5) {
					boardSqureMiddle();
				}
				else {
					printf("     ");
				}
				printf("\t");
			}
			printf("\n");
			for (int j = 0; j < 6; j++) {
				if (j == 0 || j == 5) {
					boardSqureBottom();
				}
				else {
					printf("     ");
				}
				printf("\t");
			}
			printf("\n");
			for (int j = 0; j < 6; j++) {
				if (i == 5) {
					break;
				}
				if (j == 0 || j == 5) {
					printf("  %c%c\t", 0xa6, 0xa2);
				}
				else {
					printf("\t");
				}
			}
			printf("\n");
		}
	}

	gotoxy(8, 4);
	boardSqureTop();
	gotoxy(8, 5);
	boardSqureMiddle();
	gotoxy(8, 6);
	boardSqureBottom();

	gotoxy(32, 4);
	boardSqureTop();
	gotoxy(32, 5);
	boardSqureMiddle();
	gotoxy(32, 6);
	boardSqureBottom();

	gotoxy(8, 16);
	boardSqureTop();
	gotoxy(8, 17);
	boardSqureMiddle();
	gotoxy(8, 18);
	boardSqureBottom();

	gotoxy(32, 16);
	boardSqureTop();
	gotoxy(32, 17);
	boardSqureMiddle();
	gotoxy(32, 18);
	boardSqureBottom();

	gotoxy(20, 10);
	boardSqureTop();
	gotoxy(20, 11);
	boardSqureMiddle();
	gotoxy(20, 12);
	boardSqureBottom();

	gotoxy(14, 7);
	boardSqureTop();
	gotoxy(14, 8);
	boardSqureMiddle();
	gotoxy(14, 9);
	boardSqureBottom();

	gotoxy(26, 7);
	boardSqureTop();
	gotoxy(26, 8);
	boardSqureMiddle();
	gotoxy(26, 9);
	boardSqureBottom();

	gotoxy(14, 13);
	boardSqureTop();
	gotoxy(14, 14);
	boardSqureMiddle();
	gotoxy(14, 15);
	boardSqureBottom();

	gotoxy(26, 13);
	boardSqureTop();
	gotoxy(26, 14);
	boardSqureMiddle();
	gotoxy(26, 15);
	boardSqureBottom();

	boardSqureHome();
	
}

void interfaceSetting() {
	for (int i = 0; i < 30; i++) {
		if (i < 24) {
			gotoxy(48, i);
			printf("%c%c", 0xa6, 0xa2);
		}
		else {
			gotoxy(59, i);
			printf("%c%c", 0xa6, 0xa2);
		}
	}

	//
	for (int j = 2; j < 9; j += 2) {
		gotoxy(49, j);
		for (int i = 0; i < 80 - 49; i++) {
			printf("%c%c", 0xa6, 0xa1);
		}
	}
	gotoxy(49, 18);
	for (int i = 0; i < 80 - 49; i++) {
		printf("%c%c", 0xa6, 0xa1);
	}
	gotoxy(49, 0);
	for (int i = 0; i < 80 - 49; i++) {
		printf("%c%c", 0xa6, 0xa1);
	}

	gotoxy(54, 0);
	printf("%c%c", 0xa6, 0xa4);
	gotoxy(54, 1);
	printf("%c%c", 0xa6, 0xa2);
	gotoxy(54, 2);
	printf("%c%c", 0xa6, 0xa5);

	gotoxy(62, 2);
	printf("%c%c", 0xa6, 0xa4);
	gotoxy(62, 3);
	printf("%c%c", 0xa6, 0xa2);
	gotoxy(62, 4);
	printf("%c%c", 0xa6, 0xa5);

	gotoxy(54, 4);
	printf("%c%c", 0xa6, 0xa4);
	gotoxy(54, 5);
	printf("%c%c", 0xa6, 0xa2);
	gotoxy(54, 6);
	printf("%c%c", 0xa6, 0xa5);

	gotoxy(62, 6);
	printf("%c%c", 0xa6, 0xa4);
	gotoxy(62, 7);
	printf("%c%c", 0xa6, 0xa2);
	gotoxy(62, 8);
	printf("%c%c", 0xa6, 0xa5);

	//
	gotoxy(0, 24);
	for (int i = 0; i < 80; i++) {
		printf("%c%c", 0xa6, 0xa1);
	}

	//
	gotoxy(48, 24);
	printf("%c%c", 0xa6, 0xa5);
	gotoxy(59, 24);
	printf("%c%c", 0xa6, 0xa4);

	//
	gotoxy(62, 26);
	printf("ENTER - 윷 던지기");
	gotoxy(62, 27);
	printf("ESC - 종료 메뉴");

}