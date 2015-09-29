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

#ifndef ERATHOSTHENES_H
#define ERATHOSTHENES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool in_array(int number, int remainders[], int size_rem);
int is_multiple_of(long number, int base);
long get_primes_with_earthosthenes(long limit);

#endif