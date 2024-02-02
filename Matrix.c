/*
printa una matrice
*/

//dati già dati
#include <stdio.h>
//#define row 3
//#define col 3
/*
int main() {
    
    //asing value to the matrix
    int matrix[row][col] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    //to print the matrix you need 2 neste for loop, one that counts the rows, and the other one that handle the numbers inside
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
*/
//print a matrix by input
/*int main() {
    int row, col;

    printf("Insert a dimension for the row: ");
    scanf("%d", &row);

    printf("Insert a dimension for the col: ");
    scanf("%d", &col);

    int mat[row][col];
    //storing the values
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("Inserire valore in posizione: %d, %d ", i, j);
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }  

    //printing the matrix
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/
//prendilo da input 
//come worka qui?
//io ho aout, la colonna, e la row, quindi starto da 3, e gli argomenti totali da considerare sono argc-3

#include <stdlib.h>

int main(int argc, char* argv[]) {
    int R = atoi(argv[1]);
    int C = atoi(argv[2]);

    printf("Numero rows: %d\n", R);
    printf("Numero cols: %d\n", C);

    //devo solo printarla
    //metodo con R e C
    int i, j;
    int mat[R][C];
    for(i=0; i<R; i++) {
        for(j=0; j<C; j++) {
            mat[i][j] = 
        }
        printf("\n");
    }

    //devo fare la copia in una matrice

    return 0;
}

