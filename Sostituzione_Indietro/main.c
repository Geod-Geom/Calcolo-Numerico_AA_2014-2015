#include <stdio.h>

void LETTURA_MATRICE(int righe,int colonne, double A[righe][colonne],FILE *input);
void STAMPA_MATRICE(int righe, int colonne, double A[righe][colonne]);

void ZEROS_MATRICE(int righe, int colonne, double A[righe][colonne]);
void ZEROS_VETTORE(int num, double V[num]);

int main(int argc, char **argv)
{
	int i=0;
	int N=0;    /* Numero di equazioni */
	
	/* Lettura parametri di input */
	printf("Inserire il numero di equazioni N: ");
	scanf("%d", &N);
	
	/* Allocazione della matrice A e dei vettore B e X del sistema lineare */
    double A[N][N];
    double B[N][1];
    double X[N];
	
    /* Inizializzazione di A e B */
    ZEROS_MATRICE(N,N,A);
    ZEROS_MATRICE(N,1,B);
    ZEROS_VETTORE(N,X);

	/* Lettura da file dei valori della matrice A e del vettore B */ 
	FILE *inputA=NULL;
	FILE *inputB=NULL;
	
	inputA = fopen("matriceA.dat", "r");
	if(inputA == NULL)
	{
		printf("Errore nell'apertura del file matriceA.dat\n");
		printf("Riprovare\n");
		return(1);
	} /* if */
	
	inputB = fopen("vettoreB.dat", "r");
    if(inputB == NULL)
	{
		printf("Errore nell'apertura del file vettoreB.dat\n");
		printf("Riprovare\n");
		return(1);
	} /* if */
	
	LETTURA_MATRICE(N,N,A,inputA);
	LETTURA_MATRICE(N,1,B,inputB);
	
	printf("La matrice A:\n");
	STAMPA_MATRICE(N,N,A);	
    printf("Il vettore B:\n");
	STAMPA_MATRICE(N,1,B);
	
	
	//Algoritmo sostituzione indietro
	
	X[N-1] = B[N-1][0] / A[N-1][N-1]; // X2 = B2 / A[2][2]
	
	
    printf("X[%d] = %lf\n",N,X[N-1]);
		
	int j=0;
	
	for(i=N-2; i >= 0; i--)  //i = 1, 0 
	{
		double sum = 0.0;
		
		for (j = N-1; j > i; j--) // se i = 1 -> j = 2   se i = 0 -> j 2, 1
		{
			sum += A[i][j]*X[j]; //  A[0][2]*X[2] + A[0][1]*X[1]		
		}
		
		
		X[i] = (B[i][0] - sum)/A[i][i];
		 
		 
		printf("X[%d] = %lf\n",i+1,X[i]);
		
	}/* for i */
	
	
	return 0;
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

void ZEROS_VETTORE(int num, double V[num])
{
	int i;
	
	for(i = 0; i < num; i++)
	{
			V[i] = 0.;
	}	
}

