//**********************************
//* TextRPG
//* Javier Alonso
//* 2/27/24 - Present
//* v1.01
//**********************************
#include "Main.h"

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



void map(Player &character)
{

	std::string border = "-";
	std::string space = " ";
	char spaces[mapX][mapY];
	
	if (character.posX == rat.posX && character.posY == rat.posY)
	{
		if (rat.currentHP > 0)
		{
			rat.enemyEncounter(character);
			character.posX -= 1;
		}
	}
	else if (character.posX == goblin.posX && character.posY == goblin.posY)
	{
		if (goblin.currentHP > 0)
		{
			goblin.enemyEncounter(character);
			character.posX -= 1;
		}
	}
	else if (character.posX == thief.posX && character.posY == thief.posY)
	{
		if (thief.currentHP > 0)
		{
			thief.enemyEncounter(character);
			character.posX -= 1;
		}
	}
	else if (character.posX == wolf.posX && character.posY == wolf.posY)
	{
		if (wolf.currentHP > 0)
		{
			wolf.enemyEncounter(character);
			character.posX -= 1;
		}
	}
	else if (character.posX == dungeonX && character.posY == dungeonY)
	{
		if (character.dungeonCheck())
		{
			dragon.enemyEncounter(character);
			character.posX -= 1;
		}
	}

	std::cout << "HP: " << character.currentHP << "/" << character.maxHP;
	std::cout << space * 5;
	std::cout << "Gold: " << character.gold << "g" << std::endl;
	std::cout << space * 5;
	std::cout << "Potions: " << character.potions << std::endl;
	std::cout << "+" << border * (mapX) << "+" << std::endl;

	for (int i = 0; i <= (mapX - 1); i++)
	{
		std::cout << "|";
		for (int j = 0; j <= (mapY - 1); j++)
		{
			if (i == dungeonX && j == dungeonY)
			{
				spaces[i][j] = dungeon;
				std::cout << spaces[i][j];
			}
			else if (i == townX && j == townY)
			{
				spaces[i][j] = town;
				std::cout << spaces[i][j];
			}
			else if (i == character.posX && j == character.posY)
			{
				spaces[i][j] = player;
				std::cout << spaces[i][j];
			}
			else if (i == rat.posX && j == rat.posY)
			{
				if (rat.currentHP > 0)
				{
					spaces[i][j] = enemy;
				}
				else
				{
					spaces[i][j] = emptySpace;
				}
				std::cout << spaces[i][j];
			}
			else if (i == goblin.posX && j == goblin.posY)
			{
				if (goblin.currentHP > 0)
				{
					spaces[i][j] = enemy;
				}
				else
				{
					spaces[i][j] = emptySpace;
				}
				std::cout << spaces[i][j];
			}
			else if (i == thief.posX && j == thief.posY)
			{
				if (thief.currentHP > 0)
				{
					spaces[i][j] = enemy;
				}
				else
				{
					spaces[i][j] = emptySpace;
				}
				std::cout << spaces[i][j];
			}
			else if (i == wolf.posX && j == wolf.posY)
			{
				if (wolf.currentHP > 0)
				{
					spaces[i][j] = enemy;
				}
				else
				{
					spaces[i][j] = emptySpace;
				}
				std::cout << spaces[i][j];
			}
			else
			{
				spaces[i][j] = emptySpace;
				std::cout << spaces[i][j];
			}

		}
		std::cout << "|" << std::endl;
	}
	std::cout << "+" << border * (mapX) << "+" << std::endl;
}

//not const static because we update character position
void visitTown(Player &character)
{

	static enum prices
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
		character.currentHP = character.maxHP;
		std::cin.ignore();
		std::cin.get();
		system("CLS");
		character.posX -= 1;
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
				if (character.gold >= P_HEALTHPOTION) //price of health potion
				{
					character.potions += 1;
					std::cout << "You have purchased 1 health potion." << std::endl;
					character.gold -= P_HEALTHPOTION;
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
				if (character.gold >= P_HAMMER) //price of hammer
				{
					character.currentWeapon = Player::W_HAMMER;
					std::cout << "You have purchased and equipped a hammer." << std::endl;
					character.gold -= P_HAMMER;
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
		character.posX -= 1;
	}
	else if (choice == 3)
	{
		character.posX -= 1;
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
			player.posX -= 1;
			if (player.posX == townX && player.posY == townY)
			{
				visitTown(player);
			}
			if (player.posX < 0 || player.posX > mapX)
			{
				player.posX += 1;
			}
			break;
		}
		case(KEY_DOWN):
		case(KEY_S):
		{
			player.posX += 1;
			if (player.posX == townX && player.posY == townY)
			{
				visitTown(player);
			}
			if (player.posX < 0 || player.posX >(mapX - 1))
			{
				player.posX -= 1;
			}
			break;
		}
		case(KEY_LEFT):
		case(KEY_A):
		{
			player.posY -= 1;
			if (player.posX == townX && player.posY == townY)
			{
				visitTown(player);
			}
			if (player.posY < 0 || player.posY > mapY)
			{
				player.posY += 1;
			}
			break;
		}
		case(KEY_RIGHT):
		case(KEY_D):
		{
			player.posY += 1;
			if (player.posX == townX && player.posY == townY)
			{
				visitTown(player);
			}
			if (player.posY < 0 || player.posY >(mapY - 1))
			{
				player.posY -= 1;
			}
			break;
		}
		case(KEY_BACK):
		{
			if (player.potions > 0)
			{
				while (player.currentHP != player.maxHP)
				{
					player.potions -= 1;
					player.currentHP = player.maxHP;
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
		if (playerOne.maxHP == 37)
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
	return 0;
}