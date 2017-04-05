#ifndef PELICULA_H_
#define PELICULA_H_

#include "local.h"
#include "actor.h"

typedef struct {
	int cod_Peli;
	char *nombre;
	char *genero;
	int  ano;
	int duracion;
	int cod_ActorPr;	//Relaciona la peli con el protagonista.
	int cod_Local;  	//Para relacionar la peli con el local donde se encuentra

}Pelicula;

void NuevaPelicula(Pelicula *pe, int totalPe, Actor listaActor[], int totalActor, Local listaLocal[], int totalLocal);

void imprimirListaPel(Pelicula listaPel[], int totalPel);

//void BuscarPelicula(Pelicula listaPel[], int totalPel);

//void EliminarPelicula();


#endif