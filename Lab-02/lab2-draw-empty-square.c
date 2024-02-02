/*

Write a program lab2-draw-empty-square.c taking an argument as width and draw a square of "*". Remember to add a newline character \n at the end. Upload to Einstein to test your code.

For example . Input:

./lab1-draw-empty-square 5

    Output:

*****
*   *
*   *
*   *
*****

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    
    int N = atoi(argv[1]);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i==0 || i== N-1 || j==0 || j==N-1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
    
}