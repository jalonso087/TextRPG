//**********************************
//* TextRPG
//* Javier Alonso
//* 2/27/24 - Present
//* v0.03
//**********************************

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <random>
#include <conio.h>
#include <Windows.h>
#include "player.h"
#include "mainMenu.h"
#include "enemy.h"

void visitTown(Player &character);
int enemyEncounter(Enemy &monster, Player &character);
int damageFormula(const static Player& character);
int enemyDamageFormula(const static Enemy& monster);

//found online
void gotoxy(short x, short y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };

	SetConsoleCursorPosition(hStdout, position);
}
/*
int itemGen()
{
	Items healthPot;

	int item = healthPot.spawnItem();

	std::cout << "You receive a " << item << "." << std::endl;

	return item;
}
*/

//probably add to display class on a refactor
int startScreen(void)
{
	int choice = 0;

	std::cout << "Welcome to <TextRPG>!\n" << std::endl;
	std::cout
		<< "1. Start Game\n"
		<< "2. Quit Game\n\n"
		<< "Selection: ";

	std::cin >> choice;

	return choice;
}

//probably add to display class on a refactor
void intro(void)
{
	std::cout
		<< "Instructions go here\n"
		<< "Also instructions.\nMore instructions\n\n"
		<< "Press enter to continue.\n";
	
	//just use cin to assign to a dummy variable on a refactor
	std::cin.ignore();
	std::cin.get();
	
	system("CLS");

}

//leave this as global variable -- on a refactor
int random_num(const static int &start, const static int &max)
{
	int random = start + rand() % (max);
	
	return random;
}

void checkDefeated(const static Player& character)
{
	if (character.playerVariables.defeated == true)
	{
		system("CLS");
		std::cout << "You lose." << std::endl;
		std::cin.ignore();
		exit(EXIT_SUCCESS);
	}
}

//maybe create a struct to house these together -- on a refactor
const static int mapX = 20;
const static int mapY = 20;

struct
{
	char player = 'X';
	char emptySpace = '.';
	char town = 'T';
	char dungeon = 'D';
	char enemy = 'E';

}mapMarkers;

struct
{
	int dungeonX = 4;
	int dungeonY = 15;
	int townX = 17;
	int townY = 9;

}mapMarkerLocations;

Enemy rat(Enemy::E_RAT);
Enemy goblin(Enemy::E_GOBLIN);
Enemy thief(Enemy::E_THIEF);
Enemy wolf(Enemy::E_WOLF);

