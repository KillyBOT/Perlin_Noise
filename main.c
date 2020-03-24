#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pnoise.h"

#define SIZE 1000
#define RES 32

int main(){
	FILE* f = fopen("testImage.ppm","w");

	char header[64];

	sprintf(header, "P3\n%d %d\n255\n",SIZE,SIZE);

	fputs(header,f);

	double xf,yf;
	int final;
	char grad[8];

	for(int y = 0; y < SIZE; y++){
		for(int x = 0; x < SIZE; x++){
			xf = (double)x / RES;
			yf = (double)y / RES;

			//final = 255 * perlin(xf, yf, 0);
			final = 255 * perlin_octave(xf,yf,0,8,.5);

			sprintf(grad, "%d ", final);

			fputs(grad,f);
			fputs(grad,f);
			fputs(grad,f);
		}
	}

	fclose(f);
}