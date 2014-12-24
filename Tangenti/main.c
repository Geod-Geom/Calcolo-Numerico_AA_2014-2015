/*
 * Soluzione di Eq. Non Lineari con il metodo 
 * di Newton (o metodo delle Tangenti
 * 
 */ 

#include <stdio.h>
#include <math.h>

double f(double x);                  /* Funzione di cui si cercano gli zeri */
double df(double x);                 /* Derivata della funzione */

int main()
{
	int N_max = 10;                  /* Numero massimo delle iterazioni */
	int N = 0;                       /* Numero di iterazioni */
	double a = 0., b = 0.;           /* Estremi intervallo di integrazione */
	double err1 = 0., err2 = 0.;     /* Due modi di valutazione dell'errore */
	double err_max = 0.;             /* Errore massimo accettabile */
	double xk = 0.;                  /* Soluzione k-sima */
	double x0 = 0.;                  /* Approssimazione iniziale */
	
	/* Lettura parametri di input */
	printf("Intervallo inferiore a: ");
	scanf("%lf", &a);
	printf("Intervallo superiore b: ");
	scanf("%lf", &b);
	printf("Errore massimo accettabile: ");
	scanf("%lf", &err_max);
	printf("Approssimazione iniziale: ");
	scanf("%lf", &x0);
	
	err1 = 10.0;
	err2 = fabs(f(x0));
	
	printf("Iter        xk               err1               err2\n");
	printf("%3d   % 15.11lf    % 15.11lf    % 15.11lf\n", N, xk, err1, err2);	
	

	while ( ((err1 > err_max) || (err2 > err_max)) && (N < N_max) )
	{
		N++;
		
		xk = x0 - f(x0)/df(x0);
		
		err1 = fabs(xk - x0);
		err2 = fabs(f(xk));
		
		x0 = xk;
		
		printf("%3d   % 15.11lf    % 15.11lf    % 15.11lf\n", N, xk, err1, err2);	
	} /* while */
		
	return 0; 
}/* main */

double f(double x) 
{
	return exp(x) + (0.435 / x) * (exp(x) - 1) - 1.564;
}

double df(double x) 
{
	return exp(x) + (-0.435/pow(x, 2.)) * (exp(x) - 1) + exp(x) * 0.435/x;
}
