#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13
#define SPACE 32

//intro.c
void intro();

//gameInfo.c
void gameInfo();

//function_lib.c
void TextColor(int colorNum);
void CursorHide();
void CursorShow();
void gotoxy(int x, int y);
int randomYut();

void boardSqureTop();
void boardSqureMiddle();
void boardSqureBottom();
void boardSqureHome();

//interface.c
void exitMenu();
void exitMenuClear();
void displayYut();
void displayYutClear();
void displayUserTurn(int user);
int selectTurn();

//setting.c
void userSetting();
void gameSetting();
void interfaceSetting();

//play.c
void gamePlaying();

//moveStone.c
void moveStone(int user);


//
char userName[2][30];
int userScore[2];

int stoneX[2], stoneY[2];
int throwYut;
int leftCheck[2], rightCheck[2];

int YutMoCheck[2];
int yutNum, yutNumDo;
int Yut[4];