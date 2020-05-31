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
//�ж��������Ľ��������Ƿ����Ѿ����ڵ��������Χǽ��ĳ�������غϣ����غ�˵����ײ�����Լ��������ײ����ǽ
bool Deque::suicide(int i, int j)
{
	int h = 640 / SIZE - 1;
	int v = 640 / SIZE - 1;
	for (Node* p = front; p != rear; p = p->next) {
		if ((p->x == i && p->y == j)|| i== 0 || j == 0 || i == h || j == v)//ǽ��������֪;
			return false;
	}
	return true;
}
Deque::~Deque()
{
	delete front;
	delete rear;
}