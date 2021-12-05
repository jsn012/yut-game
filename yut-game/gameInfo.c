#include "header.h"

void gameInfo() {
	system("cls");

	printf("Made by 자승넛 MayNut\n\n\n");

	printf("[ 플레이 방법 ]\n");
	printf("1. 사용자의 이름을 입력합니다.\n");
	printf("2. 윷을 먼저 던질 사용자를 정합니다.\n");
	printf("3. 순서에 따라 키보드의 ENTER키를 눌러 윷을 던집니다.\n");
	printf("4. 윷의 결과에 따라 사용자의 말이 자동으로 이동합니다.\n");
	printf("5. 플레이 도중 키보드의 ESC키를 눌러 종료할 수 있습니다.\n");
	printf("6. 게임이 종료되면 5초 후 자동으로 메인화면으로 이동합니다.\n\n\n");

	printf("[ 규칙 ]\n");
	printf("1. 먼저 말판을 돌아, 말을 모두 뺀 사용자가 승리합니다.\n");
	printf("2. 윷 또는 모가 나왔을 경우, 한 번 더 던질 수 있습니다.(최대 한번)\n");
	printf("3. 상대편의 말을 잡을 수 있습니다.\n\n\n");

	printf("ENTER - 깃허브 바로가기(새창)\n");
	printf("ESC - 홈으로 돌아가기\n");

	char ch;
	while (1) {
		ch = _getch();
		if (ch == ESC) {
			intro();
			break;
		}
		else if (ch == ENTER) {
			system("explorer https://github.com/jsn012");
		}
	}
}