// AFMineSweeper.cpp : Defines the entry point for the console application.
//


#include "Source/Board.h"
#include "Source/BoardASCIIPrinter.h"
#include "Source/Sweeper.h"

#include <iostream>
#include <string>
#include <time.h>


int main()
{
	// Ask for dimension
	int iDimension = 10;

	std::cout << "Welcome to Minesweeper" << std::endl;
	std::cout << "Type q to quit" << std::endl;
	std::cout << "Please enter board size: ";
	std::cin >> iDimension;

	// Set new random seed
	time_t timer;
	time(&timer);
	srand(unsigned int(timer));

	// Create board
	AFMineSweeper::Board board;
	board.Create(iDimension);

	bool bContinue = true;

	while (bContinue)
	{
		// Print board
		AFMineSweeper::BoardASCIIPrinter::PrintBoard(board);

		// Ask for input
		std::cout << "Please make a move col,row : ";
		std::string sInput;
		std::cin >> sInput;

		if ("q" == sInput)
		{
			bContinue = false;
		}
		else
		{
			int iCol = 0;
			int iRow = 0;
			sscanf_s(sInput.c_str(), "%d,%d", &iCol, &iRow);

			std::cout << "Your move is col " << iCol << ", row " << iRow << std::endl;

			board = AFMineSweeper::Sweeper::PerformMove(board, iCol, iRow);
		}
	}

    return 0;
}

