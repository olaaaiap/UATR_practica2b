#include "IObject.h"

Mesh3D* IObject::GetMesh()
{
	return this->mesh;
}

void IObject::SetMesh(Mesh3D* m)
{
	this->mesh = m;
}
