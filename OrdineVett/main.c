#include <stdio.h>

int main(int argc, char **argv)
{
	int A[10] = {3,5,7,8,9,4,2,1,50,100};
	
	int thi=0, next = 0, size = 10; 
	int i=0;
	
	printf("Vettore iniziale\n\n");
	for(i=0;i<size; i++)
	{
		printf("%d\t", A[i]);
	}
	
	// INSERIRE ALGORITMO PER ORDINARE IL VETT
	
    int temp;

	for(thi=0; thi<size; thi++)
	{
		for(next=thi+1; next<size; next++)
		{	
			if(A[thi] > A[next])
			{
				temp=A[thi];
				A[thi]=A[next];
				A[next]=temp;
			}
		}
		
		printf("thi = %d \n", thi);
		for(i=0;i<size; i++)
		{
			printf("%d\t", A[i]);
		}
		
	}
	

	// STAMPARE A ORDINATO
	
	printf("\nVettore ordinato\n\n");

	for(i=0;i<size; i++)
	{
		printf("%d\t", A[i]);
	}
	
	
	// STAMPARE MIN e MAX

	
	return 0;
}
