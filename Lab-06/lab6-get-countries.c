/*
Write a program lab6-get-countries.c which accepts the detail 
of a list of countries from the command line. 
Each country has the following information:

Name

Capital

Population (in million)

Size (in km2)

Using the notion of struct in C, 
the program can store all data using structure, 
and then print the information of all input country as follows:

The first line shows the header which include each information 
separated by three tab characters: \t\t\t.

The following lines show each corresponding data for each input country, 
separated by three tab characters \t\t\t.

For example:

Input:

./lab6-get-countries Ireland Dublin 4.99 84421 France Paris 67.39 632734 Germany Berlin 83.24 357386
Output:

Country			Capital			Size			Population
Ireland			Dublin			84421			4.99
France			Paris			632734			67.39
Germany			Berlin			357386			83.24
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//il tuo argv è dato da
/*
questo significa che gli elementi, essendo 4, devo skippare di 4 in 4 per trovare il corrispondente uguale
questo lo faccio attraverso un loop

argv = {
    a.out = 0;
    name1, 1 start con i = 0 (*4) + 1 per partire da 1
    cap1, 2
    pop1, 3
    size1, 4
    name2, 5
    cap2, 6
    pop2, 7
    size2 8
}
*/

typedef struct Nation {
    char name[30];
    char capital[30];
    float population;
    int size;
}nation;

int main(int argc, char **argv) {
    
    //now per storare tutta la roba, devo usa un'array of type nation

    nation arr_n[10];

    int N = (argc - 1)/4; // per indicare quante nations ho

    //devo passa i valori nell'array col for
    for(int i=0; i<N; i++)
    {
        //nell'array gli devo passare i come parametro per poi passare i subparametri con il valore i
        strcpy(arr_n[i].name,  argv[1 + (i*4)]);
        strcpy(arr_n[i].capital,  argv[2 + (i*4)]);
        arr_n[i].population = atof(argv[3 + (i*4)]);
        arr_n[i].size = atoi(argv[4 + (i*4)]);
    }

    //print for later
    for(int i=0; i<N; i++)
    {
        //printa step by step per vedere se non hai segmentation fault
        printf("\n%s\t", arr_n[i].name);
        printf("%s\t", arr_n[i].capital);
        printf("%.2f\t", arr_n[i].population);
        printf("%d\t\n", arr_n[i].size);
    }

    return 0;
}