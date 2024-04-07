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

int* input(int *arr, char** argv);
int Conta_occorrenze(int V[], int n, int val);

int main(int argc, char** argv)
{
    int arr[10];
    int *array = input(arr, argv);

    int n = 0;
    int val = atoi(argv[2]);

    int nTimes = Conta_occorrenze(array, n, val);
    printf("Il valore %d compare: %d volte.\n", val, nTimes);
    return 0;
}

int* input(int *arr, char** argv)
{
    for(int i = 0; i < 10; i++)
        arr[i] = atoi(argv[2 + i]);

    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return arr;
}

int Conta_occorrenze(int V[], int n, int val)
{
    if(i == 10) 
        return n;
    if(val == V[i])
        n++;
    
    i++;
    return Conta_occorrenze(V, n, val);
}