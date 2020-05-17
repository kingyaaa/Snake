#include "Deque.h"
#include<iostream>
#include<Windows.h>
using namespace std;
Deque::Deque()
{
	front = NULL;
	rear = NULL;
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
void Deque::push(int i, int j)//β��
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
	gotoxy(i, j);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << p->z;
}
void Deque::pop(int& i, int& j, char& k)
{
	if (front == NULL) {
		//cout << "Queue is empty." << endl;
		exit(-1);
	}
	else {
		gotoxy(front->x, front->y);
		cout << " ";
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
		if ((p->x == i && p->y == j)||i== 0 || j == 0 || i == 59 || j == 29)//ǽ��������֪;
			//gotoxy(0, 0);
			//cout << "WRONG!";
			return false;
	}
	return true;
}
Deque::~Deque()
{
	delete front;
	delete rear;
}