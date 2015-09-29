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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void usage(char* name)
{
	printf("Usage:\n%s <number>\n", name);
	exit(0);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		unsigned long int pos, steps;

		pos = atoi(argv[1]);
		printf("position: %lu\n", pos);

		/*
		formula gauss restituisce la somma dei primi N numeri.
		n(n+1)/2
		quanti passi servono? basta risolvere l'equazione di secondo grado:
		n^2+n-2x=0.

		se mi sposto nella direzione negativa il numero di passi richiesto sarà
		sempre pari a quello richesto se mi spostassi nella direzione positiva.
		*/
		steps = ceil((sqrt(1 + 8 * abs(pos)) - 1) / 2);
		printf("steps required: %lu\n", steps);
	}
	else
		usage(argv[0]);
}

