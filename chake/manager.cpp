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
    for (int i = 0; i < 8; i++)
    {
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
    this->showBoard();

    //here you can check if the func works :)

    check = board[1][3]->movement(13, 23, board);
    if (check == false)
    {
        printf("invalid movement");
    }

    printf("\n\n");
    this->showBoard();

    check = board[6][0]->movement(60,40, board);
    if (check == false)
    {
        printf("invalid movement");
    }

    printf("\n\n");
    this->showBoard();

    check = board[0][4]->movement(04, 40, board);
    if (check == false)
    {
        printf("invalid movement");
    }
    
    printf("\n\n");
    this->showBoard();



    check = board[7][0]->movement(70, 50, board);
    if (check == false)
    {
        printf("invalid movement");
    }

    

    check = board[7][1]->movement(71, 52, board);
    if (check == false)
    {
        printf("invalid movement");
    }
    
    printf("\n\n");
    this->showBoard();

    check = board[5][2]->movement(52, 40, board);
    if (check == false)
    {
        printf("invalid movement");
    }

    printf("\n\n");
    this->showBoard();

}
