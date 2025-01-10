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
	if ((move_from / 10 != move_to / 10 && move_from % 10 == move_to % 10) || (move_from / 10 == move_to / 10 && move_from % 10 != move_to % 10) // if move in a lein
		&& board[move_to % 10][move_to / 10] != nullptr)
	{

		return true;

	}
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