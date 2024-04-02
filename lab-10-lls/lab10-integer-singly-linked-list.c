/*


Write a program lab10-integer-singly-linked-list.c 
which accepts the following arguments from the command line. 

The first argument is the number of integer elements n. The next n arguments refer to the input integers.

You are required to implement a singly linked list to store all integers. 
You are encouraged to use dynamic memory allocation in the program.

It would also be great if you can use function to design the solution.

The program then displays all numbers line by line.

Input

./lab10-integer-singly-linked-list 5 8 9 21 12 4

Output

8
9
21
12
4


*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int value;
    Node* next;
};

//init the function
Node* new_node(int value);
Node* push(Node* head, int value);
void llsprint(Node* head);


int main(int argc, char **argv)
{
    Node* head = NULL; //init the head to nil

    int N = argc - 2;
    for(int i = 0; i < N; i++)
    {
        head = push(head, atoi(argv[2 + i]));
    }

    llsprint(head);

    free(head);
    return 0;
}

Node* new_node(int value)
{
    //crei una reference a head
    Node *result = malloc(sizeof(Node)); //crei un'allocazione di memoria solo per la struct nuova

    result -> value = value; // il value che qui inserisco però è dato dall'argv
    result -> next = NULL;

    return result;
}

Node* push(Node* head, int value) 
{
    //check if the head is empty or if i got to the null part
    if(!head) //aggiungi un nuovo nodo
        return new_node(value);
    
    //qui devo dire che il next diventa il next prossimo ancora
    head -> next = push(head -> next, value);
    return head;
}

void llsprint(Node* head)
{
    //funzione ricorsiva sempre
    //fin quando non becco null, continua a chiamare la func
    if(head) {
        printf("%d\n", head -> value);
        llsprint(head -> next); //vai avanti
    }
}
