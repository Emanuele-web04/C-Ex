/*
Scrivere un programma C che:

1) Prede una parola da linea di comando

2) Definisce un nodo Elemento come un record che contine une
intero pos e un carattere c, e un punattore al nodo successivo

3) Implementa la funzione
Elemento *crea_vettore_sparso(char vettore[], int len)
-che crea una lista di nodi Elemento,
-ovvero scorre il vettore in input e se l'elemento in posizione i-esima del vettore e' una vocale, 
crea un node, imposta il campo pos a i
e il campo c a vettore[i] e lo inserisce nella lista.

Input:
Indissolubilmente
Output:
(0, i) -> (3, i) -> (6, o) -> (8, u) -> (10, i) -> (13, e) -> (16, e) -> NULL
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
struct node {
    int pos;
    char c;
    Node* next;
};

//creo un init per creare un vettore
Node* create_array(char array[]);
Node* add_element(Node* head, Node* new);
void displayList(Node* head);
void freeList(Node* head);

int main(int argc, char** argv)
{
    char *array = argv[1];
    Node* myList = create_array(array);

    displayList(myList);
    freeList(myList);

    return 0;
}

Node* create_array(char array[])
{
    Node* head = NULL;
    for(int i = 0; i < strlen(array); i++)
    {
        Node* new = malloc(sizeof(Node));
        new -> pos = i;
        new -> c = array[i];
        new -> next = NULL;
        //e poi vai avanti aggiungendo
        head = add_element(head, new);
    }

    return head;
}

Node* add_element(Node* head, Node* new)
{
    if( !head )
        return new;
    head -> next = add_element(head -> next, new);
    
    return head;
}

void displayList(Node* head)
{
    if( head ) {
        if( 
        head -> c == 'a' 
        || head -> c == 'e' 
        || head -> c == 'i' 
        || head -> c == 'o' 
        || head -> c == 'u' 
        ) 
        {
            printf("(%d, %c) -> ", head -> pos, head -> c);
        }
        displayList(head -> next);
    } else {
        printf("NULL\n");
    }
}

void freeList(Node* head)
{
    if( !head )
        return;
    Node* linkToNext = head -> next;
    free(head);
    freeList(linkToNext);
}