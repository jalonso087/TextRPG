#pragma once

class Player
{
private:



protected:

public:

	//unisnged char uses less memory than int. 1 byte (8 bit) vs 4 bytes (32 bits)
	const enum weapons : unsigned char
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

	const enum items : unsigned char
	{
		I_HEALTHPOTION,
		I_ENERGYPOTION,
		I_KEY,
		I_TOWNPORTAL
	};

	
	struct
	{
		int level = 1;
		int maxHP = (level * 2) + 10;
		int posX = 0;
		int posY = 0;
		int currentHP;
		int gold = 0;
		int currentWeapon = W_STICK;

	}playerVariables;

	Player()
	{
		playerVariables.level;
		playerVariables.maxHP;
		playerVariables.posX;
		playerVariables.posY;
		playerVariables.currentHP = playerVariables.maxHP;
		playerVariables.gold;
		playerVariables.currentWeapon;
	}

	//std::string inventory(player& player, std::string item)
	//{
	//	std::string contents[10];
	//
	//}

	int getCurrentHP(void)
	{
		return playerVariables.currentHP;
	}

	int getMaxHP(void)
	{
		return playerVariables.maxHP;
	}

	int setHP(const static int &hpChange)
	{
		if (hpChange >= 0)
		{
			playerVariables.currentHP -= hpChange;
		}
		else
		{
			playerVariables.currentHP += hpChange;
		}

	}

};