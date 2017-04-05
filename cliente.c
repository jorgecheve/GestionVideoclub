#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 40 

void NuevoCliente(Cliente *cl, int totalCl) 
{
	char str[MAX_LENGTH];
	char format_str[MAX_LENGTH];

	printf("-Cliente- (%d)\n", totalCl + 1); // +1 porque empieza por 0

	printf("Nombre: ");
	fgets(str, MAX_LENGTH,stdin);
	//clear_if_needed(str);
	sscanf(str, "%s",format_str);

	cl->nombre=(char*)malloc((strlen(format_str)+1)*sizeof(char));
	strcpy(cl->nombre, format_str);

	printf("Dni del Cliente: ");
	fgets(str, MAX_LENGTH, stdin);		
	//clear_if_needed(str);
	//sscanf(str, "%d", &cl->cod_Actor);			
	sscanf(str, "%s",format_str);

	cl->dni=(char*)malloc((strlen(format_str)+1)*sizeof(char));
	strcpy(cl->dni, format_str);
	
/*printf("Edad: ");
	fgets(str, MAX_LENGTH, stdin);
	//clear_if_needed(str);
	sscanf(str, "%d", &ac->edad);
	*/

	printf("\n");

}