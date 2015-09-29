/****************************************************************************
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
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"


void check_usage(int argc)
{
	if(argc<3) {
		printf("Usage: $ <executable> -n <integer>\n");
		exit(EXIT_FAILURE);
		}

}

void print_text()
{
	printf("\nSia dato in input un intero N. Se S è una stringa che ha \n\
come valore la rappresentazione in codice binario di N, \n\
stampare il numero delle sottostringhe che iniziano e \n\
terminano col carattere '1' (le sottostringhe hanno\n\
lunghezza maggiore o uguale ad uno)\n");
}


int main(int argc, char *argv[])
{
char s[NBIT];

	
	check_usage(argc);
	printf("=========================================");
	print_text();
	printf("\n# Convert integer %s to binary ", argv[2]);
	itob(s, atoi(argv[2]));
	print_string(s);
	printf("\n# There are %d SubStrings :)\n", count_substring(s));
	printf("=========================================\n");
}

