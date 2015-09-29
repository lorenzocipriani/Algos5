/****************************************************************************
* Copyright © 2009 Alessandro Rosetti
* email: alessandro.rosetti@gmail.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
****************************************************************************/

#ifndef BITMATRIX_H
#define BITMATRIX_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <string.h>

using namespace std;

uint32_t GetStrColSize(const string& str);
uint32_t GetStrRowSize(const string& str);
void StrTranspose(string& str);

class bitmatrix
{
	public:
		bitmatrix();
		bitmatrix(uint32_t rows, uint32_t cols);
		bitmatrix(const bitmatrix &bit_mat);
		~bitmatrix();

		uint32_t GetRowNum() const
		{
			return m_rows;
		}

		uint32_t GetColNum() const
		{
			return m_cols;
		}

		uint32_t GetCellSize() const
		{
			return m_cells;
		}

		uint32_t GetSize() const
		{
			return m_cols*m_rows;
		}
		
		bool ValidCoord(uint32_t, uint32_t);

		void Randomize(uint32_t row, uint32_t col);
		bool Get(uint32_t row, uint32_t col) const;
		void Set(uint32_t row, uint32_t col);
		void Unset(uint32_t row, uint32_t col);
		void Flip(uint32_t row, uint32_t col);

		string GetCol(uint32_t col);
		string GetCols(uint32_t col_a, uint32_t col_b);
		void UnsetCol(uint32_t col);

		void SetCol(uint32_t col);
		void SetCol(const bitmatrix& bin_mat, uint32_t col);
		void SetCol(const string& str, uint32_t col);

		void SetCols(const string& str, uint32_t start_col);

		void RandomizeCol(uint32_t col);

		string GetRow(uint32_t row);
		void UnsetRow(uint32_t row);
		void SetRow(uint32_t row);
		void SetRow(const bitmatrix& bin_mat, uint32_t row);

		void SetRow(const string& str, uint32_t row);

		void RandomizeRow(uint32_t row);
		void RandomizeAll();

		void SetAll();
		void UnsetAll();
		void FlipAll();

		void Resize(uint32_t rows, uint32_t cols);
		void ResizeOnline(uint32_t rows, uint32_t cols);
		
		void Import(const string& str);
		void Import(const bitmatrix& bin_mat);

		void AttachCols(const string& str);
		void DeleteCol(uint32_t col);

		void Print() const;
		string  ToString() const;
		const bitmatrix& operator=(const bitmatrix& bit_mat);

	private:

		void DeleteMatrix();

		//! matrice di uint8_t
		uint8_t** matrix;
		//! numero di righe della matrice
		uint32_t  m_rows;
		//! il numero di colonne della matrice
		uint32_t  m_cols;
		//! il numero di celle della matrice
		uint32_t  m_cells;
};

#endif
