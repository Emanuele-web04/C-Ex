/*
    Scrivere un programma in C che:
    1) Definisce una struttura stack implementata con una single linked list, 
    in cui ciascun nodo contiene un valore intero e il puntatore al nodo successivo
    2) Prende in input dalla linea di comando un valore int n
    3) Implementa la funzione Stack* crea_stack_fibonacci(int n) che prende in input un valore intero
    e restituisce uno stack in cui sono inseriri i prmi n numeri di fibonacci 
    4) Stampa il contenuto dello stack nella funzione main

    Input: 9
    Output: 1 1 2 3 5 8 13 21 34
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack Stack;
struct stack {
    int val;
    Stack* next;
};

Stack* crea_stack_fibonacci(int n);
Stack* append(Stack* head, Stack* new);
int fib_recursive(int n);
void print(Stack* head);
void freeStack(Stack* head);

int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    Stack* mystack = crea_stack_fibonacci(n);

    print(mystack);
    printf("\n");
    freeStack(mystack);
    return 0;
}

Stack* crea_stack_fibonacci(int n)
{
    Stack* head = NULL;
    for(int i = 0; i < n; i++)
    {
        //non ho capito perchè in fibonacci non conta lo 0
        Stack* new = malloc(sizeof(Stack)); 
        new -> val = fib_recursive(i + 1);
        new -> next = NULL;
        head = append(head, new);
    }

    return head;
}

Stack* append(Stack* head, Stack* new)
{
    if( !head )
        return new;
    head -> next = append(head -> next, new);

    return head;
}

int fib_recursive(int n)
{   
    //qui devo implementare l'append per ogni valore
    if(n <= 1)
        return n;
    int res = fib_recursive(n - 2) + fib_recursive(n - 1);

    return res;
}

void print(Stack* head)
{
    if( head )  
    {
        printf("%d ", head -> val);
        print(head -> next);
    }
}

void freeStack(Stack* head)
{
    if( !head )
        return;
    Stack* linkToNext = head -> next; //per non perdere la reference di head
    free(head);
    freeStack(linkToNext);
}