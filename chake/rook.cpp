#include "rook.h"

rook::rook(char color) : piece()
{
	this->color = color;
	this->check = false;
	this->set_type();
}
rook::~rook()
{

}
bool rook::movement(int move_from, int move_to, piece* (&board)[8][8])
{

	int row_from = move_from / 10;
	int col_from = move_from % 10;
	int row_to = move_to / 10;
	int col_to = move_to % 10;
	

	int row_diff = row_to - row_from;
	int col_diff = col_to - col_from;



	if ((row_from != row_to && col_from == col_to) || (row_from == row_to && col_from != col_to)) // if move in a lein
	{

		//chake move
		if (row_from != row_to && col_from == col_to)
		{
													//col is fixed == false
			if (cal_move(row_diff, row_from, row_to, false,board))
			{

				board[row_to][col_to] = board[row_from][col_from];
				board[row_from][col_from] = nullptr;
				return true;

			}

		}
		else
		{											//row is fixed == true
			if (cal_move(col_diff, col_from, col_to, true, board))
			{

				board[row_to][col_to] = board[row_from][col_from];
				board[row_from][col_from] = nullptr;
				return true;

			}

		}

	}
	
	return false;

}

bool rook::cal_move(int diff,int from, int to, bool fixed, piece* (&board)[8][8])
{

	int i = from;
	int step = 0;

	if (diff < 0) 
	{

		step = -1;

	}
	else 
	{

		step = 1;

	}

	if (fixed)
	{

		while ((i += step) != to)
		{

			if (board[fixed][i] != nullptr)
			{

				return false;

			}

		}

		if (board[fixed][to] != nullptr)
		{
			if (board[fixed][to]->get_color() == this->color)
			{
				return false; 
			}
			else
			{
				delete board[fixed][to]; 
				printf("\nkilled!\n");
				board[fixed][to] = nullptr; 
				
			}
		}

	}
	else
	{

		while ((i += step) != to)
		{

			if (board[i][fixed] != nullptr)
			{

				return false;

			}

		}

		if (board[to][fixed] != nullptr)
		{
			if (board[to][fixed]->get_color() == this->color)
			{
				return false; // Cannot move to a square occupied by your own piece
			}
			else
			{
				delete board[to][fixed]; // Capture and delete the opponent's piece
				printf("\nkilled!\n");
				board[to][fixed] = nullptr; // Clear the destination square
				
			}
		}

	}
		


	return true;
}

void rook::set_check()
{
	//good luck
}
bool rook::get_check()
{
	return this->check;
}

char rook::get_color() const
{
	return this->color;
}
void rook::set_type()
{
	if (this->get_color() == 'w')
	{
		this->type = 'R';
	}
	else if (this->get_color() == 'b')
	{
		this->type = 'r';
	}
}
char rook::get_type() const
{
	return this->type;
}