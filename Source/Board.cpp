#include "Board.h"


#include <algorithm>


namespace AFMineSweeper
{
	void Board::Create(int iDimension)
	{
		iDimension = (std::max)(iDimension, 1);
		iDimension = (std::min)(iDimension, 40);

		m_iDimension = iDimension;

		m_cells.resize(m_iDimension);
		
		for (int i = 0; i < m_iDimension; ++i)
		{
			m_cells[i].resize(m_iDimension, CELL_UNREVEALED_EMPTY);
		}

		// Add some random mines
		float fMineProbability = 0.1f;

		for (int i = 0; i < m_iDimension; ++i)
		{
			for (int j = 0; j < m_iDimension; ++j)
			{
				if ((rand() / float(RAND_MAX)) < fMineProbability)
				{
					m_cells[i][j] = CELL_UNREVEALED_MINE;
				}
			}
		}
	}


	Cell Board::GetCell(int iCol, int iRow) const
	{
		if (iRow >= 0 && iRow < m_iDimension &&
			iCol >= 0 && iCol < m_iDimension)
		{
			return m_cells[iRow][iCol];
		}
		else
		{
			return CELL_INVALID;
		}
	}


	void Board::SetCell(int iCol, int iRow, Cell cell)
	{
		if (iRow >= 0 && iRow < m_iDimension &&
			iCol >= 0 && iCol < m_iDimension)
		{
			m_cells[iRow][iCol] = cell;
		}
	}
}