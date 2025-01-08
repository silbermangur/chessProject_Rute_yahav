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
bool king::movement(piece* bord, int new_pose)
{
	return true;
	//good luck
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

int  king::get_positon() const
{

	return this->positon;

}

void king::set_positon(int pose)
{

	this->positon = pose;

}