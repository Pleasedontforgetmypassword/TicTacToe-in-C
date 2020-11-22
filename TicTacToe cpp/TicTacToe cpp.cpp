#include <iostream>
#include <stdlib.h>

using namespace std;

// Function for displaying the board
void display(int board[3][3], bool turn);
// check for a winner
bool winner(int board[3][3], int player);
// Function to check if the board is empty
bool empty(int board[3][3]);

// main
int main()
{
	// 3x3 board
	int board[3][3] = { { 0, 0, 0 },
					    { 0, 0, 0 },
					    { 0, 0, 0 } };
	// player turn is true
	bool player = true;
	// display board
	display(board, player);


	do
	{	
		// if an end game condition is true, then end the game
		if (winner(board, 1) || winner(board, 2) || empty(board))
		{
			break;
		}
		// x
		int x;
		// y
		int y;
		// if its player turn
		if (player)
		{
			// get input
			cout << "Enter x: ";
			cin >> x;
			cout << "Enter y: ";
			cin >> y;
			cout << "\n";

			// if location is valid
			if (board[x][y] == 0)
			{
				// play it
				board[x][y] = 1;
				player = false;
			}
			// if not valid
			else
			{
				// tell user
				cout << "Invalid Location" << endl;
			}
		}
		// if computer's turn
		else
		{
			// find a empty spot
			do
			{
				x = rand() % 3;
				y = rand() % 3;
			} 
			while (board[x][y] != 0);
			// once found, play it
			board[x][y] = 2;
			player = true;
		}
		// display board
		display(board, player);

	} 
	while (true);

	// once game ends
	// if player won
	if (winner(board, 1))
	{
		// tell the user
		cout << "X wins!!!!" << endl;
	}
	// computer's win
	else if (winner(board, 2))
	{
		cout << "O wins!!!!" << endl;
	}
	// tie
	else
	{
		cout << "TIE!!!!" << endl;
	}
	// return 0
	return 0;
}

// display function
void display(int board[3][3], bool turn)
{
	// displays the turn
	if (turn)
	{
		cout << "\nX's turn" << endl;
	}
	else
	{
		cout << "\nO's turn" << endl;
	}

	// the sumbol
	char symbol = '-';

	cout << "\n";
	// loops over the board
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// whats at the location
			switch (board[i][j])
			{
				case 0:
					symbol = '-';
					break;
				case 1:
					symbol = 'x';
					break;
				case 2:
					symbol = 'o';
					break;
			}
			// should print |-|
			cout << '|' << symbol << '|';
		}
		// new row
		cout << "\n";
	}
	cout << "\n";
}

// see if someone won
bool winner(int board[3][3], int player)
{
	// check the rows
	for (int i = 0; i < 3; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][1] == player))
		{
			return true;
		}
	}
	// check the columns
	for (int j = 0; j < 3; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[1][j] == player))
		{
			return true;
		}
	}
	// check the first diagonal
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[1][1] == player))
	{
		return true;
	}
	// check the second diagonal
	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && (board[1][1] == player))
	{
		return true;
	}
	// if the above did not activate then, there is no winner yet!
	return false;
}

// check if the board is empty
bool empty(int board[3][3])
{
	// loops over the board
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// if a tile is 0
			if (board[i][j] == 0)
			{
				// there is a playable move
				return false;
			}
		}
	}
	// if the above did not activate, return true
	return true;
}