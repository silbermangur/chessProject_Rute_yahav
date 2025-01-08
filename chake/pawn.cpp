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
bool pawn::movement(piece* bord, int new_pose)
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

int  pawn::get_positon() const
{

	return this->positon;

}

void pawn::set_positon(int pose)
{

	this->positon = pose;

}