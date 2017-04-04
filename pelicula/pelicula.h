#ifndef PELICULA_H_
#define PELICULA_H_




typedef struct {
	int cod_Peli;
	char *nombre;
	char *genero;
	int  ano;
	int duracion;
	int cod_ActorPr;	//Relaciona la peli con el protagonista.
	int cod_Local;  	//Para relacionar la peli con el local donde se encuentra

}Pelicula;

void NuevaPelicula(Pelicula *pe, int totalPe);

void BuscarPelicula();

void EliminarPelicula();


#endif