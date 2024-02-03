/*

Write a program lab3-string-reverse.c to reverse a given string. The program take one argument as an input string and print out the reversed one. 
You may assume the maximum character is 50. Then upload your solution to Einstein!

For example:

    Input

./lab3-string-reverse "to be or not to be"

    Output

eb ot ton ro eb ot

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int main(int argc, char* argv[]) {
    
    //qua facciamo la copia in un vettore e printiamo il vettore tutto al contrario
    long int len = strlen(argv[1]);
    char v[len];
    char cpy[len];
    strcpy(cpy, argv[1]);
    int i;
    if(len>MAX) {
        return 1;
    }
    for(i=0; i<len; i++) {
        v[i]=cpy[len-i-1];
    }
    for(i=0; i<len; i++) {
        printf("%c", v[i]);
    }
    printf("\n");
    
    
    return 0;
}