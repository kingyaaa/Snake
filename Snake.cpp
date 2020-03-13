#include "Snake.h"
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<iostream>
#define time1 200
using namespace std;

Snake::Snake()
{
    //长度可以等价计分;速度等式于Sleep间隔;
    length = 0;
    speed = 0;
}
/*void gotoxy(int x, int y)
{
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, pos);
}*/
void Snake::initial()
{
    int flag = 1;
    //撤销结点时将结点中的数据赋值给x,y,k
    int x, y;
    char k;
    //初始化的小蛇
    int i = 2;
    int j = 2;
    q.push(i, j);
    for (; i < 12;i++) {
        q.gotoxy(i,j);
        cout << "X";
        //cout << ">";
        q.push(i + 1, j);
    }
    //初始移动方向：向右
    while (1) {
        Sleep(time1);
        q.gotoxy(i, j);
        //cout << ">";//将原蛇头改为“X”
        cout << "X";
        q.pop(x, y, k);
        q.push(i + 1, j);//添加新蛇头;
        i++;
        //q.pop(x, y, k);
        if (_kbhit()) {
            //i--;
            char ch;
            ch = _getch();
            switch (ch) {
                
                //向上;
            case 72: {
                moveUp(i, j);
                break;
            }
                   //向下;
            case 80: {
                moveDown(i, j);
                break;
            }
            default:
                break;
            }
        }
    }
}
/*void Snake::changeDirection(int i,int j)
{
    //蛇在无限循环中每次移动一格，如果按下方向键就调整移动的方向，判断移动后是否会撞到了身体或墙壁；
    char ch;
    ch = _getch();
        switch (ch) {
    //向上;
            case 72: {
            moveUp(i, j);
            break; 
        }
    //向下;
            case 80: {
            moveDown(i, j);
            break;
        }
    //向左;
            case 75: {
            moveLeft(i, j);
            break;
        }
            case 77:{ 
            moveRight(i, j);
            break;
        }
    }
    //return false;///？
}*/
void Snake::moveDown(int i, int j)
{
    //撤销结点时将结点中的数据赋值给x,y,k
    int x, y;
    char k;
    //Sleep(1000);
    q.gotoxy(i, j);
    cout << "X";
    //Sleep(1000);
    //cout << "v";
    q.pop(x, y, k);
    q.push(i, j + 1);
    if (!q.suicide(i, j + 1)) {
        ExitGame();
        return;
    }
    j++;
    //只能左右转;
    while (1) {
        /*if (_kbhit()) {
            changeDirection(i, j);
        }*/
        if (_kbhit()) {
            char ch;
            ch = _getch();
            switch (ch) {
            case 75: {
                moveLeft(i, j);
                break;
            }
            case 77: {
                moveRight(i, j);
                break;
            }
            default:
                break;
            }
        }
        Sleep(time1);
        q.gotoxy(i, j);
        cout << "X";
        //cout << "V";
        //向下
        q.pop(x, y, k);
        q.push(i, j + 1);//增加蛇身，打印蛇头;
        if (!q.suicide(i, j + 1))
            ExitGame();
        //q.suicide(i,j + 1);
        j++;
        //再次改变方向;
       
    }
   
}
void Snake::moveUp(int i, int j)
{
    int x, y;
    char k;
    //Sleep(20);
    q.gotoxy(i, j);
    cout << "X";
    //Sleep(1000);
    //cout << "v";
    q.pop(x, y, k);
    q.push(i, j - 1);
    if (!q.suicide(i, j - 1)) {
        ExitGame();//定义一个flag,自杀后flag设为0，
        return;
    }
    j--;
    /*while (1) {
        if (_kbhit()) {
            changeDirection(i, j);
        }*/
    while (1) {
        /*if (_kbhit()) {
            changeDirection(i, j);
        }*/
        if (_kbhit()) {
            char ch;
            ch = _getch();
            switch (ch) {
            case 75: {
                moveLeft(i, j);
                break;
            }
            case 77: {
                moveRight(i, j);
                break;
            }
            default:
                break;
            }
        }
        Sleep(time1);
        q.gotoxy(i, j);
        cout << "X";
        //cout << "V";
        //向下
        q.pop(x, y, k);
        q.push(i, j - 1);//增加蛇身，打印蛇头;
        //q.suicide(i,j - 1);
        if (!q.suicide(i, j - 1)) {
            ExitGame();
            return;
        }
        j--;
        //再次改变方向;

    }
}

void Snake::moveRight(int i, int j)
{
    int x, y;
    char k;
    //Sleep(20);
    q.gotoxy(i, j);
    cout << "X";
    //Sleep(1000);
    //cout << ">";
    q.pop(x, y, k);
    q.push(i + 1, j);
    if (!q.suicide(i + 1, j)) {
        ExitGame();
        return;
    }
    i++;
    while (1) {
        if (_kbhit()) {
            char ch;
            ch = _getch();
            switch (ch) {
                //向上;
            case 72: {
                moveUp(i, j);
                break;
            }
                   //向下;
            case 80: {
                moveDown(i, j);
                break;
            } //changeDirection(i, j);
            default:
                break;
            }
        }
        Sleep(time1);
        q.gotoxy(i, j);
        cout << "X";
        //cout << "Z";
        //cout << ">";
        //cout << "I";
        //向右
        q.pop(x, y, k);
        q.push(i + 1, j);//增加蛇身，打印蛇头;
        if (!q.suicide(i + 1, j)) {
            ExitGame();
            return;
        }
        i++;
        //再次改变方向;
    }
}
void Snake::moveLeft(int i, int j)
{
    int x, y;
    char k;
    //Sleep(1000);
    q.gotoxy(i, j);
    cout << "X";
    //Sleep(1000);
    //cout << ">";
    q.pop(x, y, k);
    q.push(i - 1, j);
    if (!q.suicide(i - 1, j)) {
        ExitGame();
        return;
    }
    i--;
    while (1) {
        if (_kbhit()) {
            //changeDirection(i, j);
            char ch;
            ch = _getch();
            switch (ch) {
                //向上;
            case 72: {
                moveUp(i, j);
                break;
            }
                   //向下;
            case 80: {
                moveDown(i, j);
                break;
            } //changeDirection(i, j);
            default:
                break;
            }
        }
        Sleep(time1);
        q.gotoxy(i, j);
        cout << "X";
        //cout << "Z";
        //cout << ">";
        //cout << "I";
        //向右
        q.pop(x, y, k);
        q.push(i - 1, j);//增加蛇身，打印蛇头;
        if (!q.suicide(i - 1, j)) {
            ExitGame();
            return;
        }
        i--;
        //再次改变方向;
    }
}
void Snake::ExitGame()
{
    system("cls");
    cout << "Game Over";
}
Snake::~Snake()
{

}