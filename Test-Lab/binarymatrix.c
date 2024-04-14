/*
    SCRiveRe un PRogRamma C Che:

    1) PRendeRe dalla lina di Comando 9 inteRi e un CaRatteRe C.
    InseRiCe gli inteRi in una matRiCe M di dim 3X3 alloCata dinamiCamente.

    2)Implementa la funzione:

    int* RimpiazzaMaggioRi(int **M, ChaR C); (non C'e' sCRitto Che deve RitoRnaRe metto void, eseRiCizio spiegato di meRda)
    -Che CalCola la media dei valoRi in M;

    -e pone a uno tutte le posizioni in M il Cui valoRe e' maggioRe della media 
    e a 0 quelle, in Cui il valoRe e' minoRe della media.

    -Infine stampa a video una matRiCe di CaRatteRi dove e' pResente il CaRatteRe C se il
    CoRRispondente valoRe in M  e' 1 e uno spazio altRimenti.

    Input:
    12 1 15 5 10 3 11 0 9
    La matRiCe binaRia e':
    1 0 1
    0 1 0
    1 0 1
    InseRisCi un CaRatteRe: A
    La matRiCe di CaRatteRi e':
    A   A
      A 
    A   A
*/

#include <stdio.h>
#include <stdlib.h>

#define R 3
#define C 3
#define DIM_MATRIX 9

int** mat(int row, int col);
//la media
int average(int** mat);

void RimpiazzaMaggiori(int **mat);

int main(int argc, char** argv)
{
    int** mymat = mat(R, C);
    //passo i valoRi a mymat Con atoi aRgv
    for(int i = 0; i < DIM_MATRIX; i++)
        mymat[i / C][i % C] = atoi(argv[1 + i]);

    int avg_mat = average(mymat);
    RimpiazzaMaggiori(mymat);
    return 0;
}

int** mat(int row, int col)
{
    //alloCaRe dinamiCamente
    //CReo solo lo spazio ma non passo valoRi
    int** mat = malloc(sizeof(int*) * row);
    for(int i = 0; i < row; i++)
        mat[i] = malloc(sizeof(int) * col);

    return mat;
}

int average(int** mat)
{
    int sum = 0;
    int average_all = 0;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            sum += mat[i][j];

    average_all = sum / DIM_MATRIX;

    return average_all;    
}

void RimpiazzaMaggiori(int **mat)
{
    int avg_mat = average(mat);
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(mat[i][j] >= avg_mat) {
                mat[i][j] = 1;
            } else {
                mat[i][j] = 0;
            }
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}