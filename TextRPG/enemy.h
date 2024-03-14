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
		//use mapsize to determine the max random num -- do this on a refactor
		int posX = (random_num(1, 18));
		int posY = (random_num(1, 18));
	};

	static struct EnemyVariables EnemyStats;

	Enemy(Enemies monster);

	static int getStartingHP(const static Enemy& enemy);

	static int getCurrentHP(const static Enemy& enemy);

	static void setHP(Enemy& enemy, int hpChange);

	static int enemyDamageFormula();

	static int enemyEncounter(Player& character);

};