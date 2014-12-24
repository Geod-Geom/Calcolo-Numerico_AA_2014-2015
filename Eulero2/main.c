#include <stdio.h>
#include <math.h>

double f (double t, double y);
double g (double t);


int main()
{

int n=0 , k=0;
double to=0., yo=0., h=0., ti=0., yi=0., yi_1=0., err=0.;


printf ("inserire il numero di passi = \n");
scanf ("%d", &n);
printf ("inserire il passo = \n");
scanf ("%lf", &h);
printf ("inserire istante iniziale = \n");
scanf ("%lf", &to);
printf ("inserire il valore iniziale della y = \n");
scanf ("%lf", &yo);

printf ("passo          t             y               err\n");

ti=to;
yi=yo;

for (k=1; k<=n; k++)
{
	yi_1 = yi + 0.5*h*(f(ti,yi) + f(ti+h,yi+h*f(ti,yi)));
	err=g(ti+h)-yi_1;
	printf("%4d %14.8lf %14.8lf %14.8lf\n",k,ti+h,yi_1,err);
	yi=yi_1;
	ti=ti+h;
}

	return 0;
}

double f(double t, double y)
{
return y;
}

double g (double t)
{
return 2*exp(t);
}

