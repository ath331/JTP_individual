#include "CharMG.h"
#include "Character/Character.h"

#include <iostream>

void CharMG::InputCharInfo()
{
	std::cout << "Input CharInfo_ enemyNum(int)" << std::endl;
	std::cin >> _enemyNum;
}

void CharMG::Init(bool* isGamePlaying,MapField map[][MAX_MAP_SIZE_X], int mapSizeX, int mapSizeY)
{
	_mapSizeX = mapSizeX;
	_mapSizeY = mapSizeY;

	_MakePlayerPos(isGamePlaying, map, _mapSizeX / 2, (_mapSizeY / 2 + 2));

	for (int i = 0; i < _enemyNum; i++)
	{
		Character* enemyCharacter = new Character;
		enemyCharacter->Init(isGamePlaying, map, MapField::ENEMY_, ((_mapSizeX / 2) - 1) + i, _mapSizeY / 2, _mapSizeX, _mapSizeY);
		charVec.push_back(enemyCharacter);

		int startPosX = ((_mapSizeX / 2) - 1) + i;
		int startPosY = _mapSizeY / 2;
	}
}

void CharMG::Update(MapField map[][MAX_MAP_SIZE_X])
{
	for (auto iter = charVec.begin(); iter < charVec.end(); iter++)
	{
		(*iter)->MoveCharacter(map);
	}
}

void CharMG::_MakePlayerPos(bool* isGamePlaying,MapField map[][MAX_MAP_SIZE_X], int posX, int posY)
{
	Character* playerCharacter = new Character;
	playerCharacter->Init(isGamePlaying, map, MapField::PLAYER_, posX, posY, _mapSizeX, _mapSizeY);
	charVec.push_back(playerCharacter);
}