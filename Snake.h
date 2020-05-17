#pragma once
#include"Deque.h"
#include"Food.h"
//class Food;
class Snake
{
private:
    int time,score,bonus;//初始化速度，长度,分数;
    Deque q;//链表实现的队列
    Food f;
    IMAGE SHBODY,SVBODY,EATEN;
    IMAGE RedRandomFood, SPECIAL;//GREENFood, YELLOW, SPECIAL;
public:
    Snake();
    //核心算法：初始化蛇的坐标后，每隔0.75秒移动一次，即打印时间的间隔；速度加快就是打印间隔缩短；（170）可作为正常速度，（200）作为简易模式，（100）困难；
    bool Move(int i, int j, int right, int up, int dir,int limStep);
    bool changeDirection(int i, int j,int dir,int limStep); //蛇头方向转移；
    void initial(int time);//游戏开始时初始化的小蛇
    int goal()const { return score + bonus; }//总得分，score为普通食物的得分,bonus为限时食物的得分
    void speed(int time1) { time = time1; }
    //bool knock_wall();//将蛇头与墙的坐标进行比较，判断是否撞墙
    ~Snake();
};