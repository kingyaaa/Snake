#include "Snake.h"
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<iostream>
//#define time1 150
#define SIZE 40
using namespace std;

Snake::Snake()
{
    score = 0;
    bonus = 0;
    time1 = 0;
}
void Snake::initial(int time1)
{
    loadimage(&SHBODY, _T("BodyH.jpg"), SIZE, SIZE);
    loadimage(&SVBODY, _T("Body.jpg"), SIZE, SIZE);
    loadimage(&EATEN, _T("Blank.jpg"), SIZE, SIZE);
    //撤销结点时将结点中的数据赋值给x,y,k
    int x, y;
    char k;
    //初始化的小蛇
    int i = 2;
    int j = 2;
    q.push(i, j,4);
    //putimage(i * SIZE, j * SIZE, &SHRIGHT);
    for (; i < 4; i++) {
        //q.gotoxy(i, j);
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
        //    FOREGROUND_RED | FOREGROUND_GREEN);
        //system("color 02");
        //cout << "X";
        putimage(i * SIZE, j * SIZE, &SHBODY);
        q.push(i + 1, j,4);
        //putimage((i + 1) * SIZE, j * SIZE, &SHRIGHT);
    }

    //f.randomFood();
    Move(i, j, 1, 0, 4,-1);
    //初始移动方向：向右
}

bool Snake::changeDirection(int i,int j,int dir,int limStep)
{
    //方向——上：1，下：2，左：3，右：4;
    int flag = 1,right,down,cur_dir,step = limStep;
    //if (_kbhit()) {
        char ch;
        ch = _getch();
        switch (ch) {
        //向左
        case 75: {
            cur_dir = 3;
            //原本是向上或向下走，则符合条件
            if (dir == 1 || dir == 2) {
                right = -1;
                down = 0;
                flag = Move(i, j, right, down,cur_dir,step);
                if (flag == 0)
                    return false;

            }
            break;
        }
        //向右
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
        //向上
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
        //向下
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
    int x, y, count = 0,flag,tag;
    char k;
    while (1) {
        //q.gotoxy(80, 15);
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
        //    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        //cout << "当前得分:";
        //cout << goal();
        flag = 0;
        tag = 0;
        if (_kbhit()) {
            if(!changeDirection(i, j, direction,limStep))
                return false;
        }
        if(count!=0)
            Sleep(time1);
        if(dir == 1 || dir == 2)
            putimage(i * SIZE, j * SIZE, &SVBODY);
        if(dir == 3|| dir == 4)
            putimage(i * SIZE, j * SIZE, &SHBODY);
        //q.gotoxy(i, j);
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
        //    FOREGROUND_RED | FOREGROUND_GREEN);
        //cout << "X";
        
        
        //吃到限时食物;
        if (f.spec_i() == i + right && f.spec_j() == j + down) {
            limStep = -1;
            //q.gotoxy(i + right, j + down);
            //cout << " ";
            putimage((i + right) * SIZE, (j + down) * SIZE, &EATEN);
            //将限时食物的坐标修改为(0,0),防止蛇再次到此位置时意外触发判断语句
            f.speFade();
            //限时食物 +5 分
            tag = 1;
        }
        if (tag == 1) {
            bonus += 5;
            q.push(i + right, j + down,dir);
        }

        //吃掉普通食物
        if (f.loc_x() == i + right && f.loc_y() == j + down) {
            putimage((i + right) * SIZE, (j + down) * SIZE, &EATEN);
            //q.gotoxy(i + right, j + down);
            //cout << " ";
            flag = 1;
        }
        //普通移动
        if (flag == 0 && tag == 0) {
            q.pop(x, y, k);
            q.push(i + right, j + down,dir);
            if (limStep > 0)
                limStep--;//蛇每移动一步,限定步数少一步
            //限时食物消失
            if (limStep == 0) {
                //q.gotoxy(f.spec_i(), f.spec_j());
                //cout << " ";
                putimage(f.spec_i() * SIZE, f.spec_j() * SIZE, &EATEN);
                f.speFade();
            }
        }
        if (flag == 1) {
            score++;
            f.randomFood();
            //吃到了第五个食物,则进入判断语句
            if (score % 5 == 0) {// 每吃掉5个普通食物，附加产生一个限时食物，在给定的移动步数（比如30个）之后会自动消失,吃掉会加5分;
                f.specialFood();
                limStep = 31;//因程序流程的问题，多增加一步
            }
            q.push(i + right, j + down,dir);
            if (limStep > 0) {
                limStep--;
                if (limStep == 0) {

                    //q.gotoxy(f.spec_i(), f.spec_j());
                    //cout << " ";
                    putimage(f.spec_i() * SIZE, f.spec_j() * SIZE, &EATEN);
                    f.speFade();
                }
            }
        }
        //limStep = 30; 同时出现限时食物和普通食物
        if (!q.suicide(i + right, j + down)) {
            return false;
        }//后续ExitGame();
        i += right;
        j += down;
        count = 1;
    }
}
Snake::~Snake()
{

}