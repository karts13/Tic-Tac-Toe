#include "tictactoe.h"

TicTacToe::TicTacToe()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
    moves = 0;
}

void TicTacToe::setPlayerNames(const std::string &name1, const std::string &name2)
{
    player1Name = name1;
    player2Name = name2;
}

std::string TicTacToe::getPlayer1Name()
{
    return player1Name;
}

std::string TicTacToe::getPlayer2Name()
{
    return player2Name;
}

void TicTacToe::printBoard(WINDOW *window)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            wprintw(window, " %c ", board[i][j]);
            if (j < 2)
                waddstr(window, "|");
        }
        waddstr(window, "\n");
        if (i < 2)
            waddstr(window, "-----------\n");
    }
    wrefresh(window);
}

char TicTacToe::getCurrentPlayer()
{
    return currentPlayer;
}

bool TicTacToe::makeMove(int position)
{
    bool result = false;
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
    {
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        moves++;
        result = true;
    }
    return result;
}

char TicTacToe::checkWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return board[0][2];
    }

    // No winner yet
    return ' ';
}

bool TicTacToe::isBoardFull() {
    return moves == 9;
}