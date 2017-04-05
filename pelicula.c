#include "pelicula.h"
#include "local.h"
#include "actor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LENGTH 40 

void NuevaPelicula(Pelicula *pe, int totalPe, Actor listaActor[], int totalActor, Local listaLocal[], int totalLocal) //RECIBIR LISTA DE LOCALES Y DE ACTORES.
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
	sscanf(str, "%d", &pe->cod_Peli);	//GUARDAMOS EN LA POSICION DEL ARRAY EL ATRIBUTO -en formato de numero- GUARDADO EN LA CADENA CON fgets

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
	
	int i;
	printf("Actores registrados, asigna un protagonista introduciento el codigo\n");
	for(i=0;i<totalActor;i++)
	{
		printf("Actor: %s  Codigo: %d\n", listaActor[i].nombre, listaActor[i].cod_Actor);
	}

	fgets(str, MAX_LENGTH, stdin);		
	//clear_if_needed(str);
	sscanf(str, "%d", &pe->cod_ActorPr);

	//IMPRIMIR LSITA DE LOCALES PARA QUE INTRODUZCAN EL LOCAL DONDE SE VA A ENCONTRAR LA PELICULA.

	printf("Locales registrados, asigna un local introduciento el codigo\n");
	for(i=0;i<totalLocal;i++)
	{
		printf("Direccion: %s  Codigo: %d\n", listaLocal[i].direccion,listaLocal[i].cod_local);
	}

	fgets(str, MAX_LENGTH, stdin);		
	//clear_if_needed(str);
	sscanf(str, "%d", &pe->cod_Local);
	
	//COMPROBAR SI EL CODIGO NO ES REPETIDO (OTRO MÉTODO)

	printf("\n");

}
 void imprimirListaPel(Pelicula listaPel[], int totalPel)
 {
 	int i;
 	for(i=0;i<totalPel;i++)
 	{
 		printf("Pelicula: %s Ano: %d Duracion: %d Genero: %s Codigo: %d Cod_Actor: %d Cod_Local: %d\n", 
 			listaPel[i].nombre, listaPel[i].ano, listaPel[i].duracion, listaPel[i].genero, listaPel[i].cod_Peli
 			, listaPel[i].cod_ActorPr, listaPel[i].cod_Local);  //FALTARIA EL PROTAGONISTA Y EL LOCAL
 		printf("----------------------------------------------\n");
 	}

 }

 void BuscarPelicula(Pelicula listaPel[], int totalPel)
 {
 	int i;
 	printf("Introduce el titulo de la pelicula: " );
	fgets(str, MAX_LENGTH, stdin);		//GUARDAMOS EN LA CADENA CON LONCITUD MAX. LO QUE INTRODUCE EL USUARIO
	//clear_if_needed(str);
	sscanf(str, "%d", format_str);
	for(i=0;i<totalPel;i++)
	{
		if(strcmp(str, listaPel[i]) == 0)
		{
			printf("Película encontrada: %s Ano: %d Duracion: %d Genero: %s Codigo: %d Cod_Actor: %d Cod_Local: %d\n", 
 			listaPel[i].nombre, listaPel[i].ano, listaPel[i].duracion, listaPel[i].genero, listaPel[i].cod_Peli
 			, listaPel[i].cod_ActorPr, listaPel[i].cod_Local);
		}
		else
		{
			printf("No existe esa pelicula")
		}
	}
	
 }