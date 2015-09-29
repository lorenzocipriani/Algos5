/****************************************************************************
* Copyright © 2015 Alessandro Rosetti
* email: alessandro.rosetti@gmail.com
*
* Copyright © 2015 Alessandro Spallina
* email: alessandrospallina1@gmail.com
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
#include <time.h>
#include "collision.h"

void usage(char* name)
{
	printf("Usage:\n%s <number>\n", name);
	exit(0);
}

void shuffle(int *vec, int n)
{
	if (n < 1)
		return;

	int temp, rnd;
	for (int i = 0; i < n-1; i++)
	{
	  rnd = i + rand() % (n - i);
	  temp = vec[rnd];
	  vec[rnd] = vec[i];
	  vec[i] = temp;
	}
}


int main(int argc, char **argv)
{	
	unsigned int i;
	unsigned long int n;
	unsigned int *boys = NULL, *girls = NULL;

	if (argc == 2)
	{
		
		n = atoi(argv[1]);
		printf("number of boys/girls: %lu\n", n);

		srand(time(NULL));

		boys = (unsigned int *) malloc (sizeof(int)*n);
		girls = (unsigned int *) malloc (sizeof(int)*n);

		for (i = 0; i < n; i++)
		{
			boys[i] = i;
			girls[i] = i;
		}

		shuffle((int *)boys, n);
		shuffle((int *)girls, n);

		for (int i = 0; i < n; i++)
			printf("boy: %d | girl: %d\n", boys[i], girls[i]);

		printf("\ncollisions: %u\n", calculate_collisions(boys, girls, n));
		
		free(boys);
		free(girls);
	}
	else
		usage(argv[0]);
}

