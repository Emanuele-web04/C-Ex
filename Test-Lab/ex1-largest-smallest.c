/*
 
 Write a program ex1-largest-smallest.c which accepts a requirement and an array of float numbers. 
 The first argument is a requirement which can be largest or smallest.
 The following arguments are a set of floating numbers. If the requirement is largest, the program find the largest element in the array and print it.
 If the requirement is smallest, the program find the smallest element in the array and print it.
 Limit the displayed float number to 2 digits after the decimal point. You can assume the maximum number of elements in the array is 50.
 You are asked to use functions as much as you can when design the solutions.

 Example:

 Input:

 ./ex1-largest-smallest largest 4.2 4.5 12.3 6.7 93.5 87.6
 Output

 93.50
 Input:

 ./ex1-largest-smallest smallest 4.2 4.5 12.3 6.7 93.5 87.6
 Output

 4.20
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//searching the max
float max(float array[], int N);

//searching for the min
float min(float array[], int N);

//check string with func
int check(char key[]);

int main(int argc, char* argv[]) {
    
    //check string
    char check_string[9];
    strcpy(check_string, argv[1]);
    
    int N = argc-2;
    //copy of argv in order to not pass the argv to the funcs, but the input_array
    float input_array[MAX];
    
    for(int j=0; j<N; j++) {
        input_array[j]=atof(argv[j+2]);
    }

    //check with function
    int check_key = check(check_string);
    
    float output_max = max(input_array, N);
    float output_min = min(input_array, N);
    
    if(check_key == 1){
        printf("%.2f\n", output_max);
    } else if(check_key == 0) {
        printf("%.2f\n", output_min);
    }
    
    return 0;
}

float max(float array[], int N) {
    float max_value = array[0];
    int i=1;
    while(i<N) {
        //check for max
        
            if(array[i]>max_value){
                max_value=array[i];
            }
        
        i++;
    }
    return max_value;
}

float min(float array[], int N) {
    int i=1;
    float min_value = array[0];
    while(i<N) {
        //check for max
        
            if(array[i]<min_value){
                min_value=array[i];
            }
        
        i++;
    }
    return min_value;
}

int check(char key[]){
    char largest[] = "largest";
    char smallest[] = "smallest";
    
    //compare strings
    int lar = strcmp(largest, key);
    int sma = strcmp(smallest, key);
    
    //check which string is used
    if(lar == 0){
        return 1;
    } else if(sma == 0) {
        return 0;
    }
    
    return -1;
    
}