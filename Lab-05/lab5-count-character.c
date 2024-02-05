/*

Write a program lab5-count-character.c which accepts two arguments. 

The first argument is a string and the the second argument is a character. 

You can assume that the lowercase and uppercase of a character are two different cases, 
e.g. C is not c. 
The program count the number of occurences of the character in the string and print the result. 
If the character does not exist in the string, print 0.

Note that, you are asked to use pointers for this exercise. 
So, try to use pointer as much as you can.

Example: Input:

./lab5-count-character a "abcxyza"

Output:

2

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//let's start without pointers and then try to understand how to do it
//gli passo copy nella function
void count_letter(char *array, int *counter, char *letter);

int main(int argc, char* argv[]){
    int counter=0;
    char letter = argv[1][0]; //è una stringa

    char cpy[50]; 
    // char *cpy essendo un nome di un vettore uguale al valore 
    // della prima cella, argv[2] contiene l'indirizzo del vettore
    strcpy(cpy, argv[2]);
    //pronto funzione
    count_letter(cpy, &counter, &letter);
    if(counter>0){
        printf("%d\n", counter);
    } else {
        printf("0\n");
    }

    return 0;
}
//il puntatore di un array prende l'ADDRESS del primo valore
//array[] stessa cosa
// int *counter, crea un contenitore di indirizzi per counter
void count_letter(char *array, int *counter, char *letter){
    int len = strlen(array);
    for(int i=0; i<len; i++) {
        if(array[i]==*letter){
            *counter+=1;
        }
    }
}