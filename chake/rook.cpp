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

	int i = 0;
	int step = 0;



	if ((row_from != row_to && col_from == col_to) || (row_from == row_to && col_from != col_to)) // if move in a lein
	{

		if (row_diff < 0)
		{

			step = -1;

		}
		else
		{

			step = 1;

		}

		//chake move
		if (row_from != row_to && col_from == col_to)
		{
			//col is fixed == false
			i = row_from;
			while ((i += step) != row_to)
			{

				if (board[i][col_from] != nullptr)
				{
					return false;

				}

			}

			if (board[row_to][col_to] != nullptr)
			{
				
				return eat(col_from, row_from, col_to, row_to, board);

			}
			else
			{

				move(col_from, row_from, col_to, row_to, board);
				return true;

			}

		}
		else
		{
			i = col_from;
			while ((i += step) != col_to)
			{

				if (board[row_from][i] != nullptr)
				{
					return false;

				}

			}

			if (board[row_to][col_to] != nullptr)
			{

				return eat(col_from, row_from, col_to, row_to, board);

			}
			else
			{

				move(col_from, row_from, col_to, row_to, board);
				return true;

			}

		}

	}
	
	return false;

}

bool rook::eat(int col_from, int row_from, int col_to, int row_to, piece* (&board)[8][8])
{

	if (board[row_to][col_to]->get_color() == this->color)
	{
		return false;
	}
	else
	{
		
		move(col_from, row_from, col_to, row_to, board);

	}

	return true;
	
}

void rook::move(int col_from, int row_from, int col_to, int row_to, piece* (&board)[8][8])
{

	delete board[row_to][col_to];
	printf("\nkilled!\n");
	board[row_to][col_to] = board[row_from][col_from];
	board[row_from][col_from] = nullptr;

}

void rook::set_check(piece* (&board)[8][8])
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