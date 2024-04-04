#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int argc, char** argv);
void freeMat(int** mat, char** argv);

int main(int argc, char** argv)
{ 
    int** myMat = createMatrix(argc, argv);

    freeMat(myMat, argv);
    return 0;
}

int** createMatrix(int argc, char** argv)
{
    int R = atoi(argv[1]);
    int C = atoi(argv[2]);
    //devo creare dinamicamente uno spazio per questa bella matrice
    //e quale cosa posso usare se non malloc?
    //ora esploriamo che scrivere nel malloc
    //basically devo creare tot spazio per tot righe che punteranno a degli spazi per le colonne
    //ergo se ho 2 righe, creo 2 spazi di tipo puntatore che poi userò per richiamare le colonne
    int **mat = malloc(R * sizeof(int*));

    //ora per allocare le colonne, devo creare tot spazio di colonna per ogni riga
    //ergo, ho 2 righe da 3 colonne, per 2 volte, creo uno spazio di 3
    for(int i = 0; i < R; i++)
    {
        mat[i] = malloc(C * sizeof(int)); //just an intero perchè è il valore che ci serve per C
    }

    //vado a passare i valori dentro la matrice
    for(int i = 0; i < argc -3; i++)
    {
        //uso i / C per la divisione è lo stessa, ma i % C mi da valori tipo 0, 1, 2, ovvero le colonne
        mat[i / C][i % C] = atoi(argv[3 + i]);
    }

    //print the matrix
    //doppio for
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return mat;
    //per freeuppare, passo per le row e poi per la matrice full
   /* for(int i = 0; i < R; i++)
    {
        free(mat[i]);
    }
    //free(mat);*/
}

void freeMat(int** mat, char** argv)
{
    int R = atoi(argv[1]);

    for(int i = 0; i < R; i++)
    {
        free(mat[i]);
    }
    free(mat);
}