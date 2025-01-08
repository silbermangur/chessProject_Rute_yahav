#include "pawn.h"


pawn::pawn(char color) : piece()
{
	this->color = color;
	this->check = false;
	this->set_type();
}
pawn::~pawn()
{

}
bool pawn::movement(std::string move_from, int move_to, piece* borde)
{
	return true;
	//good luck
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