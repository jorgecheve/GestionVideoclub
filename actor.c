#include "actor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_LENGTH 40 

void nuevoActorC(Actor *actor,char *nomb,int edad, int cod_Actor)
{
	actor->nombre=(char*)malloc((strlen(nomb)+1)*sizeof(char));
	strcpy(actor->nombre, nomb);
	
	actor->edad=edad;
	actor->cod_Actor=cod_Actor;
	
}
void escribirFicheroActor(Actor *p)
{
	FILE *f=fopen("Actores.txt","a");
	if (f==NULL)
	{
   		printf("Error al abrir el fichero\n");
	}

	fprintf(f, "%s #%d #%d\n",p->nombre, p->edad, p->cod_Actor);
	fclose(f);
}