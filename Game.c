
#include "Start_game.h"
#include "Board.h"
#include "Rules.h"
#include <stdio.h>
#include <stdlib.h>


int game(int **tab, int N) {
		//utworzenie nowej tablicy i zapis do niej wartoœci
		int **p;
		int **tab2 = create_new_board(get_X(), get_Y());
		
		if(tab2==NULL){
		perror ("Nie mozna utworzyc siatki");
		return 0;}
	
		else {
			for (int i = 0; i < get_Y(); i++) {
				for (int j = 0; j < get_X(); j++) {

					p = piece(tab, j, i);
					tab2[i][j] = zasady(p);
				}
			}


		board_change(tab, tab2);
		//rysuj(tab, get_X(), get_Y());
		delete_board(tab2);
	}
		return 1;
}
