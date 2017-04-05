#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pelicula.h"
#include "cliente.h"
#include "local.h"
#include "actor.h"
#include "alquilar.h"

#define MAX_LENGTH	5

int menu(void);


int main (void)
{
	Pelicula listaPelis[20]; //HAY QUE MIRAR COMO HACER PARA QUE SE PUEDA AÑADIR PELÍCULAS SIN LÍMITE
	int totalPelis=0;

	Actor listaActor[20]; 
	int totalActor=0;

	Local listaLocal[20];
	int totalLocal=0;

	Cliente listaCliente[20];
	int totalCliente=0;

	Alquilar listaAlquiler[20];
	int totalAlquiler=0;

	int option;
	do
	{

		option = menu();
		switch (option)
		{
			case 1: 
				NuevaPelicula(&listaPelis[totalPelis], totalPelis,listaActor,totalActor,listaLocal, totalLocal);
				//Pelicula *pe, int totalPe, Actor listaActor[], int totalActor, Local listaLocal[], int totalLocal
				//printf("Pelicula: %s  Duracion: %d\n",listaPelis[totalPelis].nombre,  listaPelis[totalPelis].duracion);
				totalPelis++;

				break;
			case 2: 
				NuevoActor(&listaActor[totalActor], totalActor);
				//printf("Actor: %s  Codigo: %d\n",listaActor[totalActor].nombre,  listaActor[totalActor].cod_Actor);
				totalActor++;
				break;
			case 3:
				NuevoLocal(&listaLocal[totalLocal],totalLocal);
				totalLocal++;
				break;
			case 4: 
				imprimirListaPel(listaPelis, totalPelis);
				break;

			case 5:
				//BuscarPelicula(listaPelis, totalPelis);
				break;

			case 6: 
				NuevoCliente(&listaCliente[totalCliente], totalCliente);
				printf("%s\n", listaCliente[totalCliente].dni );
				totalCliente++;
				break;
			case 7:
				NuevoAlquiler(listaPelis,totalPelis,listaCliente,totalCliente,&listaAlquiler[totalAlquiler],totalAlquiler);
				//printf("%s; %d \n", listaAlquiler[totalAlquiler].dni_clien, listaAlquiler[totalAlquiler].cod_PeliAlq);
				totalAlquiler++;
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
		printf("\t2. Introducir actor\n");
		printf("\t3. Introducir local\n");
		printf("\t4. Imprimir listado peliculas\n");
		printf("\t5. Buscar pelicula\n");
		printf("\t6. Dar de alta cliente\n");
		printf("\t7. Alquilar pelicula\n");

		
		printf("\n");
		printf("Seleccione una opcion (q para salir): ");

		fgets(str, MAX_LENGTH, stdin);
		//clear_if_needed(str); 

		len = sscanf(str, "%d", &option);
		printf("\n");

	} while ((len == 0 && str[0] != 'q') || (len > 0 && (option > 7 || option < 1)));  //Cambiar esto cuando vayamos metiendo mas opciones



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