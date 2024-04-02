/*


Write a program lab10-push-pop.c to demostrate the push and pop operations 
from a list. The program accepts the following arguments from the command line.
 The first argument is the number of integers n. 
 The next n arguments refer to the integers. 
 The last argument is the new integer we want to add to the list.

The program remove the last two elements (so pop twice), 
and then add the last two arguments into the end (so push twice). 
Then the program displays all elements line by line.

You are required to implement a linked list to store all integers. 
You are encouraged to use dynamic memory allocation in the program.

It would also be great if you can use function to design the solution.

Input

./lab10-push-pop 7 6 3 6 4 0 2 4 5 9

Output

6
3
6
4
0
5
9

Explain:

    The original list contains 7 elements: 6, 3, 6, 4, 0, 2, 4

    Then the program pops twice: pop → 6, 3, 6, 4, 0, 2 → pop → 6, 3, 6, 4, 0

    Then the program pushes two elements 5 and 9 into the list: push 5 → 6, 3, 6, 4, 0, 5 → push 9 → 6, 3, 6, 4, 0, 5, 9


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int value;
    Node* next;
};

Node* create_node(int value);
Node* append(Node* head, int value);
//** -> variabile che contine l'indirizzo di un puntatore(potere vero)
Node* pop(Node** head);
Node* freeList(Node* head);
void llsprint(Node* head);


int main(int argc, char **argv)
{
    //fare prima una prova con valori hard coded per capire se worka
    Node* head = NULL;

    int N = atoi(argv[1]);
    for(int i = 0; i < N; i++)
    {
       head = append(head, atoi(argv[2 + i]));
    }
    llsprint(head);
    printf("\n");
    pop(&head);
    pop(&head);
    for(int j = 0; j < 2; j++)
    {
       head = append(head, atoi(argv[argc - 2 + j]));
    }
    llsprint(head);
    freeList(head);
    return 0;
}

Node* create_node(int value)
{
    //reference a head
    Node *result = malloc(sizeof(Node));

    result -> value = value; //che si vedrà con l'argv
    result -> next = NULL;

    return result;
}

Node* append(Node* head, int value)
{
    //ricorsiva, quindi checko se l'head è vuoto, quindi null
    if(!head)
        return create_node(value);
    head -> next = append(head -> next, value);
    return head;
}

Node* pop(Node** head) //pop in tail
{
    //allora ragioniamo
    //nessun elemento in lista
    if(!(*head))
        return NULL;
    //se la lista ha un solo elemento
    //dobbiamo ritornare quell elemento, e la lista = NULL
    if((*head) -> next == NULL)
    {
        Node* tmp = *head;
        *head = NULL;
        return tmp;
    } 

    //altra reference in modo tale da non modificare head
    Node* curr = *head;
    while(curr -> next -> next != NULL)
        curr = curr -> next;

    //sto al penultimo, e voglio eliminare l'ultimo
    Node* tmp = curr -> next;
    curr -> next = NULL;
    return tmp;
    
}

void llsprint(Node* head)
{
    //fin quando head non diventa nullo, printa
    if(head) 
    {
        printf("%d\n", head -> value);
        llsprint(head -> next); 
    }
}

void freeList(Node* head)
{
    //funzione ricorsiva fin quando non viene head == NULL
    //if che stoppa la funzione
    if(!head)
        return;
    //top down and bottom up
    //caso ricorsivo prima
    //bottom up
    //freeList(head -> next);
    //free(head);

    //pop down
    Node* tmp = head -> next;
    free(head);
    freeList(tmp);
}


