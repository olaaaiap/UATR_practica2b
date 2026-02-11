#define GLAD_BIN

#include "mapi/common.h"
#include "FactoryEngine.h"
#include "GL1Render.h"
#include "System.h"
#include "TrianguloRot.h"


int main(int argc, char** argv)
{
	FactoryEngine::SetGraphicsBackend(FactoryEngine::GBackend::GL4);

	//Inicializar el backend dela clase FactoryEngine
	IRender* render = FactoryEngine::getNewRender();
	InputManager* inputManager = FactoryEngine::getNewInputManager();

	System* system = new System();
	system->initSystem();

	TrianguloRot* triangulo = new TrianguloRot(); //Inicializar triangulo
	System::addObject(triangulo); //Añadir triangulo al sistema
	World* world = new World();
	world->addObject(triangulo); //Añadir triangulo al mundo
	System::SetWorld(world);
	system->mainLoop();

	return 0;

}