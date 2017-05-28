#ifndef ALQUILAR2_HPP_
#define ALQUILAR2_HPP_

using namespace std;

class Alquilar2
{
private: 
	string dni_Clien;
	int cod_Peli_Al;
public:

	Alquilar2(int cod_Peli, string dni);
	int getCod_Peli()const;
	friend void escribirFicheroAlq(vector<Alquilar2> &listaAl);

	friend ostream& operator<<(ostream& out, const Alquilar2& a);
	
	
};



#endif