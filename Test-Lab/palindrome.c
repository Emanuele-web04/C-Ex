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

//usi lo stack per invertire la parola, quindi lo usi come telecomando
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack Stack;
struct stack {
    int top; //per muoversi through the array
    char* arr;
};

//crei lo spazio per lo stack
Stack* createStack(int len);
//crei gli spazi per la parola
void mallocInputAndPushingValues(Stack* s, char* word, int len);
//ora la logica sarebbe quella di poppare uno alla volta, storare i valori in un nuovo arr e fare il check
char* poppedValuesInWord(Stack* s, int len);
//check if the word is palindrome
int checkIfTheWordIsPalidrome(Stack* s, int len, char* word, char* reverseWord);
//free all the malloc
void freeAll(Stack* s, char* word, char* reverseWord, int len);

int main(int argc, char** argv)
{
    int len = strlen(argv[1]);
    char* word = malloc(sizeof(char) * len);
    strcpy(word, argv[1]);

    Stack* mystack = createStack(len);
    mallocInputAndPushingValues(mystack, word, len);

    char* my_reverse_word = poppedValuesInWord(mystack, len);

    int true_or_false = checkIfTheWordIsPalidrome(mystack, len, word, my_reverse_word);

    printf((true_or_false == 0) ? "\nLa parola è palindroma\n" : "\nLa parola non è palindroma\n");

    freeAll(mystack, word, my_reverse_word, len);
    return 0;
}

Stack* createStack(int len)
{
    Stack* s = malloc(sizeof(Stack));
    s -> top = -1;

    return s;
}

void mallocInputAndPushingValues(Stack* s, char* word, int len)
{
    s -> arr = malloc(sizeof(char) * len);
    printf("Parola originale: ");
    for(int i = 0; i < len; i++)
    {
        char value = word[i];
        s -> top += 1;
        s -> arr[s -> top] = value;
        printf("%c", value);
    }
    printf("\n");
}

char* poppedValuesInWord(Stack* s, int len)
{
    //per poppare, salvi l'ultimo value nel vettore, e diminuisci top di 1
    printf("Parola invertita: ");
    char* reverseWord = malloc(sizeof(char) * len);
    for(int i = 0; i < len; i++)
    {
        reverseWord[i] = s -> arr[s -> top];
        s -> top -= 1;
        printf("%c", reverseWord[i]);
    }
    printf("\n");
    return reverseWord;
}

int checkIfTheWordIsPalidrome(Stack* s, int len, char* word, char* reverseWord)
{
    int n = 0;
    int i = 0;
    while(i < len)
    {
        if(word[i] == reverseWord[i])
            n++;
        i++;
    }
    return (n == i) ? 0 : 1;
}

void freeAll(Stack* s, char* word, char* reverseWord, int len)
{
    free(word);
    free(reverseWord);
    free(s -> arr); // puoi eliminare tutto il blocco perchè è un array e la mem è contigua
    free(s);
}