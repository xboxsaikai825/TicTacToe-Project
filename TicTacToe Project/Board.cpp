#include "board.h"

board::board() {
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			grid[r][c] = '*';
		}
	}
	int count = 0;
	char current_player;
	this->render();
	while (this->get_winner() == '0') {
		if (count % 2 == 0) { current_player = 'X'; }
		else
			current_player = 'O';
		this->make_move(this->get_move(), current_player);
		this->render();
		count++;
	}

}

void board::render() {
	cout << "  0 1 2" << endl;
	cout << "  ------" << endl;
	for (int r = 0; r < 3; r++) {
		cout << r << "|";
		for (int c = 0; c < 3; c++) {
			cout << grid[r][c] << "|";
		}
		cout << endl;
	}
	cout << "  ------" << endl;
}

string board::get_move() {
	string input;
	cout << "Enter the x-coordinate followed by the y-coordinate ex(01): "; cin >> input;
	return input;
}

void board::make_move(string move_coords, char player) {
	char x_coord = move_coords[0];
	char y_coord = move_coords[1];
	int ix_coord = x_coord - '0';
	int iy_coord = y_coord - '0';
	cout << "X:" << ix_coord << endl;
	cout << "Y:" << iy_coord << endl;
	if (grid[iy_coord][ix_coord] == 'X' || grid[iy_coord][ix_coord] == 'O') {
		cout << "Invalid move." << endl;
		this->render();
		this->make_move(this->get_move(), player);
	}
	else if (grid[iy_coord][ix_coord] == '*') {
		grid[iy_coord][ix_coord] = player;
	}
}

char board::get_winner() {

	// checks all horizontal wins
	if ((grid[0][0] == 'X' || grid[0][0] == 'O') && grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) { return grid[0][0]; }

	else if ((grid[1][0] == 'X' || grid[1][0] == 'O') && grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) { return grid[1][0]; }

	else if ((grid[2][0] == 'X' || grid[2][0] == 'O') && grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) { return grid[2][0]; }

	// checks all vertical wins
	else if ((grid[0][0] == 'X' || grid[0][0] == 'O') && grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) { return grid[0][0]; }

	else if ((grid[0][1] == 'X' || grid[0][1] == 'O') && grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) { return grid[0][0]; }

	else if ((grid[0][2] == 'X' || grid[0][2] == 'O') && grid[0][2] == grid[1][2] && grid[1][1] == grid[2][2]) { return grid[0][0]; }

	// checks all diagonal wins

	else if ((grid[0][0] == 'X' || grid[0][0] == 'O') && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) { return grid[0][0]; }

	else if ((grid[2][0] == 'X' || grid[2][0] == 'O') && grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]) { return grid[0][0]; }

	else
		return '0';
}