//bundle into a MAP class on a refactor
void map(Player &character)
{
	char spaces[mapX][mapY];

	//std::cout << currentHP << std::endl;
		//ran into trouble using a get method on the player class, so resorted to accessing the variable directly. -- do these better on a refactor.
	
	if (character.playerVariables.posX == rat.enemyVariables.posX && character.playerVariables.posY == rat.enemyVariables.posY)
	{
		if (rat.enemyVariables.currentHP > 0)
		{
			enemyEncounter(rat, character);
			character.playerVariables.posX -= 1;
		}
	}
	else if (character.playerVariables.posX == goblin.enemyVariables.posX && character.playerVariables.posY == goblin.enemyVariables.posY)
	{
		if (goblin.enemyVariables.currentHP > 0)
		{
			enemyEncounter(goblin, character);
			character.playerVariables.posX -= 1;
		}
	}
	else if (character.playerVariables.posX == thief.enemyVariables.posX && character.playerVariables.posY == thief.enemyVariables.posY)
	{
		if (thief.enemyVariables.currentHP > 0)
		{
			enemyEncounter(thief, character);
			character.playerVariables.posX -= 1;
		}
	}
	else if (character.playerVariables.posX == wolf.enemyVariables.posX && character.playerVariables.posY == wolf.enemyVariables.posY)
	{
		if (wolf.enemyVariables.currentHP > 0)
		{
			enemyEncounter(wolf, character);
			character.playerVariables.posX -= 1;
		}
	}

	std::cout << "HP: " << character.playerVariables.currentHP << "/" << character.playerVariables.maxHP;

	//use a range for loop here on a refactor
	for (int p = 0; p < 5; p++)
	{
		std::cout << " ";
	}
	std::cout << "Gold: " << character.playerVariables.gold << "g" << std::endl;
	std::cout << "+";

	for (int k = 0; k <= (mapX-1); k++)
	{
		std::cout << "-";
	}

	std::cout << "+";
	std::cout << std::endl;

	for (int i = 0; i <= (mapX - 1); i++)
	{
		std::cout << "|";
		for (int j = 0; j <= (mapY - 1); j++)
		{
			if (i == mapMarkerLocations.dungeonX && j == mapMarkerLocations.dungeonY)
			{
				spaces[i][j] = mapMarkers.dungeon;
				std::cout << spaces[i][j];
			}
			else if (i == mapMarkerLocations.townX && j == mapMarkerLocations.townY)
			{
				spaces[i][j] = mapMarkers.town;
				std::cout << spaces[i][j];
			}
			else if (i == character.playerVariables.posX && j == character.playerVariables.posY)
			{
				spaces[i][j] = mapMarkers.player;
				std::cout << spaces[i][j];
			}
			else if (i == rat.enemyVariables.posX && j == rat.enemyVariables.posY)
			{
				if (rat.enemyVariables.currentHP > 0)
				{
					spaces[i][j] = mapMarkers.enemy;
				}
				else
				{
					spaces[i][j] = mapMarkers.emptySpace;
				}
				std::cout << spaces[i][j];
			}
			else if (i == goblin.enemyVariables.posX && j == goblin.enemyVariables.posY)
			{
				if (goblin.enemyVariables.currentHP > 0)
				{
					spaces[i][j] = mapMarkers.enemy;
				}
				else
				{
					spaces[i][j] = mapMarkers.emptySpace;
				}
				std::cout << spaces[i][j];
			}
			else if (i == thief.enemyVariables.posX && j == thief.enemyVariables.posY)
			{
				if (thief.enemyVariables.currentHP > 0)
				{
					spaces[i][j] = mapMarkers.enemy;
				}
				else
				{
					spaces[i][j] = mapMarkers.emptySpace;
				}
				std::cout << spaces[i][j];
			}
			else if (i == wolf.enemyVariables.posX && j == wolf.enemyVariables.posY)
			{
				if (wolf.enemyVariables.currentHP > 0)
				{
					spaces[i][j] = mapMarkers.enemy;
				}
				else
				{
					spaces[i][j] = mapMarkers.emptySpace;
				}
				std::cout << spaces[i][j];
			}
			else
			{
				spaces[i][j] = mapMarkers.emptySpace;
				std::cout << spaces[i][j];
			}

		}
		std::cout << "|" << std::endl;
	}
	std::cout << "+";
	for (int k = 0; k <= (mapX-1); k++)
		std::cout << "-";
	std::cout << "+";
	std::cout << std::endl;
}

double goldGen(const static Enemy& monster)
{
	double goldAmount = (random_num(1, 10)) * (monster.enemyVariables.enemyType + 1);

	std::cout << "You receive " << goldAmount << " gold." << std::endl;

	return goldAmount;
}


int enemyEncounter(Enemy &monster, Player &character)
{
	int choice;
	unsigned char result = 0;
	bool combat;
	int defeated = 0;

	combat = true;

	system("CLS");

	std::cout << "You encountered an enemy ";

	switch(monster.enemyVariables.enemyType)
	{
	case(Enemy::E_RAT):
		std::cout << "rat!\n" << std::endl;
		break;
	case(Enemy::E_GOBLIN):
		std::cout << "goblin!\n" << std::endl;
		break;
	case(Enemy::E_THIEF):
		std::cout << "thief!\n" << std::endl;
		break;
	case(Enemy::E_WOLF):
		std::cout << "wolf!\n" << std::endl;
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
		std::cout << "Enemy HP: " << monster.enemyVariables.currentHP << "/" << monster.enemyVariables.startingHP << std::endl;
		std::cout << "\nYour HP: " << character.playerVariables.currentHP << "/" << character.playerVariables.maxHP << std::endl;
		std::cout << "---------" << std::endl;

		if (playerTurn == true && compTurn == false)
		{
			std::cout << "1. Attack\n" << std::endl; 
			std::cout << "Selection: ";

			std::cin >> choice;

			if (choice == 1)
			{
				int dmg = damageFormula(character);
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
				monster.enemyVariables.currentHP -= dmg;

				std::cin.ignore();
				std::cin.get();

				playerTurn = false;
				compTurn = true;
				
				system("CLS");
				
				if (monster.enemyVariables.currentHP <= 0)
				{
					std::cout << "You defeated the monster!\n" << std::endl;

					character.playerVariables.gold += goldGen(monster);
					
					std::cin.ignore();

					result = 1;
					combat = false;
				}
			}

		} 
		else if (compTurn == true && playerTurn == false)
		{
			int dmg;
			dmg = enemyDamageFormula(monster);
			
			std::cout << "You take " << dmg << " damage from the monster!" << std::endl;

			character.playerVariables.currentHP -= dmg;

			std::cin.ignore();

			if (character.playerVariables.currentHP <= 0)
			{
				character.playerVariables.defeated = true;
			}

			checkDefeated(character);

			compTurn = false;
			playerTurn = true;

			system("CLS");
		}
	}
	system("CLS");

	return result;

}
//not const static because we update character position
void visitTown(Player &character)
{

	const static enum prices
	{
		P_HEALTHPOTION = 20,
		P_STICK = 10,
		P_CLUB = 25,
		P_HAMMER = 100
	};

	int choice = 0;

	std::cout
		<< "Welcome to <town>.\n"
		<< "1. Inn\n"
		<< "2. Shop\n"
		<< "3. Leave\n"
		<< "Selection: ";
	
	std::cin >> choice;

	if (choice == 2)
	{
		system("CLS");
		int shopChoice;

		std::cout
			<< "Welcome to the item shop!\n"
			<< "1. Health Potion - "
			<< P_HEALTHPOTION
			<< "g\n2. Stick - "
			<< P_STICK
			<< "g\n3. Club - "
			<< P_CLUB
			<< "g\n4. Hammer - "
			<< P_HAMMER
			<< "g\n"
			<< "Selection: ";

		std::cin >> shopChoice;
	}
	else if (choice == 3)
	{
		character.playerVariables.posX -= 1;
	}
	system("CLS");
}

