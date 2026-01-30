#pragma once
//#include "mapi/common.h"
#include "vertex_t.h"
#include <vector>

class Mesh3D
{

public:
	static inline int meshCounter = 0;

	int meshId;


	glm::vec4 colorRGBA; //Color básico de esta malla


	std::vector<vertex_t> vVertList; //Lista de vértices que forman la malla. Se agrupan de 3 en 3, representando los triángulos
	//std::vector<int> vertexIndexList;

	Mesh3D(); //Constructor por defecto

	int getMeshID(); //Devuelve el ID único de esta malla

	void addVertex(vertex_t	vertex);

	std::vector<vertex_t>* getVertList(); //Método para acceder a la lista de vértices almacenada.

};

