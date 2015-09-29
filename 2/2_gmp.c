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
#include <gmp.h>

/*
 * questa versione usa la libreria usata in campo scientifico e per crittografia
 * permette di lavorare con numeri di grande dimensione e ad alta precisione
*/

void usage(char* name)
{
	printf("Usage:\n%s <number>\n", name);
	exit(0);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		mpz_t pos, steps;

		mpz_init_set_str (pos, argv[1], 10);
		mpz_init(steps);

		printf("position: %s\n", mpz_get_str(NULL, 10, pos));

		mpz_abs(pos, pos);
		mpz_mul_ui (steps, pos, 8);
		mpz_add_ui (steps, steps, 1);
		mpz_sqrt(steps, steps);
		mpz_sub_ui (steps, steps, 1);
		mpz_cdiv_q_ui (steps, steps, 2);
		mpz_add_ui (steps, steps, 1);

		printf("steps required: %s\n", mpz_get_str (NULL, 10, steps));
	}
	else
		usage(argv[0]);
}

