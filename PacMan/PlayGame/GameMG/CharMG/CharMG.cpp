#include "CharMG.h"
#include "Character/Character.h"

#include <iostream>

#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

void CharMG::InputCharInfo()
{
	std::cout << "Input CharInfo_ enemyNum(int)" << std::endl;
	std::cin >> _enemyNum;
}

void CharMG::Init(MapField map[][MAX_MAP_SIZE_X], int mapSizeX, int mapSizeY)
{
	_mapSizeX = mapSizeX;
	_mapSizeY = mapSizeY;

	_MakePlayerPos(map, _mapSizeX / 2, (_mapSizeY / 2 + 2));

	for (int i = 0; i < _enemyNum; i++)
	{
		Character* enemyCharacter = new Character;
		enemyCharacter->Init(map, MapField::ENEMY_, ((_mapSizeX / 2) - 1) + i, _mapSizeY / 2, _mapSizeX, _mapSizeY);
		charVec.push_back(enemyCharacter);

		int startPosX = ((_mapSizeX / 2) - 1) + i;
		int startPosY = _mapSizeY / 2;

		_SetCharacterPos(0, startPosX, startPosY);
		map[startPosX][startPosY] = MapField::ENEMY_;
	}
}

void CharMG::Update(MapField map[][MAX_MAP_SIZE_X])
{
	for (auto iter = charVec.begin(); iter < charVec.end(); iter++)
	{
		(*iter)->MoveCharacter(map);
	}
}

void CharMG::_SetCharacterPos(int charNum, int posX, int posY)
{
	charVec[charNum]->SetCharPos(posX, posY);
}

void CharMG::_MakePlayerPos(MapField map[][MAX_MAP_SIZE_X], int posX, int posY)
{
	Character* playerCharacter = new Character;
	playerCharacter->Init(map, MapField::PLAYER_, posX, posY, _mapSizeX, _mapSizeY);
	charVec.push_back(playerCharacter);

	_SetCharacterPos(0, posX, posY);
	int playerCurPosX = charVec[0]->GetCurPosX();
	int playerCurPosY = charVec[0]->GetCurPosY();

	map[playerCurPosX][playerCurPosY] = MapField::PLAYER_;
}