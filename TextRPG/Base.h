#pragma once

int random_num(const int& start, const int& max);

const int mapX = 20;
const int mapY = 20;

class Base
{
public:
	int maxHP;
	int currentHP;
	int posX;
	int posY;
	bool defeated;
};