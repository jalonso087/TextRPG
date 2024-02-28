#pragma once

class player
{
private:



protected:

public:

	//unisnged char uses less memory than int. 1 byte (8 bit) vs 4 bytes (32 bits)
	const enum weapons : unsigned char
	{
		W_STICK,
		W_CLUB,
		W_HAMMER,
		W_MACE,
		W_KNIFE,
		W_SWORD,
		W_SPEAR,
		W_DAGGER,
		W_CLAYMORE
	};

	const enum items : unsigned char
	{
		I_HEALTHPOTION,
		I_ENERGYPOTION,
		I_KEY,
		I_TOWNPORTAL
	};

	int level,
		posX,
		posY;


	player()
	{
		level = 1;
		posX = 0;
		posY = 0;
	}

	//std::string inventory(player& player, std::string item)
	//{
	//	std::string contents[10];
	//
	//}

	char movement()
	{

	}

};