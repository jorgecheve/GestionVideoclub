#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "cliente2.hpp"

using namespace std;

	Cliente2::Cliente2(string nom, string doc)
	{
		
		this->nombre=nom;
		this->dni=doc;
	}
	string Cliente2::getDni()const
	{
		return dni;
	}
	ostream& operator<<(ostream& out, const Cliente2& p)			
	{
	out << "Nombre:" << p.nombre << ", DNI:" << p.dni;
	return out;
	}