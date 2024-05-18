#include "ComputerPlayer.h"
#include <iostream>

int ComputerPlayer::CalculateScore(int board[6][7])
{
    int directions[][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 7; col++) {
            if (board[row][col] == 0) {

                continue;
            }
            int player = board[row][col];

            // Check each direction
            for (auto& direction : directions) {
                int dx = direction[0];
                int dy = direction[1];

                bool isMatched = true;

                // do the step forward right or diagonally 4 times checking if all match in the place
                for (int i = 1; i < 4; i++)
                {
                    int newRow = row + i * dx;
                    int newCol = col + i * dy;

                    // stay within the board
                    if (newRow >= 0 && newRow < 6 && newCol >= 0 && newCol < 7)
                    {
                        // if one of the position is not equal to player set to false
                        if (board[newRow][newCol] != player)
                        {
                            isMatched = false;
                            break;
                        }
                    }
                    else
                    {
                        isMatched = false;
                        break;
                    }
                }
                if (isMatched)
                {
                    return player == 2 ? 1 : -1;
                }

            }
        }
        if (row > 6) {
            return 0;
        }
    }

    return -2;

}

int ComputerPlayer::GetBestMove(int board[6][7], int depth, int alpha, int beta, bool maximizer)
{
    int result = CalculateScore(board);

    if (result != -2){
        return result;
    }
    
    if (depth == 0) {
        return 0;
    }

    if (maximizer)
    {
        int maxScore = INT_MIN;
        for (int row = 6; row > 0; row--) {
            for (int col = 0; col < 7; col++) 
            {
                if (board[row][col] == 0) {
                    board[row][col] = 2;
                    int score = GetBestMove(board, depth - 1, alpha, beta, false);
                    board[row][col] = 0;
                    maxScore = std::max(score, maxScore);
                    alpha = std::max(alpha, score);
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return maxScore;
    }
    else {
        int minScore = INT_MAX;
        for (int row = 6; row > 0; row--) {
            for (int col = 0; col < 7; col++)
            {
                if (board[row][col] == 0) {
                    board[row][col] = 1;
                    int score = GetBestMove(board, depth - 1, alpha, beta, true);
                    board[row][col] = 0;
                    minScore = std::min(score, minScore);
                    beta = std::min(beta, score);
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return minScore;
    }
}

int ComputerPlayer::ProcessBestMove(int board[6][7])
{
    int bestScore = INT_MIN;
    int bestPostion = 0;

    for (int row = 6; row > 0; row--){
        for (int col = 0; col < 7; col++) {
            if (board[row][col] == 0)
            {
                board[row][col] = 2;
                int score = GetBestMove(board, 5, INT_MIN, INT_MAX, false);
                board[row][col] = 0;
                if (score >= bestScore) 
                {
                    bestScore = score;
                    bestPostion = col;
                }
            }
        }
    }
    return bestPostion;
}