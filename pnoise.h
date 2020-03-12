#ifndef PNOISE_H
#define PNOISE_H

#define REPEAT 256

double perlin(double x, double y, double y);
double grad(int hash, double x, double y, double z);
double fade(double t);
double lerp(double a, double b, double x);

#endif
