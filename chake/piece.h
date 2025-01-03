   #pragma once

#include <iostream>

class piece
{
public:

	virtual bool movement(std::string bord);
	virtual void set_check();
	virtual bool get_check();
	virtual void set_color();
	virtual char get_color();
	virtual void set_type();
	virtual char get_type();

private:

	char color;
	bool check;
	char type;

};