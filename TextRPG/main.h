#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>
#include <conio.h>
#include <Windows.h>
#include "Player.h"
#include "Enemy.h"
//#include "Base.h"

const int mapX = 20;
const int mapY = 20;

//Map Marker Locations
const int dungeonX = 4;
const int dungeonY = 15;
const int townX = 17;
const int townY = 9;
//

//Map markers
char player = 'X';
char emptySpace = '.';
char town = 'T';
char dungeon = 'D';
char enemy = 'E';
//

//Enemy Object Instantiation
Enemy rat(Enemy::E_RAT);
Enemy goblin(Enemy::E_GOBLIN);
Enemy thief(Enemy::E_THIEF);
Enemy wolf(Enemy::E_WOLF);
Enemy dragon(Enemy::E_DRAGON);

std::string operator * (std::string a, int num);

int random_num(const int& start, const int& max);

int startScreen(void);

void intro(void);

void visitTown(Player& character);

bool dungeonCheck(Player& character);

void gotoxy(short x, short y);

void map(Player& character);

void visitTown(Player& character);

void askMovement(Player& player);

int main(void);

