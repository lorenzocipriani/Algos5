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
*
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collision.h"

void print_matrix(unsigned int n, unsigned matrix[n][n])
{
	unsigned int i,j;
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("[%u] ", matrix[i][j]);
			
		printf("\n");
	}
}

static unsigned int get_index_girl(unsigned int boy, unsigned int girls[])
{
	int i = 0;
	while (girls[i++] != boy);
	return i-1;
}

/*
 * Teorema di Geometria Lineare: una retta si spezza nella somma delle proiezioni sugli assi.
 * Non sono riuscito ad ideare un algoritmo più efficiente, quindi sono andato di metodo grafico
 * usando una matrice NxN e "disegnando" (incrementando un intero) il percorso boy-girl.
 */
static void fit_matrix(unsigned int boys[], unsigned int girls[], unsigned int n, unsigned int matrix[n][n])
{
	int i, k;
	int j;
	int index_girls;
	
	//5-) 03 13 - 12 11 10 prima scendi, poi a sx
	
	for(i=0; i<n; i++)
	{
		j=0;
		index_girls=get_index_girl(boys[i], girls);
		
		//va giu
		while(girls[j] != girls[index_girls])
		{
			matrix[j][i]++;
			j++;
		}
		
		k=i;
		
		//va a sx
		for(; k>=0; k--)
		{
			matrix[j][k]++;
		}
	} 
}

unsigned int calculate_collisions(unsigned int boys[], unsigned int girls[], int n)
{
	unsigned int matrix[n][n];
	unsigned int collisions=0, i, j;
	
	memset(matrix, 0, n*n*sizeof(unsigned int));
	
	fit_matrix(boys, girls, n, matrix);
	
	//Scorre la matrice e conta le collisioni
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(matrix[i][j]%2==0)
			{
				collisions++;
				matrix[i][j]-=2;
			}
				
	return collisions/2;

}
