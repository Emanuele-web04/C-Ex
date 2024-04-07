/*
Scrivere un programma C che:
1) Definisce un tipo digit come un record due campi int n e int *d
2) Prendere un intero val da linea di comando
3) Implementa la funzione

void Det2Dig(int val, digit *dval) che:
-calcola il numero di bit n necessari a rappresentare val in binario;
-alloca d come vettore di n interi;
-pone in d i bit della rapresentazione binaria di val

input
57
output
La rappresentazione binaria di 57 e': 0111001
*/

#include <stdio.h>
#include <stdlib.h>

int i = 0;

typedef struct digit Digit;
struct digit {
    int n;
    int *d; //i assume che questo sia il vettore per storare i numeri del binario
};

Digit* createBinary();
void Det2Dig(int val, Digit *dval);
void freeAll(Digit* dv);

int main(int argc, char** argv)
{
    int value = atoi(argv[1]);
    Digit* mydig = createBinary(value);
    Det2Dig(value, mydig);
    freeAll(mydig);
    return 0;
}

Digit* createBinary(int val)
{
    while(!(val % 2 == 0 && val / 2 == 0))
    {   
        i++;
        val = val / 2;
    }
    printf("%d\n", i);
    Digit* dval = malloc(sizeof(Digit));
    dval -> d = malloc(sizeof(int) * i);
    return dval; 
}

void Det2Dig(int val, Digit *dval)
{
    //sto while serve per contare quante cifre mi servono per allocare la mem
    int j = i - 1;
  
    int tmp = val;
    while(j >= 0)
    {
        dval -> d[j] = tmp % 2; 
        printf("%d ", dval -> d[j]);
        tmp = tmp / 2;
        j--;
    }   
    

    printf("La conversione in binario di %d è: ", val);
    for(int k = 0; k < i; k++)
        printf("%d ", dval -> d[k]);

}

void freeAll(Digit* dv)
{
    free(dv -> d);
}