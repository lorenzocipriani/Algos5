/****************************************************************************
* Copyright © 2015 Alessandro Rosetti
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

#include <string>
#include <fstream>
#include <streambuf>

#include "bitmatrix.h"

using namespace std;

void usage(char* name)
{
	cout << "Usage:" << endl
		 << "generate random matrix : " << name << " <size_x> <size_y>" << endl
		 << "load matrix from file  : " << name << " <matrix.txt>" << endl;
	exit(0);
}

bool explore(bitmatrix *maze, bitmatrix *marks, int x1, int y1, int x2, int y2)
{
	if (!maze->ValidCoord(x1, y1) || maze->Get(x1, y1) || marks->Get(x1, y1))
		return false;

	if ((x1 == x2) && (y1 == y2))
		return true;

	marks->Set(x1, y1);

	if (explore(maze, marks, x1+1, y1,   x2, y2) ||
		explore(maze, marks, x1,   y1+1, x2, y2) ||
		explore(maze, marks, x1-1, y1,   x2, y2) ||
		explore(maze, marks, x1,   y1-1, x2, y2))
	return true;

	marks->Unset(x1, y1);
	return false;
}

bool solve(bitmatrix *maze, int x1, int y1, int x2, int y2)
{
	bool found;
	bitmatrix *marks = new bitmatrix(maze->GetColNum(), maze->GetRowNum());

	marks->UnsetAll();

	found = explore(maze, marks, x1, y1, x2, y2);
	if (found)
	{
		cout << "exit found" << endl;
		marks->Set(x2, y2);
		marks->Print();
	}
	else
		cout << "exit not found" << endl;

	delete marks;

	return found;
}

int main(int argc, char** argv)
{
	bitmatrix *maze;

	if (argc == 3)
	{
		maze = new bitmatrix(stoi(argv[1]), stoi(argv[2]));
		maze->RandomizeAll();
		maze->Unset(0, 0);
		maze->Unset(maze->GetRowNum()-1, maze->GetColNum()-1);
	}
	else if (argc == 2)
	{
		maze = new bitmatrix();
		ifstream file(argv[1]);
		string matrix((istreambuf_iterator<char>(file)),
					   istreambuf_iterator<char>());
		maze->Import(matrix);
	}
	else
		usage(argv[0]);

	maze->Print();

	cout << endl << "Solving bitmaze:" << endl;

	solve(maze, 0, 0, maze->GetRowNum()-1, maze->GetColNum()-1);

	return EXIT_SUCCESS;
}
