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
bool rook::movement(std::string bord)
{
	return true;
	//good luck
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