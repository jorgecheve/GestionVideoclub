#ifndef ACTOR2_HPP_
#define ACTOR2_HPP_

using namespace std;

class Actor2
{
private: 
	
	string nombre;
	int cod_Actor;
	int edad;
	
public:
	Actor2();
	Actor2(string nom, int cod_Actor,int edad);
	string getNombre()const;
	int getCod()const;
	friend ostream& operator<<(ostream& out, const Actor2& p);
};



#endif