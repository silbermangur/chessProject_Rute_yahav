#pragma once

#include "piece.h"

class pawn : public piece
{
public:
	pawn(char color);
	~pawn();
	bool movement(int move_from, int move_to, piece* (&board)[8][8]) override;
	void set_check() override;
	bool get_check() override;
	char get_color() const override;
	void set_type() override;
	char get_type() const override;
	void set_move(bool did_move);
	bool get_move() const;

private:
	char color;
	bool check;
	char type;
	bool forst_move;
};
