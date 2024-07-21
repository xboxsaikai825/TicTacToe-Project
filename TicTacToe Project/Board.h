#pragma once
#include <array>
#include <string>
#include <iostream>

using namespace std;

class board
{
public:
	board(); //init an empty tictactoe grid

	void render(); //prints out the current grid with pieces

	string get_move(); //asks input from user for their move

	char get_winner(); //checks if game is done and returns the winner

	void make_move(string move_coords, char player); //makes a move on the board

	bool is_board_full(); // checks if board is full
private:
	char grid[3][3] = {};
};

