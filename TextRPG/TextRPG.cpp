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
int enemyEncounter(Enemy &monster, const static Player &character);
int damageFormula(const static Player& character);

//found online
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

//bundle into a display class on a refactor
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


	
/*
else if (x == enemy2[0] && y == enemy2[1])
enemyEncounter(enemy::enemies::E_GOBLIN);
else if (x == enemy3[0] && y == enemy3[1])
enemyEncounter(enemy::enemies::E_THIEF);
else if (x == enemy4[0] && y == enemy4[1])
enemyEncounter(enemy::enemies::E_WOLF);

const int enemy1[2] = { random_num(1, 18), random_num(1, 18) };
const int enemy2[2] = { random_num(1, 18), random_num(1, 18) };
const int enemy3[2] = { random_num(1, 18), random_num(1, 18) };
const int enemy4[2] = { random_num(1, 18), random_num(1, 18) };
const int enemy5[2] = { random_num(1, 18), random_num(1, 18) };
*/

int enemyEncounter(Enemy &monster, const static Player &character)
{
	int choice;
	unsigned char result = 0;
	bool combat;

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

	while (combat)
	{
		std::cout << "Enemy HP: " << monster.enemyVariables.currentHP << "/" << monster.enemyVariables.startingHP << std::endl;
		std::cout << "\nYour HP: " << character.playerVariables.currentHP << "/" << character.playerVariables.maxHP << std::endl;
		std::cout << "1. Attack\n"
			<< "Selection: ";

		std::cin >> choice;

		if (choice == 1)
		{
			int dmg = damageFormula(character);
			std::cout << "You did " << dmg << " point of damage\n" << std::endl;;
			monster.enemyVariables.currentHP -= dmg;
			system("CLS");
			if (monster.enemyVariables.currentHP <= 0)
			{
				result = 1;
				combat = false;
			}
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
			<< "Use your wasd keys to move.\n";

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

	dmg = random_num((character.playerVariables.currentWeapon+1), (character.playerVariables.currentWeapon+1));

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