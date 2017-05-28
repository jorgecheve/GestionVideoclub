#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "alquilar2.hpp"

using namespace std;

Alquilar2::Alquilar2(int cod_Peli, string dni)
{
	this->cod_Peli_Al=cod_Peli;
	this->dni_Clien=dni;
}
int Alquilar2:: getCod_Peli()const
{
	return cod_Peli_Al;
}
void escribirFicheroAlq(vector<Alquilar2> &listaAl)
{
	ofstream fout("Alquileres.txt");
		int i;
		for(i=0;i<listaAl.size();i++)
		{
			Alquilar2 &p=listaAl[i];
			fout<<p.cod_Peli_Al<<" #"<<p.dni_Clien<<endl;
		}
	fout.close();
}
ostream& operator<<(ostream& out, const Alquilar2& a)
{
	out << "Codigo peli:" << a.cod_Peli_Al << "; Dni:" << a.dni_Clien; 
	return out;
}