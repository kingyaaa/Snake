#pragma once
#include<graphics.h>
class Deque
{
public:
	Deque();
	
	//����µĽ����Ϊ��ͷ���൱������ǰ�ƶ���һ��
	void push(int i, int j,int dir);
	
	//ɾ����β�Ľ�㣬��������β�߹��ĺۼ�;
	void pop(int& i, int& j, char& k);
	bool judge(int x,int y);
	void gotoxy(int i, int j);
	//�ж��������Ľ��������Ƿ����Ѿ����ڵ��������Χǽ��ĳ�������غϣ����غ�˵����ײ�����Լ��������ײ����ǽ
	bool suicide(int i, int j);
	~Deque();
private:
	struct Node
	{
		int x;//x����
		int y;//y����
		char z;//��ͷΪ'O'����Ϊ'X'
		Node* next;
	}*front, * rear;
	friend class Food;
	IMAGE BLANK;
};