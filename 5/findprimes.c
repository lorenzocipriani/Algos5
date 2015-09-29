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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <time.h>

#include "erathosthenes.h"
#include "atkin.h"

long limit;
clock_t begin, end;
double time_spent;

#include "erathosthenes.h"
#include "atkin.h"

long limit;
clock_t begin, end;
double time_spent;

/* If the limit for finding primes is not passed as an argument shows an error */
void usage(char* name)
{
	printf("Usage:\n%s <number>\n", name);
	exit(0);
}

/* This program uses 2 algorithms to find prime numbers:
 * -  Sieve of Erathostenes
 * -  Sieve of Atkin-Bernstein (not implemented)
 * and compares time spent on each method.
 */
int main(int argc, char **argv)
{
    if (argc > 1)
    {
    	long primes;

		limit = atol(argv[1]);

		/* Start the search with Sieve of Erathosthenes */
		printf("Find primes with Erathosthenes until %ld\n", limit);
		/* Start to count execution time */
		begin = clock();
		/* Primes contains the number of primes found */
		primes = get_primes_with_earthosthenes(limit);
		/* Stop to count execution time */
		end = clock();
		/* Compute the time spent on Sieve of Erathosthenes */
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		/* Search with Sieve od Erathostenes completed */
		printf("\nFound %ld primes in %f sec\n", primes, time_spent);

		/* Start the search with Sieve of Erathosthenes */
		//printf("\nFind primes with Atkin-Bernstein until %ld (NOT IMPLEMENTED)\n", limit);
		/* Start to count execution time */
		begin = clock();
		/* Primes contains the number of primes found */
		//primes = get_primes_with_atkin(limit);
		/* Stop to count execution time */
		end = clock();
		/* Compute the time spent on Sieve of Erathosthenes */
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		/* Search with Sieve od Erathostenes completed */
		//printf("\nFound %ld primes in %f sec\n", primes, time_spent);
    }
    else
    {
    	usage(argv[0]);
    }

}
