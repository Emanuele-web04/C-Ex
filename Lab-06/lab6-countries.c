/*Write a program lab6 - get - a - country.c which gets the detail of a country from the command line as follows : -Name - Capital - Population(in million) - Size(in km2) The program can then print the information of the country line by line in the above order of information, for example : Input :

	. / lab6 - get - a - contry Ireland Dublin 4.99 84421
	Output :

	Ireland
	Dublin
	4.99 million people
	84421 km2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//nuovo tipo di variabile, che ha dei field interni, che possono essere richiamati chiamando la struttura madre
typedef struct country Country;

struct country {
	char name[30];
	char cap[30];
	float population;
	int size;
};

int main(int argc, char** argv) {

	Country c1;
	//c1 reference alla struct, gliela passo in strcpy
	strcpy(c1.name, argv[1]);
	//same for cap
	strcpy(c1.cap, argv[2]);
	//now for pop
	c1.population = atof(argv[3]);
	//for size
	c1.size = atoi(argv[4]);

	printf("\n%s\n", c1.name);
	printf("\n%s\n", c1.cap);
	printf("\n%.2f million people\n", c1.population);
	printf("\n%d km2\n", c1.size);

	return 0;
}