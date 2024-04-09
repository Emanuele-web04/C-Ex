/*
    scrivere un programma in C :
    1) Definisce un tipo Digit come una lista i cui nodi contengono il campo bit 
    2)Implementa le funzioni Digit *Dec2Dig(int val) che:
        - calcola il numero di bit n necessari a rappresentare val in binario:
        -Crea e restituisce la lista, i cui nodi contengono i bit dell'intero val 
    3) prende da linea di comando un valore intero e stampa i bit inseriti nella lista.

    output: 26
    output:
    i bit di 26 sono 1->1->0->1->0->

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct digit Digit;
struct digit {
    int bit;
    Digit* next;
};

Digit *Dec2Dig(int val);
Digit* append(Digit* head, Digit* new);
void display(Digit* head);

int main(int argc, char** argv)
{
    int val = atoi(argv[1]);

    Digit* mylist = Dec2Dig(val);

    display(mylist);
    return 0;
}

Digit *Dec2Dig(int val)
{
    //per calcolare i bit devo vede quando quando val raggiunge lo 0
    Digit* head = NULL;
    int tmp = val;
    int n = 0;
    while(tmp != 0) 
    {   
        Digit* new = malloc(sizeof(Digit));
        new -> bit = tmp % 2;
        new -> next = NULL;
        tmp = tmp / 2;
        n++;
        head = append(head, new);
    }
    printf("Numero di bit: %d\n", n);

    return head;
}

Digit* append(Digit* head, Digit* new)
{
    if( !head )
        return new;

    head -> next = append(head -> next, new);

    return head;
}

void display(Digit* head)
{
    if( head ) {
        display(head -> next);
        printf("%d -> ", head -> bit);
    }
}