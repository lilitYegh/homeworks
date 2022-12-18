#pragma once
#include "Board.h"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define END "\033[0m"
#define TAB "\t\t"
#define CENTER "\t\t\t\t\t\t"
#define C "\n\t\t\t\t\t"
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
	void logo();
	void solved();
	int moves = 0;
public:
	void play();
};