#include <stdio.h>


void LETTURA_MATRICE(int righe,int colonne, double A[righe][colonne],FILE *input);
void STAMPA_MATRICE(int righe, int colonne, double A[righe][colonne]);
void ZEROS_MATRICE(int righe, int colonne, double A[righe][colonne]);

int main(int argc, char **argv)
{
	int i=0,j=0;
	int N=0;    /* Numero di equazioni */
	
	/* Lettura parametri di input */
	printf("Inserire il numero di equazioni N: ");
	scanf("%d", &N);
	
	/* Allocazione della matrice A */
    double A[N][N];
	
	ZEROS_MATRICE(N,N,A);

	FILE *inputA=NULL;
	
	inputA = fopen("matriceA.dat", "r");
	if(inputA == NULL)
	{
		printf("Errore nell'apertura del file matriceA.dat\n");
		printf("Riprovare\n");
		return(1);
	} /* if */
	
	LETTURA_MATRICE(N,N,A,inputA);
	
	// NORMA DUE MATRICE
	
	
	
}


void LETTURA_MATRICE(int righe,int colonne, double A[righe][colonne],FILE *input)
{
	int i,j;
	
	for(i=0; i < righe; i++)
	{
		for(j=0; j < colonne; j++)
		{
		fscanf(input, "%lf", &A[i][j]);
		}
	} 
}

void STAMPA_MATRICE(int righe, int colonne, double A[righe][colonne])
{
	int i, j;
	
	for(i=0; i < righe; i++)
	{
		for(j = 0; j < colonne; j++)
		{
			printf("% 10.5lf ", A[i][j]);
		}
		printf("\n");
	} 
}


void ZEROS_MATRICE(int righe, int colonne, double A[righe][colonne])
{
	int i, j;
	
	for(i = 0; i < righe; i++)
	{
		for(j = 0; j < colonne; j++)
		{
			A[i][j] = 0.;
		}
	}	
}
