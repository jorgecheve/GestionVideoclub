#ifndef PELICULA2_HPP_
#define PELICULA2_HPP_

using namespace std;

class Pelicula2
{
private: 
	int cod_Peli;
	string nombre;
	string genero;
	int  ano;
	int duracion;
	int cod_ActorPr;	
	int alquilada; //Será 0 cuando esté disponible y 1 cuando este alquilada.
public:
	Pelicula2();
	Pelicula2(int cod_Peli, string nombre, string genero, int ano, int duracion, int cod_ActorPr);
	void setCod_Peli(int codigo);
	int getCod_Peli()const;
	void setAlquilada(int codigo);
	int getAlquilada()const;
	void setCod_Actor(int codigo);
	int getCod_Actor()const;
	string getNombre()const;
	friend ostream& operator<<(ostream& out, const Pelicula2& p);
	friend void modificarFicheroPeli(vector<Pelicula2> &listaPe);
	
};



#endif