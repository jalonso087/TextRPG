#pragma once

int random_num(const static int& start, const static int& max);

class Enemy
{
private:

protected:

public:

	const enum enemies : unsigned char
	{
		E_RAT,
		E_GOBLIN,
		E_THIEF,
		E_WOLF,
		E_SKELETON,
		E_SPIDER,
		E_ORC,
		E_WIZARD,
		E_OGRE
	};

	const enum boss : unsigned char
	{
		B_RAT,
		B_GOBLIN,
		B_THIEF,
		B_WOLF,
		B_SKELETON,
		B_SPIDER,
		B_ORC,
		B_WIZARD,
		B_OGRE
	};

	int hp;
	int posX;
	int posY;

	Enemy() 
	{
		
		hp = 5;
		posX = random_num(1, 18);
		posY = random_num(1, 18);

	};

};