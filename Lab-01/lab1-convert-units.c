/*

Write a program called lab1-convert-units.c which does the following:

    Take input of an amount in centimetres from the command line.

    Converts this to inches. Note that there are 2.54 centimetres in every inch.

    Your program print the result with 2 digits after decimal point.

A Sample run might look like the following:

*/

#include <stdio.h>
#include <stdlib.h>
#define INCH 2.54

int main(int argc, char* argv[]) {
    
    float cm = atof(argv[1]);
    float inches = cm/INCH;

    printf("%.2f\n", inches);
    
    
    return 0;
}