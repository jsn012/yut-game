#include "header.h"

void gameInfo() {
	system("cls");

	printf("Made by �ڽ³� MayNut\n\n\n");

	printf("[ �÷��� ��� ]\n");
	printf("1. ������� �̸��� �Է��մϴ�.\n");
	printf("2. ���� ���� ���� ����ڸ� ���մϴ�.\n");
	printf("3. ������ ���� Ű������ ENTERŰ�� ���� ���� �����ϴ�.\n");
	printf("4. ���� ����� ���� ������� ���� �ڵ����� �̵��մϴ�.\n");
	printf("5. �÷��� ���� Ű������ ESCŰ�� ���� ������ �� �ֽ��ϴ�.\n");
	printf("6. ������ ����Ǹ� 5�� �� �ڵ����� ����ȭ������ �̵��մϴ�.\n\n\n");

	printf("[ ��Ģ ]\n");
	printf("1. ���� ������ ����, ���� ��� �� ����ڰ� �¸��մϴ�.\n");
	printf("2. �� �Ǵ� �� ������ ���, �� �� �� ���� �� �ֽ��ϴ�.(�ִ� �ѹ�)\n");
	printf("3. ������� ���� ���� �� �ֽ��ϴ�.\n\n\n");

	printf("ENTER - ����� �ٷΰ���(��â)\n");
	printf("ESC - Ȩ���� ���ư���\n");

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