#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;


/* Function to display the board*/
void display_board(vector<vector <char>> board, int who_won = 0) {
	cout << "\n";
	string winner;
	if (who_won != 0 && who_won != 3)
	{
		switch (who_won)
		{
		case 1:
			winner = "X";
			break;
		default:
			winner = "O";
			break;
		}
		
		cout << "===== " <<  winner << " has won the match!" << " =====";
	}
	else if (who_won == 3)
	{
		cout << "TIE! nobody won!";
	}
	else
	{
		cout << "Board:";
	}
	
	cout << "\n\n";
	for (int i = 0; i < 3; i++)
	{

		cout << " ";
		for (int j = 0; j < 3; j++)
		{
			cout << " " << board[i][j];
			if (j < 2)
			{
				cout << " |";
			}
		}
		if (i != 2)
		{
			cout << "\n ---|---|--- \n";
		}
		else
		{
			cout << "\n";
		}
	}
}

/* Function to get player input and return updated keyboard */
vector<vector <char>> player_move(vector<vector <char>> board, char player) {

	int sq_num;
	vector<int> sq_vals = {1,2,3,4,5,6,7,8,9};
	bool isvalid = false;
	int sq_count;
	
	bool done = false;


	cout << "is num: " << (0 - 'a') << '\n';

	while (!done)
	{
		sq_num = 0;
		sq_count = 0;
		cout << "It's " << player << "'s turn.\n Choose one of the squares above: ";
		cin >> sq_num;

		for (int g = 0; g < 9; g++)
		{
			if (sq_num == sq_vals[g]) {
				isvalid = true;
			}
		}
		if (isvalid == false)
		{
			cout << "\nMust be a valid number between 0 and 9.Choose again!\n";
			cin.clear();
			cin.ignore(10000, '\n');
			//cin >> sq_num;
		}

		else
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					sq_count++;

					if (sq_count == sq_num)
					{
						if (board[i][j] != 'X' && board[i][j] != 'O')
						{
							board[i][j] = player;
							done = true;
						}
						else
						{
							cout << "This square is not available!\n";
						}
					}

				}
			}

		}
	}

	return board;

	}


/*	Function that checks if game is over, and if it is, who won.
	Returns 0 if game is not over,
	1 if X won,
	2 if O won
	and 3 if there is a tie.*/
int who_won(vector<vector <char>> board) {
	
	int available = 0;
	int winner = 0;

	for (int i = 0; i < 3; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
		{
			switch (board[i][0])
			{
			case 'X':
				winner = 1;
				break;
			case 'O':
				winner = 2;
				break;
			default:
				break;
			}
		}

		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
		{
			switch (board[1][i])
			{
			case 'X':
				winner = 1;
				break;
			case 'O':
				winner = 2;
				break;
			default:
				break;
			}
		}
		


		for (int j = 0; j < 3; j++)
		{
		
			if (board[i][j] != 'X' && board[i][j] != 'O')
			{
				available++;
			}
			
		}
	}

	if (((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) || ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))) {
		switch (board[1][1])
		{
		case 'X':
			winner = 1;
			break;
		case 'O':
			winner = 2;
			break;
		default:
			break;
		}
	}

	if (winner == 0 && available == 0)
	{
		return 3;
	}
	else
	{
		return winner;
	}
	
}
