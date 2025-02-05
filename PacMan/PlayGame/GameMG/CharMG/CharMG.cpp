#include "CharMG.h"
#include "Character/Character.h"
#include "Character/Monster/Monster.h"
#include "Character/Player/Player.h"
#include "../../ProgramMG/ProgramMG.h"

#include <iostream>
#include <conio.h>
#include <windows.h>

void CharMG::Init(InputMG* inputMG, MapField map[][MAX_MAP_SIZE_X])
{
	_inputMG = inputMG;
	_CopyArr(map, _enemyPathMap);
	_mapSizeX = _inputMG->GetMapSize();
	_mapSizeY = _mapSizeX;
	_enemyNum = _inputMG->GetEnemyNum();

	//_MakePlayer
	Character* playerCharacter = new Player;
	playerCharacter->Init(inputMG, map, _enemyPathMap, MapField::PLAYER_, (_mapSizeX / 2), (_mapSizeY / 2) + 2);
	charVec.push_back(playerCharacter);

	//_MakeEnemy
	for (int i = 0; i < _enemyNum; i++)
	{
		Character* enemyCharacter = new Monster;
		enemyCharacter->Init(inputMG, map, _enemyPathMap, MapField::ENEMY_, ((_mapSizeX / 2) - 1) + i, _mapSizeY / 2);
		charVec.push_back(enemyCharacter);

		int startPosX = ((_mapSizeX / 2) - 1) + i;
		int startPosY = _mapSizeY / 2;
	}
}

void CharMG::_gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void CharMG::Draw()
{
	int posX = 0, posY = 0;
	for (auto iter = charVec.begin(); iter != charVec.end(); iter++)
	{
		posX = (*iter)->GetCurPosX();
		posY = (*iter)->GetCurPosY();

		_gotoxy(posX * 2, posY);

		if ((*iter)->GetCharState() == MapField::ENEMY_)
			std::cout << "△";
		else if ((*iter)->GetCharState() == MapField::PLAYER_)
			std::cout << "▲";
	}
}

void CharMG::_CopyArr(MapField array1[][MAX_MAP_SIZE_X], MapField array2[][MAX_MAP_SIZE_X])
{
	MapField* p1 = nullptr, * endp1 = nullptr;
	MapField* p2 = nullptr;
	p1 = &array1[0][0];
	p2 = &array2[0][0];
	endp1 = &array1[MAX_MAP_SIZE_X - 1][MAX_MAP_SIZE_X - 1];
	while (p1 <= endp1)
	{
		*p2 = *p1;
		p1++; p2++;
	}
}

void CharMG::Update(MapField map[][MAX_MAP_SIZE_X])
{
	for (auto iter = charVec.begin(); iter < charVec.end(); iter++)
	{
		(*iter)->MoveCharacter(_enemyPathMap);
	}

	//Player가 아이템을 먹었는지 체크해서 Monster 객체들에게 알려준다
	if (charVec[0]->IsGetItem())
		for (auto iter = charVec.begin() + 1; iter < charVec.end(); iter++)
		{
			(*iter)->SetGoalPos();
		}
}