#pragma once
#include "IEntity.h"
#include "Mesh3D.h"


class IObject : public IEntity
{

	Mesh3D* mesh; //Puntero de la malla que almacenará la geometría de este objeto.
public:
	static inline int objectCounter = 0;
	int objectId;
	int tipo;

	std::vector<vertex_t> vertexList;
	std::vector<int> vertexIndexList;

	Mesh3D* GetMesh();
	void SetMesh(Mesh3D* m);
	
	//mesh = m;
	

	virtual void loadDataFromFile(std::string file) = 0;
};

