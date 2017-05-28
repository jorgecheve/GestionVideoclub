#ifndef CLIENTES_H_
#define CLIENTES_H_

#ifdef __cplusplus
extern "C"
{
#endif
	
typedef struct {
	char *nombre;
	char *dni;
	
}Cliente;

void nuevoClienteC(Cliente *clien, char *nombre, char *dni);
void escribirFicheroCliente(Cliente *c);	

#ifdef __cplusplus 
}

#endif

#endif