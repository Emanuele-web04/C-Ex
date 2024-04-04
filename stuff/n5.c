/*
Presa una stringa da line di comando, len max 30,
    dai per scontato che sia tutta in lower case letter, printa il numero di vocali e consonati presenti

    ===================================
    Input ex:

    ./a.out "ciao"

    Output ex:

    vocali = 3, consonati = 1
    ===================================
    Input ex:

    ./a.out "ciao123"

    Output ex:

    vocali = 3, consonanti = 1
    ===================================
*/

#include <stdio.h>
#include <string.h>
#define MAXLENGHT 30
int main(int argc, char *argv[]) {
    long int len = strlen(argv[1]);
    if(len > MAXLENGHT) {
        return 1;
    } 

        printf("%s\n", argv[1]);
        //qui è na sorta di linear search, al posto di stoppare il programma, ogni volta che copy[i] == vocale, countVocale++
        int i=0;
        char copy[len];
        strcpy(copy, argv[1]);
        int countVoc=0;
        int countCons=0;
        while(i<len) {
            if(copy[i] == 'a' || copy[i] == 'e' || copy[i] == 'i' || copy[i] == 'o' || copy[i] == 'u') {
                countVoc++;
            //oltre questo io devo escludere aeiou, e il char mi deve essere compreso tra le
            //lettere piccole, quindi da 97 a 122 o meglio da ('a' a 'z')
            } else if('a' <= copy[i] && copy[i] <= 'z'){
                countCons++;
            }
            i++;
        }
        printf("Vocali: %d, Consonanti: %d\n", countVoc, countCons);
    
    
    return 0;
}