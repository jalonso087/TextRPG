//**********************************
//* TextRPG
//* Javier Alonso
//* 2/27/24 - Present
//* v0.02
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
char enemyEncounter(const static Enemy::enemies &monster);

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
		<< "You are <player>. You have lived all 20 years of your life in <town>.\n"
		<< "Insert story here\nblah blah blah\n\n"
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

Enemy rat;
Enemy goblin;
Enemy thief;
Enemy wolf;

void map(const static Player &character)
{
	//const static int currentHP = &character.getHP();
	//ran into trouble using a get method on the player class, so resorted to accessing the variable directly. -- do this better on a refactor.
	std::cout << "HP: " << character.playerVariables.currentHP << "/" << character.playerVariables.maxHP << std::endl;

	char spaces[mapX][mapY];

	//std::cout << currentHP << std::endl;

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
				spaces[i][j] = mapMarkers.enemy;
				std::cout << spaces[i][j];
			}
			else if (i == goblin.enemyVariables.posX && j == goblin.enemyVariables.posY)
			{
				spaces[i][j] = mapMarkers.enemy;
				std::cout << spaces[i][j];
			}
			else if (i == thief.enemyVariables.posX && j == thief.enemyVariables.posY)
			{
				spaces[i][j] = mapMarkers.enemy;
				std::cout << spaces[i][j];
			}
			else if (i == wolf.enemyVariables.posX && j == wolf.enemyVariables.posY)
			{
				spaces[i][j] = mapMarkers.enemy;
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
if (x == enemy1[0] && y == enemy1[1])
enemyEncounter(enemy::enemies::E_RAT);
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

char enemyEncounter(const static Enemy::enemies &monster)
{
	int choice;
	unsigned char result;

	system("CLS");
	std::cout << "You encountered a ";
	switch(monster)
	{
	case(0):
		std::cout << "rat!\n";
		break;
	case(1):
		std::cout << "goblin!\n";
		break;
	case(2):
		std::cout << "thief!\n";
		break;
	case(3):
		std::cout << "wolf!\n";
		break;
	}

	std::cout << "1. Attack\n"
		<< "Selection: ";

	std::cin >> choice;

	if (choice == 1)
	{
		result = 1;
	}

	std::cin.ignore();
	std::cin.get();

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

float damageFormula(const static Player::weapons &weapon)
{
	float dmg;

	dmg = random_num((weapon+1), (weapon+1));

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