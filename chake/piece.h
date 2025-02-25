#pragma once

#include <iostream>

class piece
{
public:

	virtual bool movement(int move_from, int move_to, piece* (&board)[8][8]) = 0;
	virtual void set_check() = 0;
	virtual bool get_check() = 0;
	virtual char get_color() const = 0;
	virtual void set_type() = 0;
	virtual char get_type() const = 0;

private:

	char color;
	bool check;
	char type;

};