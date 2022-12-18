#include "Board.h"
Board* Board::b_ = nullptr;


int Board::countInversions()
{
    int vec[BoardSize * BoardSize];
    for (int i = 0; i < BoardSize; ++i)
    {
        for (int j = 0; j < BoardSize; ++j)
        {
            vec[i * BoardSize + j] = elements[i][j];
        }
    }
    int inv = 0;
    for (int i = 0; i < BoardSize * BoardSize - 1; ++i)
    {
        for (int j = i + 1; j < BoardSize * BoardSize; ++j)
        {
            if (vec[i] > vec[j] && vec[i] && vec[j])
            {
                inv++;
            }
        }
    }
    return inv;
}
bool Board::isSolvable()
{
    int inv = countInversions();
  
    int pos = vSP;
    if (pos & 1)
        return !(inv & 1);
    else
        return inv & 1;
    
}
    

void Board::findEmptyField()
{
    for (int i = 0; i < BoardSize; ++i)
    {
        for (int j = 0; j < BoardSize; ++j)
        {
            if (elements[i][j] == 0)
            {
                vSP = i;
                hSP = j;
            }
        }
    }

}
void Board::generateBoard()
{
    std::array<int, 16> temp{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,0, 15 };
    auto num = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(temp.begin(), temp.end(), std::default_random_engine(num));
    for (int i = 0; i < BoardSize; ++i)
    {
        for (int j = 0; j < BoardSize; ++j)
        {
            elements[i][j] = temp[i * BoardSize + j];
        }
    }

}
Board* Board::getBoardobj()
{
    if (b_ == nullptr)
    {
        b_ = new Board();
    }
    return b_;
}
int** Board::getBoard()
{
    return elements;
}
void Board::makeBoard()
{
    for (int i = 0; i < BoardSize; ++i)
    {
        elements[i] = new int[BoardSize];
    }
    do
    {
        generateBoard();
        findEmptyField();

    } while (!isSolvable());
}


int Board::getEmptyVert()
{
    return vSP;
}
int Board::getEmptyHoriz()
{
    return hSP;
}
void Board::setEmptyVert(int v)
{
    vSP = v;
}
void Board::setEmptyHoriz(int h)
{
    hSP = h;
}