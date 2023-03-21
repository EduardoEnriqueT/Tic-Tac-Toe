#include <iostream>
#include "Header.h"
#include <iomanip>
using namespace std;

void TTT::game()
{
	welcomeMsg();
	reset();
	ShowRules();
	player = whoGoesFirst();

	do
	{
		Display();
		int move = getMove(GetTurn());
		Go(move);
		if (isWinner(GetTurn()))
			break;
		switchTurn();
	} while (!isFull());

	Display();
	if (isFull())
		cout << "draw\n";
	else
		if (GetTurn() == X)
			cout << "X is winner\n";
		else
			cout << "O is winner\n";

}


void TTT::welcomeMsg() // Menu of the game 
{
	cout << "\n\n"
		"\n\t\t\t\t\t*|=====================================================|*"
		"\n\t\t\t\t\t*|                                                     |*"
		"\n\t\t\t\t\t*|           Welcome to the Tic-Tac-Toe Game!          |*"
		"\n\t\t\t\t\t*|                                                     |*"
		"\n\t\t\t\t\t*|-----------------------------------------------------|*"
		"\n\t\t\t\t\t*|  Press X to start the game.                         |*"
		"\n\t\t\t\t\t*|  Press T to play a tactical TTT  (UNDERCONSTRUCTION)|*"
		"\n\t\t\t\t\t*|  Press Q to EXIT.                                   |*"
		"\n\t\t\t\t\t*|=====================================================|*\n" << endl;

	char choice;
	cin >> choice;
	choice = toupper(choice);
	switch (choice) {
	case 'X':
		system("cls");
		break;

	case 'T':

		break;
	case 'Q':
		exit(0);
		break;

	default:
		cout << "Bad Input, please try again !";
		
		system("cls");
		welcomeMsg();
		break;
	}
}


void TTT::reset()			//Fuction to reset the board
{
	for (int i = 0; i < Nsize; i++)
		board[i] = Blank;
}


bool TTT::isWinner(int p) // Get the winner
{

	for (int i = 0; i < Nsize; i = i + 3)
	{
		if ((board[i] == board[i + 1]) && (board[i + 1] == board[i + 2]))
		{
			if (board[i] == p)
				return true;
		}
	}


	for (int i = 0; i < 3; i++)
	{
		if ((board[i] == board[i + 3]) && (board[i + 3] == board[i + 6]))
			if (board[i] == p)
				return true;
	}

	if ((board[0] == board[4]) && (board[4] == board[8]))
		if (board[4] == p)
			return true;


	if ((board[2] == board[4]) && (board[4] == board[6]))
		if (board[4] == p)
			return true;

	return false;
}


bool TTT::isFree(int s) // Check if has a free space
{
	return(board[s] == Blank);
}


void TTT::Go(int s) 
{
	board[s] = player;
}


void TTT::Display() // Display the board 
{
	cout << setw(4) << endl << "|" << setw(4);
	for (int i = 0; i < Nsize; i++)
	{
		if (board[i] == X)
			cout << " X |" << setw(4);
		else if (board[i] == OH)
			cout << " O |" << setw(4);
		else
			cout << " |" << setw(4);
		if ((i < Nsize - 1) && ((i + 1) % 3 == 0))
			cout << setw(4) << endl << "|" << setw(4);


	}

	cout << endl;
}


bool TTT::isFull()  // Check if the board is full
{
	for (int i = 0; i < Nsize; i++)
		if (board[i] == Blank)
			return false;
	return true;
}


int TTT::GetTurn()  //Turn for the player
{
	return player;
}


void TTT::switchTurn() //Switch turn to each player
{
	if (player == X)
		player = OH;
	else
		player = X;
}


int TTT::possWin(int p) // Possible strategy to win 
{

	for (int i = 0; i < Nsize; i = i + 3)  // Vertical wins
	{
		if ((board[i] == p) && (board[i + 1] == p) && (board[i + 2] == Blank))
			return (i + 2);
		if ((board[i + 1] == p) && (board[i + 2] == p) && (board[i] == Blank))
			return i;
		if ((board[i] == p) && (board[i + 2] == p) && (board[i + 1] == Blank))
			return (i + 1);
	}


	for (int i = 0; i < 3; i++)  // Horizontal wins
	{
		if ((board[i] == p) && (board[i + 3] == p) && (board[i + 6] == Blank))
			return (i + 6);
		if ((board[i] == Blank) && (board[i + 3] == p) && (board[i + 6] == p))
			return i;
		if ((board[i] == p) && (board[i + 3] == Blank) && (board[i + 6] == p))
			return (i + 3);
	}


	//Diagonal wins
	if ((board[0] == p) && (board[4] == p) && (board[8] == Blank))
		return 8;
	if ((board[0] == Blank) && (board[4] == p) && (board[8] == p))
		return 0;
	if ((board[0] == p) && (board[4] == Blank) && (board[8] == p))
		return 4;


	if ((board[2] == p) && (board[4] == p) && (board[6] == Blank))
		return 6;
	if ((board[2] == Blank) && (board[4] == p) && (board[6] == p))
		return 2;
	if ((board[2] == p) && (board[4] == Blank) && (board[6] == p))
		return 4;


	return -1;
}


int TTT::whoGoesFirst() // Gets a random player to go first
{
	int p = rand() % 2 + 1;
	return p;
}


int TTT::getMove(int p) // Get the move of the players
{
	int move;
	if (p == X)
		cout << "Player X ";
	else
		cout << "Player O ";

	cout << "enter your move(1-9) : ";
	cin >> move;

	while (move < 1 || move > 9 || !isFree(move - 1))
	{
		cout << "Invalid move. Re-enter : ";
		cin >> move;
	}

	return move - 1;
}


//Rules of the game

void TTT::ShowRules()
{
	cout << "The game is played on a grid of 3X3 square." << endl;
	cout << "It includes 2 players: X and O." << endl;
	cout << "Players take turns and mark their characters in empty squares." << endl;
	cout << "The first player to get 3 same characters in a row wins the game." << endl;
	cout << "When all squares are filled up and no player has 3 characters in a single row then it results in a tie." << endl;

}


