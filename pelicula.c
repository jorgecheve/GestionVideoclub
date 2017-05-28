#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pelicula.h"

#define MAX_LENGTH 40 

void nuevaPeliC(Pelicula *peli, int id,char *nombre, int ano, int duracion, char *genero)
{
	peli->nombre=(char*)malloc((strlen(nombre)+1)*sizeof(char));
	strcpy(peli->nombre, nombre);

	peli->cod_Peli=id;
	peli->ano=ano;
	peli->duracion=duracion;
	
	peli->genero=(char*)malloc((strlen(genero)+1)*sizeof(char));
	strcpy(peli->genero, genero);

	peli->cod_ActorPr=-1;
}

void escribirFicheroPeli(Pelicula *p)
{
	FILE *f=fopen("Peliculas.txt","a");
	if (f==NULL)
	{
   		printf("Error al abrir el fichero\n");
	}

	//fprintf(f, "%d , %s , %s , %d , %d , %d , %d , %d\n", p->cod_Peli,p->nombre,p->genero,p->ano,p->duracion,p->cod_ActorPr,p->cod_Local,0); //Este último 0 es para disponibilidad, por defecto será 0 (no alquilada).
	fprintf(f, "%d #%s #%s #%d #%d #%d #%d\n", p->cod_Peli,p->nombre,p->genero,p->ano,p->duracion,p->cod_ActorPr,0);
	fclose(f);
}
