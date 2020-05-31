#pragma once
#include"Deque.h"
#include"Food.h"
class Snake
{
private:
    int time,score,bonus,color;//��ʼ���ٶȣ�����,����;
    Deque q;//����ʵ�ֵĶ���
    Food f;
    IMAGE SHBODY,SVBODY,EATEN;
    IMAGE RandomFood, SPECIAL;//GREENFood, YELLOW, SPECIAL;
    IMAGE SHUP, SHDOWN, SHLEFT, SHRIGHT;
public:
    Snake();
    //�����㷨����ʼ���ߵ������ÿ��0.75���ƶ�һ�Σ�����ӡʱ��ļ�����ٶȼӿ���Ǵ�ӡ������̣���150������Ϊ�����ٶȣ���100����Ϊ����ģʽ����70�����ѣ�
    bool Move(int i, int j, int right, int up, int dir,int limStep);
    bool changeDirection(int i, int j,int dir,int limStep); //��ͷ����ת�ƣ�
    void initial();//��Ϸ��ʼʱ��ʼ����С��
    void type(int t) { color = t; }
    int goal()const { return score + bonus; }//�ܵ÷֣�scoreΪ��ͨʳ��ĵ÷�,bonusΪ��ʱʳ��ĵ÷�
    void loadHead(int i,int j,int dir);
    void speed(int time1) { time = time1; }
    ~Snake();
};