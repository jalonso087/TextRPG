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
#include "player.h"
#include "mainMenu.h"
#include "enemy.h"



void visitTown(void);
char enemyEncounter(enemy::enemies monster);

int startScreen(void)
{
	int choice = 0;

	std::cout << "Welcome to <TextRPG>!\n\n" << std::endl;

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

int random_num(const int start, const int max)
{
	int random = start + rand() % (max);
	return random;
}


void map(int x, int y)
{


	const int enemy1[2] = { random_num(1, 18), random_num(1, 18) };
	const int enemy2[2] = { random_num(1, 18), random_num(1, 18) };
	const int enemy3[2] = { random_num(1, 18), random_num(1, 18) };
	const int enemy4[2] = { random_num(1, 18), random_num(1, 18) };
	const int enemy5[2] = { random_num(1, 18), random_num(1, 18) };

	//enemy enemy1(enemy::enemies::E_RAT);
	//enemy enemy2(enemy::enemies::E_GOBLIN);
	//enemy enemy3(enemy::enemies::E_THIEF);
	//enemy enemy4(enemy::enemies::E_WOLF);

	char spaces[20][20];

	char player = 'X';	
	char emptySpace = '.';							
	char town = 'T';
	char dungeon = 'D';
	char enemy = 'E';

	std::cout << "+";
	for (int k = 0; k <= 19; k++)
		std::cout << "-";
	std::cout << "+";
	std::cout << std::endl;

	for (int i = 0; i <= 19; i++)
	{
		std::cout << "|";
		for (int j = 0; j <= 19; j++)
		{
			if (i == 4 && j == 15)
			{
				spaces[i][j] = dungeon;
				std::cout << spaces[i][j];
			}
			else if (i == 17 && j == 9)
			{
				spaces[i][j] = town;
				std::cout << spaces[i][j];
			}
			else if (i == enemy1[0] && j == enemy1[1])
			{
				spaces[i][j] = enemy;
				std::cout << spaces[i][j];
			}
			else if (i == enemy2[0] && j == enemy2[1])
			{
				spaces[i][j] = enemy;
				std::cout << spaces[i][j];
			}
			else if (i == enemy3[0] && j == enemy3[1])
			{
				spaces[i][j] = enemy;
				std::cout << spaces[i][j];
			}
			else if (i == enemy4[0] && j == enemy4[1])
			{
				spaces[i][j] = enemy;
				std::cout << spaces[i][j];
			}
			else if (i == enemy5[0] && j == enemy5[1])
			{
				spaces[i][j] = enemy;
				std::cout << spaces[i][j];
			}
			else if (i == x && j == y)
			{
				spaces[i][j] = player;
				std::cout << spaces[i][j];
			}
			else
			{
				spaces[i][j] = emptySpace;
				std::cout << spaces[i][j];
			}



		}

		if (x == enemy1[0] && y == enemy1[1])
			enemyEncounter(enemy::enemies::E_RAT);
		else if (x == enemy2[0] && y == enemy2[1])
			enemyEncounter(enemy::enemies::E_GOBLIN);
		else if (x == enemy3[0] && y == enemy3[1])
			enemyEncounter(enemy::enemies::E_THIEF);
		else if (x == enemy4[0] && y == enemy4[1])
			enemyEncounter(enemy::enemies::E_WOLF);

		std::cout << "|" << std::endl;
	}
	std::cout << "+";
	for (int k = 0; k <= 19; k++)
		std::cout << "-";
	std::cout << "+";
	std::cout << std::endl;

	
}

char enemyEncounter(enemy::enemies monster)
{
	int choice;
	unsigned char result;

	system("CLS");
	std::cout << "You encountered a(n) ";
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

void visitTown(void)
{

	const static enum prices
	{
		P_HEALTHPOTION = 20,
		P_STICK = 10,
		P_CLUB = 25,
		P_HAMMER = 100
	};

	int choice;

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
}

void askMovement(player &player)
{
	int move; 
	bool validMove = false;

	while (!validMove)
	{
		std::cout
			<< "Use your arrow keys to move.\n";

		const enum arrowKey
		{
			KEY_UP = 72,
			KEY_LEFT = 75,
			KEY_DOWN = 80,
			KEY_RIGHT = 77
		};

		switch (_getch())
		{
		case(KEY_UP):
			player.posX -= 1;
			if (player.posX == 17 && player.posY == 9)
			{
				visitTown();
			}
			if (player.posX < 0 || player.posX > 20)
			{
				player.posX += 1;
				
			}
			break;
		case(KEY_DOWN):
			player.posX += 1;
			if (player.posX == 17 && player.posY == 9)
			{
				visitTown();
			}
			if (player.posX < 0 || player.posX > 19)
			{
				player.posX -= 1;
			}
			break;
		case(KEY_LEFT):
			player.posY -= 1;
			if (player.posX == 17 && player.posY == 9)
			{
				visitTown();
			}
			if (player.posY < 0 || player.posY > 20)
			{
				player.posY += 1;
			}
			break;
		case(KEY_RIGHT):
			player.posY += 1;
			if (player.posX == 17 && player.posY == 9)
			{
				visitTown();
			}
			if (player.posY < 0 || player.posY > 19)
			{
				player.posY -= 1;
			}
			break;
		}

		

		validMove = true;
	
	}

	

	system("CLS");

}



float damageFormula(player::weapons weapon)
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

	player playerOne;


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
		map(playerOne.posX, playerOne.posY);
		askMovement(playerOne);
		

		
	}

	std::cin.ignore();
	std::cin.get();
}