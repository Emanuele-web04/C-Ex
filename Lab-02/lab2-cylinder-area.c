/*

Write a program called lab2-cylinder-area.c which computes the area of a cylinder. Your program should take 2 command-line-arguments. The first of these is the radius, the second is the height. Set PI = 3.1415

    Input: The first argument is radius and the second argument is the height.

    Output:

        If there is no input argument, print out: "No input given!"

        If there is only one argument, print out: "Two arguments needed!"

        If a negative number is given, print out: "The radious or height cannot be negative!"

        Otherwise, print out the area of the Cylinder. Do some research if you want to check again how to calculate it.

        Remember to add a newline character \n at the end.

*/

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415
int main(int argc, char* argv[]) {
    //area del cerchio PI*r^2 (*h) // cilindro
    if(argc==1){
        printf("No input given!\n");
        return 1;
    } else if(argc == 2) {
        printf("Two arguments needed!\n");
        return 1;
    } 
    float r = atof(argv[1]);
    float h = atof(argv[2]);
    float areaC = 2*PI*r*h+2*PI*r*r;
    if(r<0 || h<0) {
        printf("The radious or height cannot be negative!\n");
    } else {
        printf("%.2f\n", areaC);
    }

    
    return 0;
}