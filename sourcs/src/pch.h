#ifndef PCH_H
#define PCH_H
#define PDC_DLL_BUILD

	#ifdef _WIN32
		#include <curses.h>
	#else
		#include <ncurses.h>
	#endif

	#include <ctime>
	#include <vector>
	#include <string>
	#include <fstream>
	#include <iostream>
	#include <stdlib.h>
	#include <string>
	#include <unistd.h>
	#include <cmath>
	#include <string_view>

	bool razmer();
	int printWelcomePanel(std::string _str, int row, int col);
	int mainMenu(int row, int col);
	int printRamka(int _row, int _col);
	int slozhnost(int row, int col);
	void speedMode(int slozh, int row, int col);
	void speedNormal(std::string _dataFile, int row, int col);
	long long unsigned int printMenu(std::vector <std::string>& _vec);
	void Select_level(int slozh, int row, int col);
	int level(int row, int col);
#endif