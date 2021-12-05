#include "header.h"

void intro() {
	system("cls");
	CursorHide();
	printf("\n\n\n\n\n");
	TextColor(6);
	printf("\t   #   #  #   #  #####           ##    #  #####  ####   #####\n");
	printf("\t    # #   #   #    #             # #   #  #   #  #   #    #  \n");
	printf("\t     #    #   #    #     #####   #  #  #  #   #  ####     #  \n");
	printf("\t     #    #   #    #             #   # #  #   #  #  #     #  \n");
	printf("\t     #     ###     #             #    ##  #####  #   #  #####\n");
	TextColor(7);

	gotoxy(0, 17);
	TextColor(2);
	printf("\t\t\t\t게 임 시 작\n\n");
	TextColor(7);
	printf("\t\t\t\t게 임 정 보\n\n");
	printf("\t\t\t\t   종 료\n\n");

	int menuNum = 1;
	char ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == UP) {
				if (menuNum == 1) {
					continue;
				}
				menuNum--;
			}
			else if (ch == DOWN) {
				if (menuNum == 3) {
					continue;
				}
				menuNum++;
			}

			gotoxy(0, 17);
			if (menuNum == 1) {
				TextColor(2);
				printf("\t\t\t\t게 임 시 작\n\n");
				TextColor(7);
				printf("\t\t\t\t게 임 정 보\n\n");
				printf("\t\t\t\t   종 료\n\n");
			}
			else if (menuNum == 2) {
				TextColor(7);
				printf("\t\t\t\t게 임 시 작\n\n");
				TextColor(2);
				printf("\t\t\t\t게 임 정 보\n\n");
				TextColor(7);
				printf("\t\t\t\t   종 료\n\n");
			}
			else if (menuNum == 3) {
				TextColor(7);
				printf("\t\t\t\t게 임 시 작\n\n");
				printf("\t\t\t\t게 임 정 보\n\n");
				TextColor(2);
				printf("\t\t\t\t   종 료\n\n");
				TextColor(7);
			}

			if (ch == ENTER || ch == SPACE) {
				if (menuNum == 1) { //게임 시작
					userSetting();
					gameSetting();
					interfaceSetting();
					gamePlaying();
				}
				else if (menuNum == 2) { //게임 정보
					gameInfo();
				}
				else if (menuNum == 3) { //종료
					system("cls");
					printf("> 프로그램을 종료합니다.\n");
					exit(0);
				}
			}
		}
	}
}