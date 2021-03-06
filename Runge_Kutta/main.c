/* Programma di Runge-Kutta: 
 *
 * Calcola la soluzione numerica di equazioni differenziali del primo ordine
 * con il metodo di Runge-Kutta esplicito
 * 
 * Funzioni:
 * - f(t,y): termine noto dell’equazione differenziale 
 * - g(t): soluzione analitica del problema di Cauchy
 *
 * Input:
 * - t0, y0: condizione iniziale
 * - h: passo di discretizzazione
 * - n: numero di passi
 *
 * Output:
 * - ti: nodo i-esimo
 * - yi: approssimazione al nodo ti
 *
 */
 
#include <stdio.h>
#include <math.h>
 
double f(double x,double y);
double g(double t);
   
 int main()
 {
 
	// Allocazione e inizializzazione delle variabili

	int n=0, k=0;
	double t0=0.,y0=0.,h=0.;
	double ti=0.,yi=0.,err;
		
	// Recupero dei dati dati di input
	
	printf("Inserire il numero n di passi = \n");
	scanf("%d", &n);
 	printf("Inserire il valore di h = \n");
	scanf("%lf", &h);
	printf("Inserire il valore di t0 = \n");
	scanf("%lf", &t0);
	printf("Inserire il valore di y0 = \n");
	scanf("%lf", &y0);
	
	printf("n = %d \t h = %14.8lf \t t0 = %14.8lf \t y0 = %14.8lf\n\n",n,h,t0,y0);
		
	// Implementazione dell'algoritmo di Runge-Kutta
	
	ti = t0;
	yi = y0;
	
	double k1=0,k2=0,k3=0,k4=0;
	
	for (k=1; k<=n; k++)
	{
		k1 = f(ti,yi);
		k2 = f(ti + 0.5*h, yi + 0.5*h*k1);
		k3 = f(ti + 0.5*h, yi + 0.5*h*k2);
		k4 = f(ti + h, yi + h*k3);
	
		yi = yi + h*(k1 + 2.0*k2 + 2.0*k3 + k4)/6.0;
		ti = ti + h;
		// Calcolo dell'errore
		err = g(ti)-yi;
		// Stampa dei risultati 		
		printf("%6d \t %14.8lf \t % 14.8lf \t % 10.6e\n", k, ti, yi, err);

	}	
	
 	return 0;
 }
 
 // Implementazione della funzione f(t,y) del problema di Cauchy 

 double f(double x,double y)
 {
 	return (y-x);
 }
 
// Implementazione della soluzione analitica g(t)

 double g(double t)
 {
 	return exp(t)+t+1;
 }
 
 
