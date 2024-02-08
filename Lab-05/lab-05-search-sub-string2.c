#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    
    char *string = *(argv + 1);
    char *key = *(argv + 2);
    
    int len = strlen(string);
    int len_sub_key = strlen(key);
    
    int i, j;
    j=0;
    int index = -1;
    for(i=0; i<len; i++){
        if(string[i] == key[j]){
            if(j<len_sub_key){
                index = i;
                break;
            }
            j++;
        }
    }
    
    printf("%d %d", index, index+len-1);
    return 0;
}