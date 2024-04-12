/*
    Scrivere un programma C che:
    1) Rappresenta un treno come una lista di 11 nodi (ogni nodo e' un record e rappresenta una carozza), 
    in cui un array di 100 elementi che rappresentano i posti
    (0 liberi, 1 occupato)

    2) Implementa le funzioni
    int prenota_posto(Treno T, int carrozza)
    trova le prima
    posizione libera nella carrozza corrispondente, la segna come occupata
    e restituisce la posizione come output

    3)nel main(), definisce un treno T, inizializza l'occupazione
    dei posti in modo casuale. Inoltre, prende da linea di comando il numero
    della carrozza in cui prenotare e stampa il posto prenotato nella carrozza.

    Input: 9
    Output: Posto prenotato nella carrozza 9, posto 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct carrozza Carrozza; //Nodo
struct carrozza {
    int posti[100];
    Carrozza* next;
};

typedef struct treno Treno;//treno con 11 carrozze
struct treno {
    Carrozza* head;
};

Carrozza* creaLista(Treno* T);
Carrozza* append(Carrozza* head, Carrozza* new);
int prenota_posto(Treno* T, int carrozza);

int main(int argc, char** argv)
{
    int carr = atoi(argv[1]);
    srand(time(NULL));

    Treno* T = malloc(sizeof(Treno));
    T -> head = NULL;
    Carrozza* mylist = creaLista(T);

    int carr_posto = prenota_posto(T, carr);
    if(carr_posto == -1) {
        printf("Carrozza piena\n");
    } else {
        printf("Carrozza: %d. Posto: %d\n", carr, carr_posto);
    }
   
    return 0;
}

Carrozza* creaLista(Treno* T)
{
    Carrozza* head = T -> head;
    for(int i = 0; i < 11; i++)
    {
        Carrozza* new = malloc(sizeof(Carrozza));
        for(int j = 0; j < 100; j++)
            new -> posti[j] = rand() % 2;
        new -> next = NULL;
        head = append(head, new);
    }

    return head;
}

Carrozza* append(Carrozza* head, Carrozza* new)
{
    if( !head )
        return new;
    head -> next = append(head -> next, new);

    return head;
}

int prenota_posto(Treno* T, int carr)
{
    int i = 0;
    Carrozza* carr_prenotata = T -> head;
    while(i <= carr)
    {
       carr_prenotata = carr_prenotata -> next;
       i++;
    }
    for(int j = 0; j < 100; j++)
    {
        if(carr_prenotata -> posti[j] == 0) {
            carr_prenotata -> posti[j] = 1;
            return j;
            break;
        }
    }

    return -1;
}