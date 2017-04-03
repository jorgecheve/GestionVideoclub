#ifndef ALQUILAR_H_
#define ALQUILAR_H_

typedef struct {
	char *dni_clien;	//Relaciona las peliculas con el cliente que las alquila.
	int  cod_PeliAlq;
	int alquilada;  //Para usarla como un boolean. 1 si está alquilada, 0 si ya se ha finalizado el alquiler.
}Alquilar;

void NuevoAlquiler();
void DevolverPeli();

#endif