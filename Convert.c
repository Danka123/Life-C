
//#include "Game.h"
#include "Png_creator.h"
#include <stdio.h>
#include <stdlib.h>

int get_X();
int get_Y();

void txt_conv(int **tab, char* path, int X1, int Y1) {

	FILE *g = fopen(path, "w");
	if (g == NULL)
		perror("Nie udalo sie otworzyc pliku plik2.txt\n");

	//else printf("Plik poprawnie otworzono\n");

	fprintf(g, "%d ", X1);
	fprintf(g, "%d ", Y1);
	fprintf(g, "\n");
	
	for (int i = 0; i < Y1; i++) {
		for (int j = 0; j < X1; j++) {
			fprintf(g, "%d ", tab[i][j]);
	}
		fprintf(g, "\n" );
}
	fclose(g);
}

void png_conv (int **tab, char *x, int X1, int Y1){
	process_file(tab, X1,Y1);
  	write_png_file(x);

}
