/*
devi valutare un stringa in entrata lunghezza massima 200 char, 
e' una passowrd, una password per essero ottima deve avere vocali, consonanti, numeri, caratterei speciali tipo "@" 
e deve avere anche caratteri Upper case e lower case, 
inoltre per essere una password ottima deve avere una lunghezza minima di 15 char
*/

#include <stdio.h>
#include <string.h>
#define MAX 200
int main() {
    
    char password[MAX];
    printf("Inserire password: ");
    scanf("%s", password);

    long int len = strlen(password);
    char vocals[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    //provalo a fare col while
    char numbers[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    int points = 7;
    int insecurity=0;
    int i;
    i=0;
    while(i<len) {
        if(password[i]!=vocals[i]) {
            insecurity=1;
        }
        if(password[i]!=numbers[i]){
            insecurity++;
        }
        i++;
    }
    if(insecurity>0 && insecurity<=7) {
        points = points - insecurity;
    }
    printf("%d", points);

    return 0;
}