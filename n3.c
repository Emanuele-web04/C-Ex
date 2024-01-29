/*

    Presa una stringa da lina di comando, lunghezza max 30,
    ritornare la posizione della Lettera del alfabeto Grande (upper case),
    se non ci sono upper case letter non printare niente

        Input Ex:

    ./a.out "ciaO io sono peppe"

    Output ex:

    La prima upper case letter e' in posizione 3 ed e' O
    ===================================

    (hint 'A' ritorana il numero ascii di A, stessa cosa per 'Z', e nel man asccii, tutte le lettere dalla A alla Z sono
    numeri contigui tipo 1 2 3 4 5 6)

*/

//Use linear search
//Le lettere maiuscole sono da 65 a 90
//Le lettere minuscole da 97 a 122

#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {

    printf("%s\n", argv[1]);
    long int len = strlen(argv[1]);
    char copy[len];
    strcpy(copy, argv[1]);
    int i=0;
    while(i<len) {
        printf("%c\n", copy[i]);
        i++;
    }
    i=0;
    while(i<len && !(copy[i]>'A' && copy[i]<'Z')) {
        i++;
    }
    if(i<len) {
        printf("La prima upper case letter e' in posizione %d ed e' %c\n", i, copy[i]);
    }

    return 0;
}