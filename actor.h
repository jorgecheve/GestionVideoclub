#ifndef ACTOR_H_
#define ACTOR_H_

typedef struct {
	char *nombre;
	int  edad;
	int cod_Actor;
}Actor;

void NuevoActor(Actor *ac, int totalAc);

void EditarActor();

#endif