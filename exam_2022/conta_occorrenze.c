/*
    Scrivere un programma in C che.
    1) Prenda da linea di comando 10 interi e li inserisce in un vettore

    2) Implementa la funzione ricorsiva int Conta_occorrenze(int V[], int n, int val) 
    che restituisce il numero di volte che i valore "val" compare nel vettore V

    Input 5 8 6 12 9 5 2 5 1 8 
    Output Il valore 5 compare 3 volte
*/

#include <stdio.h>
#include <stdlib.h>

int i = 0;
int Conta_occorrenze(int V[], int n, int val);

int main(int argc, char** argv)
{
    int v[10];
    int val = atoi(argv[1]);

    for(int i = 0; i < 10; i++)
        v[i] = atoi(argv[2 + i]);

    int n = 0;

    int matchFound = Conta_occorrenze(v, n, val);

    printf("%d\n", matchFound);

    return 0;
}

int Conta_occorrenze(int V[], int n, int val)
{
    if(i > 9)
        return n;
    if(V[i] == val)
        n++;
    i++;
    return Conta_occorrenze(V, n, val);
}