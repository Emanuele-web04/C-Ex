/*
    Scrivere un programma C che:
    1) Definisce un tipo digit come un record due campi int n e int *d
    2) Implementa le funzioni void Det2Dig(int val, digit *dval) che:
    - calcola il numero di bit n necessari a rappresentare val in binario;
    - alloca d come vettore di n interi
    - pone in d i bit della rappresentazione binaria di val.
    Input e Output
    Input: 57
    Output:
    La rappresentazione binaria di 57 è: 0 1 1 1 0 0 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct digit Digit;
struct digit {
    int n;
    int* d;
};

void Det2Dig(int val, Digit *dval);
void printInReverse(int n, int dim, int* vett);

int main(int argc, char** argv)
{
    Digit* my_digit = malloc(sizeof(Digit));   
    int val = atoi(argv[1]);
    Det2Dig(val, my_digit);
    for(int i = 0; i < my_digit -> n; i++)
        printf("%d ", my_digit -> d[i]);
    printInReverse(0, my_digit -> n, my_digit -> d);
    return 0;
}

void Det2Dig(int val, Digit *dval)
{
    int tmp = val;
    dval -> n = 0;
    int dim = 0;
    while(tmp != 0)
    {
        dim++;
        tmp = tmp / 2;
    }
    tmp = val;
    dval -> d = malloc(sizeof(int) * dim);
    while(tmp != 0)
    {
        dval -> d[dval -> n] = tmp % 2;
        printf("%d ",  dval -> d[dval -> n]);
        tmp = tmp / 2;
        dval -> n += 1;
    }
    printf("\n");
}

void printInReverse(int n, int dim, int* vett)
{
    if(n == dim)
        return;
    printInReverse(n + 1, dim, vett);
    printf("%d ", vett[n]);
}