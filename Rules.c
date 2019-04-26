
#include "Start_game.h"
#include <stdio.h>
#include <stdlib.h>


int n_counter(int **tab);



int zasady(int **tab) {
	int **a;
	a = tab;
	int neigh_alive = n_counter(a);

	if (neigh_alive == 3)
		return 1;
	else if (tab[1][1] == 1 && neigh_alive == 2)
		return 1;
	else return 0;
}



int n_counter(int **tab) {

	int count = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (tab[i][j]==1)
				count++;

		
	}
	count -= tab[1][1];

	return count;
}
