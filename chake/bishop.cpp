#include "bishop.h"

bishop::bishop(char color) : piece()
{
	this->color = color;
	this->check = false;
	this->set_type();
}
bishop::~bishop() 
{
    
}
bool bishop::movement(int move_from, int move_to, piece* (&board)[8][8])
{
    int row_from = move_from / 10;
    int col_from = move_from % 10;
    int row_to = move_to / 10;    
    int col_to = move_to % 10;    

    int row_diff = row_to - row_from; 
    int col_diff = col_to - col_from; 
    int row_step = 0;
    int col_step = 0;
  
    if ((row_diff == col_diff || row_diff == - col_diff) == false)
    {
        return false; 
    }

    
    if (row_diff > 0) 
    {
        row_step = 1; 
    }
    else if (row_diff < 0)
    {
        row_step = -1;
    }
    
    if (col_diff > 0) 
    {
        col_step = 1; 
    }
    else if (col_diff < 0) 
    {
        col_step = -1; 
    }

    int row = row_from + row_step;
    int col = col_from + col_step;

    while (true)
    {
        if (row == row_to && col == col_to)
        {
            if (board[row][col] != nullptr)
            {
                if (board[row][col]->get_color() == this->color)
                {
                    return false; 
                }
                else
                {
                    delete board[row][col]; 
                    printf("\nkilled!\n");
                    board[row][col] = nullptr; 
                }
            }
            break; 
        }

        if (board[row][col] != nullptr)
        {
            return false; 
        }

        row += row_step;
        col += col_step;
    }

    board[row_to][col_to] = board[row_from][col_from]; 
    board[row_from][col_from] = nullptr;              

    return true; 
}


void bishop::set_check(piece* (&board)[8][8])
{
	//good luck
}

bool bishop::get_check()
{
	return this->check;
}

char bishop::get_color() const
{
	return this->color;
}
void bishop::set_type()
{
	if (this->get_color() == 'w')
	{
		this->type = 'B';
	}
	else if (this->get_color() == 'b')
	{
		this->type = 'b';
	}
}
char bishop::get_type() const
{
	return this->type;
}