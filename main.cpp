#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "pelicula.h"
#include "pelicula2.hpp"
#include "cliente.h"
#include "cliente2.hpp"
#include "alquilar2.hpp"
#include "actor.h"
#include "actor2.hpp"
using namespace std;


#define MAX_LENGTH	100

int menu(void);
void nuevaPeli(vector<Pelicula2> &listaPe);
void nuevoCL(vector<Cliente2> &listaCl);
void alquilarPeli(vector<Pelicula2> &listaPe, vector<Cliente2> &listaCl, vector<Alquilar2> &listaAl);
void devolverPeli(vector<Pelicula2> &listaPe, vector<Alquilar2> &listaAl);
void nuevoAc(vector<Actor2> &listaAc);
void PeliculaActor(vector<Actor2> &listaAc, vector<Pelicula2> &listaPe);
void imprimirPelis(vector<Pelicula2> &listaPe, vector<Actor2> &listaAc);
void alquileresPorPeli(vector<Pelicula2> &listaPe, vector<Alquilar2> &listaAl);
void cogerPelisGuar(vector<Pelicula2> &listaPe);
void cogerActoresGuar(vector<Actor2> &listaAc);
void cogerClientesGuar(vector<Cliente2> &listaCl);
void cogerAlquileresGuar(vector<Alquilar2> &listaAl);
void clear_if_needed(char *str);

int main (void)
{
	vector<Pelicula2>listaPe;
	vector<Cliente2>listaCl;
	vector<Alquilar2>listaAl;
	vector<Actor2> listaAc;
	cogerPelisGuar(listaPe);  //PARA COGER LOS DATOS QUE HABIA GUARDADOS DE PELIS
	cogerActoresGuar(listaAc);
	cogerClientesGuar(listaCl);
	cogerAlquileresGuar(listaAl);


	int option;
	do
	{
		option = menu();
		switch (option)
		{
			case 1: 
				nuevaPeli(listaPe);
				

				break;
			case 2: 
				nuevoCL(listaCl);

				break;
			
			case 3:
				alquilarPeli(listaPe, listaCl, listaAl);

				break;
			
			case 4: 
				devolverPeli(listaPe, listaAl);
				break;
			
			case 5:
				nuevoAc(listaAc);
				break;

			case 6:
				PeliculaActor(listaAc,listaPe);
				break;
			
			case 7: 
				imprimirPelis(listaPe,listaAc);
				break;

			case 8:
				alquileresPorPeli(listaPe, listaAl);
				break;		
		}
	} while(option != 0);
	

	return 0;
}

int menu(void)
{
	char str[5];
	int len;
	int option;

	do {
		printf("\t1. Introducir pelicula\n");
		printf("\t2. Introducir cliente\n");
		printf("\t3. Realizar alquiler\n");
		printf("\t4. Devolver pelicula\n");
		printf("\t5. Introducir actor\n");
		printf("\t6. Asignar protagonista a pelicula\n");
		printf("\t7. Imprimir listado de peliculas\n");
		printf("\t8. Numero de alquileres por pelicula\n");

	
		printf("\n");
		printf("Seleccione una opcion (q para salir): ");

		fgets(str, 5, stdin);
		clear_if_needed(str); 

		len = sscanf(str, "%d", &option);
		printf("\n");

	} while ((len == 0 && str[0] != 'q') || (len > 0 && (option > 8 || option < 1)));  //Cambiar esto cuando vayamos metiendo mas opciones
	
	return (str[0] == 'q')?0:option;
}

void nuevaPeli(vector<Pelicula2> &listaPe)
{	//UTILIZAMOS C PARA RECOGER LOS DATOS PARA DEMOSTRAR QUE SABEMOS UTILIZARLO, EN OTROS METODOS USARMOS C++ DE FORMA MAS SIMPLE

	printf("-Pelicula-\n"); 

	printf("Nombre: ");

	char nom[MAX_LENGTH];

	fgets(nom, MAX_LENGTH,stdin);
	clear_if_needed(nom);
	sscanf(nom, "%[^\n]s",nom);

	printf("Ano: ");

	char ano[MAX_LENGTH];
	int year;
	
	fgets(ano, MAX_LENGTH, stdin);
	sscanf(ano, "%d", &year);

	printf("Duracion: ");

	char dur[MAX_LENGTH];
	int dura;
	
	fgets(dur, MAX_LENGTH, stdin);
	sscanf(dur, "%d", &dura);

	printf("Genero: ");

	char gen[MAX_LENGTH];

	fgets(gen, MAX_LENGTH,stdin);
	clear_if_needed(gen);
	sscanf(gen, "%[^\n]s",gen);
	
	Pelicula* p=(Pelicula*)malloc(sizeof(Pelicula));
	
	int id=listaPe.size()+1;

	nuevaPeliC(p, id, nom, year, dura, gen);

	escribirFicheroPeli(p);

	Pelicula2 peliculon(p->cod_Peli,p->nombre,p->genero,p->ano,p->duracion,-1);

	listaPe.push_back(peliculon);
	cout<<"Pelicula " << listaPe.size() <<" registrada correctamente"<<endl;

	cout<<listaPe[listaPe.size()-1]<<endl;
}

