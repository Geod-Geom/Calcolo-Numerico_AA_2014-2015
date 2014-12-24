#include <stdio.h>
#include <math.h>

double f(double t, double y)
{
 	return y-t;
}

double g(double t)
 {
 	return exp(t)+t+1;
 }
 
int main()
{
	// Allocazione e inizializzazione delle variabili
	int n = 0, k = 0;
	double t0 = 0., y0 = 0., h = 0.;
	double ti = 0., yi = 0.;
	double err = 0.;

	// Recupero dei dati dati di input
	printf("Inserire il numero n di passi = \n");
	scanf("%d", &n);
 	printf("Inserire il valore di h = \n");
	scanf("%lf", &h);
	printf("Inserire il valore di t0 = \n");
	scanf("%lf", &t0);
	printf("Inserire il valore di y0 = \n");
	scanf("%lf", &y0);
	
	printf("n = %d \t h = % 14.8lf \t t0 = % 14.8lf \t y0 = % 14.8lf\n\n", n, h, t0, y0);
	
	// INSERIRE ALGORITMO
	
	
	
 	return 0;
}
