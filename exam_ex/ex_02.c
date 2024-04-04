/*
Scrivere un programma C che:
1) Prende da linea di comando due interi n e m, e n*m interi successivi.
Alloca una matrice di interi M di dimensioni nxm e la inizializza con gli
interi letti in input

2) Implementa la funzione
mini_max_pari_dispari(int **M, int n, int m, int *row, int *col)
che individua la riga la cui somma degli elementi sia minima
e la colonna la cui somma degli elementi sia massima


input:
    3 4 12 33 22 11 3 67 1 23 76 34 12 1
output:
    La riga con somma minima e': 0
    La colonna con somma massima e': 1
*/

#include <stdio.h>
#include <stdlib.h>

//allocazione matrice con inter n*m
int** createMatrix(char** argv, int argc);
void displayMat(int** mat, char** argv);
void freeMat(int** mat, char** argv);
void mini_max_pari_dispari(int **mat, char** argv);

int main(int argc, char** argv)
{ 
    int** myMat = createMatrix(argv, argc);
    mini_max_pari_dispari(myMat, argv);

    freeMat(myMat, argv);
    return 0;
}

int** createMatrix(char** argv, int argc)
{
    int R = atoi(argv[1]);
    int C = atoi(argv[2]);
    //crea una matrice da allocare
    int** mat = malloc((R) * sizeof(int*));
    for(int i = 0; i < (R); i++)
    {
        mat[i] = malloc((C) * sizeof(int));
    }
    //adesso gli passo i valori
    for(int i = 0; i < (argc) - 3; i++)
    {
        mat[i / C][i % C] = atoi(argv[3 + i]);
    }
    displayMat(mat, argv);
    return mat;
}

void displayMat(int** mat, char** argv)
{
    int R = atoi(argv[1]);
    int C = atoi(argv[2]);

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

}

void freeMat(int** mat, char** argv)
{
    int R = atoi(argv[1]);
    printf("\n");
    for(int i = 0; i < R; i++)
    {
        free(mat[i]);
        printf("Freeing row n^%d: succeded\n", i);
    }
    free(mat);
    printf("All freed\n");
}

void mini_max_pari_dispari(int **mat, char** argv)
{
    int R = atoi(argv[1]);
    int C = atoi(argv[2]);
    int somma;
    int maxSum = 10000000;
    int minSum = -10000000;

//somma per righe (somma minima)
    for(int i = 0; i < R; i++)
    {
        //reset della somma
        somma = 0;
        for(int j = 0; j < C; j++)
        {
            somma += mat[i][j];
        } 
        printf("somma riga: %d\n", somma);
        if(somma < maxSum) {
            maxSum = somma;
        }
    }
    
    printf("somma minima righe: %d\n", maxSum);

    for(int i = 0; i < C; i++)
    {
        //reset della somma
        somma = 0;
        for(int j = 0; j < R; j++)
        {
            somma += mat[j][i];
        } 
        printf("somma colonna: %d\n", somma);
        if(somma > maxSum) {
            maxSum = somma;
        }
    }
    
    printf("somma massima colonne: %d\n", maxSum);

}