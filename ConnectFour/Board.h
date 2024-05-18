#pragma once
#include <iostream>
class Board{
private:
	static const int row = 6;
	static const int column = 7;
	

public:
	Board();
	void Draw();
	bool Input(int col, bool isAi);
	int board[row][column];
};

