#pragma once
#include"Deque.h"
//class Snake;
class Food
{
private:
    friend class Deque;
    int x, y,i,j,count;
public:
    Food();
    //��ͨʳ���������
    void randomFood();
    //����ʳ��ĳ���
    int specialFood();
    void gotoxy(int i, int j);
    //������ͨʳ���x����
    int loc_x()  { return x; }
    //������ͨʳ���y����
    int loc_y()  { return y; }
    //��������ʳ���x����
    int spec_i() { return i; }
    //��������ʳ���y����
    int spec_j() { return j; }
    //����ʳ����ʧ
    void speFade();
    ~Food();
};