#include "GameChecker.h"
#include <iostream>

int GameChecker::CheckGameStatus(int board[6][7])
{
    // direction for down, right,  diagonal down left to right, diagonal right to left
    int directions[][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 7; col++) {
            if (board[row][col] == 0) {
                
                continue;
            }
            int player = board[row][col];

            // Check each direction
            for (auto& direction : directions) {
                int dx =  direction[0];
                int dy =  direction[1];

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
                    return player;
                }
            }
        }
    }
	return -2;
}
