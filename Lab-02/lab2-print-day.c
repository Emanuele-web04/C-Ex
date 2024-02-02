/*

Write a program lab2-print-day.c which takes a single Command-line Argument (an integer) 
and prints the name of the day of the week to which it corresponds. The details are:

    1 = Sunday

    2 = Monday

    3 = Tuesday

    4 = Wednesday

    5 = Thursday

    6 = Friday

    7 = Saturday

    Build the program as before and upload to einstein.

    Remember to add a newline character \n at the end.

*/

#include <stdio.h>
#include <stdlib.h>
#define R 7
#define C 10
int main(int argc, char*argv[]) {
    char day[R][C] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thurday", "Friday", "Saturday"};
    int i=0;
    int j=0;
    while(i<R) {
            if(atoi(argv[1]) == i+1) {
                printf("%s\n", day[i]);
                return 0;
            }
            i++;
    }
    return 0;
}