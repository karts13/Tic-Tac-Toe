#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "helper.hpp"
#include "menu.hpp"

int main() {
    std::vector<std::string> items = {"Play against a human", "Play against the computer", "Exit"};
    Menu *menu = new Menu(items);
    std::string choice = menu->menu_navigation();
    delete menu;
    
    initscr();
    echo();
    curs_set(1);
    if(choice == items.at(0)) {
        playAgainstHuman(stdscr);
    } else if(choice == items.at(1)) {
        playAgainstComputer(stdscr);
    } else if(choice == items.at(2)) {
        waddstr(stdscr, "Goodbye!\n");
        wrefresh(stdscr);
        endwin();
    } else {
        waddstr(stdscr, "Invalid choice. Please choose 1 or 2.\n");
        wrefresh(stdscr);
    }
    endwin();

    return 0;
}
