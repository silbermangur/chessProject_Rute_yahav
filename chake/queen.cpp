#include "queen.h"
#include "bishop.h"
#include "rook.h"

queen::queen(char color) : piece()
{
	this->color = color;
	this->check = false;
	this->set_type();
}

queen::~queen()
{

}

bool queen::movement(int move_from, int move_to, piece* (&board)[8][8])
{
	int row_from = move_from / 10;
	int col_from = move_from % 10;
	int row_to = move_to / 10;
	int col_to = move_to % 10;

	if (bishopMove(move_from, move_to, board) || rookMove(move_from, move_to, board))
	{
		return true; 
	}

	return false; 
}

void queen::set_check(piece* (&board)[8][8])
{

}
bool queen::get_check()
{
	return this->check;
}
char queen::get_color() const
{
	return this->color;
}
void queen::set_type()
{
	if (this->get_color() == 'w')
	{
		this->type = 'Q';
	}
	else if (this->get_color() == 'b')
	{
		this->type = 'q';
	}
}
char queen::get_type() const
{
	return this->type;
}

bool queen::rookMove(int move_from, int move_to, piece* (&board)[8][8])
{

    int row_from = move_from / 10;
    int col_from = move_from % 10;
    int row_to = move_to / 10;
    int col_to = move_to % 10;


    int row_diff = row_to - row_from;
    int col_diff = col_to - col_from;



    if ((row_from != row_to && col_from == col_to) || (row_from == row_to && col_from != col_to)) // if move in a lein
    {

        //chake move
        if (row_from != row_to && col_from == col_to)
        {
            //col is fixed == false
            if (cal_move(row_diff, row_from, row_to, false, board))
            {

                board[row_to][col_to] = board[row_from][col_from];
                board[row_from][col_from] = nullptr;
                return true;

            }

        }
        else
        {											//row is fixed == true
            if (cal_move(col_diff, col_from, col_to, true, board))
            {

                board[row_to][col_to] = board[row_from][col_from];
                board[row_from][col_from] = nullptr;
                return true;

            }

        }

    }

    return false;
}

bool queen::cal_move(int diff, int from, int to, bool fixed, piece* (&board)[8][8])
{
    int i = from;
    int step = 0;

    if (diff < 0)
    {

        step = -1;

    }
    else
    {

        step = 1;

    }

    if (fixed)
    {

        while ((i += step) != to)
        {

            if (board[fixed][i] != nullptr)
            {

                return false;

            }

        }

        if (board[fixed][to] != nullptr)
        {
            if (board[fixed][to]->get_color() == this->color)
            {
                return false;
            }
            else
            {
                delete board[fixed][to];
                printf("\nkilled!\n");
                board[fixed][to] = nullptr;

            }
        }

    }
    else
    {

        while ((i += step) != to)
        {

            if (board[i][fixed] != nullptr)
            {

                return false;

            }

        }

        if (board[to][fixed] != nullptr)
        {
            if (board[to][fixed]->get_color() == this->color)
            {
                return false; // Cannot move to a square occupied by your own piece
            }
            else
            {
                delete board[to][fixed]; // Capture and delete the opponent's piece
                printf("\nkilled!\n");
                board[to][fixed] = nullptr; // Clear the destination square

            }
        }

    }

    return true;
}
bool queen::bishopMove(int move_from, int move_to, piece* (&board)[8][8])
{
    int row_from = move_from / 10;
    int col_from = move_from % 10;
    int row_to = move_to / 10;
    int col_to = move_to % 10;

    int row_diff = row_to - row_from;
    int col_diff = col_to - col_from;
    int row_step = 0;
    int col_step = 0;

    if ((row_diff == col_diff || row_diff == -col_diff) == false)
    {
        return false;
    }


    if (row_diff > 0)
    {
        row_step = 1;
    }
    else if (row_diff < 0)
    {
        row_step = -1;
    }

    if (col_diff > 0)
    {
        col_step = 1;
    }
    else if (col_diff < 0)
    {
        col_step = -1;
    }

    int row = row_from + row_step;
    int col = col_from + col_step;

    while (true)
    {
        if (row == row_to && col == col_to)
        {
            if (board[row][col] != nullptr)
            {
                if (board[row][col]->get_color() == this->color)
                {
                    return false;
                }
                else
                {
                    delete board[row][col];
                    printf("\nkilled!\n");
                    board[row][col] = nullptr;
                }
            }
            break;
        }

        if (board[row][col] != nullptr)
        {
            return false;
        }

        row += row_step;
        col += col_step;
    }

    board[row_to][col_to] = board[row_from][col_from];
    board[row_from][col_from] = nullptr;

    return true;
}