#ifdef _WIN32
	#include "pdcurses.h"
#else
    #include <ncurses.h>
#endif

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern int col, row;