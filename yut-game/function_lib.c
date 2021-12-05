#include "header.h"

void TextColor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void CursorHide() { //커서 숨기기
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void CursorShow() { //커서 보이기
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int randomYut() {
	yutNum = 0;
	yutNumDo = 0;

	srand(time(0));
	yutNum = rand() % 16;

	if (yutNum < 4) { //0~3 (25%)
		srand(time(0));
		yutNumDo = rand() % 4;

		if (yutNumDo == 0) { //0 = 백도 (6.25%)
			return 0;
		}
		else { //1~3 = 도 (18.75%)
			return 1;
		}
	}
	else if (yutNum < 10) { //4~9 = 개 (37.5%)
		return 2;
	}
	else if (yutNum < 14) { //10~13 = 걸 (25%)
		return 3;
	}
	else if (yutNum < 15) { //14 = 윷 (6.25%)
		return 4;
	}
	else { //15 = 모 (6.25%)
		return 5;
	}
}


//
void boardSqureTop() {
	printf("%c%c", 0xa6, 0xa3);
	printf("%c%c", 0xa6, 0xa1);
	printf("%c%c", 0xa6, 0xa1);
	printf("%c%c", 0xa6, 0xa1);
	printf("%c%c", 0xa6, 0xa4);
}

void boardSqureMiddle() {
	printf("%c%c   %c%c", 0xa6, 0xa2, 0xa6, 0xa2);
}

void boardSqureBottom() {
	printf("%c%c", 0xa6, 0xa6);
	printf("%c%c", 0xa6, 0xa1);
	printf("%c%c", 0xa6, 0xa1);
	printf("%c%c", 0xa6, 0xa1);
	printf("%c%c", 0xa6, 0xa5);
}

void boardSqureHome() {
	gotoxy(40, 20);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("%c%c", 0xa6, 0xa3);
	printf("%c%c", 0xa6, 0xa1);
	printf("%c%c", 0xa6, 0xa1);
	printf("%c%c", 0xa6, 0xa1);
	printf("%c%c ", 0xa6, 0xa4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(40, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("%c%c   %c%c ", 0xa6, 0xa2, 0xa6, 0xa2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(40, 22);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("%c%c", 0xa6, 0xa6);
	printf("%c%c", 0xa6, 0xa1);
	printf("%c%c", 0xa6, 0xa1);
	printf("%c%c", 0xa6, 0xa1);
	printf("%c%c ", 0xa6, 0xa5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}