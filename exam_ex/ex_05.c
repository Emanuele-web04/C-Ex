/*
Scrivere un programma C che:
1) Prende in input dalla linea di comando una parola
2) Implmenta la funzione ricorsiva 
  void separa_vocali(char V[], int n)
  -che stampa prima tutte le vocali
  -e poi tutte le consonanti
input:
  vOlutAmEnte
output:
  e E A u O v l t m n t
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0;

void separa_vocali(char V[], int n);
void separaVocaliFor(char V[]);

int main(int argc, char** argv)
{
    char *V = argv[1];
   // separa_vocali(V);
    separa_vocali(V, i);
    printf("\n");
    return 0;
}

void separa_vocali(char V[], int n)
{
    n = i++; //laggo perchè mi riferivo a ++i, ovvero aumentava prima, invece qua aumenta dopo
    
    printf("%d\n", n);
    char c = V[n];

    //questo lo usa come bool
    int lowerletter_vowels, upperletter_vowels;
    lowerletter_vowels = ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' );
    upperletter_vowels = ( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' );

    //caso base
    if( i > strlen(V) )
        return;

    //comportamento principale della function
    if(lowerletter_vowels || upperletter_vowels)
        printf("%c ", c);

    separa_vocali(V, n);

    //quando finisce la ricorsione, ritorna indietro nello stack e chiama tutto quello che è "rimasto", dal più dentro al più fuori
    if(!(lowerletter_vowels || upperletter_vowels)) //algebra booleana con l'or
        printf("%c ", c);
}

void separaVocaliFor(char V[])
{
    int i = 0;
    int j = 0;
    char lowerVocals[5] = { 'a', 'e', 'i', 'o', 'u' };
    char upperVocals[5] = { 'A', 'E', 'I', 'O', 'U' };
    for(int i = 0; i < strlen(V); i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if( V[i] == lowerVocals[j] || V[i] == upperVocals[j] )
                printf("%c ", V[i]);
        }
    }
}