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
    int v[100];
};

Stack* createStack();
void Push_vec(Stack *s, int v[], int n);
int* Pop_vec(Stack* s, int n);
void freeAll(Stack* s, int* v);

int main(int argc, char** argv)
{
    int n = argc - 1;
    int v[argc - 1];
    for(int i = 0; i < n; i++)
        v[i] = atoi(argv[1 + i]);

    Stack* my_s = createStack();
    Push_vec(my_s, v, n);

    int* halfStack = Pop_vec(my_s, n);

    for(int i = 0; i < n / 2; i++)
        printf("%d ", halfStack[i]);
    printf("\n");

    freeAll(my_s, halfStack);
    return 0;
}

Stack* createStack()
{
    Stack* s = malloc(sizeof(Stack));
    s -> top = -1;

    return s;
}

void Push_vec(Stack* s, int v[], int n)
{
    for(int i = 0; i < n; i++)
    {
        s -> top += 1;
        s -> v[i] = v[i];
    }
}

int* Pop_vec(Stack* s, int n)
{
    int* result = malloc(sizeof(int) * ((n - 1) / 2));
    for(int i = 0; i < n / 2; i++)
    {
        result[i] = s -> v[s -> top];
        s -> top -= 1;
    }

    return result;
}

void freeAll(Stack* s, int* v)
{
    free(v);
    free(s);
}