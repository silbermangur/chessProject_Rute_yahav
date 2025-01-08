   #pragma once

#include <iostream>

class piece
{
public:

	virtual bool movement(piece* bord, int new_pose) = 0;
	virtual void set_check() = 0;
	virtual bool get_check() = 0;
	//the color is picked in the constructor so no need to set it manually
	virtual char get_color() const = 0;
	virtual void set_type() = 0;
	virtual char get_type() const = 0;
	virtual void set_positon(int pose) = 0;
	virtual int get_positon() const = 0;

private:

	char color;
	bool check;
	char type;
	int positon; //positoin of the piece 

};