#pragma once

int random_num(const static int& start, const static int& max);

class Enemy
{
private:

protected:

public:

	const enum Enemies : unsigned char
	{
		E_RAT,
		E_GOBLIN ,
		E_THIEF,
		E_WOLF,
		E_SKELETON,
		E_SPIDER,
		E_ORC,
		E_WIZARD,
		E_OGRE,
		E_DRAGON
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
		B_OGRE,
		B_DRAGON
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
		enemyVariables.startingHP = (monster * 2) + 5;

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
			enemyVariables.enemyType = E_WOLF;
		}
		else if (monster == E_DRAGON)
		{
			enemyVariables.enemyType = E_DRAGON;
		}
		enemyVariables.startingHP;
		enemyVariables.currentHP = enemyVariables.startingHP;
		enemyVariables.posX;
		enemyVariables.posY;

	};

	int getStartingHP(const static Enemy& enemy)
	{
		return enemy.enemyVariables.startingHP;
	}

	int getCurrentHP(const static Enemy& enemy)
	{
		return enemy.enemyVariables.currentHP;
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

	int enemyDamageFormula()
	{
		int dmg;

		dmg = random_num((enemyVariables.enemyType + 1), (enemyVariables.enemyType + 2));

		return dmg;
	}

	int enemyEncounter(Player& character)
	{
		int choice;
		unsigned char result = 0;
		bool combat = true;
		int defeated = 0;

		system("CLS");

		std::cout << "You encountered an enemy ";

		switch (enemyVariables.enemyType)
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
		case(B_DRAGON):
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
			std::cout << "Enemy HP: " << enemyVariables.currentHP << "/" << enemyVariables.startingHP << std::endl;
			std::cout << "\nYour HP: " << character.playerVariables.currentHP << "/" << character.playerVariables.maxHP << std::endl;
			std::cout << "---------" << std::endl;

			if (playerTurn == true && compTurn == false)
			{
				std::cout << "1. Attack" << std::endl;
				std::cout << "2. Potions x" << character.playerVariables.potions << std::endl;
				std::cout << "3. Run" << std::endl;
				std::cout << "Selection: ";

				std::cin >> choice;

				if (choice == 1)	//Attack
				{
					int dmg = character.damageFormula();
					std::cout << "You did " << dmg << " point(s) of damage with your ";
					switch (character.playerVariables.currentWeapon)
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
					enemyVariables.currentHP -= dmg;

					std::cin.ignore();
					std::cin.get();

					playerTurn = false;
					compTurn = true;

					system("CLS");

					if (enemyVariables.currentHP <= 0)
					{
						std::cout << "You defeated the monster!" << std::endl;
						std::cout << "You have become stronger." << std::endl;
						character.playerVariables.maxHP += 5;

						character.lootGen();

						std::cin.ignore();

						result = 1;
						combat = false;
					}
				}
				else if (choice == 2)	//Potions
				{
					if (character.playerVariables.currentHP < character.playerVariables.maxHP && character.playerVariables.potions > 0)
					{
						system("CLS");
						character.playerVariables.currentHP = character.playerVariables.maxHP;
						character.playerVariables.potions -= 1;
						std::cout << "You have healed completely." << std::endl;
						std::cin.ignore();
						std::cin.get();
						system("CLS");
					}
					else if (character.playerVariables.currentHP == character.playerVariables.maxHP)
					{
						system("CLS");
						std::cout << "You are already at full health." << std::endl;
						std::cin.ignore();
						std::cin.get();
						system("CLS");
					}
					else if (character.playerVariables.potions == 0)
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

				character.playerVariables.currentHP -= dmg;

				std::cin.ignore();

				if (character.playerVariables.currentHP <= 0)
				{
					character.playerVariables.defeated = true;
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

};