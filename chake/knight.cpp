#include "knight.h"


knight::knight(char color) : piece()
{
	this->color = color;
	this->check = false;
	this->set_type();
}
knight::~knight()
{

}
bool knight::movement(std::string bord)
{
	return true;
	//good luck
}
void knight::set_check()
{
	//good luck
}
bool knight::get_check()
{
	return this->check;
}

char knight::get_color() const
{
	return this->color;
}
void knight::set_type()
{
	if (this->get_color() == 'w')
	{
		this->type = 'N';
	}
	else if (this->get_color() == 'b')
	{
		this->type = 'n';
	}
}
char knight::get_type() const
{
	return this->type;
}