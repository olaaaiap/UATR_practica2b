#pragma once
#include <list>
#include "Object3D.h"
class World
{
	//Clase que estará encargada de contener un escenario con objetos, cámaras...
	std::list<Object3D*> objects; //Lista de objetos que están en el escenario.

public:
	World();
	void addObject(Object3D* obj); //Método para añadir objetos a la lista de objetos de este mundo.
	void removeObject(Object3D* obj); //Método para borrar un objeto.
	size_t getNumObjects(); //Método que devuelve el tamaño de la lista de objetos.
	Object3D* getObject(size_t index); //Método que devuelve el objeto que se encuentra en la posición index de la lista.
	std::list<Object3D*>& getObjects(); //Método que devuelve por referencia la lista completa de objetos.
	void update(float deltaTime); //Método que actualiza el estado de este mundo. Llama al método step de cada uno de sus objetos pasándoles la variable deltaTime.
};

