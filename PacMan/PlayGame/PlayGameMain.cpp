#include "GameMG/GameMG.h"
#include <windows.h>
int main()
{
	//�ܼ� ������ ���̱�
	/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 3, 6 };
	SetConsoleCursorPosition(hConsole, pos);*/

	bool isGamePlaying = true;

	GameMG gameMG;
	gameMG.Init(&isGamePlaying);

	while (isGamePlaying)
	{
		system("cls");
		gameMG.Draw();
		gameMG.Update();
		Sleep(400);
	}
}