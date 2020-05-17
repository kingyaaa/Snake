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
    //普通食物随机出现
    void randomFood();
    //特殊食物的出现
    int specialFood();
    void gotoxy(int i, int j);
    //返回普通食物的x坐标
    int loc_x()  { return x; }
    //返回普通食物的y坐标
    int loc_y()  { return y; }
    //返回特殊食物的x坐标
    int spec_i() { return i; }
    //返回特殊食物的y坐标
    int spec_j() { return j; }
    //特殊食物消失
    void speFade();
    ~Food();
};