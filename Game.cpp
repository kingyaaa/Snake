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
	loadimage(&WELCOME, _T("GameStart.jpg"), 14 * SIZE, 14 * SIZE);
	loadimage(&REDSNAKE, _T("SnakeHeadUP.jpg"), 2 * SIZE, 2 * SIZE);
	loadimage(&YELLOWSNAKE, _T("YellowHeadUp.jpg"), 2 * SIZE, 2 * SIZE);
}
void Game::NewGame()
{
	int flag = 1;
	MOUSEMSG m;
	cleardevice();
	loadWelcome();
	settextstyle(3 * SIZE / 4, 0, _T("Arial Black"));
	outtextxy(7 * SIZE, 10 * SIZE, _T("Start"));
	outtextxy(7 * SIZE, 11 * SIZE, _T("Top Score"));
	outtextxy(7 * SIZE, 12 * SIZE, _T("Store"));
	while (flag) {
		FlushMouseMsgBuffer();
		m = GetMouseMsg();
		if (m.x >= 280 && m.x <= 350 && m.y >= 400 && m.y <= 430) {
			settextcolor(LIGHTBLUE);
			outtextxy(7 * SIZE, 10 * SIZE, _T("Start"));
			settextcolor(BLACK);
			outtextxy(7 * SIZE, 11 * SIZE, _T("Top Score"));
			outtextxy(7 * SIZE, 12 * SIZE, _T("Store"));
		}
		else if (m.x >= 280 && m.x <= 400 && m.y >= 440 && m.y <= 470) {
			settextcolor(BLACK);
			outtextxy(7 * SIZE, 10 * SIZE, _T("Start"));
			settextcolor(LIGHTBLUE);
			outtextxy(7 * SIZE, 11 * SIZE, _T("Top Score"));
			settextcolor(BLACK);
			outtextxy(7 * SIZE, 12 * SIZE, _T("Store"));
		}
		else if (m.x >= 280 && m.x <= 350 && m.y >= 480 && m.y <= 510) {
			settextcolor(BLACK);
			outtextxy(7 * SIZE, 10 * SIZE, _T("Start"));
			outtextxy(7 * SIZE, 11 * SIZE, _T("Top Score"));
			settextcolor(LIGHTBLUE);
			outtextxy(7 * SIZE, 12 * SIZE, _T("Store"));
		}
		else{
			settextcolor(BLACK);
			outtextxy(7 * SIZE, 10 * SIZE, _T("Start"));
			outtextxy(7 * SIZE, 11 * SIZE, _T("Top Score"));
			outtextxy(7 * SIZE, 12 * SIZE, _T("Store"));
		}
		//cout << m.x << endl;
		//cout << m.y << endl;
		switch (m.uMsg) {
			case WM_LBUTTONDOWN:	//点左键
			{
				if (m.x >= 280 && m.x <= 350 && m.y >= 400 && m.y <= 430){
					PlayGame();
					cleardevice();
					flag = 0;
				}
				if (m.x >= 280 && m.x <= 400 && m.y >= 440 && m.y <= 470) {
					ScoreTop();
				}
				if (m.x >= 280 && m.x <= 350 && m.y >= 480 && m.y <= 510) {
					Store();
				}
				break;
			}
			default:
				break;
		}
	}
}
void Game::Store()
{
	cleardevice();
	loadWelcome();
	putimage(5 * SIZE, 10 * SIZE, &REDSNAKE);
	putimage(9 * SIZE, 10 * SIZE, &YELLOWSNAKE);
	int flag = 1;
	MOUSEMSG m;
	while (flag) {
		FlushMouseMsgBuffer();
		m = GetMouseMsg();
		switch (m.uMsg) {
			case WM_LBUTTONDOWN:
			{
				if (m.x >= 200 && m.x <= 280 && m.y >= 400 && m.y <= 480) {
					snake.type(1);
					flag = 0;
				}
				if (m.x >= 360 && m.x <= 440 && m.y >= 400 && m.y <= 480) {
					snake.type(2);
					flag = 0;
				}
				break;
			}
			default:
				break;
		}
	}
	cleardevice();
	loadWelcome();
}
//打印墙的坐标
void Game::Wall()
{
	setlinestyle(PS_SOLID, 80);   //设置画线的大小
	setlinecolor(BLACK);
	line(0, 0, 16 * SIZE, 0);
	line(0, 16 * SIZE, 16 * SIZE, 16 * SIZE);
	line(0, 0, 0, 16 * SIZE);
	line(16 * SIZE, 0, 16 * SIZE, 16 * SIZE);
}
void Game::loadWelcome()
{
	Wall();
	putimage(1 * SIZE, 1 * SIZE, &WELCOME);
}
void Game::ScoreTop()
{
	//计算最高得分;
	loadWelcome();
	settextstyle(3 * SIZE / 4, 0, _T("Arial Black"));
	char s[10];
	settextcolor(RED);
	sprintf_s(s, "%s%d", "TOP: ",MaxScore);
	outtextxy(7 * SIZE, 11 * SIZE, s);
	Sleep(1000);
	cleardevice();
	loadWelcome();
	settextcolor(BLACK);
	settextstyle(3 * SIZE / 4, 0, _T("Arial Black"));
	outtextxy(7 * SIZE, 10 * SIZE, _T("Start"));
	outtextxy(7 * SIZE, 11 * SIZE, _T("Top Score"));
	outtextxy(7 * SIZE, 12 * SIZE, _T("Store"));
}
int Game::SetGame()
{
	loadWelcome();
	settextstyle(3 * SIZE / 4, 0, _T("Arial Black"));
	outtextxy(7 * SIZE, 10 * SIZE, _T("E  A  S  Y "));
	outtextxy(7 * SIZE, 11 * SIZE, _T("N O R M A L"));
	outtextxy(7 * SIZE, 12 * SIZE, _T("H  A  R  D "));
	MOUSEMSG m;
	int flag = 1,time;
	while (flag) {
		FlushMouseMsgBuffer();
		m = GetMouseMsg();
		cout << m.x << endl;
		cout << m.y << endl;
		if (m.x >= 280 && m.x <= 430 && m.y >= 400 && m.y <= 430) {
			settextcolor(LIGHTRED);
			outtextxy(7 * SIZE, 10 * SIZE, _T("E  A  S  Y "));
			settextcolor(BLACK);
			outtextxy(7 * SIZE, 11 * SIZE, _T("N O R M A L"));
			outtextxy(7 * SIZE, 12 * SIZE, _T("H  A  R  D "));
		}
		else if (m.x >= 280 && m.x <= 430 && m.y >= 440 && m.y <= 470) {
			settextcolor(BLACK);
			outtextxy(7 * SIZE, 10 * SIZE, _T("E  A  S  Y "));
			settextcolor(LIGHTRED);
			outtextxy(7 * SIZE, 11 * SIZE, _T("N O R M A L"));
			settextcolor(BLACK);
			outtextxy(7 * SIZE, 12 * SIZE, _T("H  A  R  D "));
		}
		else if (m.x >= 280 && m.x <= 430 && m.y >= 480 && m.y <= 510) {
			settextcolor(BLACK);
			outtextxy(7 * SIZE, 10 * SIZE, _T("E  A  S  Y "));
			outtextxy(7 * SIZE, 11 * SIZE, _T("N O R M A L"));
			settextcolor(LIGHTRED);
			outtextxy(7 * SIZE, 12 * SIZE, _T("H  A  R  D "));
		}
		else {
			settextcolor(BLACK);
			outtextxy(7 * SIZE, 10 * SIZE, _T("E  A  S  Y "));
			outtextxy(7 * SIZE, 11 * SIZE, _T("N O R M A L"));
			outtextxy(7 * SIZE, 12 * SIZE, _T("H  A  R  D "));
		}
		switch (m.uMsg) {
		case WM_LBUTTONDOWN:	//点左键
		{
			if (m.x >= 280 && m.x <= 430 && m.y >= 400 && m.y <= 430) {
				time = 150;
				flag = 0;
			}
			if (m.x >= 280 && m.x <= 430 && m.y >= 440 && m.y <= 470) {
				time = 100;
				flag = 0;
			}
			if (m.x >= 280 && m.x <= 430 && m.y >= 480 && m.y <= 510) {
				time = 70;
				flag = 0;
			}
			break;
		}
		default:
			break;
		}
	}
	return time;
}
//游戏开始，调用蛇的"初始函数"
void Game::PlayGame()
{
	cleardevice();
	int t = SetGame();
	snake.speed(t);
	//开始游戏
	cleardevice();
	Wall();
	snake.initial();//小蛇动起来
	ExitGame();
}
//退出游戏界面，显示Game Over和最终得分
 void Game::ExitGame()
{
	Sleep(1000);
	cleardevice();
	settextstyle(2 * SIZE, 0, _T("Arial Black"));
	settextcolor(RED);
	outtextxy(4 * SIZE, 4 * SIZE, _T("Game Over"));
	char str[20];
	sprintf_s(str, "%s%d", "SCORE -- ", snake.goal());
	outtextxy(4 * SIZE, 6 * SIZE, str);
	settextcolor(BLACK);	
	//记录最高得分
	if(MaxScore < snake.goal())
		MaxScore = snake.goal();
	Sleep(2000);
	cleardevice();
}
Game::~Game()
{
	
}