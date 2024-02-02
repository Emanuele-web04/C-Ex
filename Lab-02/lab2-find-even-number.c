/*

Write a program lab2-find-even-number.c to find all even elements in an array of integers. 
Note that for learning purpose, you need to use array to store the input elements in this exercise.

Input: Each argument is an integer element of the array 
Output: In each line, print out the result as follows: <index> - <value>. 
If there is no even number, print out "Not found!" followed by a new line character.

You may assume the max length of the array is 10. Upload to Einstein to test your code.

For example: Input:

./lab1-find-even-number 3 5 12 43 4 2 5

Output:

2 - 12
4 - 4
5 - 2

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(int argc, char* argv[]) {
    
    //nested loop in order to track every number with linear search
    int i, j;
    int v[MAX];

    //while per copiare i dati nel vettore
    i=0;
    while(i<argc-1) {
        v[i] = atoi(argv[i+1]);
        i++;
    }
    i=0;
    j=0;
    int check=0;
    while(i<argc-1) {
        if(v[i]%2==0) {
            printf("%d - %d\n", i, v[i]);
            check=1;
        } 
        i++;
    }
    if(check!=1) {
        printf("Not found!\n");
    }

    return 0;
}