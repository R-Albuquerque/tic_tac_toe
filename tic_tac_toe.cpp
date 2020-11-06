// Made by Rafael Albuquerque (https://github.com/R-Albuquerque)
#include <iostream>
#include "funcs_ttt.h"

using namespace std;

int main()
{
	vector<vector<char> > board = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	bool player_flag = true;
	char player_turn;
	int win = 0;

	cout << "\n ===== " << "TIC TAC TOE" << " ===== \n";

	while (win == 0)
	{
		display_board(board, win);
		if (player_flag)
		{
			player_turn = 'X';
		}
		else{
			player_turn = 'O';
		}
		board = player_move(board, player_turn);
		win = who_won(board);
		player_flag = !player_flag;

	}

	display_board(board, win);


}

