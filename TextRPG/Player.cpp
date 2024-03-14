#include <Windows.h>
#include <iostream>
#include "Player.h"

Player::Player()
{
	level;
	maxHP;
	posX;
	posY;
	currentHP = maxHP;
	gold;
	currentWeapon;
	defeated;
}

void Player::checkDefeated()
{
	if (defeated == true)
	{
		system("CLS");
		std::cout << "You lose." << std::endl;
		std::cin.ignore();
		exit(EXIT_SUCCESS);
	}
}

void Player::lootGen()
{
	double goldAmount = (random_num(1, 10)) * 2;
	int rand = random_num(1, 10);

	if (rand >= 1 && rand <= 10)
	{
		std::cout << "You receive " << goldAmount << " gold." << std::endl;
		gold += goldAmount;
	}

	if (rand > 4 && rand < 8)
	{
		std::cout << "You receive 10 health potions.";
		potions += 10;
	}
	else if (rand > 7 && rand <= 10)
	{
		if (currentWeapon != W_HAMMER)
		{
			std::cout << "You receive a hammer.";
			currentWeapon = W_HAMMER;
		}
	}
}

int Player::damageFormula()
{
	int dmg;

	dmg = random_num((currentWeapon + 1), (currentWeapon + 3));

	return dmg;
}

bool Player::dungeonCheck()
{
	return(maxHP == 32);
}