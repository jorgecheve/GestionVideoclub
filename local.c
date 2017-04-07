#include "local.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 40 

void NuevoLocal(Local *lo, int totalLo)
{
	char str[MAX_LENGTH];
	char format_str[MAX_LENGTH];

	printf("-Local- (%d)\n", totalLo + 1); // +1 porque empieza por 0

	printf("Direccion: ");
	fgets(str, MAX_LENGTH,stdin);
	//clear_if_needed(str);
	sscanf(str, "%s",format_str);

	lo->direccion=(char*)malloc((strlen(format_str)+1)*sizeof(char));
	strcpy(lo->direccion, format_str);

	/*printf("Codigo del local: ");
	fgets(str, MAX_LENGTH, stdin);		
	//clear_if_needed(str);
	sscanf(str, "%d", &lo->cod_local);	*/		
	lo->cod_local=totalLo;

	printf("\n");
}