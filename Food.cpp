#include "Food.h"
#include<iostream>
#include<ctime>
#include<Windows.h>
#define random(a,b) (rand() % (b - a)) + a + 1//¼ÆËãËæ»úÊý
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
	special = false;
}
void Food::randomFood()
{
	srand((unsigned)time(NULL));
	x = random(0, 14);
	y = random(0, 10);
}
Food::~Food()
{

}