/*
16. Write a C program to remove duplicates from a single unsorted linked list.
Test Data and Expected Output :

Original Singly List:
1 2 3 3 4 
After removing duplicate elements from the said singly list:
1 2 3 4 

Original Singly List:
1 2 3 3 4 4 
After removing duplicate elements from the said singly list:
1 2 3 4 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int data;
    Node* next;
};

Node* createList(int argc, char** argv);
Node* appendNode(Node* head, Node* new);
void display(Node* head);
void displayIte(Node* head);

int main(int argc, char** argv)
{
    Node* myList = createList(argc, argv);

    displayIte(myList);
    printf("\n");
    display(myList);
    printf("\n");
    return 0;
}

Node* createList(int argc, char** argv)
{
    Node* head = NULL;
    for(int i = 0; i < argc - 1; i++)
    {
        Node* new = malloc(sizeof(Node));
        new -> data = atoi(argv[i + 1]);
        new -> next = NULL;
        head = appendNode(head, new);
    }
    return head;
}

Node* appendNode(Node* head, Node* new)
{
    if( !head )
        return new;

    head -> next = appendNode(head -> next, new);
    return head;
}

void displayIte(Node* head)
{
    Node* curr = NULL;
    while(head)
    {
        printf("%d ", head -> data);
        curr = head -> next;
        while(curr && (head -> data == curr -> data))
        {
            curr = curr -> next;
        }
        head -> next = curr;
        head = head -> next;
    }
}

void display(Node* head)
{
    if ( head ) {
        printf("%d ", head -> data);
        display(head -> next);
    }
}