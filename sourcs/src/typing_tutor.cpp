#include "pch.h"
const unsigned int SEK = 20;
int level(int row, int col)
{
	erase();
	printRamka(row, col);
	std::vector<std::string> mStr = {
		"  Select the level",
		"1. level 1 to 5",
		"2. level 6 to 10",
		"3. level 11 to 15",
		"4. Backward"

	};

	noecho();
	keypad(stdscr, TRUE);
	return printMenu(mStr);
}

void level1(std::string _dataFile, int row, int col)
{
	std::ifstream dataFile(_dataFile);
	std::vector<std::string> vec;

	while (!dataFile.eof())
	{
		std::string temp;
		std::getline(dataFile, temp);
		vec.push_back(temp);
	}

	unsigned int startTime = clock();
	unsigned int endTime = startTime;
	nodelay(stdscr, TRUE);
	int ch;
	int temp;
	long long unsigned int i = 0;
	std::string tempA;
	bool flag = 1;
	int x_temp = col / 2, level = 1;
	int popitki = 0;
	unsigned int dop = 0;

	do
	{
		if ((ch = getch()) == ERR)
		{
			if (flag)
			{
				erase();
				printRamka(row, col);
				tempA = vec.at(level - 1);
				move(row / 2, col / 2);
				printw("%s", tempA.c_str());
				flag = 0;
				popitki++;
			}
			endTime = clock();
			move(1, 10);
			printw("%d ms", dop + SEK * 1000 - (endTime - startTime));
			move(1, 1);
			printw("level %d", level);
		}
		else
		{
			temp = ch;
			flag = 0;

			if (tempA[i] == temp)
			{
				move(row / 2, x_temp);
				x_temp++;
				addch(tempA.at(i) | A_BLINK);
				i++;
				if (i == tempA.length())
				{
					dop += 5;
					x_temp = col / 2;
					flag = 1;
					i = 0;
					level++;
					if (level == 5)
					{
						
					}
				}
			}
		}
	} while (endTime < startTime + SEK * 1000);

	nodelay(stdscr, FALSE);
	
}

void Select_level(int slozh, int row, int col)
{
	erase();
	printRamka(row, col);

	switch (slozh)
	{
	case 1:
	{
		level1("level1.txt", row, col);
		break;
	}

	case 2:
	{
		break;
	}

	case 3:
	{
		break;
	}
	case 4:
		break;
	}
}
