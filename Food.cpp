#include "Food.h"
#include<iostream>
#include<ctime>
#include<Windows.h>
#define random(a,b) (rand() % (b - a)) + a + 1//���������
#define SIZE 40
using namespace std;
void Food::gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
Food::Food()
{
	i = 0;
	j = 0;
	x = 0;
	y = 0;
	count = 0;
}
void Food::randomFood()
{
	//Deque q;
	srand((int)time(0));
	x = random(0, 14);
	y = random(0, 10);
	/**
	while(!q.judge(x, y)) { //�õ���Deque��
		x = random(0, 14);
		y = random(0, 10);
	}
	**/
	//gotoxy(x, y);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
	//	FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	//cout << "*";
}
int Food::specialFood()
{
	srand((int)time(0));
	i = random(0, 14);
	j = random(0, 10);
	//gotoxy(i, j);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
	//	FOREGROUND_RED | FOREGROUND_BLUE);
	//cout << "&";
	
	//TODO

	//q.gotoxy(80, 8);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
	//	FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	//cout << "$ ����ʱʳ��ܿ��Ҫ��ʧ���;";
	return 0;
}
void Food::speFade()
{
	i = -1;
	j = -1;
	
	//TODO

	//gotoxy(80, 8);
	//��ʱʳ����ʧ����ʾ��Ҳ��ʧ;
	//cout << "                                 ";
	//gotoxy(0, 0);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
	//	FOREGROUND_RED);
	//cout << "#";

}
Food::~Food()
{

}