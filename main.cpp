#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "helper.h"

int main() {
    int choice;
    initscr();
    
    waddstr(stdscr, "Welcome to Tic-Tac-Toe!\n");
    waddstr(stdscr, "Choose an option:\n");
    waddstr(stdscr, "1. Play against a human\n");
    waddstr(stdscr, "2. Play against the computer\n");
    waddstr(stdscr, "Enter your choice (1 or 2): ");
    wrefresh(stdscr);
    choice = getch();

    if(choice == 49) {
        playAgainstHuman(stdscr);
    } else if(choice == 50) {
        playAgainstComputer(stdscr);
    } else {
        waddstr(stdscr, "Invalid choice. Please choose 1 or 2.\n");
        wrefresh(stdscr);
    }

    endwin();

    return 0;
}
