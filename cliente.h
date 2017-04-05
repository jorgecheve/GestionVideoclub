#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct {
	char *nombre;
	char *dni;
	
}Cliente;

void NuevoCliente(Cliente *cl, int TotalCl);

void EditarCliente();

#endif
