#include "Snake.h"
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<iostream>
#define time1 200
using namespace std;

Snake::Snake()
{
    //���ȿ��ԵȼۼƷ�;�ٶȵ�ʽ��Sleep���;
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
    //�������ʱ������е����ݸ�ֵ��x,y,k
    int x, y;
    char k;
    //��ʼ����С��
    int i = 2;
    int j = 2;
    q.push(i, j);
    for (; i < 12;i++) {
        q.gotoxy(i,j);
        cout << "X";
        //cout << ">";
        q.push(i + 1, j);
    }
    //��ʼ�ƶ���������
    while (1) {
        Sleep(time1);
        q.gotoxy(i, j);
        //cout << ">";//��ԭ��ͷ��Ϊ��X��
        cout << "X";
        q.pop(x, y, k);
        q.push(i + 1, j);//�������ͷ;
        i++;
        //q.pop(x, y, k);
        if (_kbhit()) {
            //i--;
            char ch;
            ch = _getch();
            switch (ch) {
                
                //����;
            case 72: {
                moveUp(i, j);
                break;
            }
                   //����;
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
    //��������ѭ����ÿ���ƶ�һ��������·�����͵����ƶ��ķ����ж��ƶ����Ƿ��ײ���������ǽ�ڣ�
    char ch;
    ch = _getch();
        switch (ch) {
    //����;
            case 72: {
            moveUp(i, j);
            break; 
        }
    //����;
            case 80: {
            moveDown(i, j);
            break;
        }
    //����;
            case 75: {
            moveLeft(i, j);
            break;
        }
            case 77:{ 
            moveRight(i, j);
            break;
        }
    }
    //return false;///��
}*/
void Snake::moveDown(int i, int j)
{
    //�������ʱ������е����ݸ�ֵ��x,y,k
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
    //ֻ������ת;
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
        //����
        q.pop(x, y, k);
        q.push(i, j + 1);//����������ӡ��ͷ;
        if (!q.suicide(i, j + 1))
            ExitGame();
        //q.suicide(i,j + 1);
        j++;
        //�ٴθı䷽��;
       
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
        ExitGame();//����һ��flag,��ɱ��flag��Ϊ0��
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
        //����
        q.pop(x, y, k);
        q.push(i, j - 1);//����������ӡ��ͷ;
        //q.suicide(i,j - 1);
        if (!q.suicide(i, j - 1)) {
            ExitGame();
            return;
        }
        j--;
        //�ٴθı䷽��;

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
                //����;
            case 72: {
                moveUp(i, j);
                break;
            }
                   //����;
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
        //����
        q.pop(x, y, k);
        q.push(i + 1, j);//����������ӡ��ͷ;
        if (!q.suicide(i + 1, j)) {
            ExitGame();
            return;
        }
        i++;
        //�ٴθı䷽��;
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
                //����;
            case 72: {
                moveUp(i, j);
                break;
            }
                   //����;
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
        //����
        q.pop(x, y, k);
        q.push(i - 1, j);//����������ӡ��ͷ;
        if (!q.suicide(i - 1, j)) {
            ExitGame();
            return;
        }
        i--;
        //�ٴθı䷽��;
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