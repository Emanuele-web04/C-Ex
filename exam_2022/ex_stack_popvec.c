/*
    Scrivere un programma C che:
    1) Definisce un tipo Stack come un record che include un vettore d i 100 interi 
    2) Implementa le e funzioni void Push_vec(Stack *S, int v[], int n), la quale inserisce nello stack tutti i valori contenuti nel vettore v. 
    e int* Pop_vec(Stack*S,intn), la quale restituisce un vettore di interi contenente i primi n valori estratti dallo stack.
    3) Legge un elenco d i n interi da riga di comando, gli inserisce nello stack, estrae n/2 interi dallo stack e li stampa a video.

    Input:1 2 3 4 5 6 7 8 9 10
    Output: valori estratti sono:1 0 9 8 7 6
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack Stack;
struct stack {
    int top;
    int arr[100];
};

Stack* createStack(int v[], int n);
void Push_vec(Stack *s, int v[], int n);
int* Pop_vec(Stack* s, int n);
void print(Stack* s, int n);

int main(int argc, char** argv)
{
    int v[100];
    int n = argc - 1;

    for(int i = 0; i < n; i++)
        v[i] = atoi(argv[1 + i]);
    
    Stack* mystack = createStack(v, n);

    print(mystack, n);
    //printf("%d\n", mystack -> top); //s -> top == 9, perchè parto da 0, quindi faccio da x fino a x - 1
    int* poppedVals = Pop_vec(mystack, n);

    free(mystack);
    free(poppedVals);
    return 0;
}

//creo lo stack
Stack* createStack(int v[], int n)
{
    Stack* s = malloc(sizeof(Stack));
    s -> top = -1;

    for(int i = 0; i < n; i++)
        Push_vec(s, v, n);

    return s;
}

//pusha solo un numero nello stack
void Push_vec(Stack *s, int v[], int n)
{
    s -> top += 1;
    s -> arr[s -> top] = v[s -> top]; 
}

//rimuove solo un elemento alla volta, partendo dall'ultimo
int* Pop_vec(Stack* s, int n)
{
    int *res = malloc(sizeof(int) * n / 2);
    printf("%d\n", n / 2);
    for(int i = 0; i < n / 2; i++)
    {
        res[i] = s -> arr[s -> top];
        printf("%d ", res[i]);
        s -> top -= 1;
    }
    printf("\n");
    return res;
}

void print(Stack* s, int n)
{
    //condizione di base
    for(int i = 0; i < n; i++)
        printf("%d ", s -> arr[i]);
    printf("\n");
}