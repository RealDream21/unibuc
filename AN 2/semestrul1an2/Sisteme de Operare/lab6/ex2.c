#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define maxn 1000
#define maxm 1000

void* mult_vectors(int* args)
{
	//int l1, c2, int matrix1[][maxn], int matrix2[][maxm], int limit
	int l1 = args[0];
	int c2 = args[1];
	int** matrix1 = args[2];
	int** matrix2 = args[3];
	int limit = args[4];
	
	int c = 0;
	for(int i = 0; i < limit; i++)
		c += matrix1[l1][i] * matrix2[i][c2];
		
	int* rez = (int*)malloc(sizeof(int));
	(*rez) = c;
	return rez;
}


int main()
{
	int n1 = 4, m1 = 2, n2 = 2, m2 = 3;
	int matrix1[][maxn] = {{1, 2,}, {3, 4}, {5, 6}, {7, 8}};
	int matrix2[][maxm] = {{1, 2, 3}, {4, 5, 6}};
	int rez_matrix[maxn][maxm];
	matrix_mult(n1, m1, matrix1, n2, m2, matrix2, rez_matrix);
	//inmultire matrice una 4x2 alta 2x3 => 4x3
	
	for(int i = 0; i < n1; i++)
	{
		for(int j = 0; j < m2; j++)
			printf("%d ", rez_matrix[i][j]);
		printf("\n");
	}

}


void matrix_mult(int n1, int m1, int matrix1[][maxn], int n2, int m2, int matrix2[][maxm], int rez_matrix[maxn][maxm])
{
	pthread_t threads[n1 * m2];
	int k = 0;
	for(int k1 = 0; k1 < n1; k++)
	{
		for(int k2 = 0; k2 < m2; k2++)
		{
			printf("%d, %d", k1, k2);
			void* rez;
			int args[] = {k1, k2, matrix1, matrix2, m2};
			pthread_create(&threads[k++], NULL, mult_vectors, args);
			pthread_join(threads[k - 1], &rez);
			rez_matrix[k1][k2] = *(int*)rez;
			free(rez);
		}
	}
}

