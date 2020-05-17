#include "Game.h"
void Game::gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
Game::Game(int max)
{
	time = 0;
	//��ȡ��ǰ��ҵ���ߵ÷ּ�¼
	MaxScore = max;
}
void Game::NewGame()
{
	Wall();
	int i, j, ope = 0,flag = 1;
	i = 20, j = 12;
	gotoxy(24, 12);
	cout << "�� ʼ �� Ϸ";
	gotoxy(24, 14);
	cout << "�� �� �� ¼";
	gotoxy(20, 12);
	cout << "��";
	//ͨ�����¼�ѡ��ͬ�Ĺ���
	while (1) {
		if (!flag)
			return;
		if (_kbhit()) {
			char ch;
			ch = _getch();
			switch (ch) {
				//����:
			case 80: {
				if (j == 14)
					break;
				gotoxy(i, j);
				cout << "  ";
				ope = 1;
				j = j + 2;
				gotoxy(i, j);
				cout << "��";
				break;
			}
			case 13: {
				switch (ope) {
				case 0: {flag = 0; PlayGame(); break; }
				case 1: {flag = 0; ScoreTop(); break; }
				}
				break;
			}
			case 72: {
				if (j == 12)
					break;
				gotoxy(i, j);
				cout << "  ";
				ope = 0;
				j = j - 2;
				gotoxy(i, j);
				cout << "��";
				break;
			}
			}
		}
	}
}
//��ӡǽ������
void Game::Wall()//ǽ��60*30;
{
	//��ǽ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED);
	for (int j = 0; j < 60; j++) {
		gotoxy(j, 0);
		cout << "#";
	}
	for (int i = 0; i < 30; i++) {
		gotoxy(0, i);
		cout << "#";
	}
	for (int j = 0; j < 30; j++) {
		gotoxy(59, j);
		cout << "#";
	}
	for (int i = 0; i < 60; i++) {
		gotoxy(i, 29);
		cout << "#";
	}
	//gotoxy(70, 15);
	//cout << "��ǰ�÷�:";
}
void Game::ScoreTop()
{
	//������ߵ÷�;
	system("cls");
	Wall();
	gotoxy(28, 13);
	cout << MaxScore;
	Sleep(1000);
	system("cls");
}
int Game::SetGame()
{
	gotoxy(20, 12);
	cout << "  ";
	gotoxy(24, 10);
	cout << "�� �� ģ ʽ";
	gotoxy(24, 12);
	cout << "�� �� ģ ʽ";
	gotoxy(24, 14);
	cout << "�� �� ģ ʽ";
	gotoxy(20, 10);
	cout << "��";
	int i, j, ope = 0,count = 0,time;
	i = 20, j = 10;
	//ͨ�����¼�ѡ��ģʽ
	while (1) {
		ope = 0;
		if (_kbhit()) {
			char ch;
			ch = _getch();
			switch (ch) {
				//����:
			case 80: {
				if (j == 14)
					break;
				gotoxy(i, j);
				cout << "  ";
				ope++;
				count++;
				j = j + 2 * ope;
				gotoxy(i, j);
				cout << "��";
				break;
			}
			case 13: {
				switch (count) {
				case 0: {time = 200; break; }
				case 1: {time = 150; break; }
				case 2: {time = 100; break; }
				}
				system("cls");
				return time;
				break;
			}
			case 72: {
				if (j == 10)
					break;
				gotoxy(i, j);
				cout << "  ";
				ope--;
				count--;
				j = j + 2 * ope;
				gotoxy(i, j);
				cout << "��";
				break;
			}
			default:
				break;
			}
		}
	}
}
//��Ϸ��ʼ�������ߵ�"��ʼ����"
void Game::PlayGame()
{
	Wall();
	//ѡ���Ѷ�
	int t = SetGame();
	snake.speed(t);
	//��ʼ��Ϸ
	Wall();
	snake.initial(time);//С�߶�����
	ExitGame();
}
//�˳���Ϸ���棬��ʾGame Over�����յ÷�
 void Game::ExitGame()
{
	Sleep(1000);
	system("cls");
	Wall();
	gotoxy(28, 15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED);
	cout << "Game Over"<<endl;
	Sleep(1000);
	system("cls");
	Wall();
	gotoxy(26, 15);
	cout << "���յ÷֣�";
	cout << snake.goal();
	//��¼��ߵ÷�
	if(MaxScore < snake.goal())
		MaxScore = snake.goal();
	Sleep(1000);
	system("cls");
	//cout << endl << endl;
	//system("pause");
}
Game::~Game()
{
	
}