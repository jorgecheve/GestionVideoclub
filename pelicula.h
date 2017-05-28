#ifndef PELICULA_H_
#define PELICULA_H_

#ifdef __cplusplus
extern "C"
{
#endif
	
	typedef struct {
	int cod_Peli;
	char *nombre;
	char *genero;
	int  ano;
	int duracion;
	int cod_ActorPr;	//Relaciona la peli con el protagonista.
}Pelicula;

void nuevaPeliC(Pelicula *peli, int id,char *nombre, int ano, int duracion, char *genero);
void escribirFicheroPeli(Pelicula *p);


#ifdef __cplusplus 
}

#endif

#endif