#pragma once
#include "piece.h"

class bishop : public piece
{
public:
	bishop(char color);
	virtual ~bishop();
	bool movement(int move_from, int move_to, piece* (&board)[8][8]) override;
	void set_check() override;
	bool get_check() override;
	char get_color() const override;
	void set_type() override;
	char get_type() const override;

private:
	char color;
	bool check;
	char type;
};
