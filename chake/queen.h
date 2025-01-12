#pragma once
#include "piece.h"


class queen : public piece
{
public:
	queen(char color);
	~queen();
	bool movement(int move_from, int move_to, piece* (&board)[8][8]) override;
	void set_check() override;
	bool get_check() override;
	char get_color() const override;
	void set_type() override;
	char get_type() const override;
	bool rookMove(int move_from, int move_to, piece* (&board)[8][8]);

	bool bishopMove(int move_from, int move_to, piece* (&board)[8][8]);
	bool eat(int col_from, int row_from, int col_to, int row_to, piece* (&board)[8][8]);
	void move(int col_from, int row_from, int col_to, int row_to, piece* (&board)[8][8]);


private:
	char color;
	bool check;
	char type;
};