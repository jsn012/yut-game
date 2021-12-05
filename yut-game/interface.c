#include "header.h"

int selectTurn() {
	exitMenuClear();

	gotoxy(60, 20);
	printf("���� ����");
	gotoxy(55, 22);
	TextColor(9);
	printf("�� �浹");
	gotoxy(67, 22);
	TextColor(7);
	printf("�� �鵹");

	char ch;
	int turnNum = 1;
	while (1) {
		ch = _getch();
		if (ch == ESC) {
			exitMenuClear();
			break;
		}

		if (ch == LEFT) {
			if (turnNum == 2) {
				turnNum--;
			}
			gotoxy(55, 22);
			TextColor(9);
			printf("�� �浹");
			gotoxy(67, 22);
			TextColor(7);
			printf("�� �鵹");
		}
		else if (ch == RIGHT) {
			if (turnNum == 1) {
				turnNum++;
			}
			gotoxy(55, 22);
			TextColor(7);
			printf("�� �浹");
			gotoxy(67, 22);
			TextColor(9);
			printf("�� �鵹");
			TextColor(7);
		}

		if (ch == ENTER) {
			if (turnNum == 1) {
				return 0;
			}
			else if (turnNum == 2) {
				return 1;
			}
		}

	}
}

void exitMenu() {
	exitMenuClear();

	gotoxy(56, 20);
	printf("�����Ͻðڽ��ϱ�?");
	gotoxy(58, 22);
	TextColor(4);
	printf("Yes");
	gotoxy(68, 22);
	TextColor(7);
	printf("No");

	char exitMenuCheck;
	int exitMenuNum = 1;
	while (1) {
		exitMenuCheck = _getch();
		if (exitMenuCheck == ESC) {
			exitMenuClear();
			break;
		}

		if (exitMenuCheck == LEFT) {
			if (exitMenuNum == 2) {
				exitMenuNum--;
			}
			gotoxy(58, 22);
			TextColor(4);
			printf("Yes");
			gotoxy(68, 22);
			TextColor(7);
			printf("No");
		}
		else if (exitMenuCheck == RIGHT) {
			if (exitMenuNum == 1) {
				exitMenuNum++;
			}
			gotoxy(58, 22);
			TextColor(7);
			printf("Yes");
			gotoxy(68, 22);
			TextColor(4);
			printf("No");
			TextColor(7);
		}

		if (exitMenuCheck == ENTER) {
			if (exitMenuNum == 1) {
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
			else if (exitMenuNum == 2) {
				exitMenuClear();
				break;
			}
		}

	}
}

void displayYut() {
	displayYutClear();
	Sleep(300);

	gotoxy(52, 9);
	for (int i = 52 + 5; i < 80; i++) {
		printf("%c%c", 0xa6, 0xa1);
	}
	gotoxy(52, 17);
	for (int i = 52 + 5; i < 80; i++) {
		printf("%c%c", 0xa6, 0xa1);
	}

	for (int i = 9; i < 18; i++) {
		for (int j = 52; j < 76; j += 6) {
			gotoxy(j, i);
			printf("%c%c", 0xa6, 0xa2);
			gotoxy(j + 5, i);
			printf("%c%c", 0xa6, 0xa2);
		}
	}

	for (int i = 52; i < 76; i += 6) {
		gotoxy(i, 9);
		printf("%c%c", 0xa6, 0xa3);
		gotoxy(i + 5, 9);
		printf("%c%c", 0xa6, 0xa4);
		gotoxy(i, 17);
		printf("%c%c", 0xa6, 0xa6);
		gotoxy(i + 5, 17);
		printf("%c%c", 0xa6, 0xa5);
	}

	//
	if (yutNum < 4) {
		for (int i = 1; i < 4; i++) { //��
			for (int j = 0; j < 3; j++) {
				gotoxy(55 + (i * 6), 11 + (j * 2));
				printf("X");
			}
		}

		if (yutNumDo == 0) { //�鵵
			gotoxy(55, 13);
			printf("-");
			gotoxy(50, 16);
			printf("��");
			gotoxy(50, 17);
			printf("��");
		}
		else { //��
			gotoxy(50, 17);
			printf("��");
		}
	}
	else if (yutNum < 10) { //��
		for (int i = 2; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				gotoxy(55 + (i * 6), 11 + (j * 2));
				printf("X");
			}
		}
		gotoxy(50, 17);
		printf("��");
	}
	else if (yutNum < 14) { //��
		for (int i = 3; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				gotoxy(55 + (i * 6), 11 + (j * 2));
				printf("X");
			}
		}
		gotoxy(50, 17);
		printf("��");
	}
	else if (yutNum < 15) { //��
		//����
		gotoxy(50, 17);
		printf("��");
	}
	else { //��
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				gotoxy(55 + (i * 6), 11 + (j * 2));
				printf("X");
			}
		}
		gotoxy(50, 17);
		printf("��");
	}
}

void displayYutClear() {
	for (int i = 9; i < 18; i++) {
		gotoxy(50, i);
		printf("                          ");
	}
}

void exitMenuClear() {
	for (int i = 0; i < 3; i++) {
		gotoxy(51, 20 + i);
		printf("                           ");
	}
}

void displayUserTurn(int user) {
	exitMenuClear();

	gotoxy(52, 21);
	printf("[ %s ]�� �����Դϴ�.", user == 0 ? "�� �浹" : "�� �鵹");
}