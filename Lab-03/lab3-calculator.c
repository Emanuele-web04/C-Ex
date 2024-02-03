/*

Write a program lab3-calculator.c to calculate product or division of two floating numbers. 
The first argument is operator type multiply or divide, the second and third arguments are two floating numbers. 
The program should print out the calculating result. If it is not possible to take the calculation, print out invalid. 

For example:

Example 1. - Input:

./lab3-calculator multiply 5.2 4.6

    Output:

23.92

Example 2. - Input:

./lab3-calculator divide 12.1 0

    Output:

invalid

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    
    //argv[1] è il tipo che vogliamo
    //strcmp con multiply or divide
    //printare float e usare dunque atof
    char multiply[] = "multiply";
    char divide[] = "divide";
    int cmpM = strcmp(argv[1], multiply);
    int cmpD = strcmp(argv[1], divide);
    float divRes = atof(argv[2])/atof(argv[3]);
    float mulRes = atof(argv[2])*atof(argv[3]);
    if(atof(argv[3])==0) {
        printf("invalid\n");
    } else {
    if(cmpD == 0) {
        printf("%f\n", divRes);
    } else if(cmpM == 0) {
        printf("%f\n", mulRes);
    }
    }

    return 0;
}