#include "pch.h"
constexpr auto VERSION = "Beta v1.0";

int printWelcomePanel(string _str, int row, int col)
{
    ifstream myTextFile;
    myTextFile.open(_str);
    if (!myTextFile.is_open())
        return 1; 
    move(row / 2, col / 2);
    printw("Hello");
	refresh();
	getch(); // TODO time
    myTextFile.close();
    return 0;
}

int main(int argc, char** argv)
{
    
try{
	initscr();
	razmer();
	int row, col;
    getmaxyx(stdscr, row, col);
    printRamka(row, col);
    printWelcomePanel("Welcome.txt", row, col);

    while (1) {
        switch (mainMenu(row, col)) {
        case 1:{
			int temp = slozhnost(row, col);
			speedMode(temp, row, col);
			break;
		}
        case 2:
        case 3:
        case 4:
            return 0;
        }
    }
}catch(const char* _error){
	endwin();
	std::cout << _error;
	return 1;
}
    getch();
    endwin();
    return 0;
}