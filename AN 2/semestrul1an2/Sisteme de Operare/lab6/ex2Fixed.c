#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 1000
#define maxm 1000

typedef struct thread_params{
    int m, p, n;
    int c_line;
    int c_column;
}thread_params;

int matrix1[][1000] = {{1, 2, 3}, {4, 5 ,6}};
int matrix2[][1000] = {{10, 11}, {20, 21}, {30, 31}};
int matrix3[1000][1000];

void* matrix_mult(void* params)
{
    thread_params* tp = (thread_params*)(params);
    int rez = 0;

    for(int i = 0; i < tp->p; i++)
    {
        rez += matrix1[tp->c_line][i] * matrix2[i][tp->c_column];
    }
    int* to_return = malloc(sizeof(int));
    (*to_return) = rez;
    free(tp);
    return to_return;
}


int main()
{
    int m, p, n;
    m = 2;
    p = 3;
    n = 2;
    
    pthread_t threads[n * m + 5];
    int k = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            thread_params* tp = malloc(sizeof(thread_params));
            tp->m = m;
            tp->p = p;
            tp->n = n;
            tp->c_line = i;
            tp->c_column = j;
            pthread_create(&threads[k++], NULL, matrix_mult, tp);
        }
    }

    k = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            void* rez_ptr;
            int* rez;
            pthread_join(threads[k++], &rez_ptr);
            rez = (int*)(rez_ptr);
            matrix3[i][j] = (*rez);
            free(rez);
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%d ", matrix3[i][j]);
        printf("\n");
    }
   
    return 0;
}
