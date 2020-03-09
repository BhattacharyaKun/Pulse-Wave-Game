#pragma once
#include<iostream>
#include<conio.h>
#include <time.h>
#include<windows.h>
#include<ctime>
#include<chrono>
#include<string>
#include<thread>
#include<random>

static std::default_random_engine rG(time(0));
static std::uniform_int_distribution<int> exi(1, 20);
static int ex = exi(rG);

class game
{
public:
	game();
	char arr[22][42], traps[20][40];
	int moved = 0, press = 'a', pX = 20, pY = 2, eX = 1, eY = 40, toDraw[16][2], toDrawLight[16][2], key, u, d, l, r, c = 0, timeCount = 0, trapsTime = 0;
	bool gameEnd = false, won = false, trapDied = false;
	COORD coord = { 0,0 };

	void m_welS();
	void m_slowPrint();
	char m_cfi(char temp);
	void m_checkHit();
	void m_drawHit();
	void m_drawInit();
	void m_hidecursor();
	void m_enemyAI();
	void m_playerSpawn();
	void m_checkTrapHit();
	void m_movement();
	void m_draw();
	~game();
};

