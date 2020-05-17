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
	loadimage(&SHUP, _T("SnakeHeadUp.jpg"), SIZE, SIZE);
	loadimage(&SHDOWN, _T("SnakeHeadDown.jpg"), SIZE, SIZE);
	loadimage(&SHLEFT, _T("SnakeHeadLeft.jpg"), SIZE, SIZE);
	loadimage(&SHRIGHT, _T("SnakeHeadRight.jpg"), SIZE, SIZE);
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
void Deque::push(int i, int j,int dir)//β��
{
	Node* p = new Node;
	p->x = i;
	p->y = j;
	p->z = 'O';
	p->next = NULL;//β��Ϊ NULL ��
	if (front == NULL)
		front = p;
	else
		rear->next = p;
	rear = p;
	//gotoxy(i, j);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
	//	FOREGROUND_GREEN | FOREGROUND_BLUE);
	//cout << p->z;
	if (dir == 1)	putimage(i * SIZE, j * SIZE, &SHUP);
	if (dir == 2)	putimage(i * SIZE, j * SIZE, &SHDOWN);
	if (dir == 3)	putimage(i * SIZE, j * SIZE, &SHLEFT);
	if (dir == 4)	putimage(i * SIZE, j * SIZE, &SHRIGHT);
	//������ͷͼ��(�ĸ�������ͬ)
}
void Deque::pop(int& i, int& j, char& k)
{
	if (front == NULL) {
		//cout << "Queue is empty." << endl;
		exit(-1);
	}
	else {
		//gotoxy(front->x, front->y);
		//cout << " ";
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
//�ж��������Ľ��������Ƿ����Ѿ����ڵ��������Χǽ��ĳ�������غϣ����غ�˵����ײ�����Լ��������ײ����ǽ
bool Deque::suicide(int i, int j)
{
	for (Node* p = front; p != rear; p = p->next) {
		if ((p->x == i && p->y == j)|| i== 0 || j == 0 || i == 15 || j == 11)//ǽ��������֪;
			return false;
	}
	return true;
}
Deque::~Deque()
{
	delete front;
	delete rear;
}