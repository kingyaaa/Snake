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
	//获取此前玩家的最高得分记录
	MaxScore = max;
}
void Game::NewGame()
{
	Wall();
	snake.initial(120);
	//PlayGame();
	/*int i, j, ope = 0,flag = 1;
	i = 20, j = 12;
	//gotoxy(24, 12);
	//cout << "开 始 游 戏";
	outtextxy(24 * SIZE, 12 * SIZE, _T("开始游戏"));
	//gotoxy(24, 14);
	//cout << "最 高 纪 录";
	outtextxy(24*SIZE, 14*SIZE, _T("最高纪录"));
	//gotoxy(20, 12);
	//cout << "→";
	//outtextxy(20*SIZE, 12*SIZE, _T("→"));
	//通过上下键选择不同的功能
	MOUSEMSG m;
	while (1) {
		FlushMouseMsgBuffer();
		m = GetMouseMsg();
		if (!flag)
			return;
		//if (_kbhit()) {
			//char ch;
			//ch = _getch();
			switch (m.uMsg) {
			case WM_LBUTTONDOWN:	//点左键
			{
				if (m.x >= 24 * SIZE && m.x <= 27 * SIZE && m.y == 12 * SIZE)
				{
					flag = 0;
					PlayGame();
				}
				if (m.x >= 24 * SIZE && m.x <= 27 * SIZE && m.y == 14 * SIZE) {
					flag = 0;
					ScoreTop();
				}
			//case 80: {
				//if (j == 14 * SIZE)
				//	break;
				//gotoxy(i, j);
				//cout << "  ";
				//ope = 1;
				//j = j + 2;
				//gotoxy(i, j);
				//cout << "→";
				//break;
			//}
			//case 13: {
			//	switch (ope) {
			//	case 0: {flag = 0; PlayGame(); break; }
			//	case 1: {flag = 0; ScoreTop(); break; }
			//	}
			//	break;
			//}
			//case 72: {
			//	if (j == 12)
			//		break;
			//	gotoxy(i, j);
			//	cout << "  ";
			//	ope = 0;
			//	j = j - 2;
			//	gotoxy(i, j);
			//	cout << "→";
			//	break;
			//}
				break;
			}
			default:
				break;
		}
	}*/
}
//打印墙的坐标
void Game::Wall()//墙是60*30;
{
	//红墙
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
	//	FOREGROUND_RED);
	setlinestyle(PS_SOLID, 80);   //设置画线的大小
	setlinecolor(RED);
	line(0, 0, 16 * SIZE, 0);
	line(0, 12 * SIZE, 16 * SIZE, 12 * SIZE);
	line(0, 0, 0, 12 * SIZE);
	line(16 * SIZE, 0, 16 * SIZE, 12 * SIZE);
	/*for (int j = 0; j < 60; j++) {
		//gotoxy(j, 0);
		//cout << "#";
	}*/
	//for (int i = 0; i < 30; i++) {
		//gotoxy(0, i);
		//cout << "#";
	//}
	//for (int j = 0; j < 30; j++) {
		//gotoxy(59, j);
		//cout << "#";
	//}
	/*for (int i = 0; i < 60; i++) {
		gotoxy(i, 29);
		cout << "#";
	}
	//gotoxy(70, 15);
	//cout << "当前得分:";
	*/
}
void Game::ScoreTop()
{
	//计算最高得分;
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
	cout << "简 易 模 式";
	gotoxy(24, 12);
	cout << "正 常 模 式";
	gotoxy(24, 14);
	cout << "困 难 模 式";
	gotoxy(20, 10);
	cout << "→";
	int i, j, ope = 0,count = 0,time;
	i = 20, j = 10;
	//通过上下键选择模式
	while (1) {
		ope = 0;
		if (_kbhit()) {
			char ch;
			ch = _getch();
			switch (ch) {
				//向下:
			case 80: {
				if (j == 14)
					break;
				gotoxy(i, j);
				cout << "  ";
				ope++;
				count++;
				j = j + 2 * ope;
				gotoxy(i, j);
				cout << "→";
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
				cout << "→";
				break;
			}
			default:
				break;
			}
		}
	}
}
//游戏开始，调用蛇的"初始函数"
void Game::PlayGame()
{
	Wall();
	//选择难度
	int t = SetGame();
	snake.speed(t);
	//开始游戏
	Wall();
	snake.initial(time);//小蛇动起来
	ExitGame();
}
//退出游戏界面，显示Game Over和最终得分
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
	cout << "最终得分：";
	cout << snake.goal();
	//记录最高得分
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