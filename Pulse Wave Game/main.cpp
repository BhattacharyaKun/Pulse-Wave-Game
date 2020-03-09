#include "game.h"
#include <iostream>
#include<ctime>
#include<windows.h>
#include<MMSystem.h>
#include<conio.h>

int main()
{
	game G;
	
	G.m_hidecursor();
	PlaySound(L"Audio/COS.wav", NULL,SND_LOOP | SND_ASYNC);
	G.m_slowPrint();
	G.m_welS();
	G.m_drawInit();
	G.m_playerSpawn();
	G.m_draw();
	while (!G.gameEnd)
	{
		G.m_movement();
	}
	if (G.won)
	{
		system("cls");
		std::cout << " ________________________________________ " << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|        YOU ESCAPED THE KILLER          |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|                                        |" << std::endl;
		std::cout << "|________________________________________|" << std::endl;
		PlaySound(L"Audio/W1.wav", NULL, SND_SYNC);
		PlaySound(L"Audio/W2.wav", NULL, SND_SYNC);
		PlaySound(L"Audio/W3.wav", NULL, SND_SYNC);
	}
	else
	{
		system("cls");
		if (G.trapDied)
		{
			std::cout << " ________________________________________ " << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|     YOU STEPPED ON A TRAP AND DIED     |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|________________________________________|" << std::endl;
			PlaySound(L"Audio/D.wav", NULL, SND_SYNC);
		}
		else
		{
			std::cout << " ________________________________________ " << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|            ENEMY KILLED YOU            |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|                                        |" << std::endl;
			std::cout << "|________________________________________|" << std::endl;
			PlaySound(L"Audio/D.wav", NULL, SND_SYNC);
		}
	}
	return 0;
}