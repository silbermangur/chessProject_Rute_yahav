#pragma once

#include "piece.h"

class pawn : public piece
{
public:
	pawn(char color);
	~pawn();
	bool movement(std::string bord) override;
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
