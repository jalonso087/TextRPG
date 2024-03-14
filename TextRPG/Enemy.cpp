#include <iostream>
#include <Windows.h>
#include <random>
#include "Player.h"
#include "Enemy.h"

Enemy::Enemy(EnemyType monster)
{
	//EnemyVariables EnemyStats;

	startingHP = (monster * 2) + 5;

	if (monster == E_RAT)
	{
		enemyType = E_RAT;
	}
	else if (monster == E_GOBLIN)
	{
		enemyType = E_GOBLIN;
	}
	else if (monster == E_THIEF)
	{
		enemyType = E_THIEF;
	}
	else if (monster == E_WOLF)
	{
		enemyType = E_WOLF;
	}
	else if (monster == E_DRAGON)
	{
		enemyType = E_DRAGON;
	}
	startingHP;
	currentHP = startingHP;
	posX;
	posY;
};

//int Enemy::getStartingHP(const static Enemy& enemy)
//{
//	return EnemyStats.startingHP;
//}

//int Enemy::getCurrentHP(const static Enemy& enemy)
//{
//	return EnemyStats.currentHP;
//}

//void Enemy::setHP(Enemy& enemy, int hpChange)
//{
//	if (hpChange >= 0)
//	{
//		EnemyStats.currentHP -= hpChange;
//	}
//	else
//	{
//		EnemyStats.currentHP += hpChange;
//	}
//}

//If a method is part of a specific class, should I ever need to pass an object of that class as an argument?
//This seems redundant. If I'm calling the method using rat.method() , why would I be forced to use rat.method(rat)?
int Enemy::enemyDamageFormula()
{
	//EnemyVariables EnemyStats;

	int dmg;

	dmg = random_num(enemyType + 1, enemyType + 2);

	return dmg;
}

int Enemy::enemyEncounter(Player& character)
{
	//EnemyVariables EnemyStats;

	int choice;
	unsigned char result = 0;
	bool combat = true;
	int defeated = 0;

	system("CLS");

	std::cout << "You encountered an enemy ";

	switch (enemyType)
	{
	case(E_RAT):
		std::cout << "rat!\n" << std::endl;
		break;
	case(E_GOBLIN):
		std::cout << "goblin!\n" << std::endl;
		break;
	case(E_THIEF):
		std::cout << "thief!\n" << std::endl;
		break;
	case(E_WOLF):
		std::cout << "wolf!\n" << std::endl;
		break;
	case(E_DRAGON):
		std::cout << "DRAGON!\n" << std::endl;
		break;
	}

	std::cout << "Press enter to continue." << std::endl;
	std::cin.get();

	system("CLS");

	bool playerTurn = true;
	bool compTurn = false;

	while (combat)
	{
		std::cout << "BATTLE\n---------" << std::endl;
		std::cout << "Enemy HP: " << currentHP << "/" << startingHP << std::endl;
		std::cout << "\nYour HP: " << character.currentHP << "/" << character.maxHP << std::endl;
		std::cout << "---------" << std::endl;

		if (playerTurn == true && compTurn == false)
		{
			std::cout << "1. Attack" << std::endl;
			std::cout << "2. Potions x" << character.potions << std::endl;
			std::cout << "3. Run" << std::endl;
			std::cout << "Selection: ";

			std::cin >> choice;

			if (choice == 1)	//Attack
			{
				int dmg = character.damageFormula();
				std::cout << "You did " << dmg << " point(s) of damage with your ";
				switch (character.currentWeapon)
				{
				case(Player::W_STICK):
				{
					std::cout << "stick!\n" << std::endl;
					break;
				}
				case(Player::W_CLUB):
				{
					std::cout << "club!\n" << std::endl;
					break;
				}
				case(Player::W_HAMMER):
				{
					std::cout << "hammer!\n" << std::endl;
					break;
				}
				case(Player::W_MACE):
				{
					std::cout << "mace!\n" << std::endl;
					break;
				}
				}
				currentHP -= dmg;

				std::cin.ignore();
				std::cin.get();

				playerTurn = false;
				compTurn = true;

				system("CLS");

				if (currentHP <= 0)
				{
					std::cout << "You defeated the monster!" << std::endl;
					std::cout << "You have become stronger." << std::endl;
					character.maxHP += 5;

					character.lootGen();

					std::cin.ignore();

					result = 1;
					combat = false;
				}
			}
			else if (choice == 2)	//Potions
			{
				if (character.currentHP < character.maxHP && character.potions > 0)
				{
					system("CLS");
					character.currentHP = character.maxHP;
					character.potions -= 1;
					std::cout << "You have healed completely." << std::endl;
					std::cin.ignore();
					std::cin.get();
					system("CLS");
				}
				else if (character.currentHP == character.maxHP)
				{
					system("CLS");
					std::cout << "You are already at full health." << std::endl;
					std::cin.ignore();
					std::cin.get();
					system("CLS");
				}
				else if (character.potions == 0)
				{
					system("CLS");
					std::cout << "You do not have any potions." << std::endl;
					std::cin.ignore();
					std::cin.get();
					system("CLS");
				}
			}
			else if (choice == 3)	//Run
			{
				break;
			}

		}

		else if (compTurn == true && playerTurn == false)
		{
			int dmg;
			dmg = enemyDamageFormula();

			std::cout << "You take " << dmg << " damage from the monster!" << std::endl;

			character.currentHP -= dmg;

			std::cin.ignore();

			if (character.currentHP <= 0)
			{
				character.defeated = true;
			}

			character.checkDefeated();

			compTurn = false;
			playerTurn = true;

			system("CLS");
		}
	}
	system("CLS");

	return result;

}