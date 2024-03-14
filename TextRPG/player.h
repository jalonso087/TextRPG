#pragma once

int random_num(const static int& start, const static int& max);

class Player
{
public:

	int level = 1;
	int maxHP = (level * 2) + 10;
	int posX = 0;
	int posY = 0;
	int currentHP;
	int gold = 0;
	int currentWeapon = W_STICK;
	int potions = 0;
	bool defeated;

	enum Weapons
	{
		W_STICK,
		W_CLUB,
		W_HAMMER,
		W_MACE,
		W_KNIFE,
		W_SWORD,
		W_SPEAR,
		W_DAGGER,
		W_CLAYMORE
	};

	Player();

	void checkDefeated(void);

	void lootGen(void);

	int damageFormula(void);

	bool dungeonCheck();

};