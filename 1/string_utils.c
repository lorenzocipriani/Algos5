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
#include <stdbool.h>
#include "string_utils.h"

void print_string(char str[])
{
	int i;

		printf("[");
	
		for(i=0; i<NBIT; i++) {
			printf("%c", str[i]);
		}
	
		printf("]\n");
}


/*
 * sposta a sinistra tutti gli elementi dell'array di char
 */
static void flip_to_left(char s[])
{
	int i;
		
		for(i=1; i<NBIT; i++)
			s[i-1]=s[i];
}


/*
 * converte intero in base 10 a intero in base 2
 */
static void bin(char dest[], int n)
{
	static bool isArrayEmpty=true;
	
		if(n>1)
			bin(dest, n/2);
		
		if(!isArrayEmpty)
			flip_to_left(dest);
		
		dest[NBIT-1]=(char)48+(n%2);
		isArrayEmpty=false;
		
}


/*
 * inizializza l'array e chiama la funzione bin()
 */
void itob(char dest[], int n)
{
		memset((void *)dest, (int)'0', NBIT);
		bin(dest, n);
}


/*
 * conta le ricorrenze di 1 nella main string
 */
static int count_one(char str[])
{
	int i, count=0;
	
		for(i=0; i<NBIT; i++) {
			if(str[i]=='1')
				count++;
		}

		return count;
}


/*
 * conta il numero di sub string presenti nella stringa.
 */
int count_substring(char str[])
{
	int i;
	int one_counter; //numero di ricorrenze di 1 nella main string
	int substring_counter=0; //numero di substrings (considerando substringa la stringa completa!)
	
		one_counter=count_one(str);
	
		return (one_counter+((one_counter*one_counter-1)/2));
}
