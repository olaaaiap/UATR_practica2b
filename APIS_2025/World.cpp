#include "World.h"
#include "System.h"

World::World()
{
}


void World::addObject(Object3D* obj)
{
	this->objects.push_back(obj);
}

void World::removeObject(Object3D* obj)
{
	this->objects.remove(obj);
}

size_t World::getNumObjects()
{
	return this->objects.size();
}

Object3D* World::getObject(size_t index)
{
	if (index >= this->objects.size()) return nullptr;

	std::list<Object3D*>::iterator iterador = objects.begin();
	std::advance(iterador, index);
	return *iterador;
}

std::list<Object3D*>& World::getObjects()
{
	return this->objects;
}

void World::update(float deltaTime)
{
	for (auto obj : this->objects) 
	{
		obj->step(deltaTime);
	}
}

