 
#include <stdio.h>
#include <math.h>

double f(double t, double y);
double g(double t); 
 
int main()
{
	// Allocazione e inizializzazione delle variabili
	int n = 0, k = 0;
	double t0 = 0., y0 = 0., h = 0.;
	double ti = 0., yi = 0., yi_1=0. /* la nostra y(i+1)*/;
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
	
	// Implementazione dell'algoritmo di Eulero
	ti = t0;
	yi = y0;
	
	for (k=1; k<=n; k++)
	{
		yi_1 = yi + h * f(ti,yi);
		
		// Calcolo dell'errore		
		err = g(ti + h) - yi_1;

		// Aggiornamento variabili
		yi = yi_1;
		ti = ti + h;
		
		printf("%6d \t %14.8lf \t % 14.8lf \t % 10.6e\n", k, ti, yi, err);
	}/* for */
	
 	return 0;
}

// Implementazione della funzione f(t,y) del problema di Cauchy 
 double f(double t, double y)
 {
 	return y-t;
 }

// Implementazione della soluzione analitica g(t)
 double g(double t)
 {
 	return exp(t)+t+1;
 }
