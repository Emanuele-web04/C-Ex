/*
    prendi da command line una matrice e printane i valore
    i primi due elementi sono: riga e colonne, il resto so i valori
    Input:
    ./a.out 3 3 1 2 3 4 5 6 7 8 9
    Output:
    (1, 2, 3) (4, 5, 6) (7, 8, 9)
*/

#include <stdio.h>
#include <stdlib.h>

void createMatrix(int argc, char **argv);
void displayMatrix(int **mat, char **argv);

int main(int argc, char** argv) 
{
    createMatrix(argc, argv);

    return 0;
}

void createMatrix(int argc, char **argv)
{
    int R = atoi(argv[1]);
    int C = atoi(argv[2]);

   //devo allocare uno spazio per tot righe e per tot colonne
   int **mat = malloc(R * sizeof(int*)); 
   //ora che devo creare 9 elementi o quello che è, dovrei fa tipo R*C
   for(int i = 0; i < R; i++)
   {
        mat[i] = malloc(C * sizeof(int));//ad ogni riga, gli passo tot colonn
   }

   for(int i = 0; i < argc - 3; i++)
   {
        mat[i / C][i % C] = atoi(argv[3 + i]);
   }

    displayMatrix(mat, argv);

}

void displayMatrix(int **mat, char **argv)
{
    int R = atoi(argv[1]);
    int C = atoi(argv[2]);
    
    for(int i = 0; i < R; i++)
    {
        printf("(");
        for(int j = 0; j < C; j++)
        {
            printf("%d", mat[i][j]);
        }
        printf(")\n");
    }
}
