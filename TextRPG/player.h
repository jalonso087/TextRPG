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
		int hp = (level * 2) + 10;
		int posX = 0;
		int posY = 0;

	}playerVariables;

	Player()
	{
		playerVariables.level;
		playerVariables.hp;
		playerVariables.posX;
		playerVariables.posY;
	}

	//std::string inventory(player& player, std::string item)
	//{
	//	std::string contents[10];
	//
	//}

	int getHP(const static Player& character)
	{
		return character.playerVariables.hp;
	}

	int setHP(const static Player& character, int hpChange)
	{
		if (hpChange >= 0)
		{
			character.playerVariables.hp -= hpChange;
		}
		else
		{
			character.playerVariables.hp += hpChange;
		}

	}

};