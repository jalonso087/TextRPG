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
int damageFormula(const static Player& character);
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
		<< "Defeat all 4 (E)nemies to unlock the (D)ungeon.\n"
		<< "Use the town to rest and buy potions.\n\n"
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



//maybe create a struct to house the map -- on a refactor
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

//bundle into a display class on a refactor
void map(Player &character)
{
	std::string border = "-";
	char spaces[mapX][mapY];

	//std::cout << currentHP << std::endl;
		//ran into trouble using a get method on the player class, so resorted to accessing the variable directly. -- do these better on a refactor.
	
	if (character.playerVariables.posX == rat.enemyVariables.posX && character.playerVariables.posY == rat.enemyVariables.posY)
	{
		if (rat.enemyVariables.currentHP > 0)
		{
			rat.enemyEncounter(character);
			character.playerVariables.posX -= 1;
		}
	}
	else if (character.playerVariables.posX == goblin.enemyVariables.posX && character.playerVariables.posY == goblin.enemyVariables.posY)
	{
		if (goblin.enemyVariables.currentHP > 0)
		{
			goblin.enemyEncounter(character);
			character.playerVariables.posX -= 1;
		}
	}
	else if (character.playerVariables.posX == thief.enemyVariables.posX && character.playerVariables.posY == thief.enemyVariables.posY)
	{
		if (thief.enemyVariables.currentHP > 0)
		{
			thief.enemyEncounter(character);
			character.playerVariables.posX -= 1;
		}
	}
	else if (character.playerVariables.posX == wolf.enemyVariables.posX && character.playerVariables.posY == wolf.enemyVariables.posY)
	{
		if (wolf.enemyVariables.currentHP > 0)
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

	//use a range for loop here on a refactor
	for (int p = 0; p < 5; p++)
	{
		std::cout << " ";
	}
	std::cout << "Gold: " << character.playerVariables.gold << "g" << std::endl;
	std::cout << "+";

	//for (int k = 0; k <= (mapX-1); k++)
	//{
	//	std::cout << "-";
	//}
	std::cout << border * (mapX);


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

		character.playerVariables.posX -= 1;

		switch (shopChoice)
		{
		case(1):
		{
			if (character.playerVariables.gold >= 2) //cost of health potion
			{
				character.playerVariables.potions += 1;
				std::cout << "You have purchased 1 health potion." << std::endl;
				character.playerVariables.gold -= 2;
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
			if (character.playerVariables.gold >= 30) //cost of health potion
			{
				character.playerVariables.currentWeapon = Player::W_HAMMER;
				std::cout << "You have purchased and equipped a hammer." << std::endl;
				character.playerVariables.gold -= 30;
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
				player.playerVariables.currentHP = player.playerVariables.maxHP;
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
		askMovement(playerOne);
		if (playerOne.playerVariables.maxHP == 37)
		{
			system("CLS");
			std::cout << "You win!" << std::endl;
			std::cout << "Press enter to exit." << std::endl;
			playGame = false;
			std::cin.ignore();
			std::cin.get();
			exit(EXIT_SUCCESS);

		}
		
	}

	std::cin.ignore();
	std::cin.get();
}