void nuevoCL(vector<Cliente2> &listaCl)
{
	string nombre;
	string dni;

	cout<< "Registro de cliente"<< endl;

	cout<<"Introduce el nombre"<<endl;
	
	getline(cin,nombre);

	bool repetido=false;
	do
	{
		repetido=false;
		cout<<"Introduce el DNI"<<endl;
		
		getline(cin, dni);
		
		int i;
		for(i=0;i<listaCl.size();i++)
		{
			if(dni==listaCl[i].getDni())
			{
				repetido=true;
			}
		}

		if(repetido==true)
		{
			cout<<"DNI ya en uso"<<endl;
		}
		
	}while(repetido==true);
	
	Cliente* c=(Cliente*)malloc(sizeof(Cliente));

	char *n=new char[nombre.length()+1];		//Convertimos los string en char para crear el struct de C
	strcpy(n, nombre.c_str());
	char *d=new char[dni.length()+1];
	strcpy(d, dni.c_str());

	nuevoClienteC(c, n, d);

	escribirFicheroCliente(c);
	delete[] n;
	delete[] d;

	Cliente2 cl(c->nombre, c->dni);
	listaCl.push_back(cl);

	cout<<cl<<endl;
	//cout<<cl.getDni<<endl;

}
void nuevoAc(vector<Actor2> &listaAc)
{
	printf("-Actor-\n"); 

	printf("Nombre: ");

	char nom[MAX_LENGTH];
	//char format_nom[MAX_LENGTH];

	fgets(nom, MAX_LENGTH,stdin);
	clear_if_needed(nom);
	sscanf(nom, "%[^\n]s",nom);

	printf("Edad: ");

	char dur[MAX_LENGTH];
	int edad;
	
	fgets(dur, MAX_LENGTH, stdin);
	sscanf(dur, "%d", &edad);

	int cod=listaAc.size()+1;
	
	Actor* p=(Actor*)malloc(sizeof(Actor));
	
	nuevoActorC(p,nom,edad,cod);

	escribirFicheroActor(p);

	Actor2 interprete(p->nombre,p->cod_Actor,p->edad);

	listaAc.push_back(interprete);
	cout<<"Actor " << listaAc.size() <<" registrado correctamente"<<endl;

	cout<<listaAc[listaAc.size()-1]<<endl;

}
void alquilarPeli(vector<Pelicula2> &listaPe, vector<Cliente2> &listaCl, vector<Alquilar2> &listaAl)
{
	cout<<"--Alquiler de pelicula--"<<endl;

	string introDni;
	bool correcto=false;

	while(correcto==false)
	{
		cout<<"Introduce tu DNI"<<endl;
		getline(cin, introDni);

		int i;
		for(i=0; i<listaCl.size();i++)
		{
			if(introDni==listaCl[i].getDni())
			{
				correcto=true;;
			}
		}

		if(correcto==false) cout<<"DNI no valido, introduzcalo de nuevo"<<endl;
	}

	cout<<"Bienvenido, elige la pelicula que quieres alquilar introduciendo el codigo"<<endl;

	int i; 
	for(i=0;i<listaPe.size();i++)
	{
		if(listaPe[i].getAlquilada()==0)
		{
			cout<<listaPe[i]<<endl;
		}
		
	}
	int intropeli=0;
	//getline(cin, intropeli);
	cin>>intropeli;
	cin.ignore();
	bool encon=false;
	int pos;
	for(i=0;i<listaPe.size();i++)
	{
		if(intropeli==listaPe[i].getCod_Peli() && listaPe[i].getAlquilada()==0)
		{
			encon=true;
			pos=i;
		}
	}
	if(encon==true)
	{
		Alquilar2 alquiler(listaPe[pos].getCod_Peli(), introDni);
		listaAl.push_back(alquiler);
		escribirFicheroAlq(listaAl);
		cout<<listaAl[listaAl.size()-1]<<endl;

		listaPe[pos].setAlquilada(1);
		modificarFicheroPeli(listaPe);
		cout<<"Alquiler completado con exito"<<endl;
	}else
	{
		cout<<"Pelicula no valida"<<endl;
	}

}

