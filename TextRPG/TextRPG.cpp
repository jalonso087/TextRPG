//**********************************
//* TextRPG
//* Javier Alonso
//* 2/27/24
//* v0.01
//**********************************

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "player.h"
#include "mainMenu.h"
#include "enemy.h"

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
		<< "Insert story here\nblah blah blah"
		<< "Press enter to continue.\n";
	
	std::cin.ignore();
	std::cin.get();
	system("CLS");

}

static char askMovement(void)
{
	unsigned char move; 

	std::cout
		<< "Which direction would you like to go?\n"
		<< "w. North\n"
		<< "a. West\n"
		<< "s. South\n"
		<< "d. East\n"
		<< "Selection: ";

	std::cin >> move;

	return move;

}

int main(void)
{
	int startChoice = startScreen();
	bool playGame = false;
	bool quitGame = false;

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
	
	while (playGame)
	{
		//game loop here
		askMovement();

		
	}

	std::cin.ignore();
	std::cin.get();
}