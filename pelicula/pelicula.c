#include "pelicula.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 40 

void NuevaPelicula(Pelicula *pe, int totalPe) //RECIBIR LISTA DE LOCALES Y DE ACTORES.
{
	char str[MAX_LENGTH];
	char format_str[MAX_LENGTH];

	printf("-Pelicula- (%d)\n", totalPe + 1); // +1 porque empieza por 0

	printf("Nombre: ");
	fgets(str, MAX_LENGTH,stdin);
	//clear_if_needed(str);
	sscanf(str, "%s",format_str);

	pe->nombre=(char*)malloc((strlen(format_str)+1)*sizeof(char));
	strcpy(pe->nombre, format_str); //asignamos el valor a la pelicula añadiendole el /0 en la ultima posicion.

	printf("Codigo de pelicula: ");
	fgets(str, MAX_LENGTH, stdin);		//GUARDAMOS EN LA CADENA CON LONCITUD MAX. LO QUE INTRODUCE EL USUARIO
	//clear_if_needed(str);
	sscanf(str, "%d", &pe->cod_Peli);			//GUARDAMOS EN LA POSICION DEL ARRAY EL ATRIBUTO -en formato de numero- GUARDADO EN LA CADENA CON fgets

	printf("Ano: ");
	fgets(str, MAX_LENGTH, stdin);
	//clear_if_needed(str);
	sscanf(str, "%d", &pe->ano);

	printf("Duracion: ");
	fgets(str, MAX_LENGTH, stdin);
	//clear_if_needed(str);
	sscanf(str, "%d", &pe->duracion);

	printf("Genero: ");
	fgets(str, MAX_LENGTH,stdin);
	//clear_if_needed(str);
	sscanf(str, "%s",format_str);
	pe->genero=(char*)malloc((strlen(format_str)+1)*sizeof(char));
	strcpy(pe->genero, format_str);

	//IMPRIMIR LISTA DE ACTORES PRINCIPALES PARA QUE INTRODUZCAN EL CÓDIGO.
	
	//IMPRIMIR LSITA DE LOCALES PARA QUE INTRODUZCAN EL LOCAL DONDE SE VA A ENCONTRAR LA PELICULA.

	printf("\n");

}