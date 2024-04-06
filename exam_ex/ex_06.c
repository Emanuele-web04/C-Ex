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
//abbiamo detto che deve essere di 9 elementi e di disposizione 3x3
#define N 9
#define R_C 3

//doppio puntatore perchè dopo gli devo passa la matrice nel main ergo **
int** createMatrix(char** argv);
int average(int** mat);
void displayMat(int** mat);
void binaryMat(int** mat);
void binaryCharMat(int** mat, char c);
void displayCharMat(int** mat);

int main(int argc, char** argv)
{
    char c = argv[argc - 1][0];
    int** mymat = createMatrix(argv);
    int avg_mat = average(mymat);

    displayMat(mymat);
    printf("\nThe average is: %d\n", avg_mat);

    binaryMat(mymat);
    displayMat(mymat);

    binaryCharMat(mymat, c);
    displayMat(mymat);
    
    displayCharMat(mymat);
    
    return 0;
}

int** createMatrix(char** argv)
{
    //devo creare un full spazio per quante righe ci sono
    //e un full spazio per quante colonne ci sono, nel loop delle righe
    int** mat = malloc(R_C * sizeof(int*)); //int* che mi punta alle colonne
    for(int i = 0; i < R_C; i++)
        mat[i] = malloc(R_C * sizeof(int));

    for(int i = 0; i < N; i++)
        mat[i / R_C][i % R_C] = atoi(argv[1 + i]);

    return mat;
}

int average(int** mat)
{
    int sum = 0;
    int average_all = 0;
    for(int i = 0; i < R_C; i++)
    {
        for(int j = 0; j < R_C; j++)
            sum += mat[i][j];
    }
    average_all = sum / N;

    return average_all;    
}

void displayMat(int** mat)
{
    printf("\n");
    for(int i = 0; i < R_C; i++)
    {
        for(int j = 0; j < R_C; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void binaryMat(int** mat)
{
    int avg = average(mat);

    for(int i = 0; i < R_C; i++)
    {
        for(int j = 0; j < R_C; j++)
        {
            //ho messo >= perchè se esce lo stesso numero di agv non fa un cazzo
            if(mat[i][j] >= avg) 
            {
                mat[i][j] = 1;
            } else {
                mat[i][j] = 0;
            }
        }

    }
}

void displayCharMat(int** mat)
{
    char c;
    printf("\n");
    for(int i = 0; i < R_C; i++)
    {
        for(int j = 0; j < R_C; j++)
        {
            c = mat[i][j];
            printf("%c ", c);   
        }
        printf("\n");
    }
}

void binaryCharMat(int** mat, char c)
{
    for(int i = 0; i < R_C; i++)
    {
        for(int j = 0; j < R_C; j++)
        {
            //ho messo >= perchè se esce lo stesso numero di agv non fa un cazzo
            if(mat[i][j] == 1) 
            {
                mat[i][j] = c;
            } else {
                mat[i][j] = ' ';
            }
        }

    }
    
}

