#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

// Class for the Tic-Tac-Toe game
class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    string player1Name;
    string player2Name;
    int moves;

public:
    // Constructor to initialize the game
    TicTacToe() {
        // Initialize the board and set the starting player to 'X'
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
        moves = 0;
    }

    // Function to set player names
    void setPlayerNames(const string& name1, const string& name2) {
        player1Name = name1;
        player2Name = name2;
    }

    // Function to get player 1's name
    string getPlayer1Name() const {
        return player1Name;
    }

    // Function to get player 2's name
    string getPlayer2Name() const {
        return player2Name;
    }

    // Function to print the game board
    void printBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "-----------\n";
        }
    }

    // Function to get the current player ('X' or 'O')
    char getCurrentPlayer() const {
        return currentPlayer;
    }

    // Function to make a move on the board
    bool makeMove(int position) {
        // Convert the single position input to row and column
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        // Check if the cell is empty and within valid bounds
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            moves++;
            return true;
        }
        return false;
    }

    // Function to check if there is a winner
    char checkWinner() {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                return board[i][0];
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
                return board[0][i];
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
            return board[0][0];
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
            return board[0][2];
        }

        // No winner yet
        return ' ';
    }

    // Function to check if the board is full
    bool isBoardFull() const {
        return moves == 9;
    }
};

// Function to play against a human opponent
void playAgainstHuman() {
    int player1Score = 0;
    int player2Score = 0;
    string player1, player2;
    int position;

    // Declare variables for player names
    string currentPlayer1, currentPlayer2;

    while (true) {
        // Check if this is a new game or a continuation
        if (player1.empty() || player2.empty()) {
            cout << "Enter Player 1's name: ";
            cin >> player1;
            cout << "Enter Player 2's name: ";
            cin >> player2;
        }

        // Set current player names
        currentPlayer1 = player1;
        currentPlayer2 = player2;

        TicTacToe game;
        game.setPlayerNames(currentPlayer1, currentPlayer2);

        while (true) {
            cout << "Current board:\n";
            game.printBoard();
            cout << currentPlayer1 << " (X), enter position (1-9): ";
            cin >> position;

            if (position >= 1 && position <= 9 && game.makeMove(position)) {
                char winner = game.checkWinner();
                if (winner != ' ') {
                    cout << currentPlayer1 << " wins!" << endl;
                    player1Score++;
                    break;
                } else if (game.isBoardFull()) {
                    cout << "It's a draw!" << endl;
                    break;
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }

            cout << "Current board:\n";
            game.printBoard();
            cout << currentPlayer2 << " (O), enter position (1-9): ";
            cin >> position;

            if (position >= 1 && position <= 9 && game.makeMove(position)) {
                char winner = game.checkWinner();
                if (winner != ' ') {
                    cout << currentPlayer2 << " wins!" << endl;
                    player2Score++;
                    break;
                } else if (game.isBoardFull()) {
                    cout << "It's a draw!" << endl;
                    break;
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }

        // Display points after each game
        cout << "Points:\n";
        cout << currentPlayer1 << ": " << player1Score << " points\n";
        cout << currentPlayer2 << ": " << player2Score << " points\n";

        // Ask if players want to start a new game
        cout << "Do you want to start a new game? (yes/no): ";
        string newGameChoice;
        cin >> newGameChoice;

        if (newGameChoice != "yes") {
            break; // Exit the loop if not starting a new game
        }
    }
}

// Function to play against the computer
void playAgainstComputer() {
    TicTacToe game;
    string playerName;
    int position;

    cout << "Enter your name: ";
    cin >> playerName;

    game.setPlayerNames(playerName, "Computer");

    while (true) {
        cout << "Current board:\n";
        game.printBoard();
        cout << game.getPlayer1Name() << " (X), enter position (1-9): ";
        cin >> position;

        if (position >= 1 && position <= 9 && game.makeMove(position)) {
            char winner = game.checkWinner();
            if (winner != ' ') {
                if (winner == 'X') {
                    cout << game.getPlayer1Name() << " wins!" << endl;
                } else {
                    cout << game.getPlayer2Name() << " wins!" << endl;
                }
                break;
            } else if (game.isBoardFull()) {
                cout << "It's a draw!" << endl;
                break;
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }

        // Computer's turn (random move)
        do {
            position = rand() % 9 + 1; // Generate a random position (1-9)
        } while (!game.makeMove(position));

        char winner = game.checkWinner();
        if (winner != ' ') {
            if (winner == 'X') {
                cout << game.getPlayer1Name() << " wins!" << endl;
            } else {
                cout << game.getPlayer2Name() << " wins!" << endl;
            }
            break;
        }
    }
}

int main() {
    // Initialize random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    int choice;
    
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Play against a human" << endl;
    cout << "2. Play against the computer" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        playAgainstHuman();
    } else if (choice == 2) {
        playAgainstComputer();
    } else {
        cout << "Invalid choice. Please choose 1 or 2." << endl;
    }

    return 0;
}
