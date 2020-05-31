#include "Deque.h"
#include<iostream>
#include<Windows.h>
#define SIZE 40
using namespace std;
Deque::Deque()
{
	front = NULL;
	rear = NULL;
	loadimage(&BLANK, _T("Blank.jpg"), SIZE, SIZE);
}
void Deque::gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
void Deque::push(int i, int j,int dir)//尾插
{
	Node* p = new Node;
	p->x = i;
	p->y = j;
	p->z = 'O';
	p->next = NULL;//尾部为 NULL ！
	if (front == NULL)
		front = p;
	else
		rear->next = p;
	rear = p;
}
void Deque::pop(int& i, int& j, char& k)
{
	if (front == NULL) {
		exit(-1);
	}
	else {
		putimage(front->x * SIZE, front->y * SIZE, &BLANK);
		i = front->x;
		j = front->y;
		k = front->z;
		Node* p = front;
		front = front->next;
		delete p;
	}
}
bool Deque::judge(int x,int y)
{
	if(rear!= NULL && rear->x == x && rear->y == y)
		return false;
	for (Node* p = front; p != rear; p = p->next) {
		if (p->x == x && p->y == y)
			return false;
	}
	return true;
}
//判断蛇新增的结点的坐标是否与已经存在的身体或者围墙的某个坐标重合，若重合说明蛇撞到了自己的身体或撞到了墙
bool Deque::suicide(int i, int j)
{
	int h = 640 / SIZE - 1;
	int v = 640 / SIZE - 1;
	for (Node* p = front; p != rear; p = p->next) {
		if ((p->x == i && p->y == j)|| i== 0 || j == 0 || i == h || j == v)//墙的坐标已知;
			return false;
	}
	return true;
}
Deque::~Deque()
{
	delete front;
	delete rear;
}