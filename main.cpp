#include"Deque.h"
#include"Food.h"
#include"Snake.h"
#include"Game.h"
#include<iostream>
#include<Windows.h>
using namespace std;
void hide();//���ع��
int main()
{
	int max = 0;
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();
	hide();
	int t = 1;
	while (t) {
		Game game(max);
		game.NewGame();
		max = game.ScoringBar();
	}
	closegraph();
}

void hide()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}