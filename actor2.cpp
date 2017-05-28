#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "actor2.hpp"

using namespace std;

	Actor2::Actor2()
	{
		this->cod_Actor=-1;
		this->nombre="ini";
		this->edad=-1;
		
	}
	Actor2::Actor2(string nom, int cod_Actor,int edad)
	{
		
		this->nombre=nom;
		this->cod_Actor=cod_Actor;
		this->edad=edad;
	}
	string Actor2::getNombre()const
	{
		return nombre;
	}
	int Actor2::getCod()const
	{
		return cod_Actor;
	}
	ostream& operator<<(ostream& out, const Actor2& p)			
	{
	out << "Nombre:" << p.nombre <<"Edad: "<<p.edad <<", Codigo:" << p.cod_Actor;
	return out;
	}