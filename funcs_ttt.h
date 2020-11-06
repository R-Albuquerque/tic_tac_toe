#pragma once
#include <iostream>
#include <vector>

using namespace std;

void display_board(vector<vector <char>> board, int who_won = 0);
vector<vector <char>> player_move(vector<vector <char>> board, char player);
int who_won(vector<vector <char>> board);