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

#define N_CARROZZE 11

typedef struct carrozza Carrozza;
struct carrozza {
    int posti[100];
    Carrozza* next;
};

typedef struct treno Treno;
struct treno {
    Carrozza* head;
};

//funzione che crea il treno allocato dinamicamente
Treno* creaTreno(int carr);
//funzione che mi assegna i posti in maniera randomica
void assegna_posti_random(Carrozza* carro);
//funzione che crea la carrozza allocata dinamicamente
Carrozza* creaCarrozza();
//funzione per prenotare i posti
int prenota_posto(Treno* T, int carr);

int main(int argc, char** argv) 
{
    int carr = atoi(argv[1]);
    srand(time(NULL));

    Treno* T = creaTreno(carr);

    int posto_prenotato = prenota_posto(T, carr);
    if(posto_prenotato == -1) {
        printf("Carrozza piena\n");
    } else {
        printf("Posto prenotato: carrozza %d al posto %d\n", carr, posto_prenotato);
    }

    return 0;
}

Treno* creaTreno(int carr)
{
    Treno* T = malloc(sizeof(Treno));
    for(int i = 0; i < carr; i++)
        T -> head = creaCarrozza();

    return T;
}

void assegna_posti_random(Carrozza* carro)
{
    for(int i = 0; i < 100; i++) 
    {
        carro -> posti[i] = rand() % 2;
        printf("%d ", carro -> posti[i]);
    }
    printf("\n\n");
}

Carrozza* creaCarrozza()
{
    Carrozza* singola_carrozza = malloc(sizeof(Carrozza));

    assegna_posti_random(singola_carrozza);
    singola_carrozza -> next = NULL;

    return singola_carrozza;
}

int prenota_posto(Treno* T, int carr)
{
    Carrozza* carr_prenotata = T -> head;
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


