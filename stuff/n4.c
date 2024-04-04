/*
   Presa un stringa da line di comand, lungehzza max 30,
    ritoran la posizione delle primo carattere numerico tipo '1', '2' ecc

    ===================================
    Input ex:

    ./a.out "ho 21 anni"

    Output ex:

    primio numero in posizione 3 e valore 2
*/

#include <stdio.h>
#include <string.h>
#define MAXLENGHT 30
int main(int argc, char *argv[]) {

    printf("%s\n", argv[1]);
    long int len = strlen(argv[1]);
    char copy[len];
    strcpy(copy, argv[1]);
    int i=0;
    while(i<len && !('0'<copy[i] && copy[i] < '9')) {
        i++;
    }
    if(i<len) {
        printf("primio numero in posizione %d e valore %c\n", i, copy[i]);
    }
    
    return 0;
}