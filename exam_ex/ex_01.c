/*
Scrivere un programma C che :
1)Definisce un Punto come un record con i campi float x e y

2)Implementa uno stack con capacita' limitata di 10 punti, con le funzioni
void Push(Stack *s, Punto P)
Punto Pop(Stack* s)

3)Inserice in sequenza nello stack i punti
P1(12,3), P2(14,4), P3(7, 9).

Successivamente estrae un punto alla volta dallo stack e stampa
le cordinate del punto estratto
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct punto Point;
typedef struct stack Stack;

struct punto {
    float x;
    float y;
};

struct stack {
    Point arr[10];
    int top; //questo è il big bro che si muove di posizione
};

//devo creare uno spazio allocato dinamicamente per lo stack
Stack* createStack();
void push(Stack* s, Point P);
Point pop(Stack* s);

int main()
{
    Point P1;
    P1.x = 12;
    P1.y = 3;

    Point P2;
    P2.x = 14;
    P2.y = 4;

    Point P3;
    P3.x = 7;
    P3.y = 9;

    Stack* mystack = createStack();

    push(mystack, P1);
    push(mystack, P2);
    push(mystack, P3);

    for(int i = 0; i < 3; i++)
    {
        Point P = pop(mystack);
        printf("Last point: P(%.0f, %.0f)\n", P.x, P.y);
    }

    return 0;
}

Stack* createStack()
{
    //crea uno spazio per l'array
    Stack* result = malloc(sizeof(Stack)); 
    result -> top = -1;
    
    return result;
}

void push(Stack* s, Point P)
{
    //per spostarmi nell'array devo aumentare top man mano di 1
    s -> top += 1;
    s -> arr[s -> top] =  P;
}

Point pop(Stack* s)
{
    //dato che top può actually muoversi, lui finito i push
    //si ritroverà dritto dritto alla fine dell'array, ergo printi quel valore
    //e diminuisci di 1
    Point res = s -> arr[s -> top];
    s -> top -= 1;
    return res;
}