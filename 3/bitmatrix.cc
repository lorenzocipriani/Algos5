#include "bitmatrix.h"
#include <time.h>

bitmatrix::bitmatrix()
{
	srand(time(NULL));
	matrix = NULL;
}

bitmatrix::bitmatrix(uint32_t rows, uint32_t cols)
{
	bitmatrix();
	Resize(cols, rows);
}

bitmatrix::bitmatrix(const bitmatrix &bit_mat)
{
	m_rows = bit_mat.m_rows;
	m_cols = bit_mat.m_cols;
	m_cells = bit_mat.m_cells;
	matrix = new uint8_t*[m_rows];
	for (int i = 0; i < m_rows; i++)
		matrix[i] = new uint8_t[m_cells];

	Import(bit_mat);
}

bitmatrix::~bitmatrix()
{
	DeleteMatrix();
}

bool bitmatrix::ValidCoord(uint32_t y, uint32_t x)
{
	if ( x < 0 || x >= m_cols )
		return false;
	if ( y < 0 || y >= m_rows )
		return false; 
	return true;
}

void bitmatrix::DeleteMatrix()
{
	if (matrix == NULL)
		return;

	for (int i = 0; i < m_rows; i++)
	{
		if (matrix[i] != NULL)
			delete[] matrix[i];
	}

	delete[] matrix;
	matrix = NULL;
}

void bitmatrix::Resize(uint32_t rows, uint32_t cols)
{   
	//DeleteMatrix();
	
	m_rows = (rows ? rows : 1);
	m_cols = (cols ? cols : 1);
	m_cells = int(m_cols/8) + (int(m_cols%8) ? 1 : 0);
	matrix = new uint8_t*[m_rows];
	for (int i = 0; i < m_rows; i++)	
	   matrix[i] = new uint8_t[m_cells];
}

void bitmatrix::Randomize(uint32_t row, uint32_t col)
{
	if (row >= m_rows || col >= m_cols)
		return;

	if (rand() % 2)
		Unset(row, col);
	else
		Set(row, col);
}

bool bitmatrix::Get(uint32_t row, uint32_t col) const
{
	if (row >= m_rows || col >= m_cols)
		return false;

	return matrix[row][int(col/8)] & uint8_t(1 << int(col%8));
}

void bitmatrix::Set(uint32_t row, uint32_t col)
{
	if (row >= m_rows || col >= m_cols)
		return;

	matrix[row][int(col/8)] |= uint8_t(1 << int(col%8));
}

void bitmatrix::Unset(uint32_t row, uint32_t col)
{
	if (row >= m_rows || col >= m_cols)
		return;

	matrix[row][int(col/8)] &= ~uint8_t(1 << int(col%8));
}

void bitmatrix::Flip(uint32_t row, uint32_t col)
{
	if (row >= m_rows || col >= m_cols)
		return;

	if (matrix[row][int(col/8)] & uint8_t(1 << int(col%8)))
		Unset(row, col);
	else
		Set(row, col);
}

void bitmatrix::RandomizeCol(uint32_t col)
{
	if (col >= m_cols)
		return;

	for (int i = 0; i < m_rows; i++)
		Randomize(i, col);
}

void bitmatrix::RandomizeRow(uint32_t row)
{
	if (row >= m_rows)
		return;

	for (int i = 0; i < m_cells; i++)
		matrix[row][i] = uint8_t(rand() % 256);
}

void bitmatrix::RandomizeAll()
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cells; j++)
			 matrix[i][j] = uint8_t(rand() % 256);
}

void bitmatrix::SetAll()
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cells; j++)
			 matrix[i][j] = uint8_t(255); // 11111111
}

void bitmatrix::UnsetAll()
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cells; j++)
			 matrix[i][j] = uint8_t(0); // 00000000
}

void bitmatrix::FlipAll()
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cells; j++)
			 matrix[i][j] = ~uint8_t(matrix[i][j]);
}

void bitmatrix::ResizeOnline(uint32_t rows, uint32_t cols)
{
	bitmatrix temp(*this);
	DeleteMatrix();

	m_rows = (rows ? rows : 1);
	m_cols = (cols ? cols : 1);
	m_cells = int(m_cols/8) + (int(m_cols%8) ? 1 : 0);
	matrix = new uint8_t*[m_rows];
	for (int i = 0; i < m_rows; i++)
	   matrix[i] = new uint8_t[m_cells];

	Import(temp);
}

