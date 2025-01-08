#pragma once
#include "piece.h"

class king : public piece
{
public:
	king(char color);
	~king();
	bool movement(std::string move_from, int move_to, piece* borde) override;
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