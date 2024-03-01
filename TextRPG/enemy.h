#pragma once

int random_num(const static int& start, const static int& max);

class Enemy
{
private:

protected:

public:

	const enum enemies : unsigned char
	{
		E_RAT,
		E_GOBLIN,
		E_THIEF,
		E_WOLF,
		E_SKELETON,
		E_SPIDER,
		E_ORC,
		E_WIZARD,
		E_OGRE
	};

	const enum boss : unsigned char
	{
		B_RAT,
		B_GOBLIN,
		B_THIEF,
		B_WOLF,
		B_SKELETON,
		B_SPIDER,
		B_ORC,
		B_WIZARD,
		B_OGRE
	};

	struct
	{
		int enemyType;
		int startingHP;
		int currentHP;
		//use mapsize to determine the max random num -- do this on a refactor
		int posX = (random_num(1, 18));
		int posY = (random_num(1, 18));

	}enemyVariables;

	Enemy(enemies monster) 
	{
		enemyVariables.startingHP = monster + 5;

		if (monster == E_RAT)
		{
			enemyVariables.enemyType = E_RAT;
		}
		else if (monster == E_GOBLIN)
		{
			enemyVariables.enemyType = E_GOBLIN;
		}
		else if (monster == E_THIEF)
		{
			enemyVariables.enemyType = E_THIEF;
		}
		else if (monster == E_WOLF)
		{
			enemyVariables.enemyType == E_WOLF;
		}
		enemyVariables.startingHP;
		enemyVariables.currentHP = enemyVariables.startingHP;
		enemyVariables.posX;
		enemyVariables.posY;

	};

	int getHP(const static Enemy& enemy)
	{
		return enemy.enemyVariables.startingHP;
	}

	int setHP(Enemy& enemy, int hpChange)
	{
		if (hpChange >= 0)
		{
			enemy.enemyVariables.currentHP -= hpChange;
		}
		else
		{
			enemy.enemyVariables.currentHP += hpChange;
		}
		
	}

};