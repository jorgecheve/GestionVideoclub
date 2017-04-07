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

	/*printf("Codigo de pelicula: ");
	fgets(str, MAX_LENGTH, stdin);	 
	//clear_if_needed(str);*/
	//sscanf(totalPe, "%d", &pe->cod_Peli);	//El codigo sera determinara automaticamente, por el tamaño del array
	pe->cod_Peli=totalPe;

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
	if(totalActor>0)
	{
		int i;
		printf("Actores registrados, asigna un protagonista introduciento el codigo\n");
		for(i=0;i<totalActor;i++)
		{
		printf("Actor: %s  Codigo: %d\n", listaActor[i].nombre, listaActor[i].cod_Actor);
		}

		fgets(str, MAX_LENGTH, stdin);		
		//clear_if_needed(str);
		sscanf(str, "%d", &pe->cod_ActorPr);
	}
	else{
		pe->cod_ActorPr=-1;
	}
	

	//IMPRIMIR LSITA DE LOCALES PARA QUE INTRODUZCAN EL LOCAL DONDE SE VA A ENCONTRAR LA PELICULA.
	if(totalLocal>0)
	{
		int i;
		printf("Locales registrados, asigna un local introduciento el codigo\n");
		for(i=0;i<totalLocal;i++)
		{
		printf("Direccion: %s  Codigo: %d\n", listaLocal[i].direccion,listaLocal[i].cod_local);
		}

	fgets(str, MAX_LENGTH, stdin);		
	//clear_if_needed(str);
	sscanf(str, "%d", &pe->cod_Local);
	}else{
		pe->cod_Local=-1;
	}
	
	
	//COMPROBAR SI EL CODIGO NO ES REPETIDO (OTRO MÉTODO)



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

 /*void EliminarPelicula(Pelicula listaPel[], int totalPel)
 {
 	char str[MAX_LENGTH];
 	int i;
 	for(i=0;i<totalPel;i++)
 	{
 		printf("Pelicula: %s Ano: %d Duracion: %d Genero: %s Codigo: %d Cod_Actor: %d Cod_Local: %d\n", 
 			listaPel[i].nombre, listaPel[i].ano, listaPel[i].duracion, listaPel[i].genero, listaPel[i].cod_Peli
 			, listaPel[i].cod_ActorPr, listaPel[i].cod_Local);  //FALTARIA EL PROTAGONISTA Y EL LOCAL
 		printf("----------------------------------------------\n");
 	}

 	printf("Introduce codigo de pelicula a eliminar"  );
	fgets(str, MAX_LENGTH, stdin);		
	//sscanf(str, "%d", &pe->cod_Peli);// poner aqui para eliminar

 }*/


 void BuscarPelicula(Pelicula listaPel[], int totalPel)
 {
 	int i;

 	char str[MAX_LENGTH];
	char format_str[MAX_LENGTH];
	

 	printf("Introduce el titulo de la pelicula: " );
	fgets(str, MAX_LENGTH, stdin);		//GUARDAMOS EN LA CADENA CON LONCITUD MAX. LO QUE INTRODUCE EL USUARIO
	//clear_if_needed(str);
	sscanf(str, "%s", format_str);

	printf("%s\n", format_str);

	int encontrada=0;

	for(i=0;i<totalPel;i++)
	{
		
		if(strcmp(format_str, listaPel[i].nombre) == 0)
		{
			printf("Pelicula encontrada: %s \n Ano: %d Duracion: %d Genero: %s Codigo: %d Cod_Actor: %d Cod_Local: %d\n", 
 			listaPel[i].nombre, listaPel[i].ano, listaPel[i].duracion, listaPel[i].genero, listaPel[i].cod_Peli
 			, listaPel[i].cod_ActorPr, listaPel[i].cod_Local);

 			encontrada=1;
		}		
	}
	if(encontrada==0){
		printf("No disponemos de esa pelicula\n");
	}
}