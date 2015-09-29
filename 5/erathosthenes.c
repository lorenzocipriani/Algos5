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

#include "erathosthenes.h"
#include "atkin.h"

long get_primes_with_earthosthenes(long limit)
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
}
