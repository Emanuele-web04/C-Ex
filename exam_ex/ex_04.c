
/*
Scrivere un programma C che:
1) Prende in input dalla linea di comando una parola
2) definisce un nodo Carattere come record che contine un
carattere e un punatore al nodo successivo
3) implmenta la funzione
Intero *crea_lista(char parola[]) (penso che qua il tipo e' sbagliato)
che prende in input una parola e
restituisce il puntatore alla testa di una lista 
di caratteri

input
  imprescindibile
output
  La lista e':i->m->p->r->e->s->c->i->n->d->i->b->i->l->e->NULL
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word Word;
struct word {
    char letter;
    Word* next;
};

Word* create_list(char parola[]);
Word* append_node(Word* head, Word* new);
void display(Word* head);
void llfree(Word* head);

int main(int argc, char **argv)
{
    //la prima cosa che devo fa è creare la lista
    //gli passo la parola
    char *word = *( argv + 1 );
    //poi per richiamarmi l'append, devo creare una variabile di tipo struct che mi gestisca il tutto
    Word* list = create_list(word); //perchè così gestisco i valori col puntatore

    display(list);
    llfree(list);

    return 0;
}

Word* create_list(char parola[])
{
    Word* head = NULL;
    for( int i = 0; i < strlen(parola); i++ )
    {
        Word* new = malloc(sizeof(Word));
        //per ogni lettera passagli la lettera nell'argv
        new -> letter = parola[i];
        new -> next = NULL;
        //magg scurdat di aggiungergli l'elemento
        head = append_node(head, new);
    }
    return head;
}

//quando creiamo una ll, dobbiamo appendere dei pezzi di memoria che dobbiamo allocare
Word* append_node(Word* head, Word* new) // work* head, int value
{
    if ( !head )
        return new; //ritorna un nuovo valore puntatore

    head -> next = append_node(head -> next, new);

    return head; //se non ritorno, sminchio; se non ritorno taglio la lista e ritorna null
}

void display(Word* head)
{
    if ( head ) //finchè l'head non è nullo devi printare e andare avanti
    {
        printf("%c -> ", head -> letter);
        display(head -> next);
    } else if ( head == NULL )
    {
        printf("NULL\n");
    }

}

void llfree(Word* head)
{
    //uso di variabile temporanea per non toccare head direttamente
    if ( !head )
        return;
    Word* linkNext = head -> next;
    free(head);
    llfree(linkNext);
}