void devolverPeli(vector<Pelicula2> &listaPe, vector<Alquilar2> &listaAl)
{
	cout<<"--Devolucion de pelicula--"<<endl;

	cout<<"Lista de peliculas alquiladas"<<endl;
	int i;
	for(i=0;i<listaPe.size();i++)
	{
		if(listaPe[i].getAlquilada()==1)
		{
			cout<<listaPe[i]<<endl;
		}
	}
	cout<<endl<<"Introduce el codigo de la pelicula a devolver"<<endl;

	int intropeli=0;
	cin>>intropeli;
	cin.ignore();
	bool encon=false;
	int pos;
	for(i=0;i<listaPe.size();i++)
	{
		if(intropeli==listaPe[i].getCod_Peli() && listaPe[i].getAlquilada()==1)
		{
			encon=true;
			pos=i;
		}
	}
	if(encon==true)
	{
		listaPe[pos].setAlquilada(0);
		modificarFicheroPeli(listaPe);
		cout<<"Pelicula devuelta con exito"<<endl;
	}
	else{cout<<"Pelicula no valida"<<endl;}


}
void PeliculaActor(vector<Actor2> &listaAc, vector<Pelicula2> &listaPe)
{
	int Cod_act=0;
	int Cod_Peli=0;

	cout << "Escoga el actor deseado por su codigo" << endl;

	for(int i=0; i<listaAc.size();i++)
		cout <<listaAc[i]<< endl;

	cin>>Cod_act;
	cin.ignore();
	//COMPROBAR QUE ESTA BIEN INTRODUCIDO
	bool encontrado=false;
	for(int i=0;i<listaAc.size();i++)
	{
		if(listaAc[i].getCod()==Cod_act) encontrado=true;
	}
	bool encontrado2=false;
	if(encontrado==true)
	{
			cout << "Escoga la pelicula deseada por su codigo" << endl;

			for(int i=0; i<listaPe.size();i++)
				cout << listaPe[i] << endl;


			cin>>Cod_Peli;
			cin.ignore();
			for(int i=0; i<listaPe.size();i++)
			{
				if(listaPe[i].getCod_Peli()==Cod_Peli)
				{
					listaPe[i].setCod_Actor(Cod_act);
					encontrado2=true;
					cout << "El protagonista ha sido asignado correctamente" << endl;
					modificarFicheroPeli(listaPe);
				}
			}
			if(encontrado2==false) cout<<"Pelicula escogida no valida"<<endl;
	}else cout<<"Actor no valido"<<endl;

}

void alquileresPorPeli(vector<Pelicula2> &listaPe, vector<Alquilar2> &listaAl)
{
	int numAlquileres[listaPe.size()]={};

	for(int i=0;i<listaAl.size();i++)
	{
		numAlquileres[listaAl[i].getCod_Peli()-1]++;
		//cout<<numAlquileres[listaAl[i].getCod_Peli()-1]<<endl;
	}

	for(int i=0;i<listaPe.size();i++)
	{
		cout<<listaPe[i].getNombre()<<": "<<numAlquileres[i]<<" veces alquilada"<<endl;
	}

	
}


