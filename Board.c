#include "Start_game.h"
#include <stdlib.h>
#include <stdio.h>

int get_X();
int get_Y();

int **create_new_board(int x, int y) {
	int **tab;

	//tworzenie tablicy
	tab = (int**)malloc(y * sizeof(int*));
	for (int i = 0; i < y; i++)
		tab[i] = (int*)malloc(x * sizeof(int));

	return tab;

}

int **piece(int **tab, int x1, int y1) {
	int x2 = 3;
	int y2 = 3;
	int **piece;
	//tworzenie wycinka

	piece = (int**)malloc(y2 * sizeof(int*));
	for (int i = 0; i < y2; i++)
		piece[i] = (int*)malloc(x2 * sizeof(int));


	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) {
			if ((x1 + b - 1) < get_X() && (y1 + a - 1) < get_Y() && (x1 + b - 1) >= 0 && (y1 + a - 1) >= 0) {
				piece[a][b] = tab[y1 + a - 1][x1 + b - 1];
			}

			else
				piece[a][b] = -1;
		}
}

	return piece;
}


void delete_board(int **tab) {
	
	for (int i=0; i < get_X(); i++) {
		free (tab[i]);
	}
		free(tab);


}


void rysuj(int **tab, int x, int y) {

	printf("\n\n");
	for (int i = 0; i <y; i++) {
		for (int j = 0; j < x; j++) {
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
}

void board_change(int **t1, int **t2) {

	for (int i = 0; i < get_Y(); i++) {
		for (int j = 0; j < get_X(); j++) {
			t1[i][j] = t2[i][j];
		}
	}
}
