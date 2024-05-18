#pragma once

class ComputerPlayer
{
public:
	int CalculateScore(int board[6][7]);
	int GetBestMove(int board[6][7], int depth, int alpha, int beta, bool maximizer);
	int ProcessBestMove(int board[6][7]);

};

