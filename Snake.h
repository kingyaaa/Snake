#pragma once
#include"Deque.h"
#include"Food.h"
//class Food;
class Snake
{
private:
    int time,score,bonus;//��ʼ���ٶȣ�����,����;
    Deque q;//����ʵ�ֵĶ���
    Food f;
    IMAGE SHBODY,SVBODY,EATEN;
    IMAGE RedRandomFood, SPECIAL;//GREENFood, YELLOW, SPECIAL;
public:
    Snake();
    //�����㷨����ʼ���ߵ������ÿ��0.75���ƶ�һ�Σ�����ӡʱ��ļ�����ٶȼӿ���Ǵ�ӡ������̣���170������Ϊ�����ٶȣ���200����Ϊ����ģʽ����100�����ѣ�
    bool Move(int i, int j, int right, int up, int dir,int limStep);
    bool changeDirection(int i, int j,int dir,int limStep); //��ͷ����ת�ƣ�
    void initial(int time);//��Ϸ��ʼʱ��ʼ����С��
    int goal()const { return score + bonus; }//�ܵ÷֣�scoreΪ��ͨʳ��ĵ÷�,bonusΪ��ʱʳ��ĵ÷�
    void speed(int time1) { time = time1; }
    //bool knock_wall();//����ͷ��ǽ��������бȽϣ��ж��Ƿ�ײǽ
    ~Snake();
};