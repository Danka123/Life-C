#include "Game.h"
#include "Reader.h"
//#include "Board.h"
#include "Flags.h"
#include "Convert.h"
#include "Start_game.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


	int N=4;
	char *inputfilename="plik.txt";
	char *picfolder="wyniki/generacja nr";
	char *outputfilename="result.txt";
	char *outpng ="wyniki/generacja nr ";



int main(int argc, char *argv[]) {

	char x[100];


	printf("Automat komórkowy\n");
	flags(argc,argv);

	///OTWIERANIE PLIKU TXT, Z KTÓREGO ZBUDUJEMY TABLICÊ I TWORZENIE TABLICY OD RAZU
	
	int **tab, **p;
	FILE *file = file_open(inputfilename);
	tab = create_board(file);
	
	if(tab!=NULL){


	for(int i=0;i<N;i++){
		//printf("obrot %d z %d \n\n", i, N);
		if(game(tab, N)){
		txt_conv (tab,outputfilename,get_X(), get_Y());
		sprintf(x,"%s %d",outpng, i+1);
		png_conv(tab,x,get_X(), get_Y());
	}
}

	png_conv(tab,picfolder,get_X(),get_Y());

}
	else perror("Nie udalo sie wykonac symulacji");
	return 0;
}


