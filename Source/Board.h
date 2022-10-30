#pragma once


#include <vector>


namespace AFMineSweeper
{
	enum Cell
	{
		CELL_INVALID,
		CELL_UNREVEALED_EMPTY,
		CELL_UNREVEALED_MINE,
		CELL_BLOWN_MINE,
		CELL_0,
		CELL_1,
		CELL_2,
		CELL_3,
		CELL_4,
		CELL_5,
		CELL_6,
		CELL_7,
		CELL_8
	};


	class Board
	{
	public:
		void Create(int iDimension);

		int GetDimension() const { return m_iDimension ; }

		Cell GetCell(int iCol, int iRow) const;
		void SetCell(int iCol, int iRow, Cell cell);

	private:
		std::vector<std::vector<Cell>> m_cells;
		int m_iDimension;
	};
}