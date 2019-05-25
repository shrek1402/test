#include "pch.h"
#include <ctime>
using namespace std;

int main(int argc, char** argv)
{
    int row, col;
    initscr();
    getmaxyx(stdscr, row, col);
    printRamka(row, col);
    printWelcomePanel(argv[1], row, col);
	keypad(stdscr, TRUE);
	
    while (1) {
        switch (mainMenu(row, col)) {
			case 1:{
				int temp = slozhnost(row, col);
				speedMode(temp, row, col);
				break;
			}
			case 2:
            {
                int tmp = level (row, col);	
        	Select_level(tmp, row, col);
            }
			case 3:
			case 4:
				return 0;
        }
    }

    getch();
    endwin();
    return 0;
}
