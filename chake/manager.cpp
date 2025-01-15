#include "manager.h"
#include "rook.h"
#include "king.h"
#include "knight.h"
#include "bishop.h"
#include "pawn.h"
#include "queen.h"

manager::manager()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = nullptr;
        }
    }

    for (int j = 0; j < 8; j++)
    {
        board[1][j] = new pawn('w');
        board[6][j] = new pawn('b');
    }

    board[0][0] = new rook('w');
    board[0][7] = new rook('w');
    board[7][0] = new rook('b');
    board[7][7] = new rook('b');

    board[0][1] = new knight('w');
    board[0][6] = new knight('w');
    board[7][1] = new knight('b');
    board[7][6] = new knight('b');

    board[0][2] = new bishop('w');
    board[0][5] = new bishop('w');
    board[7][2] = new bishop('b');
    board[7][5] = new bishop('b');

    board[0][3] = new king('w');
    board[7][3] = new king('b');

    board[0][4] = new queen('w');
    board[7][4] = new queen('b');

   

}

manager::~manager()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != nullptr)
            {
                delete board[i][j];
            }
        }
    }
}


void manager::showBoard() 
{
    std::cout << "  ";
    for (int j = 0; j < 8; j++) 
    {
        std::cout << j << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 8; i++) 
    {
        std::cout << i << " ";
        for (int j = 0; j < 8; j++) 
        {
            if (board[i][j] == nullptr) 
            {
                std::cout << "# ";
            }
            else 
            {
                std::cout << board[i][j]->get_type() << " ";
            }
        }
        std::cout << std::endl;
    }
}


bool manager::checkValid(std::string frontInput)
{
    return true;
}
int manager::getCode()
{
    return this->code;
}
void manager::setCode()
{

}
void manager::play()
{
    
    bool check = false;
    bool validInput = false;
    int from = 0;
    int to = 0;
    char answer = ' ';
    bool keepGoing = true;

    this->showBoard();

    while (keepGoing)
    {
        validInput = false; // Reset validInput for each iteration

        while (!validInput)
        {
            std::cout << "\nenter the start position: ";
            std::cin >> from;

            if (from < 0 || from > 77) // Validate input is within range
            {
                std::cout << "\ninvalid position" << std::endl;
                continue;
            }

            if (board[from / 10][from % 10] == nullptr)
            {
                std::cout << "\ninvalid movement" << std::endl;
            }
            else
            {
                validInput = true;
            }
        }

        std::cout << "\nenter the end position: ";
        std::cin >> to;

        if (to < 0 || to > 77) 
        {
            std::cout << "\ninvalid position" << std::endl;
            continue;
        }

        check = board[from / 10][from % 10]->movement(from, to, board);
        if (check == false)
        {
            std::cout << "\ninvalid movement" << std::endl;
        }
        else
        {
            std::cout << "\n" << std::endl;
            this->showBoard();
        }

        std::cout << "\ncontinue? Y/N ";
        std::cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            keepGoing = true;
        }
        else if (answer == 'N' || answer == 'n')
        {
            keepGoing = false;
        }
        else
        {
            std::cout << "\nInvalid input. Exiting." << std::endl;
            keepGoing = false;
        }
    }

}   
