#include "ConnectFour.h"
#include "ComputerPlayer.h"

void Game::Start() {
    Board board;
    GameChecker checker;
    ComputerPlayer ai;

    board.Draw();
    int column;
    while (std::cin >> column) {
        if (board.Input(column, false)) {
            board.Draw();
            int aiMove = ai.ProcessBestMove(board.board);
            board.Input(aiMove, true);
            board.Draw();
            int result = checker.CheckGameStatus(board.board);
            std::cout << result << std::endl;
             if (result == 1) {
                std::cout << "Player 1 Win" << std::endl;
                break;
            }
            if (result == 2){
                std::cout << "Player 2 Win" << std::endl;
                break;
            }
            
            
        }
        else {
            std::cout << "Invalid placement" << std::endl;
        }
    }
}