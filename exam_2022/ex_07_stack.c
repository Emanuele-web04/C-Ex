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


//allora bro, lo stack significa first in last out
//appena leggi stack devi pensa subito a push and pop ktm coglione
//lo stack è un tool che ti fa muovere attraverso la stringa
//leggi bene il testo e vedi che vuole

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack Stack;
struct stack {
    int top; // per muoverti nell'array
    char* arr;
};

Stack* createWord(int len, char* word);
void push(Stack* s, char value);
char pop(Stack* s);

int main(int argc, char** argv)
{ 
    char* word = argv[1];
    int len = strlen(word);

    Stack* mystack = createWord(len, word);

    //appendo i valori col push
    char value;
    printf("La parola normale è: ");
    for(int i = 0; i < len; i++) 
    {
        value = word[i];
        push(mystack, value);
        printf("%c", value);
    }
    printf("\n");
   
    //una volta storati tutti i valori inizio a poppare
    int n = 0;
    printf("La parola al contrario è: ");
    int j = 0;
    while(j < len)
    {
        char poppedValue = pop(mystack);
        printf("%c", poppedValue);
        if(poppedValue == word[j])
            n++;

        j++;
    }
      printf("\n");
    if(n == j)
        printf("\nLa parola è palindroma\n");


    return 0;
}

Stack* createWord(int len, char* word)
{
    //vuole che creo lo spazio per tutti gli n elementi
    Stack* s = malloc(sizeof(Stack));
    s -> arr = malloc(sizeof(char) * len);
    s -> top = -1;

    return s;
}

//pusha solo 1 elemento, non di più
void push(Stack* s, char value)
{
    s -> top += 1;
    s -> arr[s -> top] = value;
}

char pop(Stack* s)
{
    char result = s -> arr[s -> top];
    s -> top -= 1;

    return result;
}