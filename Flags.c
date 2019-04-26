#include <stdio.h>
#include <stdlib.h>
#include <string.h>



	int N;
	char *inputfilename;
	char *picfolder;
	char *outputfilename;
	char *outpng;




void set_N(int a){
 N=a;
}


void set_inpf (char *a){
	inputfilename=a;
}


void set_oupf (char *a){
	outputfilename=a;
}

void set_picf (char *a){
	picfolder=a;
}


void set_outpng (char *a){
	outpng=a;
}


void flags (int argc, char *argv[]){

	char *a=argv[1];


	for (int i=1;i<argc;i++){
		a=argv[i];

		if(strcmp(a, "-N")==0 || strcmp(a,"--N")==0){
			if ((atoi(argv[i+1])>0))
				set_N(atoi(argv[i+1]));
			else {
				perror("Podana liczba generacji jest nieprawidlowa. Ustawiam domyslna liczbe na 5");			
				set_N(5);
			}
		}

		else if ((strcmp(a, "-input_filename"))==0 || (strcmp(a,"--input_filename"))==0)
			set_inpf(argv[i+1]);

		else if ((strcmp(a, "-picfolder"))==0 || (strcmp(a,"--picfolder"))==0)
			set_picf(argv[i+1]);

		else if ((strcmp(a, "-output_filename"))==0 || (strcmp(a,"--output_filename"))==0)
			set_oupf(argv[i+1]);
		else if ((strcmp(a, "-outpng"))==0 || (strcmp(a,"--outpng"))==0)
			set_outpng(argv[i+1]);

	}
}





