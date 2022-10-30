#include "Sweeper.h"
#include <iostream>


namespace AFMineSweeper
{
	Board Sweeper::PerformMove(Board board, int iCol, int iRow)
	{
		int count = 0;


		if (board.GetCell(iCol, iRow) == 2)
		{
			board.SetCell(iCol, iRow, CELL_BLOWN_MINE);
			std::cout << "you lost! " << std::endl;
			return board;
		}

		else
		{
			for (int i = iCol - 1; i <= iCol + 1; i++)
			{
				for (int j = iRow - 1; j <= iRow + 1; j++)
				{
					if ((board.GetCell(i, j) == 2) || (board.GetCell(i, j) == 3))
					{ 
						count++;
					}
				}
			}
			std::cout << count << std::endl;
			board.SetCell(iCol, iRow, Cell(count + 4));
			return board;
		}
	}
}