void askMovement(Player &player)
{
	int move; 
	bool validMove = false;

	while (!validMove)
	{
		std::cout
			<< "Use your wasd or arrow keys to move.\n";

		const enum arrowKey
		{
			KEY_UP = 72,
			KEY_W = 119,
			KEY_LEFT = 75,
			KEY_A = 97,
			KEY_DOWN = 80,
			KEY_S = 115,
			KEY_RIGHT = 77,
			KEY_D = 100
		};

		switch (_getch())
		{
		case(KEY_W):
		case(KEY_UP):
		{
			player.playerVariables.posX -= 1;
			if (player.playerVariables.posX == mapMarkerLocations.townX && player.playerVariables.posY == mapMarkerLocations.townY)
			{
				visitTown(player);
			}
			if (player.playerVariables.posX < 0 || player.playerVariables.posX > mapX)
			{
				player.playerVariables.posX += 1;

			}
			break;
		}
		case(KEY_S):
		case(KEY_DOWN):
		{
			player.playerVariables.posX += 1;
			if (player.playerVariables.posX == mapMarkerLocations.townX && player.playerVariables.posY == mapMarkerLocations.townY)
			{
				visitTown(player);
			}
			if (player.playerVariables.posX < 0 || player.playerVariables.posX >(mapX - 1))
			{
				player.playerVariables.posX -= 1;
			}
			break;
		}
		case(KEY_A):
		case(KEY_LEFT):
		{
			player.playerVariables.posY -= 1;
			if (player.playerVariables.posX == mapMarkerLocations.townX && player.playerVariables.posY == mapMarkerLocations.townY)
			{
				visitTown(player);
			}
			if (player.playerVariables.posY < 0 || player.playerVariables.posY > mapY)
			{
				player.playerVariables.posY += 1;
			}
			break;
		}
		case(KEY_D):
		case(KEY_RIGHT):
		{
			player.playerVariables.posY += 1;
			if (player.playerVariables.posX == mapMarkerLocations.townX && player.playerVariables.posY == mapMarkerLocations.townY)
			{
				visitTown(player);
			}
			if (player.playerVariables.posY < 0 || player.playerVariables.posY >(mapY - 1))
			{
				player.playerVariables.posY -= 1;
			}
			break;
		}
		}
		validMove = true;
	}	
	gotoxy(0, 0);
}

int damageFormula(const static Player &character)
{
	int dmg;

	dmg = random_num((character.playerVariables.currentWeapon+1), (character.playerVariables.currentWeapon+3));

	return dmg;
}

int enemyDamageFormula(const static Enemy& monster)
{
	int dmg;

	dmg = random_num((monster.enemyVariables.enemyType + 1), (monster.enemyVariables.enemyType + 2));

	return dmg;
}

int main(void)
{
	srand(time(NULL));

	int startChoice = startScreen();
	bool playGame = false;
	bool quitGame = false;

	Player playerOne;

	if (startChoice == 1)
	{
		playGame = true;
		
		system("CLS");
		intro();
	}
	else
	{
		quitGame = true;
		return 0;
	}

	system("CLS");		//use to clear the screen to make space for new player map	

	while (playGame)
	{
		//game loop here
		map(playerOne);
		askMovement(playerOne);
		
	}

	std::cin.ignore();
	std::cin.get();
}