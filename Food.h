#pragma once
#include"Deque.h"
class Food
{
private:
    friend class Deque;
    int x,y,i,j,count;
public:
    Food();
    //��ͨʳ���������
    void randomFood();
    //����ʳ��ĳ���
    bool special;
    void gotoxy(int i, int j);
    //������ͨʳ���x����
    int loc_x()  { return x; }
    //������ͨʳ���y����
    int loc_y()  { return y; }
    ~Food();
};