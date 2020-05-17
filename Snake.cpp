#include "Snake.h"
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<iostream>
#define SIZE 40
using namespace std;

Snake::Snake()
{
    score = 0;
    bonus = 0;
    time = 0;
}
void Snake::initial(int time1)
{
    time = time1;
    loadimage(&SHBODY, _T("BodyH.jpg"), SIZE, SIZE);
    loadimage(&SVBODY, _T("Body.jpg"), SIZE, SIZE);
    loadimage(&EATEN, _T("Blank.jpg"), SIZE, SIZE);
    loadimage(&RedRandomFood, _T("RedFood.jpg"), SIZE, SIZE);
    loadimage(&SPECIAL, _T("SpecialFood.jpg"), SIZE, SIZE);
    //��ʼ����С��
    int i = 2;
    int j = 2;
    q.push(i, j, 4);
    //putimage(i * SIZE, j * SIZE, &SHRIGHT);
    for (; i < 4; i++) {
        //q.gotoxy(i, j);
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
        //    FOREGROUND_RED | FOREGROUND_GREEN);
        //system("color 02");
        //cout << "X";
        putimage(i * SIZE, j * SIZE, &SHBODY);
        q.push(i + 1, j,4);
    }
    //�������ʳ��,�ж�ʳ������ĺϷ���
    f.randomFood();
    while (!q.judge(f.loc_x(),f.loc_y())) {
        f.randomFood();
    }
    putimage(f.loc_x() * SIZE, f.loc_y() * SIZE, &RedRandomFood);
    Move(i, j, 1, 0, 4,-1);
    //��ʼ�ƶ���������
}

bool Snake::changeDirection(int i,int j,int dir,int limStep)
{
    //���򡪡��ϣ�1���£�2����3���ң�4;
    int flag = 1,right,down,cur_dir,step = limStep;
    //if (_kbhit()) {
        char ch;
        ch = _getch();
        switch (ch) {
        //����
        case 75: {
            cur_dir = 3;
            //ԭ�������ϻ������ߣ����������
            if (dir == 1 || dir == 2) {
                right = -1;
                down = 0;
                flag = Move(i, j, right, down,cur_dir,step);
                if (flag == 0)
                    return false;

            }
            break;
        }
        //����
        case 77: {
            cur_dir = 4;
            if (dir == 1 || dir == 2) {
                right = 1;
                down = 0;
                //Move(i, j, right, down, cur_dir);
                flag = Move(i, j, right, down, cur_dir,step);
                if (flag == 0)
                    return false;
            }
            break;
        }
        //����
        case 72: {
            cur_dir = 1;
            if (dir == 3 || dir == 4) {
                right = 0;
                down = -1;
                //Move(i, j, right, down,cur_dir);
                flag = Move(i, j, right, down, cur_dir,step);
                if (flag == 0)
                    return false;
            }
            break;
        }
        //����
        case 80: {
            cur_dir = 2;
            if (dir == 3 || dir == 4) {
                right = 0;
                down = 1;
                //Move(i, j, right, down,cur_dir);
                flag = Move(i, j, right, down, cur_dir,step);
                if (flag == 0)
                    return false;
            }
            break;
        }
        default:
            break;
        }
    //}
}

bool Snake::Move(int i, int j, int right, int down,int dir,int limStep)
{
    int direction = dir;
    int x, y, count = 0,flag,tag;               //tag:��־�Ƿ�Ե�����ʱʳ��
                                                //flag:��־�Ƿ�Ե�����ͨʳ��
    char k;
    while (1) {
        //q.gotoxy(80, 15);
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
        //    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        //cout << "��ǰ�÷�:";
        //cout << goal();
        flag = 0;
        tag = 0;
        if (_kbhit()) {
            if(!changeDirection(i, j, direction,limStep))
                return false;
        }
        if(count!=0)
            Sleep(time);
        if(dir == 1 || dir == 2)
            putimage(i * SIZE, j * SIZE, &SVBODY);
        if(dir == 3|| dir == 4)
            putimage(i * SIZE, j * SIZE, &SHBODY);
        //q.gotoxy(i, j);
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
        //    FOREGROUND_RED | FOREGROUND_GREEN);
        //cout << "X"
        //�Ե���ʱʳ��;
        if (f.spec_i() == i + right && f.spec_j() == j + down) {
            limStep = -1;
            //q.gotoxy(i + right, j + down);
            //cout << " ";
            putimage((i + right) * SIZE, (j + down) * SIZE, &EATEN);
            //����ʱʳ��������޸�Ϊ(0,0),��ֹ���ٴε���λ��ʱ���ⴥ���ж����
            f.speFade();
            //��ʱʳ�� +5 ��
            tag = 1;
        }
        if (tag == 1) {
            bonus += 5;
            limStep = -1;
            q.push(i + right, j + down,dir);
        }
        //�Ե���ͨʳ��
        if (tag != 1 &&  f.loc_x() == i + right && f.loc_y() == j + down) {
            putimage((i + right) * SIZE, (j + down) * SIZE, &EATEN);
            //q.gotoxy(i + right, j + down);
            //cout << " ";
            flag = 1;
        }
        //��ͨ�ƶ�
        if (flag == 0 && tag == 0) {
            q.pop(x, y, k);
            q.push(i + right, j + down,dir);
            if (limStep > 0)
                limStep--;//��ÿ�ƶ�һ��,�޶�������һ��
            //��ʱʳ����ʧ
        }
        if (flag == 1) {
            score++;
            q.push(i + right, j + down, dir);
            f.randomFood();
            while (!q.judge(f.loc_x(), f.loc_y())) {
                f.randomFood();
            }
            putimage(f.loc_x() * SIZE, f.loc_y() * SIZE, &RedRandomFood);
            //�Ե��˵����ʳ��,������ж����
            //if (flag == 1 && score % 3 == 0) {// ÿ�Ե�5����ͨʳ����Ӳ���һ����ʱʳ��ڸ������ƶ�����������30����֮����Զ���ʧ,�Ե����5��;
            if (score % 3 == 0) {
                f.specialFood();
                //�ж���������Ƿ����ߵ��������ͨʳ��������غ�
                while (!q.judge(f.spec_i(), f.spec_j())) {
                    f.specialFood();
                }
                putimage(f.spec_i() * SIZE, f.spec_j() * SIZE, &SPECIAL);
                limStep = 21;//��������̵����⣬������һ��
            }
        }
        //limStep = 10; ͬʱ������ʱʳ�����ͨʳ��
        if (!q.suicide(i + right, j + down)) {
            return false;
        }//����ExitGame();
        i += right;
        j += down;
        if (limStep == 0) {
            //q.gotoxy(f.spec_i(), f.spec_j());
            //cout << " ";
            putimage(f.spec_i() * SIZE, f.spec_j() * SIZE, &EATEN);
            f.speFade();
        }
        count = 1;
    }
}
Snake::~Snake()
{

}