#include "Game.h"

void Game::play()
{
    b = Board::getBoardobj();
    b->makeBoard();
    bool end = false;
    do
    {
        system("cls");
        print();
        char direction = getDir();
        Sleep(40);
        move(direction);
        if (win() == 1) {
            system("cls");
            print();
            solved();
            std::cout << C << "Puzzle has been solved in " << moves << " moves.\n";
            end = true;
        }

    } while (end == false);

}
void Game::solved()
{
    std::cout << CYAN;
    std::cout << TAB << " _____             _        _              _                          _           _\n";
    std::cout << TAB << "|  _  |_ _ ___ ___| |___   | |_ ___ ___   | |_ ___ ___ ___    ___ ___| |_ _ ___ _| |\n";
    std::cout << TAB << "|   __| | |- _|- _| | -_|  |   | .'|_ -|  | . | -_| -_|   |  |_ -| . | | | | -_| . |\n";
    std::cout << TAB << "|__|  |___|___|___|_|___|  |_|_|__,|___|  |___|___|___|_|_|  |___|___|_|\\_/|___|___|\n";
    std::cout << END;
                                                                                                                                                                                                                                                           
}
void Game::logo() 
{
    std::cout << CYAN;                                                 
    std::cout << TAB << "  $$\\  $$$$$$$\\                                                            $$\\\n";
    std::cout << TAB << "$$$$ | $$  ____|                                                           $$ |\n";
    std::cout << TAB << "\\_$$ | $$ |                         $$$$$$\\  $$\\   $$\\ $$$$$$$$\\ $$$$$$$$\\ $$ | $$$$$$\\\n";
    std::cout << TAB << "  $$ | $$$$$$$\\                    $$  __$$\\ $$ |  $$ |\\____$$  |\\____$$  |$$ |$$  __$$\\\n";
    std::cout << TAB << "  $$ | \\_____$$\\                   $$ /  $$ |$$ |  $$ |  $$$$ _/   $$$$ _/ $$ |$$$$$$$$ |\n";
    std::cout << TAB << "  $$ | $$\\   $$ |                  $$ |  $$ |$$ |  $$ | $$  _/    $$  _/   $$ |$$   ____|\n";
    std::cout << TAB << "$$$$$$\\\\$$$$$$  |                  $$$$$$$  |\\$$$$$$  |$$$$$$$$\\ $$$$$$$$\\ $$ |\\$$$$$$$\\\n";
    std::cout << TAB << "\\______|\\______/                   $$  ____/  \\______/ \\________|\\________|\\__| \\_______|\n";
    std::cout << TAB << "                                   $$ |\n";
    std::cout << TAB << "                                   $$ |\n";
    std::cout << TAB << "                                   \__|\n";
    std::cout << END;
}
                                            
void Game::print()
{
    logo();
    for (int i = 0; i < BoardSize; i++)
    {
        std::cout << MAGENTA << CENTER << "+----+----+----+----+\n" << END;
        for (int j = 0; j < BoardSize; j++)
        {
            if (j == 0)
            {
                std::cout << CENTER;
            }
            std::cout << MAGENTA << "| " << END;
            if (b->getBoard()[i][j] == 0)
            {
                std::cout << std::setw(3) << " ";
            }
            else
            {
                std::cout << CYAN  << std::setw(3) << b->getBoard()[i][j] << END;
            }
        }
        std::cout << MAGENTA << "|\n" << END;
    }
    std::cout << MAGENTA << CENTER << "+----+----+----+----+\n" << END;
}

char Game::getDir()
{
    char dir;
    std::cout << C << "w - Up, s - Down, a - Left, d - Right\n";
    std::cin >> dir;
    return dir;
}

void Game::move(char direction)
{
    switch (direction)
    {
    case 'W':
    case 'w':
        moveUp();
        break;

    case 'S':
    case 's':
        moveDown();
        break;

    case 'D':
    case 'd':
        moveRight();
        break;

    case 'A':
    case 'a':
        moveLeft();
        break;

    default:
        std::cout << "Can not move that way.\n";
        break;
    }
}



void Game::moveUp()
{
    int vSP = b->getEmptyVert();
    int hSP = b->getEmptyHoriz();
    int vP = vSP;
    if (vP + 1 < 4 && vP >= 0) {

        b->getBoard()[vSP][hSP] = b->getBoard()[vSP + 1][hSP];
        b->getBoard()[vSP + 1][hSP] = 0;
        b->setEmptyVert(vSP + 1);
        moves++;
    }

}
void Game::moveDown()
{
    int vSP = b->getEmptyVert();
    int hSP = b->getEmptyHoriz();
    int vP = vSP;
    if (vP + 1 <= 4 && vP > 0) {

        b->getBoard()[vSP][hSP] = b->getBoard()[vSP - 1][hSP];
        b->getBoard()[vSP - 1][hSP] = 0;
        b->setEmptyVert(vSP - 1);
        moves++;
    }
    
}
void Game::moveRight()
{
    int vSP = b->getEmptyVert();
    int hSP = b->getEmptyHoriz();
    int hP = hSP;
    if (hP + 1 <= 4 && hP > 0) {

        b->getBoard()[vSP][hSP] = b->getBoard()[vSP][hSP - 1];
        b->getBoard()[vSP][hSP - 1] = 0;
        b->setEmptyHoriz(hSP - 1);
        moves++;
    }
}
void Game::moveLeft()
{
    int vSP = b->getEmptyVert();
    int hSP = b->getEmptyHoriz();
    int hP = hSP;
    if (hP + 1 < 4 && hP >= 0) {

        b->getBoard()[vSP][hSP] = b->getBoard()[vSP][hSP + 1];
        b->getBoard()[vSP][hSP + 1] = 0;
        b->setEmptyHoriz(hSP + 1);
        moves++;
    }
}

int Game::win()
{
    int check[BoardSize][BoardSize] =
    { {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };

    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
        {
            if (b->getBoard()[i][j] != check[i][j])
            {
                return -1;
            }
        }
    }
    return 1;

}