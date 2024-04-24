/*
    Scrivere un programma in C che:
    1) Prende in input dalla linea di comando una parola.
    2) Definisce uno stack AStack a capacità limitata il cui array interno sia allocato dinamicamente 
    con capacità pari alla lunghezza della parola in input
    3) Usi lo stack per invertire la parola
    4) Usi lo stack per verificare se la parola è palindroma

    Input: onorarono
    Output:
    La parola è palindroma e la sua inversione è: onorarono
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack Stack;
struct stack {
    int top;
    char* arr;
};

Stack* createStack(int len, char* string);
//creo la funzione push che viene chiamata poi per len volte in create stack
void push(Stack* s, char* string);
//int* pop per ritornare un vettore coi valori inversi per poi fare la comparison con s nel main
char* pop(Stack* s, int len);
//free
void freeAll(Stack* s, char* rev, char* string);

int main(int argc, char** argv)
{
    int len = strlen(argv[1]);
    char* word = malloc(sizeof(char) * len);
    strcpy(word, argv[1]);

    Stack* s = createStack(len, word);

    char* rev_string = pop(s, len);

    int check_for_palindrome = 0;
    for(int i = 0; i < len; i++)    
    {
        if(s -> arr[i] == rev_string[i])
            check_for_palindrome++;
    }

    printf((check_for_palindrome == len) ? "Palindrome\n" : "Not Palindrome\n");

    freeAll(s, rev_string, word);
    return 0;
}

Stack* createStack(int len, char* string)
{
    Stack* s = malloc(sizeof(Stack));
    s -> top = -1;
    s -> arr = malloc(sizeof(char) * len);

    for(int i = 0; i < len; i++)
        push(s, string);

    return s;
}

void push(Stack* s, char* string)
{
    s -> top += 1;
    s -> arr[s -> top] = string[s -> top];
}

char* pop(Stack* s, int len)
{
    char* rev_string = malloc(sizeof(char) * len);
    for(int i = 0; i < len; i++)
    {
        rev_string[i] = s -> arr[s -> top];
        s -> top -= 1;
    }

    return rev_string;
}

void freeAll(Stack* s, char* rev, char* string)
{
    free(rev);
    free(string);
    free(s -> arr);
    free(s);
}