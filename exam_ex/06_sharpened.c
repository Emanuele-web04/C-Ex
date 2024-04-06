/*
Scrivere un Programma C che:

1) Prendere dalla lina di comando 9 interi e un carattere C.
Inserice gli interi in una matrice M di dim 3X3 allocata dinamicamente.

2)Implementa la funzione:

int* RimpiazzaMaggiori(int **M, char c); (non c'e' scritto che deve ritornare metto void, esericizio spiegato di merda)
-che calcola la media dei valori in M;

-e pone a uno tutte le posizioni in M il cui valore e' maggiore
della media e a 0 quelle, in cui il valore e' minore della media.

-Infine stampa a video una matrice di caratteri dove e' presente il carattere c se il
corrispondente valore in M  e' 1 e uno spazio altrimenti.

Input:
12 1 15 5 10 3 11 0 9
La matrice binaria e':
1 0 1
0 1 0
1 0 1
Inserisci un carattere: A
La matrice di caratteri e':
A   A
  A 
A   A
*/

#include <stdio.h>
#include <stdlib.h>

#define R 3
#define C 3
#define N 9

//Inserice gli interi in una matrice M di dim 3X3 allocata dinamicamente.
int** createMat(char** argv); //questa la devo fa peffo

/*calcola la media dei valori in mat
-e pone a uno tutte le posizioni in M il cui valore e' maggiore
della media e a 0 quelle, in cui il valore e' minore della media.*/

//non ho capito che deve ritornare se fa già tutto qua dentro
void rimpiazzaMaggiori(int **mat, char c);  
//free peffo
void freemat(int** mat);

int main(int argc, char** argv)
{ 
    char c = argv[argc - 1][0];

    int** mymat = createMat(argv);
    rimpiazzaMaggiori(mymat, c);

    free(mymat);
    return 0;
}

int** createMat(char** argv)
{
    int** mat = malloc(R * sizeof(int*));
    for(int i = 0; i < R; i++)
        mat[i] = malloc(C * sizeof(int));
    
    //passo i valori
    for(int i = 0; i < N; i++)
        mat[i / C][i % C] = atoi(argv[1 + i]);

    return mat;
}

void rimpiazzaMaggiori(int **mat, char c)
{
    int sum = 0;
    int avg = 0;

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            sum += mat[i][j];

    avg = sum / N;

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if( mat[i][j] >= avg ) {
                mat[i][j] = 1;
                printf("%c", c);
            } else {
                mat[i][j] = 0;
                printf(" ");
            }
        }
        printf("\n");
    }
}

void freemat(int** mat)
{
    for(int i = 0; i < R; i++)
        free(mat[i]);
    
    free(mat);
}