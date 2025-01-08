#pragma once
#include <iostream>
#include "piece.h"

class manager
{
public:
	manager();
	~manager();
	void showBoard();
	bool checkValid(std::string frontInput);
	int getCode();
	void setCode();
	void play();


private:
	piece* board[8][8]; //this is the board that contains the pieces's (objects) pointers and moves them
	int code;

};