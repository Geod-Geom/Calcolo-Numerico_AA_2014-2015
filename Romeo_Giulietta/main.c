/* Programma di Runge-Kutta: 
 *
 * Soluzione di un sistema di due equazioni differenziali del primo ordine
 * con il metodo di Runge-Kutta del IV ordine
 * 
 * Funzioni:
 * - f(x, y, z)  
 * - g(x, y, z)
 *
 * Input:
 * - x0, y0, z0: condizione iniziale
 * - h: passo di discretizzazione
 * - n: numero di passi
 *
 * Output:
 * - xi: nodo i-esimo
 * - yi: approssimazione al nodo xi
 *
 *     case('1')  
        disp   
% CASO 1 ('alpha = 0.1; beta  = 0.00005; sigma = 0.005; omega = 0.1 -> passione esplosiva')   
% CASO 2 ('alpha = 0.1; beta  = +/- 0.00005; sigma = 0.005; omega = 0.1 -> Romeo ama troppo Giulietta che alla fine lo odia')
% CASO 3 ('alpha = -0.1; beta  = -0.00005; sigma = -0.005; omega = -0.1 -> La passione si spegne in entrambi')
% CASO 4 ('alpha = 0.1*I; beta  = +/- 0.00005; sigma = 0.005; omega = 0.1*I -> Romeo non Ë convinto e Giulietta lo Ë meno di lui')
% CASO 5 ('alpha = 0.1*I; beta  = +/- 0.00005*I; sigma = 0.005*I; omega = 0.1*I -> Romeo non Ë convinto mentre Giulietta cambia idea')
% CASO 6 ('alpha = 0.1*I; beta  = 0.005*I; sigma = 0.005*I; omega = 0.1*I -> passano da amore a odio (battimenti)')
% CASO 7 ('alpha = 0.1*I; beta  = - 0.005; sigma = -0.005 I; omega = 0.1*I -> la passione di Giulietta oscilla fino a trascinare Romeo ma ormai Ë tardi') 
 */
 
#include <stdio.h>
#include <complex.h>
 
double complex f(double complex x, double complex y, double complex z)
{ 
	double complex alpha=0.1*I, beta= - 0.005;
	
	return alpha*y+beta*z;
}

double complex g(double complex x, double complex y, double complex z)
{
	double complex sigma= -0.005*I, omega= 0.1*I;
	
	return sigma*y + omega*z;
}
   
 int main()
 {
 
	// Allocazione e inizializzazione delle variabili
	int n=0, k=0;
	double complex x0=0., y0=0., z0, h=0.;
	double complex xi=0., yi=0., zi=0.;

		
	/* Apertura file di output */
	FILE *OUT = NULL;
	OUT = fopen("Runge-Kutta_sistema.txt", "w");
	// Controllo apertura file
	if(OUT == NULL)
	{
		printf("Errore nell'apertura del file\n");
		printf("Riprovare\n");
		return(1);
	} /* if */
	
    x0 = 0; y0 = 1; z0 = 2; 
    h = 1; n = 1000;
		
	// Implementazione dell'algoritmo di Runge-Kutta

	xi = x0;
	yi = y0;
	zi = z0;
	
	double complex k1=0, k2=0, k3=0, k4=0; /* Incrementa funzione y */
	double complex t1=0, t2=0, t3=0, t4=0; /* Incrementa funzione z */
	
	for (k=1; k<=n; k++)
	{
		k1 = f(xi, yi, zi);
		t1 = g(xi, yi, zi);
		
		k2 = f(xi + 0.5*h, yi + 0.5*h*k1, zi + 0.5*h*t1);
		t2 = g(xi + 0.5*h, yi + 0.5*h*k1, zi + 0.5*h*t1);
		
		k3 = f(xi + 0.5*h, yi + 0.5*h*k2, zi + 0.5*h*t2);
		t3 = g(xi + 0.5*h, yi + 0.5*h*k2, zi + 0.5*h*t2);
		
		k4 = f(xi + h, yi + h*k3, zi + h*t3);
		t4 = g(xi + h, yi + h*k3, zi + h*t3);
	
		yi = yi + h*(k1 + 2.0*k2 + 2.0*k3 + k4)/6.0;
		zi = zi + h*(t1 + 2.0*t2 + 2.0*t3 + t4)/6.0;
		
		xi = xi + h;
		
		// Stampa dei risultati 
	    printf("%4d\t %6.2lf +%6.2lf*I %14.8lf +%14.8lf*I %14.8lf +%14.8lf*I \n", k, creal(xi), cimag(xi), creal(yi), cimag(yi), creal(zi), cimag(zi));
		fprintf(OUT, "%4d\t %14.8lf %14.8lf %14.8lf %14.8lf %14.8lf %14.8lf \n", k, creal(xi), cimag(xi), creal(yi), cimag(yi), creal(zi), cimag(zi));
	}	
	
	fclose(OUT);
	
 	return 0;
 }
 
 
