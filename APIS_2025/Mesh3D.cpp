#include "Mesh3D.h"

Mesh3D::Mesh3D()
{
	this->meshId = meshCounter++;

	//Triangulo
	this->vVertList =
	{
		{ { 0.0f,  0.5f, 0.0f, 1.0f } },  // vértice superior
		{ { -0.5f, -0.5f, 0.0f, 1.0f } }, // inferior izquierda
		{ { 0.5f, -0.5f, 0.0f, 1.0f } }   // inferior derecha
	};

	this->colorRGBA = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f); //Rojo

}

int Mesh3D::getMeshID()
{
	return this->meshId;
}

void Mesh3D::addVertex(vertex_t vertex)
{
	this->vVertList.push_back(vertex);
}

std::vector<vertex_t>* Mesh3D::getVertList()
{
	return nullptr;
}