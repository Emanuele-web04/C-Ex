/*

Rugby has several ways of scoring points. They are:

    A try (worth 5 points)

    A conversion (worth 2 points)

    A penalty (worth 3 points)

    A drop-goal (worth 3 points).

Write a program called lab1-rugby.c which does the following:

    Take four inputs (try, conversion, penalty, drop-goal) from command lines;

    Calculate the total point;

    Print the total point;

A Sample run might look like the following:

Input:

./lab1-rugby 2 1 1 3

Output:

24

*/

#include <stdio.h>
#include <stdlib.h>
#define TRY 5
#define CONVERSION 2
#define PENALTY 3
#define DROP_GOAL 3
int main(int argc, char* argv[]) {
    
    //quello che scrivo nella linea di comando lo moltiplica per le costanti dal prof date
    
    int sumPoints=0;
    int points[] = {TRY, CONVERSION, PENALTY, DROP_GOAL};
    
    for(int i=0; i<argc-1; i++) {
        sumPoints+=atoi(argv[i+1])*points[i];
    }

    printf("%d\n", sumPoints);
    
    return 0;
}