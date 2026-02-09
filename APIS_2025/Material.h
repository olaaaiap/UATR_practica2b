#pragma once
#include <vector>
#include <string>
#include "IRenderProgram.h"


class Material 
{
protected:
	IRenderProgram* program; // Puntero al programa de renderizado asociado a este material

public:
	IRenderProgram* getProgram() { return program; } // Método para obtener el programa de renderizado asociado a este material

	virtual void loadPrograms(const std::vector<std::string>& files) = 0; // Método virtual puro para cargar los programas de renderizado desde archivos
	virtual void prepare() = 0; // Método virtual puro para preparar el material antes de su uso (por ejemplo, configurar uniformes, texturas, etc.)
};
