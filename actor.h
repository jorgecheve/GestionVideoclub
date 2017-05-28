#ifndef ACTOR_H_
#define ACTOR_H_

#ifdef __cplusplus
extern "C"
{
#endif
	
typedef struct {
	char *nombre;
	int  edad;
	int cod_Actor;
	
}Actor;

void nuevoActorC(Actor *actor,char *nombre,int edad, int cod_Actor);	
void escribirFicheroActor(Actor *p);
#ifdef __cplusplus 
}

#endif

#endif