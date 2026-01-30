#include "TrianguloRot.h"

#include "GLFWInputManager.h"


TrianguloRot::TrianguloRot()
{
    //Crear objeto mesh3D
	Mesh3D* mesh = new Mesh3D();

    this->objectId = objectCounter++;

    //this->vertexList =
    //{
    //  {{ 0.5f, 0.5f,0.0f,1.0f}},//superior derecha
    //  {{-0.5f, 0.5f,0.0f,1.0f}},//superior izquierda
    //  {{-0.5f,-0.5f,0.0f,1.0f}},//inferior izquierda 
    //  {{ 0.5f,-0.5f,0.0f,1.0f}} //inferior derecha
    //}; //posiciones de vertices

    this->vertexList = {
      {{ 0.0f,  0.5f, 0.0f, 1.0f }}, // superior
      {{-0.5f, -0.5f, 0.0f, 1.0f }}, // abajo izquierda
      {{ 0.5f, -0.5f, 0.0f, 1.0f }}  // abajo derecha
    };
    this->vertexIndexList = { 0, 1, 2 };


    //this->vertexIndexList = { 2,1,0, 2,0,3 };

    for (auto v : this->vertexList) {
        mesh->addVertex(v);
	}

    this->setPosicion({ 0.0f,0.0f,0.0f,1.0f });
    this->setRotacion({ 0.0f,0.0f,0.0f,1.0f });
    this->setEscala({ 1.0f,1.0f,1.0f,1.0f });

}

void TrianguloRot::step(double deltaTime)
{
    //Actualizar el atributo de rotaciones, haciendolo girar sobre el eje Y a una velocidad de 90 grados por segundo.
    float velRot = 90.0f;

    // Modify rotation around Y axis
    glm::vec4 rot = this->GetRotacion();
    if (GLFWInputManager::keyboardState[GLFW_KEY_R])
        rot.y += static_cast<float>(velRot * deltaTime);
    if (GLFWInputManager::keyboardState[GLFW_KEY_T])
        rot.y -= static_cast<float>(velRot * deltaTime);

    this->setRotacion(rot);



    //Ademas, se comprobara si se ha pulsado la tecla E cada vez que se le invoque. si es asi, invocará la función exit de system
    if (GLFWInputManager::keyboardState[GLFW_KEY_E]) {
        std::exit(0);
	}
}
