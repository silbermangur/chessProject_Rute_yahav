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
bool bishop::movement(int move_from, int move_to, piece* board[8][8])
{
	return true;
	//good luck
}
void bishop::set_check()
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