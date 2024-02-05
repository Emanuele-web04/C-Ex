/*
 
 Write a program ex1-is-symmetric.c which accepts a string as an input. 
 The program checks if the input string is symmetric and print yes, otherwise print no.
 You are asked to use functions as much as you can when design the solutions.

 Input:

 ./ex1-is-symmetric "ABCDBA"
 Output

 no
 Input:

 ./ex1-is-symmetric "ABCXYZ ZYXCBA"
 Output

 yes
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//create copy
void copy(char v[MAX], char m[MAX]);

//print statement
void print(char v[MAX], char m[MAX]);

int main(int argc, char* argv[]){
    
    //copy of a string into a char array in order to handle it
    char v[50];
    strcpy(v, argv[1]);

    //this works
    char m[MAX];
    copy(v, m);
    
    print(v, m);
    
    return 0;
}

void copy(char v[MAX], char m[MAX]){
    long int len = strlen(v);
    for(int i=0; i<len; i++){
        m[i] = v[len-i-1];
    }
}

void print(char v[MAX], char m[MAX]){
    int cmp = strcmp(v, m);
    
    if(cmp==0){
        printf("yes\n");
    } else {
        printf("no\n");
    }
}