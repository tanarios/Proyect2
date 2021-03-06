#ifndef LISTAREPARTI_H
#define LISTAREPARTI_H
#include "NodoReparti.h"

class ListaReparti {
	
private:
	
	NodoReparti* ini;
	
public:
	
	ListaReparti();
	~ListaReparti();
	
	//Methods
	
	Repartidor *userR(string id);
	void agregar_reparti(Repartidor* repa);
	bool buscar_reparti(string);
	void eliminar_reparti();
	void mostrarlistaR();
	bool checkR(string num_cedula);
	NodoReparti *get_ini();
	
};

#endif
