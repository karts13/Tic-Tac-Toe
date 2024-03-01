#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <ncurses.h>
#include <string>

class TicTacToe {
    private:
        char board[3][3];
        char currentPlayer;
        std::string player1Name;
        std::string player2Name;
        int moves;
    public:
        TicTacToe();
        void setPlayerNames(const std::string& name1, const std::string& name2);
        std::string getPlayer1Name();
        std::string getPlayer2Name();
        void printBoard(WINDOW *window);
        char getCurrentPlayer();
        bool makeMove(int position);
        char checkWinner();
        bool isBoardFull();
};

#endif