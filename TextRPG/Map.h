#pragma once

class Map
{

private:

protected:

public:
	void map(Player& character)
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

		for (int k = 0; k <= (mapX - 1); k++)
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
		for (int k = 0; k <= (mapX - 1); k++)
			std::cout << "-";
		std::cout << "+";
		std::cout << std::endl;
	}
};