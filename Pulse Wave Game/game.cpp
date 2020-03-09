#include "game.h"


game::game() {};
char game::m_cfi(char temp)
{
	press = temp;
	int seconds = 1;
	while (seconds != 0) {
		if (_kbhit()) {
			press = _getch();
			break;
		}
		Sleep(200);
		--seconds;
	}
	return press;
}
void game::m_welS()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			toDraw[i][j] = NULL;
			toDrawLight[i][j] = NULL;
		}
	}
	timeCount++;
	std::cout << " ________________________________________ " << std::endl;
	std::cout << "|                                        |" << std::endl;
	std::cout << "| ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	std::cout << "          THE PULSE WAVE GAME          ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "|" << std::endl;
	std::cout << "|                                        |" << std::endl;
	std::cout << "|              HOW TO PLAY               |" << std::endl;
	std::cout << "|   You use your Pulse Power to detect   |" << std::endl;
	std::cout << "| nearby objects, pulse only regenerates |" << std::endl;
	std::cout << "|after 5 moves, it can be used by hitting|" << std::endl;
	std::cout << "|            the SPACE button            |" << std::endl;
	std::cout << "|                                        |" << std::endl;
	std::cout << "| Your goal in the game is to evade the  |" << std::endl;
	std::cout << "|killer and escape his room while evading|" << std::endl;
	std::cout << "|         the traps in his room.         |" << std::endl;
	std::cout << "|                                        |" << std::endl;
	std::cout << "|The enemy uses their guns everytime you |" << std::endl;
	std::cout << "|             use your pulse             |" << std::endl;
	std::cout << "|                                        |" << std::endl;
	std::cout << "|       ^ represents the exit door       |" << std::endl;
	std::cout << "|                                        |" << std::endl;
	if (timeCount % 4 == 0)
	{
		std::cout << "|         PRESS SPACE TO CONTINUE        |" << std::endl;
	}
	else
	{
		std::cout << "|                                        |" << std::endl;
	}
	std::cout << "|                                        |" << std::endl;
	std::cout << "|________________________________________|" << std::endl;
	while (press != ' ')
	{
		press = m_cfi(press);
		system("cls");
		m_welS();
	}
}
void game::m_slowPrint()
{
	std::string message = "          WELCOME TO          \nTHE\n  PULSE             ^\n      WAVE        < o >\n         GAME       v\n\n PRESS ANY KEY TO CONTINUE";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	for (const char c : message)
	{
		std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	_getch();
	system("cls");
}
void game::m_enemyAI()
{
	PlaySound(L"Audio/EL.wav", NULL, SND_ASYNC);
	arr[eX][eY] = ' ';
	if (eY - pY < 4)
	{
		eY -= (eY - pY);
	}
	else if (eY - pY < -4)
	{
		eY -= (eY - pY);
	}
	else
	{
		if (pX > eX&& pY < eY)
		{
			eX += 4;
			eY -= 4;

		}
		else if (pX > eX&& pY > eY)
		{
			eX += 4;
			eY += 4;
		}
	}

	if (pX < eX && pY < eY)
	{
		eX -= 4;
		eY -= 4;

	}
	else if (pX < eX && pY > eY)
	{
		eX -= 4;
		eY += 4;
	}

	if (eX < 1)
	{
		eX = 1;
	}
	else if (eX > 20)
	{
		ex = 20;
	}
	if (eY < 1)
	{
		eY = 1;
	}
	else if (eY > 40)
	{
		eY = 40;
	}
	for (int i = 0; i < 40; i++)
	{
		if((eY - i) > 1)
		arr[eX][eY - i] = '-';

		if((eY + i) < 40)
		arr[eX][eY + i] = '-';

		if((eX - i) > 1)
		arr[eX - i][eY] = '|';

		if((eX + i) < 40)
		arr[eX + i][eY] = '|';
		arr[eX][eY] = '\x9C';
		m_draw();
		if ((eY - i) > 1)
			arr[eX][eY - i] = ' ';

		if ((eY + i) < 40)
			arr[eX][eY + i] = ' ';

		if ((eX - i) > 1)
			arr[eX - i][eY] = ' ';

		if ((eX + i) < 40)
			arr[eX + i][eY] = ' ';
	}

	if (eX == pX || eY == pY)
	{
		gameEnd = true;
	}
	else
	{
		PlaySound(L"Audio/COS.wav", NULL, SND_LOOP | SND_ASYNC);
	}
}
void game::m_drawHit()
{
	for (int i = 0; i < 16; i++)
	{
		arr[game::toDraw[i][0]][game::toDraw[i][1]] = '\xDB';
		game::toDraw[i][0] = NULL;
		game::toDraw[i][1] = NULL;
	}
};
void game::m_hidecursor() {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
void game::m_movement()
{
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 42; j++) {
			if (arr[i][j] == '\xDB')
			{
				arr[i][j] = '\xB2';
			}
			else if (arr[i][j] == '\xB2')
			{
				arr[i][j] = '\xB1';
			}
			else if (arr[i][j] == '\xB1')
			{
				arr[i][j] = ' ';
			}
		}
	}
	key = _getch();
	if (key == 'a') {
		arr[pX][pY] = ' ';
		pY--;
		arr[pX][pY] = 'o';
		if (pY == 0) {
			arr[pX][pY] = '|';
			pY++;
			arr[pX][pY] = 'o';
		}
		moved++;
		m_draw();
		m_checkTrapHit();
	}
	else if (key == 'd') {
		arr[pX][pY] = ' ';
		pY++;
		arr[pX][pY] = 'o';
		if (pY == 41) {
			arr[pX][pY] = '|';
			pY--;
			arr[pX][pY] = 'o';
		}
		moved++;
		m_draw();
		m_checkTrapHit();
	}
	else if (key == 'w') {
		arr[pX][pY] = ' ';
		pX--;
		arr[pX][pY] = 'o';
		if (pX == 0 && pY == ex) {
			gameEnd = true;
			won = true;
		}
		if (pX == 0) {
			arr[pX][pY] = '_';
			pX++;
			arr[pX][pY] = 'o';
		}
		moved++;
		m_draw();
		m_checkTrapHit();
	}
	else if (key == 's') {
		arr[pX][pY] = ' ';
		pX++;
		arr[pX][pY] = 'o';
		if (pX == 21) {
			arr[pX][pY] = '_';
			pX--;
			arr[pX][pY] = 'o';
		}
		moved++;
		m_draw();
		m_checkTrapHit();
	}
	else if (key == ' ') {
		if (moved >= 5)
		{
			PlaySound(L"Audio/ML.wav", NULL, SND_ASYNC );
			for (int i = 1; i <= 4; i++) {
				u = pX - i;
				d = pX + i;
				l = pY - i;
				r = pY + i;
				arr[u][pY] = '^';
				arr[d][pY] = 'v';
				arr[pX][l] = '<';
				arr[pX][r] = '>';
				m_draw();
				c = 0;
				m_checkHit();
				arr[pX - i][pY] = ' ';
				arr[pX + i][pY] = ' ';
				arr[pX][pY - i] = ' ';
				arr[pX][pY + i] = ' ';
				m_drawHit();
				m_draw();
			}
			moved = 0;
			m_enemyAI();
		}
	}
	else {
		m_movement();
	}
}
void game::m_checkHit()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (traps[i][j] == '-')
			{
   				if ((i == u && j == pY) || (i == d && j == pY) || (i == pX && j == l) || (i == pX && j == r))
				{
					toDraw[c][0] = i;
					toDraw[c][1] = j;
					c++;
				}
			}
			if (traps[pX][pY] == '-')
			{
				trapDied = true;
				gameEnd = true;
			}
		}
	}
}
void game::m_checkTrapHit()
{
	if (traps[pX][pY] == '-')
	{
		trapDied = true;
		gameEnd = true;
	}
}
void m_slowPrint(const std::string& message, unsigned int millis_per_char)
{
	for (const char c : message)
	{
		std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(millis_per_char));
	}
}
void game::m_drawInit()
{
	std::uniform_int_distribution<int> block(1, 40);
	std::uniform_int_distribution<int> nol(1, 12);
	std::uniform_int_distribution<int> ln(2, 19);
	std::uniform_int_distribution<int> noc(1, 22);
	std::uniform_int_distribution<int> cn(1, 30);
	int noOfLines = nol(rG);
	int* lines = new int[noOfLines];
	for (int i = 0; i < noOfLines; i++) {
		lines[i] = ln(rG);
	}
	for (int i = 0; i < 42; i++) {
		if (i == 0) {
			arr[0][i] = '\xC9';
		}
		else if (i == 41)
		{
			arr[0][i] = '\xBB';
		}
		else {
			arr[0][i] = '\xCD';
		}
	}
	for (int i = 1; i < 21; i++) {
		for (int j = 0; j < 42; j++) {
			if (j == 0 || j == 41) {
				arr[i][j] = '\xBA';
			}
			else {
				arr[i][j] = ' ';
			}
		}
	}
	for (int i = 0; i < 42; i++) {
		if (i == 0 || i == 41) {
			arr[21][i] = '\xBA';
		}
		else {
			arr[21][i] = '\xCD';
		}
	}
	for (int i = 0; i < 8; i++)
	{
		toDraw[i][0] = NULL;
		toDraw[i][1] = NULL;
	}
	for (int i = 0; i < noOfLines; i++) {
		int noOfCols = noc(rG);
		int* cols = new int[noOfCols];
		for (int j = 0; j < noOfCols; j++) {
			cols[j] = cn(rG);
		}
		for (int j = 0; j < noOfCols; j++) {
			traps[lines[i]][cols[j]] = '-';
		}
	}
}
void game::m_playerSpawn()
{
	arr[pX][pY] = 'o';
}
void game::m_draw() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 42; j++) {
			if (i != 0)
			{
				if (j == 0 || j == 41) {
					arr[i][j] = '\xBA';
				}
			}
			else
			{
				if (j == 0) {
					arr[i][j] = '\xC9';
				}
				else if (j == 41)
				{
					arr[i][j] = '\xBB';
				}
				else if (j == ex)
				{
					arr[i][j] = '^';
				}
				else
				{
					arr[i][j] = '\xCD';
				}
			}
			if (i == 21) {
				if (j == 0) {
					arr[i][j] = '\xC8';
				}
				else if (j == 41)
				{
					arr[i][j] = '\xBC';
				}
				else {
					arr[i][j] = '\xCD';
				}
			}
		}
	}
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 42; j++) {
			if (arr[i][j] == '\xDB')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				std::cout << arr[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else if (arr[i][j] == '\xB2')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				std::cout << arr[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else if (arr[i][j] == '\xB1')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				std::cout << arr[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
			{
				std::cout << arr[i][j];
			}
		}
		std::cout << std::endl;
	}

	if (moved < 5)
	{
		std::cout << "Pulse Wave available after : " << 5 - moved << " moves";
	}
	else
	{
		std::cout << "Pulse Wave available                                ";
	}
};
game::~game() {};