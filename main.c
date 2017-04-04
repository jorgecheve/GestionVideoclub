#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pelicula/pelicula.h"
#include "cliente/cliente.h"
#include "local/local.h"
#include "actor/actor.h"
#include "alquilar/alquilar.h"

#define MAX_LENGTH	5

int menu(void);


int main (void)
{
	Pelicula listaPelis[20]; //HAY QUE MIRAR COMO HACER PARA QUE SE PUEDA AÑADIR PELÍCULAS SIN LÍMITE
	int totalPelis=0;

	int option;
	do
	{

		option = menu();
		switch (option)
		{
			case 1: 
				NuevaPelicula(&listaPelis[totalPelis], totalPelis);

				printf("Pelicula: %s  Duracion: %d\n",listaPelis[totalPelis].nombre,  listaPelis[totalPelis].duracion);

				totalPelis++;
				break;
			case 2: 
				break;

			case 3: 
				break;
		}
	} while(option != 0);
	

	return 0;
}

int menu(void)
{
	char str[MAX_LENGTH];
	int len;
	int option;

	do {
		printf("\t1. Introducir pelicula\n");
		printf("\t2. Imprimir listado peliculas\n");
		printf("\t3. Peliculas más alquiladas\n");
		printf("\t4. Dar de alta cliente\n");
		
		printf("\n");
		printf("Seleccione una opción (q para salir): ");

		fgets(str, MAX_LENGTH, stdin);
		//clear_if_needed(str); 

		len = sscanf(str, "%d", &option);
		printf("\n");
	} while ((len == 0 && str[0] != 'q') || (len > 0 && (option > 4 || option < 1)));  //Cambiar esto cuando vayamos metiendo mas opciones

	return (str[0] == 'q')?0:option;
}

/**
	Esta funcion elimina los caracteres pendientes si es necesario
	Se usa junto con fgets para leer la entrada hasta cierta longitud

void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}
*/