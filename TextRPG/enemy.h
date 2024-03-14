#pragma once
#include "Player.h"

int random_num(const static int& start, const static int& max);

class Enemy
{
public:

	const enum Enemies
	{
		E_RAT,
		E_GOBLIN,
		E_THIEF,
		E_WOLF,
		E_DRAGON = 9
	};

	struct EnemyVariables
	{
		int enemyType;
		int startingHP;
		int currentHP;
		int posX = (random_num(1, 18));
		int posY = (random_num(1, 18));
	};

	//if i make this static, i get a linker error but no compiler error. as is, i get multiple compiler errors but no linker error
	struct EnemyVariables EnemyStats;

	Enemy(Enemies monster);

	static int enemyDamageFormula();

	static int enemyEncounter(Player& character);

};