string bitmatrix::GetCol(uint32_t col)
{  
	string str = "";

	if (col >= m_cols)
		return str;

	for (int i = 0; i < m_rows; i++)
		str += (matrix[i][int(col/8)] & uint8_t(1 << int(col%8))) ? "1" : "0";
	
	StrTranspose(str);
	return str;
}

string bitmatrix::GetCols(uint32_t col_a, uint32_t col_b)
{   
	string str = "";

	if (col_a > m_cols || col_b > m_cols || col_a > col_b)
		return str;

	for (int j = col_a; j <= col_b; j++)
	{
		for (int i = 0; i < m_rows; i++)
			str += (matrix[i][int(j/8)] & uint8_t(1 << int(j%8))) ? "1" : "0";
		
		str+="\n";
	}

	StrTranspose(str);
	return str;
}

void bitmatrix::UnsetCol(uint32_t col)
{
	if (col >= m_cols)
		return;

	for (int i = 0; i < m_rows; i++)
		Unset(i, col);
}

void bitmatrix::SetCol(uint32_t col)
{
	if (col >= m_cols)
		return;

	for (int i = 0; i < m_rows; i++)
		Set(i, col);
}

void bitmatrix::SetCol(const bitmatrix& bin_mat, uint32_t col)
{
	if (bin_mat.GetRowNum() < m_rows || col >= m_cols)
		return;

	for (int i = 0; i < m_rows; i++)
	{
		uint8_t mask = bin_mat.matrix[i][int(col/8)] & uint8_t(1 << int(col%8));
		if (mask)
			matrix[i][int(col/8)] |= uint8_t(1 << int(col%8));
		else
			matrix[i][int(col/8)] &= ~uint8_t(1 << int(col%8));
	}
}

void bitmatrix::SetCol(const string& str, uint32_t col)
{
	if (col >= m_cols)
		return;

	const char* c_str = str.c_str();
	if (!c_str)
		return;

	uint32_t row = 0; 
	for (int i = 0; c_str[i] != '\0'; i++)
	{
		if (row >= m_rows)
			break;

		if(c_str[i] == '\n')
			continue;

		if (c_str[i] == '0')
			Unset(row, col);
		else 
			Set(row, col);

		row++;
	}
}

void bitmatrix::SetCols(const string& str, uint32_t start_col)
{
	int row_size = GetStrRowSize(str);
	int col_size = GetStrColSize(str);

	if (start_col > m_cols)
		return;

	const char* c_str = str.c_str();
	if (!c_str)
		return;

	for (int i = 0; i < col_size; i++)
	{
		for (int j = 0; j < (row_size + 1); j++)
		{
			if (c_str[j + i * (row_size + 1)] == '0')
				Unset(i, start_col + j);
			else
				Set(i, start_col + j);
		}
	}
}

string bitmatrix::GetRow(uint32_t row)
{
	string str = "";

	if (row >= m_cols)
		return str;

	for (int i = 0; i < m_cols; i++)
		str += (matrix[row][int(i/8)] & uint8_t(1 << int(i%8))) ? "1" : "0";
	
	return str;
}

void bitmatrix::UnsetRow(uint32_t row)
{
	if (row >= m_rows)
		return;

	for (int i = 0; i < m_cells; i++)
		matrix[row][i] = uint8_t(0); // 00000000
}

void bitmatrix::SetRow(uint32_t row)
{
	if (row >= m_rows)
		return;

	for (int i = 0; i < m_cells; i++)
		matrix[row][i] = uint8_t(255); // 11111111
}

void bitmatrix::SetRow(const bitmatrix& bin_mat, uint32_t row)
{
	if (bin_mat.GetColNum() < m_cols || row >= m_rows)
		return;

	for (int j = 0; j < m_cells; j++)
	{
		matrix[row][j] = bin_mat.matrix[row][j];
	}
}

void bitmatrix::SetRow(const string& str, uint32_t row)
{
	if (row >= m_rows)
		return;

	const char* c_str = str.c_str();
	if (!c_str)
		return;

	uint32_t col = 0;

	for (int i = 0; c_str[i] != '\0'; i++)
	{
		if (col >= m_cols)
			break;

		if (c_str[i] == '0')
			Unset(row, col);
		else // qualsiasi cifra che non sia 0 viene considerata 1
			Set(row, col);

		col++;
	}
}

