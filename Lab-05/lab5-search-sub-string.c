/*
 
 Write a program lab5-search-sub-string.c which accepts two arguments. 
 The first argument is a string, and the second is a string with smaller length than the first input string.
 The program checks if the first string contains the second string.
 If yes, print the positions of the first and last character of the second string in the first string.

 Example:

 Input:

 ./search-sub-string "This is a word" "word"
 Output:

 10 13
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_pos(char *full_string, char *string_to_search);

int main(int argc, char *argv[]){
    
    //copy of the first string
    char *full_string = *(argv + 1);
    
    //copy of the second string
    char string_to_search=(argv+2);
    
    int i=0;
    int j=0;
    int index = -1;
    while(*(full_string)!='\0'){
        if(check_pos(full_string, string_to_search) == 1){
            index = i;
            break;
        }
        i++;
        full_string++;
    }
    printf("%d", index);
    
    return 0;
}

int check_pos(char *full_string, char *string_to_search){
   
    int i=0;
    int len = strlen(string_to_search);
    //finchè nella key non becco il carattere vuoto, quindi si prende la sua dimensione basically
    while(i < len){
        //estrapoli il valore con la dereference
        if(full_string[i] != string_to_search[i]){
            return -1;
        }
        
        //vai avanti nella cella dell'indirizzo di stirng_to_search
        i++;
        
    }
    
    
    return 1;
}