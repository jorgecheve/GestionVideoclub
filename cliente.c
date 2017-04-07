#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 40 

void NuevoCliente(Cliente *cl, int totalCl, Cliente lista[]) 
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

	int repetido=0;
	do
	{	
		repetido=0;
		printf("Dni del Cliente: ");
		fgets(str, MAX_LENGTH, stdin);		
		//clear_if_needed(str);
		//sscanf(str, "%d", &cl->cod_Actor);			
		sscanf(str, "%s",format_str);

		
		int i;
		for(i=0;i<totalCl;i++)
		{
			if(strcmp(lista[i].dni, format_str)==0)
			{
			repetido=1;

			}
		}
		if(repetido==0)
		{
		cl->dni=(char*)malloc((strlen(format_str)+1)*sizeof(char));
		strcpy(cl->dni, format_str);
		}else
		{
			printf("Dni ya en uso, introduzca otro\n");
		}
	}while(repetido!=0);
	


	printf("\n");

}