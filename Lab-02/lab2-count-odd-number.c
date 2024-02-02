/*

Write a program lab2-count-odd-number.c to count the number of odd numbers in an array of integers. 
Note that for learning purpose, you need to use array to store the input elements in this exercise.

Input: Each argument is an integer element of the array 
Output: The total number of odd elements in the array followed by a new line character.

You may assume the max length of the array is 10. Upload to Einstein to test your code.

For example: Input:

./lab1-count-odd-number 3 5 12 43 4 2 5

Output:

4

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int main(int argc, char* argv[]) {
    //da i fino a argc-1 
    //in loop per argc-1
    //v[i] = atoi(argv[i+1])

    int i;
    int v[MAX];
    int oddCount = 0;
    i=0;
    while(i<argc-1) {
        v[i]=atoi(argv[i+1]);
        if(v[i]%2==1) {
            oddCount++;
        }
        i++;
    }
    printf("%d\n", oddCount);

    return 0;
}