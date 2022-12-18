#pragma once
#include <algorithm>
#include <array>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include<windows.h>

const int BoardSize = 4;
class Board
{
private:
    int** elements = new int* [BoardSize];
    int vSP = 0;
    int hSP = 0;
    int countInversions();
    bool isSolvable();
    void findEmptyField();
    void generateBoard();

    static Board* b_;
    Board() = default;

public:
    static Board* getBoardobj();
    void makeBoard();
    int** getBoard();
    int getEmptyVert();
    int getEmptyHoriz();
    void setEmptyVert(int v);
    void setEmptyHoriz(int h);

    Board(Board& obj) = delete;
    Board(Board&& obj) = delete;
    void operator=(Board&) = delete;
    Board& operator=(Board&& obj) = delete;
};