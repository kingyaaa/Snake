#pragma once
#include"Snake.h"
#include<Windows.h>
#include<iomanip>
#include<iostream>
#include<conio.h>
using namespace std;
class Game//�ṩ����ӿڣ�
{
private:
    //��Ա����
    Snake snake;
    int time;
    int MaxScore;
public:
    Game(int max);
    void NewGame();//��Ϸ��ӭ����
    void Wall();//��ӡǽ�����꣨50��*��30+20��
    void PlayGame();//��Ϸ��ʼ:������Snake����Food��
    int ScoringBar() { return MaxScore; }//�Ʒ���
    int SetGame();//��Ϸ�Ѷ����ã�Easy,Normal,Hard;
    void ExitGame();//��Ϸ�������棺��snake.PlayGame()��ָ���
    void ScoreTop();//��ʾ�÷ּ�¼
    void gotoxy(int i,int j);
    ~Game();
};