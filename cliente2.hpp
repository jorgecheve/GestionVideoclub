#ifndef CLIENTE2_HPP_
#define CLIENTE2_HPP_

using namespace std;

class Cliente2
{
private: 
	
	string nombre;
	string dni;
	
public:

	Cliente2(string nom, string doc);
	string getDni()const;
	friend ostream& operator<<(ostream& out, const Cliente2& p);
};



#endif