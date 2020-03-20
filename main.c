#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pnoise.h"

int main(){
	FILE* f = fopen("testImage.ppm","w");

	fputs("P3\n1024 1024\n255\n",f);

	double xf,yf;
	int final;
	char grad[8];

	for(int y = 0; y < 1024; y++){
		for(int x = 0; x < 1024; x++){
			xf = (double)x / 32;
			yf = (double)y / 32;

			final = 255 * perlin(xf, yf, 0);

			sprintf(grad, "%d ", final);

			fputs(grad,f);
			fputs(grad,f);
			fputs(grad,f);
		}
	}

	fclose(f);
}