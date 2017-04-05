#include "alquilar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pelicula.h"
#include "cliente.h"



#define MAX_LENGTH 40 

void NuevoAlquiler(Pelicula listaPelis[], int totalPelis, Cliente listaClientes[], int totalClientes, Alquilar *al, int totalAl)
{	
	char str[MAX_LENGTH];
	char format_str[MAX_LENGTH];

	printf("--ALQUILER--\n\n");
	printf("Introduce tu DNI\n");

	fgets(str, MAX_LENGTH, stdin);		
	//clear_if_needed(str);
	sscanf(str, "%s", format_str);

	strcpy(format_str,format_str);

	int i;
	int encontrado=-1;
	for(i=0;i<totalClientes;i++)
	{
		if(strcmp(format_str,listaClientes[i].dni)==0)
		{
			encontrado=i;
		}
	}
	if(encontrado==-1) printf("Cliente no encontrado\n");

	if(encontrado!=-1)
	{
		printf("Bienvenido, %s\n", listaClientes[encontrado].nombre);

		for(i=0; i<totalPelis;i++)
		{
			printf("%d- %s\n",i+1, listaPelis[i].nombre);
		}

		printf("ESCOGE UNA PELICULA PARA ALQUILAR INTRODUCIENDO SU NUMERO\n");

		int opcion;

		fgets(str, 4, stdin);
		//clear_if_needed(str);
		sscanf(str, "%d", &opcion);

		if(opcion>0 && opcion<=totalPelis)
		{
			al->dni_clien=(char*)malloc((strlen(listaClientes[encontrado].dni)+1)*sizeof(char));
			strcpy(al->dni_clien, listaClientes[encontrado].dni);

			al->cod_PeliAlq=listaPelis[opcion-1].cod_Peli;

			al->alquilada=1; //Como si fuera un boolean. 1 si no ha sido devuelto aún.
		}else
		{
			printf("Opcion escogida no valida\n");
		}

		//COMPROBAR SI LA PELICULA YA HABIA SIDO ALQUILADA


	}	
	
}