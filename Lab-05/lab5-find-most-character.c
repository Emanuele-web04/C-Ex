/*
 
 Write a program lab5-find-most-character.c which accept an input string as argument. 
 The program find the character which has the most number of appearance in the string and print the character out.
 You can assume there is only one most frequent character.
 Again, use pointer as much as you can in this exercise.

 Example: Input:

 ./lab5-find-most-character "abcxyzbcc"
 Output:

 c
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void store(char *array, int *array_store, long int *len, char **argv);

int max(int *array, int *max_value, long int *len);

void search(int *array, char *array_string, int *max_value, long int *len);

int main(int argc, char* argv[]){
    char cpy[50];
    strcpy(cpy, argv[1]);
    long int len = strlen(cpy);
    
    int counter;
    int store_counter[len];
    store(cpy, store_counter, &len, argv);
     
    int max_value = store_counter[0];
    max(store_counter, &max_value, &len);

    search(store_counter, cpy, &max_value, &len);

    return 0;
}

void store(char *array, int *array_store, long int *len, char **argv){
    int counter;
    for(int i=0; i<*len; i++){
        counter=0;
        for(int j=0; j<*len; j++){
            if(array[i]==argv[1][j]){
                counter += 1;
            }
        }
        array_store[i] = counter;
    }
}

int max(int *array, int *max_value, long int *len){
    int q=1;
    
    while(q<*len){
        printf("%d ", array[q]);
        if(*max_value < array[q+1]){
            *max_value = array[q];
            
        }
        q++;
    }
    return *max_value;
}

void search(int *array, char *array_string, int *max_value, long int *len){
    int p=0;
    while(p<*len && *max_value != array[p]){
        p += 1;
    }
    printf("\n%c\n", array_string[p]);
}