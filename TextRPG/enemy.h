#pragma once
#include "Player.h"
//#include "Base.h"

int random_num(const int& start, const int& max);

class Enemy
{
public:
	int enemyType;
	int startingHP;
	int currentHP;
	int posX = (random_num(1, 18));
	int posY = (random_num(1, 18));

	enum EnemyType
	{
		E_RAT,
		E_GOBLIN,
		E_THIEF,
		E_WOLF,
		E_DRAGON = 9
	};

	Enemy(EnemyType monster);

	int enemyDamageFormula();

	int enemyEncounter(Player& character);

};