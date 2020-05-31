#pragma once
#include<graphics.h>
class Deque
{
public:
	Deque();
	
	//添加新的结点作为蛇头，相当于蛇往前移动了一步
	void push(int i, int j,int dir);
	
	//删除蛇尾的结点，即消除蛇尾走过的痕迹;
	void pop(int& i, int& j, char& k);
	bool judge(int x,int y);
	void gotoxy(int i, int j);
	//判断蛇新增的结点的坐标是否与已经存在的身体或者围墙的某个坐标重合，若重合说明蛇撞到了自己的身体或撞到了墙
	bool suicide(int i, int j);
	~Deque();
private:
	struct Node
	{
		int x;//x坐标
		int y;//y坐标
		char z;//蛇头为'O'蛇身为'X'
		Node* next;
	}*front, * rear;
	friend class Food;
	IMAGE BLANK;
};