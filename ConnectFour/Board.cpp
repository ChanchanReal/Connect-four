#include "Board.h"

Board::Board() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            board[i][j] = 0;
        }
    }
}

void Board::Draw() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (board[i][j] == 1)
                std::cout << " B ";
            else if (board[i][j] == 2)
                std::cout << " R ";

            if (board[i][j] == 0)
                std::cout << " . ";
        }
        std::cout << std::endl;
    }
}

bool Board::Input(int col, bool isAi) {
    for (int i = row; i >= 0; i--) {
        if (board[i][col] == 0) {
            if (!isAi)
                board[i][col] = 1;
            else {
                board[i][col] = 2;
            }
                
            return true;
        }
    }
    return false;
}