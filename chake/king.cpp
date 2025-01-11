#include "king.h"


king::king(char color) : piece()
{
	this->color = color;
	this->check = false;
	this->set_type();
}
king::~king()
{

}
bool king::movement(int move_from, int move_to, piece* (&board)[8][8])
{
    int row_from = move_from / 10;
    int col_from = move_from % 10; 
    int row_to = move_to / 10;    
    int col_to = move_to % 10;     
    int row_diff = row_to - row_from;
    int col_diff = col_to - col_from;

    if ((row_diff >= -1 && row_diff <= 1) &&
        (col_diff >= -1 && col_diff <= 1) &&
        !(row_diff == 0 && col_diff == 0))
    {

        if (board[row_to][col_to] != nullptr)
        {
            if (board[row_to][col_to]->get_color() == this->color)
            {
                return false;
            }
            else
            {
                delete board[row_to][col_to]; 
                printf("\nkilled!\n");
                board[row_to][col_to] = nullptr;
            }
        }

        board[row_to][col_to] = board[row_from][col_from];
        board[row_from][col_from] = nullptr;          

        return true;
    }

    return false;
}


void king::set_check()
{
	//good luck
}
bool king::get_check()
{
	return this->check;
}

char king::get_color() const
{
	return this->color;
}
void king::set_type()
{
	if (this->get_color() == 'w')
	{
		this->type = 'K';
	}
	else if (this->get_color() == 'b')
	{
		this->type = 'k';
	}
}
char king::get_type() const
{
	return this->type;
}