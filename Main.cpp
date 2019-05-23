#include "pch.h"
constexpr auto VERSION = "Beta v1.0";
int main(int argc, char** argv)
{
	initscr();
	int row, col;
    getmaxyx(stdscr, row, col);
    curs_set(0);
	refresh();
	WINDOW *win = newwin(3, col, 0, 0);
	box(win,0,0);
	
	WINDOW *win1 = newwin(row - 3, col, 3, 0); 
	box(win1, 0, 0);
	
	mvaddstr(1, col - 10, VERSION);
	wrefresh(win1);
	wrefresh(win);

    endwin();
    return 0;
	
}