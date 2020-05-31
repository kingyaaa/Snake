#include "Snake.h"
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<iostream>
#include<thread>
#define SIZE 40
using namespace std;

Snake::Snake()
{
    score = 0;
    bonus = 0;
    time = 0;
    color = 1;
    loadimage(&EATEN, _T("Blank.jpg"), SIZE, SIZE);
    loadimage(&SPECIAL, _T("SpecialFood.jpg"), SIZE, SIZE);
}
void Snake::initial()
{
    //初始化的小蛇,加载图片
    if (color == 1) {
        loadimage(&SHUP, _T("SnakeHeadUp.jpg"), SIZE, SIZE);
        loadimage(&SHDOWN, _T("SnakeHeadDown.jpg"), SIZE, SIZE);
        loadimage(&SHLEFT, _T("SnakeHeadLeft.jpg"), SIZE, SIZE);
        loadimage(&SHRIGHT, _T("SnakeHeadRight.jpg"), SIZE, SIZE);
        loadimage(&RandomFood, _T("RedFood.jpg"), SIZE, SIZE);
        loadimage(&SHBODY, _T("RedBodyH.jpg"), SIZE, SIZE);
        loadimage(&SVBODY, _T("RedBodyV.jpg"), SIZE, SIZE);
    }
    if (color == 2) {
        loadimage(&SHUP, _T("YellowHeadUp.jpg"), SIZE, SIZE);
        loadimage(&SHDOWN, _T("YellowHeadDown.jpg"), SIZE, SIZE);
        loadimage(&SHLEFT, _T("YellowHeadLeft.jpg"), SIZE, SIZE);
        loadimage(&SHRIGHT, _T("YellowHeadRight.jpg"), SIZE, SIZE);
        loadimage(&RandomFood, _T("YellowFood.jpg"), SIZE, SIZE);
        loadimage(&SHBODY, _T("YellowBodyH.jpg"), SIZE, SIZE);
        loadimage(&SVBODY,_T("YellowBodyV.jpg"), SIZE, SIZE);
    }
    int i = 2;
    int j = 2;
    q.push(i, j, 4);
    loadHead(i, j, 4);
    for (; i < 4; i++) {
        putimage(i * SIZE, j * SIZE, &SHBODY);
        q.push(i + 1, j,4);
        loadHead(i, j, 4);
    }
    //产生随机食物,判断食物坐标的合法性
    f.randomFood();
    while (!q.judge(f.loc_x(),f.loc_y())) {
        f.randomFood();
    }
    putimage(f.loc_x() * SIZE, f.loc_y() * SIZE, &RandomFood);
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
void Snake::loadHead(int i, int j, int dir)
{
    if (dir == 1)	putimage(i * SIZE, j * SIZE, &SHUP);
    if (dir == 2)	putimage(i * SIZE, j * SIZE, &SHDOWN);
    if (dir == 3)	putimage(i * SIZE, j * SIZE, &SHLEFT);
    if (dir == 4)	putimage(i * SIZE, j * SIZE, &SHRIGHT);
    //插入蛇头图像(四个方向不相同)
}
bool Snake::Move(int i, int j, int right, int down,int dir,int limStep)
{
    int direction = dir;
    int x, y, count = 0,flag,tag;               //flag:标志是否吃到了食物
    char k;
    while (1) {
        settextcolor(BLACK);
        settextstyle(3 * SIZE / 4, 0, _T("微软雅黑"));
        char str[20];
        sprintf_s(str, "%s%d", " SCORE: ", score + bonus);
        outtextxy(10*SIZE,0, str);
        flag = 0;
        if (_kbhit()) {
            if(!changeDirection(i, j, direction,limStep))
                return false;
        }
        if (count != 0)
            Sleep(time);
        if (dir == 1 || dir == 2)
            putimage(i * SIZE, j * SIZE, &SVBODY);
        if (dir == 3|| dir == 4)
            putimage(i * SIZE, j * SIZE, &SHBODY);
        if (f.loc_x() == i + right && f.loc_y() == j + down && !f.special) {
            score++;
            putimage((i + right) * SIZE, (j + down) * SIZE, &EATEN);
            flag = 1;
        }
        //吃掉食物,食物消失
        if (f.loc_x() == i + right && f.loc_y() == j + down && f.special) {
            f.special = false;
            limStep = -1;
            bonus += 4;
            score++;
            putimage((i + right) * SIZE, (j + down) * SIZE, &EATEN);
            flag = 1;
        }
        //普通移动
        if (flag == 0) {
            q.pop(x, y, k);
            q.push(i + right, j + down,dir);
            loadHead(i + right, j + down, dir);
            if (limStep > 0)
                limStep--;//蛇每移动一步,限定步数少一步
            //限时食物消失
        }
        if (flag == 1) {
            q.push(i + right, j + down, dir);
            loadHead(i + right, j + down, dir);
            f.randomFood();
            while (!q.judge(f.loc_x(), f.loc_y())) {
                f.randomFood();
            }
            //吃到了第五个食物,则进入判断语句
            // 每吃掉5个普通食物，则食物变为限时食物，在给定的移动步数（比如30个）之后会自动消失,吃掉会加5分;
            if (score % 5 == 0) {
                f.special = true;
                //判断随机坐标是否与蛇的坐标或普通食物的坐标重合
                putimage(f.loc_x() * SIZE, f.loc_y() * SIZE, &SPECIAL);
                limStep = 20;
            }
            else {
                f.special = false;
                putimage(f.loc_x() * SIZE, f.loc_y() * SIZE, &RandomFood);
            }
        }
        if (!q.suicide(i + right, j + down)) {
            return false;
        }//后续ExitGame();
        i += right;
        j += down;
        if (limStep == 0) {
            limStep = -1;
            putimage(f.loc_x() * SIZE, f.loc_y() * SIZE, &EATEN);
            //限时消失后要产生一个新的食物
            f.randomFood();
            while (!q.judge(f.loc_x(), f.loc_y())) {
                f.randomFood();
            }
            putimage(f.loc_x() * SIZE, f.loc_y() * SIZE, &RandomFood);
        }
        count = 1;
    }
}
Snake::~Snake()
{

}