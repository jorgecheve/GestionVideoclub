#include "actor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 40 

void NuevoActor(Actor *ac, int totalAc) 
{
	char str[MAX_LENGTH];
	char format_str[MAX_LENGTH];

	printf("-Actor- (%d)\n", totalAc + 1); // +1 porque empieza por 0

	printf("Nombre: ");
	fgets(str, MAX_LENGTH,stdin);
	//clear_if_needed(str);
	sscanf(str, "%s",format_str);

	ac->nombre=(char*)malloc((strlen(format_str)+1)*sizeof(char));
	strcpy(ac->nombre, format_str);

	/*printf("Codigo del actor: ");
	fgets(str, MAX_LENGTH, stdin);		
	//clear_if_needed(str);
	sscanf(str, "%d", &ac->cod_Actor);*/	

	ac->cod_Actor=totalAc; //Para que se genere automaticamente sin que se repitan		

	
	printf("Edad: ");
	fgets(str, MAX_LENGTH, stdin);
	//clear_if_needed(str);
	sscanf(str, "%d", &ac->edad);

	printf("\n");

}