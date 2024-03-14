//**********************************
//* TextRPG
//* Javier Alonso
//* 2/27/24 - Present
//* v1.00
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
#include "Enemy.h"

void visitTown(Player &character);
//int damageFormula(const static Player& character);
bool dungeonCheck(Player& character);

std::string operator * (std::string a, int num)
{
	std::string newStr;
	while (num--)
	{
		newStr += a;
	}
	return newStr;
}

void gotoxy(short x, short y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };

	SetConsoleCursorPosition(hStdout, position);
}

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

void intro(void)
{
	std::cout
		<< "Defeat all 4 (E)nemies to unlock the (D)ungeon.\n"
		<< "Use the town to rest and buy potions.\n\n"
		<< "Press enter to continue.\n";

	std::cin.ignore();
	std::cin.get();
	
	system("CLS");

}

int random_num(const static int &start, const static int &max)
{
	int random = start + rand() % (max);
	
	return random;
}

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
Enemy dragon(Enemy::E_DRAGON);

void map(Player &character)
{
	std::string border = "-";
	std::string space = " ";
	char spaces[mapX][mapY];
	
	if (character.playerVariables.posX == rat.EnemyStats.posX && character.playerVariables.posY == rat.EnemyStats.posY)
	{
		if (rat.EnemyStats.currentHP > 0)
		{
			rat.enemyEncounter(character);
			character.playerVariables.posX -= 1;
		}
	}
	else if (character.playerVariables.posX == goblin.EnemyStats.posX && character.playerVariables.posY == goblin.EnemyStats.posY)
	{
		if (goblin.EnemyStats.currentHP > 0)
		{
			goblin.enemyEncounter(character);
			character.playerVariables.posX -= 1;
		}
	}
	else if (character.playerVariables.posX == thief.EnemyStats.posX && character.playerVariables.posY == thief.EnemyStats.posY)
	{
		if (thief.EnemyStats.currentHP > 0)
		{
			thief.enemyEncounter(character);
			character.playerVariables.posX -= 1;
		}
	}
	else if (character.playerVariables.posX == wolf.EnemyStats.posX && character.playerVariables.posY == wolf.EnemyStats.posY)
	{
		if (wolf.EnemyStats.currentHP > 0)
		{
			wolf.enemyEncounter(character);
			character.playerVariables.posX -= 1;
		}
	}
	else if (character.playerVariables.posX == mapMarkerLocations.dungeonX && character.playerVariables.posY == mapMarkerLocations.dungeonY)
	{
		if (dungeonCheck(character))
		{
			dragon.enemyEncounter(character);
			character.playerVariables.posX -= 1;
		}
	}

	std::cout << "HP: " << character.playerVariables.currentHP << "/" << character.playerVariables.maxHP;
	std::cout << space * 5;
	std::cout << "Gold: " << character.playerVariables.gold << "g" << std::endl;
	std::cout << space * 5;
	std::cout << "Potions: " << character.playerVariables.potions << std::endl;
	std::cout << "+" << border * (mapX) << "+" << std::endl;

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
			else if (i == rat.EnemyStats.posX && j == rat.EnemyStats.posY)
			{
				if (rat.EnemyStats.currentHP > 0)
				{
					spaces[i][j] = mapMarkers.enemy;
				}
				else
				{
					spaces[i][j] = mapMarkers.emptySpace;
				}
				std::cout << spaces[i][j];
			}
			else if (i == goblin.EnemyStats.posX && j == goblin.EnemyStats.posY)
			{
				if (goblin.EnemyStats.currentHP > 0)
				{
					spaces[i][j] = mapMarkers.enemy;
				}
				else
				{
					spaces[i][j] = mapMarkers.emptySpace;
				}
				std::cout << spaces[i][j];
			}
			else if (i == thief.EnemyStats.posX && j == thief.EnemyStats.posY)
			{
				if (thief.EnemyStats.currentHP > 0)
				{
					spaces[i][j] = mapMarkers.enemy;
				}
				else
				{
					spaces[i][j] = mapMarkers.emptySpace;
				}
				std::cout << spaces[i][j];
			}
			else if (i == wolf.EnemyStats.posX && j == wolf.EnemyStats.posY)
			{
				if (wolf.EnemyStats.currentHP > 0)
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
	std::cout << "+" << border * (mapX) << "+" << std::endl;
}

bool dungeonCheck(Player& character)
{
	return(character.playerVariables.maxHP == 32);
}

//not const static because we update character position
void visitTown(Player &character)
{

	const static enum prices
	{
		P_HEALTHPOTION = 2,
		P_STICK = 5,
		P_CLUB = 20,
		P_HAMMER = 30
	};

	int choice = 0;

	system("CLS");

	std::cout
		<< "Welcome to <town>.\n"
		<< "1. Inn\n"
		<< "2. Shop\n"
		<< "3. Leave\n"
		<< "Selection: ";
	
	std::cin >> choice;

	if (choice == 1)	//INN
	{
		system("CLS");
		std::cout << "You have fully healed." << std::endl;
		character.playerVariables.currentHP = character.playerVariables.maxHP;
		std::cin.ignore();
		std::cin.get();
		system("CLS");
		character.playerVariables.posX -= 1;
	}
	else if (choice == 2)	//SHOP
	{
		system("CLS");
		int shopChoice;

		std::cout
			<< "Welcome to the item shop!\n"
			<< "1. Health Potion - "
			<< P_HEALTHPOTION
			<< "g\n2. Hammer - "
			<< P_HAMMER
			<< "g\n"
			<< "Selection: ";

		std::cin >> shopChoice;

		switch (shopChoice)
		{
			case(1):
			{
				if (character.playerVariables.gold >= P_HEALTHPOTION) //price of health potion
				{
					character.playerVariables.potions += 1;
					std::cout << "You have purchased 1 health potion." << std::endl;
					character.playerVariables.gold -= P_HEALTHPOTION;
				}
				else
				{
					std::cout << "You do not have enough gold for that." << std::endl;
				}
				std::cin.ignore();
				std::cin.get();
			
				break;
			}
			case(2):
			{
				if (character.playerVariables.gold >= P_HAMMER) //price of hammer
				{
					character.playerVariables.currentWeapon = Player::W_HAMMER;
					std::cout << "You have purchased and equipped a hammer." << std::endl;
					character.playerVariables.gold -= P_HAMMER;
				}
				else
				{
					std::cout << "You do not have enough gold for that." << std::endl;
				}
				std::cin.ignore();
				std::cin.get();

				break;
			}
		}
		character.playerVariables.posX -= 1;
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
			<< "Use your WASD or ARROW keys to move.\n BACKSPACE to use a health potion.";

		const enum arrowKey
		{
			KEY_UP = 72,
			KEY_W = 119,
			KEY_LEFT = 75,
			KEY_A = 97,
			KEY_DOWN = 80,
			KEY_S = 115,
			KEY_RIGHT = 77,
			KEY_D = 100,
			KEY_BACK = 8 
		};

		switch (_getch())
		{
		case(KEY_UP):
		case(KEY_W):
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
		case(KEY_DOWN):
		case(KEY_S):
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
		case(KEY_LEFT):
		case(KEY_A):
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
		case(KEY_RIGHT):
		case(KEY_D):
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
		case(KEY_BACK):
		{
			if (player.playerVariables.potions > 0)
			{
				while (player.playerVariables.currentHP != player.playerVariables.maxHP)
				{
					player.playerVariables.potions -= 1;
					player.playerVariables.currentHP = player.playerVariables.maxHP;
				}
			}
			else
			{
				system("CLS");
				std::cout << "You do not have any health potions." << std::endl;
				std::cin.ignore();
				system("CLS");
			}
			break;
		}
		}
		validMove = true;
	}	
	gotoxy(0, 0);
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
		if (playerOne.playerVariables.maxHP == 37)
		{
			system("CLS");
			std::cout << "You win!" << std::endl;
			std::cout << "Press enter to exit." << std::endl;
			playGame = false;
			std::cin.ignore();
			exit(EXIT_SUCCESS);
		}
		askMovement(playerOne);
	}
	std::cin.ignore();
	std::cin.get();
}