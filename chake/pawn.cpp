#include "pawn.h"


pawn::pawn(char color) : piece()
{
	this->color = color;
	this->check = false;
	this->set_type();
	this->set_move(false);
}
pawn::~pawn()
{

}
bool pawn::movement(int move_from, int move_to, piece* (&board)[8][8])
{

	int row_from = move_from / 10;
	int col_from = move_from % 10;
	int row_to = move_to / 10;
	int col_to = move_to % 10;

	int move = 0;

	if (this->get_color() == 'w')
	{

		move = 1;

	}
	else
	{

		move = -1;

	}

	if (((((!this->get_move() && (move_from + move * 20) == move_to) && (board[row_to + 1][col_to] == nullptr)) //if is the forset move cake if he move 2
		||// else
		((move_from + move * 10) == move_to)) && (board[row_to][col_to] == nullptr)) // chake if the move is valied
		||
		((((row_from + move) == row_to) && (col_from + 1 == col_to || col_from - 1 == col_to)) && board[row_to][col_to] != nullptr && board[row_to][col_to]->get_color() != this->get_color()) // chake if its tring to eat ander piece
		)
	{
		
		if (!this->get_move())
		{

			this->set_move(true);

		}

		board[row_to][col_to] = board[row_from][col_from];
		board[row_from][col_from] = nullptr;
		return true;

	}
	
	return false;

}

void pawn::set_move(bool did_move)
{

	this->forst_move = did_move;

}

bool pawn::get_move() const
{

	return this->forst_move;

}

void pawn::set_check()
{
	//good luck
}
bool pawn::get_check()
{
	return this->check;
}
char pawn::get_color() const
{
	return this->color;
}
void pawn::set_type()
{
	if (this->get_color() == 'w')
	{
		this->type = 'P';
	}
	else if (this->get_color() == 'b')
	{
		this->type = 'p';
	}
}
char pawn::get_type() const
{
	return this->type;
}