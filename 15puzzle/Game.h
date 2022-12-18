#pragma once
#include "Board.h"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define END "\033[0m"
class Game
{
private:
	Board* b;
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void move(char direction);
	char getDir();
	int win();

	void print();

	int moves = 0;
public:
	void play();
};