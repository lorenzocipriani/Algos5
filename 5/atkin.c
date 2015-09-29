/****************************************************************************
 * Copyright © 2015 Lorenzo Cipriani
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
 * @author Lorenzo Cipriani
 * @see <a href="https://bitbucket.org/lorenzocipriani/algos5/overview">Bitbucket repository</a>
 * @version 1.0 2015-09-22
 *
 ****************************************************************************/

#include "atkin.h"

bool in_array(int number, int remainders[], int size_rem)
{
	//printf("\nSize of remainders[]: %d\n", size_rem);
	int i = 0;
	while (i < size_rem)
	{
		if (remainders[i] == number)
		{
			//printf("%d is in array\n", number);
			return true;
		}
		i++;
	}
	return false;
}


int is_multiple_of(long number, int base)
{

	int remainders[0];
	int size_rem = 0;

	//printf("Base is %d\n", base);
	if (base == 2)
	{
		size_rem = 30;
		int remainders[30] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58};
		//memcpy(remainders, remainders2, sizeof(remainders2));
	}
	if (base == 3)
	{
		size_rem = 10;
		int remainders[10] = {3, 9, 15, 21, 27, 33, 39, 45, 51, 57};
		//memcpy(remainders, remainders3, sizeof(remainders3));
	}
	if (base == 5)
	{
		size_rem = 4;
		int remainders[4] = {5, 25, 35, 55};
		//memcpy(remainders, remainders5, sizeof(remainders5));
	}

	//printf("Testing %ld as multiple of %d\n", number, base);
	number = number % 60;
	if (in_array(number, remainders, size_rem) != 0)
	{
		//printf("\n%ld is multiple of %d\n", number, base);
		return true;
	}

	return false;
}


long get_primes_with_atkin(long limit)
{
	long numbers = 1;

	long size = limit + 1;
	//long primes[size];
	long* primes = NULL;
	long* add_primes = NULL;

	add_primes = (long*) realloc (primes, 3 * sizeof(long));
	primes = add_primes;
	primes[0] = -1;
	primes[1] = -1;
	primes[2] = 1;

	if (limit > 2)
	{
		long i = 3;
		while (i < size)
		{
			add_primes = (long*) realloc (primes, (i + 1) * sizeof(long));
			primes = add_primes;
			if (
					(is_multiple_of(i, 2) == 1)
					|| (is_multiple_of(i, 3) == 1)
					|| (is_multiple_of(i, 5) == 1)
				)
			{
				if ((i == 3)||(i == 5))
				{
					primes[i] = 1;
					numbers++;
				}
				else
				{
					primes[i] = 0;
				}
			}
			else
			{
				primes[i] = 1;
			}

			i++;
		}
	}

	if (limit > 7)
	{
		long i = 7;
		while (i < size)
		{
			if (primes[i] == 1)
			{
				int j = i;
				int m = 2;
				while ((j * m) < limit)
				{
					primes[(j * m)] = 0;
					m++;
				}
				numbers++;
			}
			i++;
		}
	}

	long i = 0;
	while (i < size)
	{
		if (primes[i] == 1)
		{
			printf("%ld ", i);
		}
		i++;
	}
	return numbers;

	/*

	long i = 1;
	while (i < limit)
	{
		i++;
		if (in_array((long) i, (int[]) {2, 3, 5}, 3))
		{
			printf("%ld ", i);
			continue;
		}
		if (is_multiple_of(i, 2) == 1)
		{
			continue;
		}
		if (is_multiple_of(i, 3) == 1)
		{
			continue;
		}
		if (is_multiple_of(i, 5) == 1)
		{
			continue;
		}
		printf("%ld ", i);
	}
	printf("\n");

	 */
}