void bitmatrix::Import(const string& str)
{
	const char* c_str = str.c_str();
	if (!c_str)
		return;

	uint32_t row = 0;
	uint32_t col = 0;
	
	Resize(GetStrColSize(str), GetStrRowSize(str));

	for (int i = 0; c_str[i] != '\0'; i++)
	{
		if (c_str[i] == '\n')
		{
			row++;

			if (row >= m_rows)
				break;

			col = 0;
			continue;
		}

		if (col >= m_cols)
			continue;

		if (c_str[i] == '0')
			Unset(row, col);
		else
			Set(row, col);

		col++;
	}
}

void bitmatrix::Import(const bitmatrix& bin_mat)
{
	uint32_t max_rows = (m_rows > bin_mat.GetRowNum() ? bin_mat.GetRowNum() : m_rows);
	uint32_t max_cells  = (m_cells > bin_mat.GetCellSize() ? bin_mat.GetCellSize() : m_cells);
	uint8_t mask = 0;

	if (bin_mat.GetColNum() < m_cols)
	{
		for (int i = 0; i < (bin_mat.GetColNum()%8); i++)
			mask |= uint8_t(1 << i);
	}

	for (int i = 0; i < max_rows; i++)
	{
		for (int j = 0; j < max_cells; j++)
		{
			if (mask && (j == max_cells - 1))
			{
				matrix[i][j] &= ~mask;
				matrix[i][j] |= bin_mat.matrix[i][j] & mask;
			}
			else
				matrix[i][j] = bin_mat.matrix[i][j];
		}
	}
}

void bitmatrix::AttachCols(const string& str)
{
	uint32_t n_add_cols = GetStrRowSize(str);
	uint32_t old_col_size = m_cols;
	const char *c_str = str.c_str();
	
	if (!c_str)
		return;

	if(n_add_cols == 0 || GetStrColSize(str) != GetRowNum())
		return;

	Resize(m_rows, m_cols + n_add_cols);
	SetCols(str, old_col_size);
}

void bitmatrix::DeleteCol(uint32_t col)
{
	if (col >= m_cols)
		return;

	string chunk_a, chunk_b;
	
	if (col)
		chunk_a = GetCols(0, col - 1);
	if (col < m_cols)
	chunk_b = GetCols(col + 1, m_cols);

	Resize(m_rows, m_cols -1);

	SetCols(chunk_a, 0);
	SetCols(chunk_b, col);
}


uint32_t GetStrColSize(const string& str)
{
	/* conta i \n */
	uint32_t cols = 0;
	uint32_t row_size = GetStrRowSize(str);

	for (int i = row_size + 1 ; str[i] != '\0'; i += (row_size + 1))
		cols++;

	return cols + 1;
}

uint32_t GetStrRowSize(const string& str)
{
	/* controlla solo quanto è alta la prima colonna */
	uint32_t rows ;

	for (rows = 0; str[rows] != '\n'; rows++);

	return rows;
}

void StrTranspose(string& str)
{   
	uint32_t rows = GetStrRowSize(str), cols = GetStrColSize(str);
	string temp_string;

	for (int i = 0; i < rows ; i++)
	{
		for (int j = 0; j < cols; j++)
			temp_string += str.c_str()[j * (rows + 1) + i];
		temp_string += "\n";
	}

	str = temp_string;
}

void bitmatrix::Print() const
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
			 cout << (matrix[i][int(j/8)] & uint8_t(1 << int(j%8)) ? 1 : 0 );
		cout << endl;
	}
}

string bitmatrix::ToString() const
{
	string s = "";
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
			s += (matrix[i][int(j/8)] & uint8_t(1 << int(j%8))) ? "1" : "0";
		s+="\n";
	}
	return s;
}

const bitmatrix& bitmatrix::operator=(const bitmatrix& bit_mat)
{
	DeleteMatrix();

	m_rows = bit_mat.m_rows;
	m_cols = bit_mat.m_cols;
	m_cells = bit_mat.m_cells;
	matrix = new uint8_t*[m_rows];
	for (int i = 0; i < m_rows; i++)
	   matrix[i] = new uint8_t[m_cells];

	Import(bit_mat);

	return bit_mat;
}
