#pragma once

int random_num(const static int& start, const static int& max);

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

	struct
	{
		int level = 1;
		int maxHP = (level * 2) + 10;
		int posX = 0;
		int posY = 0;
		int currentHP;
		int gold = 0;
		int currentWeapon = W_STICK;
		int potions = 0;
		bool defeated;

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
		playerVariables.defeated;
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

	void checkDefeated()
	{
		if (playerVariables.defeated == true)
		{
			system("CLS");
			std::cout << "You lose." << std::endl;
			std::cin.ignore();
			exit(EXIT_SUCCESS);
		}
	}

	void lootGen()
	{
		double goldAmount = (random_num(1, 10)) * 2;
		int rand = random_num(1, 10);

		if (rand >= 1 && rand <= 10)
		{
			std::cout << "You receive " << goldAmount << " gold." << std::endl;
			playerVariables.gold += goldAmount;
		}

		if (rand > 4 && rand < 8)
		{
			std::cout << "You receive 10 health potions.";
			playerVariables.potions += 10;
		}
		else if (rand > 7 && rand <= 10)
		{
			if (playerVariables.currentWeapon != W_HAMMER)
			{
				std::cout << "You receive a hammer.";
				playerVariables.currentWeapon = W_HAMMER;
			}
		}
	}

	int damageFormula()
	{
		int dmg;

		dmg = random_num((playerVariables.currentWeapon + 1), (playerVariables.currentWeapon + 3));

		return dmg;
	}



};