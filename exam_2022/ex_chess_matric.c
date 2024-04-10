/*
    Scrivere un programma C che:
    1) Prende due interi M ed N da linea di comando e alloca una matrice di char di M
    righe e N colonne
    2) Inserisce nella posizione i,j della matrice il valore (65+i+j)
    3) Implementa la funzione void stampa_a_scacchi(char **Matrice, int M, int N) che
    stampa il valore della matrice quando la riga o la colonna è dispari e uno spazio
    altrimenti.
    Input e Output 
    Input: 5 7
    Output:
    La matrice di interi M è:
        B     D     F
     B     D     F     H
        D     F     H
     D     F     H     J
        F     H     J
*/

#include <stdio.h>
#include <stdlib.h>

char** createMat(int R, int C);
char** insertingValuesInTheMatrix(char** mat, int R, int C);
void stampa_a_scacchi(char** m, int R, int C);
void freeMat(char** m, int R);

int main(int argc, char** argv)
{
    int R = atoi(argv[1]);
    int C = atoi(argv[2]);

    char** mymatrix = createMat(R, C);
    char** my_matrix_with_values = insertingValuesInTheMatrix(mymatrix, R, C);

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            printf("%c ", my_matrix_with_values[i][j]);

    stampa_a_scacchi(my_matrix_with_values, R, C);

    freeMat(mymatrix, R);
    return 0;
}

char** createMat(int R, int C)
{
    char** matrix = malloc(sizeof(char*) * R); //perchè punta alle colonne
    //ad ogni riga, gli assegni lo spazio per le colonne
    for(int i = 0; i < R; i++)
        matrix[i] = malloc(sizeof(char) * C);

    return matrix;
}

char** insertingValuesInTheMatrix(char** mat, int R, int C)
{
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            mat[i][j] = (65 + i + j);

    return mat;
}

// che stampa il valore della matrice quando la riga o la colonna è dispari e uno spazio altrimenti.
void stampa_a_scacchi(char** m, int R, int C)
{
    printf("\n");
    for(int i = 0; i < R; i++) 
    {
        for(int j = 0; j < C; j++)
        {
            if(i % 2 != j % 2) {
                printf("%c", m[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
   }
}

void freeMat(char** m, int R)
{
    for(int i = 0; i < R; i++)
        free(m[i]);
    free(m);
}