void imprimirPelis(vector<Pelicula2> &listaPe, vector<Actor2> &listaAc) //SE IMPRIMIRAN CON LOS DATOS DEL PROTAGONISTA
{
	for(int i=0;i<listaPe.size();i++)
	{
		string prota="Protagonista no asignado";
		for(int j=0;j<listaAc.size();j++)
		{
			if(listaPe[i].getCod_Actor()==listaAc[j].getCod())
			{
				prota="Protagonista: "+listaAc[j].getNombre();
			}
		}

		cout<<listaPe[i]<<", "<<prota<<endl<<endl;
	}
}

	void cogerPelisGuar(vector<Pelicula2> &listaPe)
	{
		FILE *f=fopen("Peliculas.txt","r");

		if(f==NULL)
		{
			printf("Aun no existe fichero de peliculas\n");
		}
		else
		{
			char cadena[MAX_LENGTH];
			int numLineas=0;
			while(fgets(cadena,MAX_LENGTH,f)!=NULL)
			{
				numLineas++;

				char nom[MAX_LENGTH]; char gen[MAX_LENGTH];
				int cod_P, year, dura, cod_Act, alquilada;
				sscanf(cadena,"%d #%100[0-9a-zA-Z ] #%100[0-9a-zA-Z ] #%d #%d #%d #%d\n", &cod_P, nom, gen, &year, &dura, &cod_Act,&alquilada);
				//cout<<cod_P<<" "<<nom<<" "<<gen<<" "<<year<<" "<<dura<<" "<<cod_Act<<" "<<cod_Loc<<" "<<alquilada<<endl;
				Pelicula2 peli(cod_P,nom,gen,year,dura,cod_Act);
				peli.setAlquilada(alquilada);
				listaPe.push_back(peli);

				cout<<listaPe[numLineas-1]<<endl;

			}
		}
		fclose(f);
	}

	void cogerActoresGuar(vector<Actor2> &listaAc)
	{
		FILE *f=fopen("Actores.txt","r");

		if(f==NULL)
		{
			printf("Aun no existe fichero de actores\n");
		}
		else
		{
			char cadena[MAX_LENGTH];
			int numLineas=0;
			while(fgets(cadena,MAX_LENGTH,f)!=NULL)
			{
				numLineas++;
				char nom[MAX_LENGTH]; 
				int cod_Act, edad;
				sscanf(cadena,"%100[0-9a-zA-Z ] #%d #%d\n", nom, &edad, &cod_Act);
				//cout<<cod_P<<" "<<nom<<" "<<gen<<" "<<year<<" "<<dura<<" "<<cod_Act<<" "<<cod_Loc<<" "<<alquilada<<endl;

				Actor2 a(nom,cod_Act, edad);

				listaAc.push_back(a);

				//cout<<listaAc[numLineas-1]<<endl;

			}
		}
		fclose(f);
	}

	void cogerClientesGuar(vector<Cliente2> &listaCl)
	{
		FILE *f=fopen("Clientes.txt","r");

		if(f==NULL)
		{
			printf("Aun no existe fichero clientes\n");
		}
		else
		{
			char cadena[MAX_LENGTH];
			int numLineas=0;
			while(fgets(cadena,MAX_LENGTH,f)!=NULL)
			{
				numLineas++;
				char nom[MAX_LENGTH]; 
				char dni[MAX_LENGTH];
				sscanf(cadena,"%100[0-9a-zA-Z ] #%100[0-9a-zA-Z ]\n", nom, dni);
				//cout<<cod_P<<" "<<nom<<" "<<gen<<" "<<year<<" "<<dura<<" "<<cod_Act<<" "<<cod_Loc<<" "<<alquilada<<endl;

				Cliente2 cl(nom,dni);

				listaCl.push_back(cl);

				//cout<<listaCl[numLineas-1]<<endl;

			}
		}
		fclose(f);
	}

	void cogerAlquileresGuar(vector<Alquilar2> &listaAl)
	{
		FILE *f=fopen("Alquileres.txt","r");

		if(f==NULL)
		{
			printf("Aun no existe fichero de alquileres\n");
		}
		else
		{
			char cadena[MAX_LENGTH];
			int numLineas=0;
			while(fgets(cadena,MAX_LENGTH,f)!=NULL)
			{
				numLineas++;
				char dni[MAX_LENGTH]; 
				int cod_P;
				sscanf(cadena,"%d #%100[0-9a-zA-Z ]\n", &cod_P, dni);
				//cout<<cod_P<<" "<<nom<<" "<<gen<<" "<<year<<" "<<dura<<" "<<cod_Act<<" "<<cod_Loc<<" "<<alquilada<<endl;

				Alquilar2 a(cod_P,dni);

				listaAl.push_back(a);

				//cout<<listaAl[numLineas-1]<<endl;

			}
		}
		fclose(f);
	}

	void clear_if_needed(char *str)
	{
		if (str[strlen(str) - 1] != '\n')
		{
			int c;    
	    	while ( (c = getchar()) != EOF && c != '\n');
	    }
	}