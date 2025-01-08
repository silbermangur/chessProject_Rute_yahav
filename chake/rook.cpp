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
bool rook::movement(piece* bord, int new_pose)
{
	
	//chake if movmant is good 
	if (((new_pose / 10 == this->get_positon() / 10 && new_pose % 10 != this->get_positon() % 10) || (new_pose / 10 != this->get_positon() / 10 && new_pose % 10 == this->get_positon() % 10))
		&& bord[new_pose / 10 + new_pose % 10].get_color() != this->get_color()) // if not the same clore   nullptr not work dont know y
	{

		if (new_pose / 10 != this->get_positon() / 10)
		{

			while (new_pose / 10 == this->get_positon() / 10)
			{

				

			}

		}
		
		return true;

	}
	return false;

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

int rook::get_positon() const
{

	return this->positon;

}

void rook::set_positon(int pose)
{

	this->positon = pose;

}