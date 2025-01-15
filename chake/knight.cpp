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
bool knight::movement(int move_from, int move_to, piece* (&board)[8][8])
{
	int row_from = move_from / 10;
	int col_from = move_from % 10;
	int row_to = move_to / 10;
	int col_to = move_to % 10;

	if((row_to == row_from + 2 || row_to == row_from - 2) && (col_to == col_from + 1 || col_to == col_from - 1) //chake if the move mant is up or done
		||
		(row_to == row_from + 1 || row_to == row_from - 1) && (col_to == col_from + 2 || col_to == col_from - 2))//chake if the move mant is lafte or rihte
	{ 
		
		if (board[row_to][col_to] != nullptr && board[row_to][col_to]->get_color() != this->get_color())
		{
			delete board[row_to][col_to];
			std::cout << "\nkilled!" << std::endl;
			board[row_to][col_to] = nullptr;
		}

		board[row_to][col_to] = board[row_from][col_from];
		board[row_from][col_from] = nullptr;
		return true;

	}

	return false;
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