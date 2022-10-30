#include "BoardASCIIPrinter.h"


#include <algorithm>
#include <iostream>


namespace AFMineSweeper
{
	void BoardASCIIPrinter::PrintBoard(Board &board)
	{
		int iDimension = board.GetDimension();

		// Top row
		for (int i = 0; i < iDimension + 2; ++i)
		{
			std::cout << '_';
		}

		std::cout << std::endl;

		for (int j = 0; j < iDimension; ++j)
		{
			std::cout << '|';

			for (int i = 0; i < iDimension; ++i)
			{
				std::cout << ReadableCell(board.GetCell(i, j));
			}

			std::cout << '|';

			std::cout << std::endl;
		}

		// Bottom row
		for (int i = 0; i < iDimension + 2; ++i)
		{
			std::cout << '-';
		}

		std::cout << std::endl;
	}


	char BoardASCIIPrinter::ReadableCell(Cell cell)
	{
		char cTolken;

		switch (cell)
		{
		case CELL_UNREVEALED_EMPTY:
			cTolken = '.';
			break;

		case CELL_UNREVEALED_MINE:
			cTolken = '.';
			break;

		case CELL_BLOWN_MINE:
			cTolken = '*';
			break;

		case CELL_0:
			cTolken = ' ';
			break;

		case CELL_1:
			cTolken = '1';
			break;

		case CELL_2:
			cTolken = '2';
			break;

		case CELL_3:
			cTolken = '3';
			break;

		case CELL_4:
			cTolken = '4';
			break;

		case CELL_5:
			cTolken = '5';
			break;

		case CELL_6:
			cTolken = '6';
			break;

		case CELL_7:
			cTolken = '7';
			break;

		case CELL_8:
			cTolken = '8';
			break;

		default:
			cTolken = ' ';
			break;
		}

		return cTolken;
	}
}