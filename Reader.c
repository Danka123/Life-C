
#include <stdio.h>
#include <stdlib.h>

FILE *file_open(char* nazwa) {

	FILE *g = fopen(nazwa, "r");
	if (g == NULL)
		perror("Nie udalo sie otworzyc pliku");

	//else printf("Plik poprawnie otworzono\n");
	return g;
}
