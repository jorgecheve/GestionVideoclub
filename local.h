#ifndef LOCAL_H_
#define LOCAL_H_

typedef struct {
	int cod_local;
	char *direccion;
	
} Local;

void NuevoLocal(Local *lo, int totalLo);

#endif