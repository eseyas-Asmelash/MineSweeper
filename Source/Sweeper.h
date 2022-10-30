#pragma once


#include "Board.h"


namespace AFMineSweeper
{
	class Sweeper
	{
	public:
		static Board PerformMove(Board board, int iCol, int iRow);
	};
}