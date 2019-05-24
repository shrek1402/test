#include "kmenu.h"
#include "stdfix.h"
#include <ctime>
#include <vector>
#include <string>
using namespace std;
constexpr auto _VERSION = "Beta v1.0";
constexpr unsigned int _SEC = 1;


bool razmer()
{
	int col, row;
	getmaxyx(stdscr, row, col);
	if (row <  10) throw "Uvelich visotu okna";
	if (col < 40) throw "Uvelich shirinu okna";
	return true;
}

long long unsigned int printMenu(std::vector <std::string>& _vec)
{
	long long unsigned int c = 1;
	int temp;
	int col, row;
	getmaxyx(stdscr, row, col);
	
	do{
		for(long long unsigned int i = 0; i < _vec.size(); i++){
			move(row/2 + i, col/2 - 9);
			
			if (i == c){
				for (long long unsigned int j=0; j< _vec[i].length(); j++)
				addch(_vec[i][j] | A_BLINK);
			}
			else{
				printw("%s", _vec[i].c_str());
			}
		}
		
		if ((temp = getch()) == KEY_UP){
				if (c != 1)
					c--;
				else
					c = 4;
		}
		else if (temp == KEY_DOWN){
			if (c != 4)
				c++;
			else
				c = 1;
		}
		refresh();
	}while(temp != '\n');
	
	return c;
}

int mainMenu(int row, int col)
{
    erase();
    printRamka(row, col);
	std::vector <std::string> mStr = {
		"    Menu",
		"1. Speed mode",
		"2. Time mode",
		"3. Blind seal mode",
		"4. Exit"
	};

	noecho();
	keypad(stdscr, TRUE);
	
	return printMenu(mStr);
}

int printRamka(int _row, int _col)
{
	curs_set(0);
	refresh();
	WINDOW *win = newwin(3, _col, 0, 0);
	box(win,0,0);
	
	WINDOW *win1 = newwin(_row - 3, _col, 3, 0); 
	box(win1, 0, 0);
	
	mvaddstr(1, _col - 10, _VERSION);
	wrefresh(win1);
	wrefresh(win);
    return 0;
}

int slozhnost(int row, int col)
{
	erase();
    printRamka(row, col);
	vector <std::string> mStr = {
		"  Slozhn", // TODO eng
		"1. Eazy",
		"2. Normal",
		"3. Hard",
		"4. Back"
	};

	noecho();
	keypad(stdscr, TRUE);
	
	return printMenu(mStr);
}

void resultTabl(int result, int popitki)
{
	erase();
	
	int row,col;
	getmaxyx(stdscr, row, col);
	printRamka(row, col);
	int ySize = 9,
		xSize = col -(row - ySize +3 +2),
		yy = (row - ySize - 5) / 2 + 4,
		xx = (col - xSize) / 2;
			if ((col - xSize)%2 != 0)
				xSize++;
			if ((row - ySize)%2 == 0)
				ySize++;
		
		int sm;
		result > 0? 
			sm = 6:
			sm = 7;
			
		move(yy + 1, xx+xSize/2 - sm);
		printw("Tvoy resul'tat");
			
		WINDOW *win = newwin(ySize, xSize, yy, xx);
		move(yy + 4, xx+xSize/2 - sm);
		printw("Result: %d", result);
		move(yy + 6, xx+xSize/2 -sm); 
				// TODO add: time, % ...
		result > 0? 
			printw("MOLODEC! :)"):
			printw("NE MOLODEC! :(");
		
		move(yy + 5, xx+xSize/2 -sm);
		double a = 0;
		if (result)
			a = _SEC*1.0/result;
		
		printw("Reaction: %.2f", a);
			
		box(win,0,0);
		wrefresh(win);
		getch();
}

void speedNormal(string _dataFile, int row, int col)
{
	std::ifstream dataFile(_dataFile);
	if(!dataFile)
		throw "File not open";
	
	  long long unsigned int	i = 0;
	std::vector<std::string> 	vec;
				 std::string	tempA;
				unsigned int	result = 0,
								startTime = clock();
								endTime = startTime;				
						bool	flag = 1;
						 int	ch,
								temp,
								x,y, x_temp,
								popitki = 0;
							
	while(!dataFile.eof()){
		std::string temp;
		std::getline(dataFile, temp);
		vec.push_back(temp);
	}
					
	nodelay(stdscr, TRUE);
	do{
		if ((ch = getch()) == ERR){
			if (flag){
				tempA = vec.at(rand() % vec.size());
				x = (rand() % (col- tempA.length()-1)+1) ;
				y = (rand() % (row-5)) + 4;
				erase();
				printRamka(row, col);
				move(y,x);
				printw("%s", tempA.c_str());
				flag = 0;
				popitki++;
			}
				
			endTime = clock();
			move(1,5);
			printw("%d ms", endTime - startTime);
			move(1,1);
			printw("%d", result);
		}
		else{
			temp = ch;
			flag = 0;
		
			if ((int)tempA[i] != temp || i == 0){
				
				if(tempA[i] != temp){
					i=0;
					flag = 1;
				}
				else{
					x_temp = x;
					move(y, x_temp++);
					addch(tempA.at(i)| A_BLINK );
					i++;
				}
				
				refresh();
			}
			else{
				move(y, x_temp++);
				addch(tempA.at(i)| A_BLINK );
				i++;
				
				if (i == tempA.length()){
					flag =1;
					i=0;
					
					if (endTime < startTime + _SEC * 1000){
						result++;
					}
				}
				
				refresh();						
			}
		}
	}while(endTime < startTime + _SEC * 1000);
	
	
	nodelay(stdscr, FALSE);
	resultTabl(result, popitki);
	
}

void speedEz()
{
	int row,col;
	unsigned int result = 0,
				 startTime = clock(),
				 endTime = startTime;
		
	int	ch,
		temp,
		x,y,
		popitki = 0;
	char tempA;
	bool flag = 1;
	getmaxyx(stdscr, row, col);
	nodelay(stdscr, TRUE);
	do{
		if ((ch = getch()) == ERR){
			if (flag){
				tempA = rand() % 26 + 0x61;
				x = (rand() % (col-1)) ;
				y = (rand() % (row-5)) + 4;
				erase();
				printRamka(row, col);
				move(y,x);
				printw("%c",tempA);
				flag = 0;
				popitki++;
			}
					
			endTime = clock();
			move(1,5);
			printw("%d ms", endTime - startTime);
			move(1,1);
			printw("%d", result);
		}
		else{
			temp = ch;
			flag = 0;
			
			if ((int)tempA != temp){
				flag = 1;
			}
			else{
				flag =1;
				result++;
			}
			refresh();						
		}
		
	}while(endTime < startTime + _SEC * 1000);
	
	
	nodelay(stdscr, FALSE);	
	resultTabl(result, popitki);
}

void speedMode(int slozh, int row, int col)
{
	erase();
    printRamka(row, col);
	
	switch (slozh) {
        case 1:
		{
			speedEz();
			break;
		}
        
		case 2:{
			speedNormal("Word.txt", row, col);
			break;
		}
			
		case 3:{
			speedNormal("Pred.txt", row, col);
			break;
		}
		case 4:
			break;
    }	
}