/*
    Scrivere un programma in C che:
    1) Prende un vettore di n interi da linea di comando
    2) Definisce un nodo Elemento come un record che contiene due interi: pos e val,
    e un puntatore al nodo successivo
    3) Implementa la funzione Elemento *crea_vettore_sparso(int V[], int len) 
    che crea una lista di nodi Elemento, ovvero scorre il vettore in input 
    e se l'elemento in posizione i-esima del vettore è diverso da zero, crea un nodo, importa il campo pos a i
    e il campo val a vettore[i] e lo inserisce nella lista
    Input: 2 0 0 0 5 0 0 0 -8 0 0 0 -11 0 0 0 3
    Output: 
    Il vettore sparso è: (0, 2) -> (4, 5) -> (8, -8) -> (12, -11) -> (16, 3) -> NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int pos;
    int val;
    Node* next; //points to the next node
};

//questa funzione crea il nodo se e solo se il val è diverso da 0, imposta il campo pos a i del loop
Node* crea_vettore_sparso(int *V, int len);
Node* append(Node* head, Node* new);
void print(Node* head);
void freeList(Node* head);

int main(int argc, char** argv) 
{
    int len = argc - 1;
    //i think i have to create an array of len and pass all the value inside of it
    int arr[len];
    for(int i = 0; i < len; i++)
        arr[i] = atoi(argv[1 + i]);

    Node* mynode = crea_vettore_sparso(arr, len);
    print(mynode);
    return 0;
}

Node* crea_vettore_sparso(int *V, int len) 
{
    //setta l'head a null e poi gli passi i valori
    Node* head = NULL;
    for(int i = 0; i < len; i++)
    {
        //check if i have to create a node when the value of V[i] is different from 0
        if( V[i] != 0 ) {
            Node* new = malloc(sizeof(Node));
            new -> pos = i;
            new -> val = V[i];
            new -> next = NULL;
            head = append(head, new);
        }
    }

    return head;
}

Node* append(Node* head, Node* new)
{
    if( !head )
        return new; 
    //you check for the next node if it is Empty or NULL
    //metti head -> next perchè altrimenti 
    head -> next = append(head -> next, new);//The two head -> next are NOT LINKED!!

    return head; //to have something to take
}

void print(Node* head)
{
    if( !head ) {
        printf("NULL");
        return;
    }
    printf("(%d, %d) -> ", head -> pos, head -> val);
    print(head -> next);
}

void freeList(Node* head)
{
    if( !head )
        return;
    free(head);
    freeList(head -> next);
}