#pragma once
#include"Snake.h"
#include<Windows.h>
#include<iomanip>
#include<iostream>
#include<conio.h>
using namespace std;
class Game//提供对外接口；
{
private:
    //成员对象
    Snake snake;
    int time;
    int MaxScore;
public:
    Game(int max);
    void NewGame();//游戏欢迎界面
    void Wall();//打印墙的坐标（50）*（30+20）
    void PlayGame();//游戏开始:调用类Snake和类Food。
    int ScoringBar() { return MaxScore; }//计分栏
    int SetGame();//游戏难度设置：Easy,Normal,Hard;
    void ExitGame();//游戏结束界面：由snake.PlayGame()的指令触发
    void ScoreTop();//显示得分纪录
    void gotoxy(int i,int j);
    ~Game();
};