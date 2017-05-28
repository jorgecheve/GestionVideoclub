#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include "pelicula2.hpp"

using namespace std;

	Pelicula2::Pelicula2()
	{
		this->cod_Peli=-1;
		this->nombre="ini";
		this->genero="ini";
		this->ano=-1;
		this->duracion=-1;
		this->cod_ActorPr=-1;

		this->alquilada=0;
	}
	Pelicula2::Pelicula2(int cod_Peli, string nombre, string genero, int ano, int duracion, int cod_ActorPr)
	{
		this->cod_Peli=cod_Peli;
		this->nombre=nombre;
		this->genero=genero;
		this->ano=ano;
		this->duracion=duracion;
		this->cod_ActorPr=cod_ActorPr;

		this->alquilada=0;			//LO PONEMOS POR DEFECTO A 0.(peli disponible)

	}
	
	void Pelicula2::setCod_Peli(int codigo)
	{
		this->cod_Peli=codigo;
	} 
	int Pelicula2::getCod_Peli() const	//Al declarar un método de una clase como const indicamos que NO va a modificar el objeto this correspondiente
	{
		return cod_Peli;
	}
	void Pelicula2::setAlquilada(int codigo)
	{
		this->alquilada=codigo;
	} 
	int Pelicula2::getAlquilada() const	
	{
		return alquilada;
	}
	
	void Pelicula2::setCod_Actor(int codigo)
	{
		this->cod_ActorPr=codigo;
	} 
	int Pelicula2::getCod_Actor()const
	{
		return cod_ActorPr;
	}
	string Pelicula2::getNombre()const
	{
		return nombre;
	}
	void modificarFicheroPeli(vector<Pelicula2> &listaPe)  //Borra lo que habia, y lo llena con toda la lista
	{														//Esta vez escribimos en el fichero de otra manera.(C++) 
		ofstream fout("Peliculas.txt");
		int i;
		for(i=0;i<listaPe.size();i++)
		{
			Pelicula2 &p=listaPe[i];
			fout<<p.cod_Peli<<" #"<<p.nombre<<" #"<<p.genero<<" #"<<p.ano<<" #"<<p.duracion<<" #"<<p.cod_ActorPr<<" #"<<p.alquilada<<endl;
		}
		
		fout.close();
	}

	ostream& operator<<(ostream& out, const Pelicula2& p)			
	{	
		string alq;
		if(p.alquilada==0)
		{
			alq="Disponible";
		}else
		{
			alq="No disponible";
		}
	out << "Codigo:" << p.cod_Peli << "/ Nombre:" << p.nombre << ", Genero:" << p.genero <<", Ano:"<<p.ano<<", Duracion:"<<p.duracion<<", "<< alq;
	return out;
	}

