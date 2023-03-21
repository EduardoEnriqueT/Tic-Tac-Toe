
class TTT {
	//Private data
private:
	const static int Nsize = 9; // Size of the board
	int board[Nsize]; //Make the board
	int player;
	const int X = 1;
	const int OH = 2;
	const int Blank = 3;

public: //Public data with all the functions
	void reset();
	bool isWinner(int p);
	bool isFree(int s);
	void Go(int s);
	void Display();
	bool isFull();
	int GetTurn();
	void switchTurn();
	int possWin(int p);
	int whoGoesFirst();
	int getMove(int p);
	void ShowRules();
	void game();
	void welcomeMsg();
};
