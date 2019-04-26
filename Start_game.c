#include "Board.h"
#include <stdlib.h>
#include <stdio.h>

int X=0, Y=0;
int **create_new_board(int,int);

void set_X(int a) {
	X = a;
}

void set_Y(int a) {
	Y = a;
}

int get_X() {
	return X;
}

int get_Y() {
	return Y;
}


void write_board(int** tab) {
	for (int i = 0; i < get_Y(); i++) {
		for (int j = 0; j < get_X(); j++) {

			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
}


int **create_board(FILE  *f) {
	int c;
	int **tab;

	if (f != NULL) {
		fscanf(f, "%d", &c);
		set_X(c);
		fscanf(f, "%d", &c);
		set_Y(c);
	}
	
	if (get_Y()<=0 || get_X()<=0){
		perror ("Zle wymiary tablicy w pliku\n");
		return NULL;
}

	else if (get_Y()>1000 || get_X()>1000){
		perror ("Za duze wymiary tablicy w pliku\n");
		return NULL;
}

	else {
		//printf("to x %d, a to y %d\n", get_X(), get_Y());
		

		tab= create_new_board(get_X(), get_Y());

		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				if (fscanf(f, "%d", &c) != EOF)
					tab[i][j] = c;
			else {
				perror ("Niepoprawne dane zamieszczone w pliku, za malo danych dotyczacych komorek!\n\n");
				return NULL;
			}
		}
	}

		//write_board(tab);
		printf("\n");

	return tab;
}
}

