#include "helper.h"
#include "tictactoe.h"

void playAgainstHuman(WINDOW * window) {
    int player1Score = 0;
    int player2Score = 0;
    std::string player1, player2;
    int position, ch;

    std::string currentPlayer1, currentPlayer2;

    while(true) {
        wclear(window);
        wrefresh(window);
        if(player1.empty() || player2.empty()) {
            waddstr(window, "Enter Player 1's name: ");
            wrefresh(window);
            while((ch = getch()) != '\n') {
                player1.push_back(ch);
            }
            waddstr(window, "Enter Player 2's name: ");
            wrefresh(window);
            while((ch = getch()) != '\n') {
                player2.push_back(ch);
            }
        }
        currentPlayer1 = player1;
        currentPlayer2 = player2;

        TicTacToe game;
        game.setPlayerNames(currentPlayer1, currentPlayer2);

        while(true) {
            wclear(window);
            waddstr(window, "Current board:\n");
            game.printBoard(window);
            waddstr(window, currentPlayer1.c_str());
            waddstr(window, " (X), enter position (1-9): ");
            wrefresh(window);
            position = getch() - 49;
            if (position >= 1 && position <= 9 && game.makeMove(position)) {
                char winner = game.checkWinner();
                if(winner != ' ') {
                    waddstr(window, currentPlayer1.c_str());
                    waddstr(window, " wins!\n");
                    wrefresh(window);
                    player1Score++;
                    break;
                } else if(game.isBoardFull()) {
                    waddstr(window, "It's a draw!\n");
                    wrefresh(window);
                    break;
                }
            } else {
                waddstr(window, "Invalid move. Try again.\n");
                wrefresh(window);
            }

            wclear(window);
            waddstr(window, "Current board:\n");
            game.printBoard(window);
            waddstr(window, currentPlayer2.c_str());
            waddstr(window, " (O), enter position (1-9): ");
            wrefresh(window);
            position = getch() - 49;
            if (position >= 1 && position <= 9 && game.makeMove(position)) {
                char winner = game.checkWinner();
                if(winner != ' ') {
                    waddstr(window, currentPlayer2.c_str());
                    waddstr(window, " wins!\n");
                    wrefresh(window);
                    player2Score++;
                    break;
                } else if(game.isBoardFull()) {
                    waddstr(window, "It's a draw!\n");
                    wrefresh(window);
                    break;
                }
            } else {
                waddstr(window, "Invalid move. Try again.\n");
                wrefresh(window);
            }
        }

        // Display points after each game
        wclear(window);
        waddstr(window, "Points:\n");
        wprintw(window, "%s: %d points\n", currentPlayer1.c_str(), player1Score);
        wprintw(window, "%s: %d points\n", currentPlayer2.c_str(), player2Score);
        waddstr(window, "Do you want to start a new game? (yes/no): ");
        wrefresh(window);
        std::string newGameChoice;
        while((ch = getch()) != '\n') {
            newGameChoice.push_back(ch);
        }
        if(newGameChoice != "yes") {
            break;
        }
    }
}

void playAgainstComputer(WINDOW *window) {
    TicTacToe game;
    std::string playerName;
    int position, ch;

    srand(static_cast<unsigned>(time(nullptr)));
    
    wclear(window);
    wrefresh(window);
    waddstr(window, "Enter your name: ");
    while((ch = getch()) != '\n') {
        playerName.push_back(ch);
    }
    game.setPlayerNames(playerName, "Computer");

    while(true) {
        wclear(window);
        wrefresh(window);
        waddstr(window, "Current board:\n");
        game.printBoard(window);
        wprintw(window, "%s (X), enter position (1-9): ", game.getPlayer1Name().c_str());
        wrefresh(window);
        position = getch() - 49;
        if(position >= 1 && position <= 9 && game.makeMove(position)) {
            char winner = game.checkWinner();
            if(winner != ' ') {
                if(winner == 'X') {
                    wprintw(window, "%s wins!\n", game.getPlayer1Name().c_str());
                    wrefresh(window);
                } else {
                    wprintw(window, "%s wins!\n", game.getPlayer2Name().c_str());
                    wrefresh(window);
                }
                break;
            } else if(game.isBoardFull()) {
                waddstr(window, "It's a draw!\n");
                wrefresh(window);
                break;
            }
        } else {
            waddstr(window, "Invalid move. Try again.\n");
            wrefresh(window);
        }

        // Computer's turn (random move)
        do {
            position = rand() % 9 + 1;
        } while(!game.makeMove(position));

        char winner = game.checkWinner();
        if(winner != ' ') {
            if(winner == 'X') {
                wprintw(window, "%s wins!\n", game.getPlayer1Name().c_str());
                wrefresh(window);
            } else {
                wprintw(window, "%s wins!\n", game.getPlayer2Name().c_str());
                wrefresh(window);
            }
            break;
        }
    }
}