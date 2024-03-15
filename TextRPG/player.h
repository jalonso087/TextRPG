#pragma once
#include "Base.h"

int random_num(const int& start, const int& max);

class Player : public Base
{
public:

	int gold = 0;
	int currentWeapon = W_STICK;
	int potions = 0;

	enum Weapons
	{
		W_STICK,
		W_HAMMER = 3,
	};

	Player();

	void checkDefeated(void);

	void lootGen(void);

	int damageFormula(void);

	bool dungeonCheck();
};