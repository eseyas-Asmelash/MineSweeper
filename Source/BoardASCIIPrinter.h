#pragma once


#include "Board.h"


namespace AFMineSweeper
{
	class BoardASCIIPrinter
	{
	public:
		static void PrintBoard(Board &board);

		static char ReadableCell(Cell cell);
	};
}