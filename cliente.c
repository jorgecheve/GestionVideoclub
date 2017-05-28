#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_LENGTH 40 

void nuevoClienteC(Cliente *clien, char *nomb, char *doc)
{
	clien->nombre=(char*)malloc((strlen(nomb)+1)*sizeof(char));
	strcpy(clien->nombre, nomb);

	clien->dni=(char*)malloc((strlen(doc)+1)*sizeof(char));
	strcpy(clien->dni,doc);
}

void escribirFicheroCliente(Cliente *c)
{
	FILE *f=fopen("Clientes.txt","a");
	if (f==NULL)
	{
   		printf("Error al abrir el fichero\n");
	}

	fprintf(f, "%s #%s\n", c->nombre,c->dni);
	fclose(f);
}