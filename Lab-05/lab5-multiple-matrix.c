/*

Write a program lab5-multiple-matrix.c which accepts the following arguments. 
The first two arguments indicate the first two dimensions of the first matrix m1 rows, n1 columns. 
The following m1xn1 arguments refer to each element in the first matrix. 
Similarly, the following two arguments indicate the dimension of the seconde matrix m2 rows, 
n2 columns and the following m2 x n2 arguments refer to each element in the second matrix. 
The program print the resulting matrix of the product of the two given matrix.

Do your own research online to revisit how two matrices can be multiplied.

Example:

Input:

./lab5-multiple-matrix 3 3 1 2 3 6 5 4 8 7 9 3 2 1 2 9 8 6 7

Output:

37 39
75 80
125 135

Explain:

Based on the inputs, we have the 3x3 Matrix A:

1 2 3
6 5 4
8 7 9

and the 3x2 matrix B:

1 2
9 8
6 7

The AxB return the resulting matrix above.

Note: You can use normal array and functions to solve this task. ù
After you can produce a correct program, try to use pointer to replace array in your solution.

*/


#include <stdio.h>
#include <stdlib.h>

void assing_values(int(*mat)[50], int* r, int* c, char** argv);
void assing_values2(int(*mat)[50], int* r, int* c, char** argv, char** p);

void mul_mat(int(*mat1)[50], int(*mat2)[50], int(*mul)[50], int* r, int* c1, int* c2);
int main(int argc, char* argv[]) {

    int mat1[50][50];
    int mat2[50][50];
    int r2, c2;
    int r1 = atoi(*(argv + 1));
    int c1 = atoi(*(argv + 2));

    char** p = (argv + 3 + (r1 * c1));
    r2 = atoi(*(p));
    p++;
    c2 = atoi(*(p));
    p++;

    int mul[50][50];

    assing_values(mat1, &r1, &c1, argv);
    assing_values2(mat2, &r2, &c2, argv, p);

    mul_mat(mat1, mat2, mul, &r1, &c1, &c2);

    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void assing_values(int(*mat)[50], int* r, int* c, char** argv) {
    for (int i = 0; i < (*r) * (*c); i++) {
        mat[i / *c][i % *c] = atoi(*(argv + 3 + i));
    }
}

void assing_values2(int(*mat)[50], int* r, int* c, char** argv, char** p) {
    for (int i = 0; i < (*r) * (*c); i++) {
        mat[i / *c][i % *c] = atoi(*(p + i));
    }
}

void mul_mat(int(*mat1)[50], int(*mat2)[50], int(*mul)[50], int* r, int* c1, int* c2) {
    for (int i = 0; i < *r; i++) {
        for (int j = 0; j < *c2; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < *c1; k++) {
                mul[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}