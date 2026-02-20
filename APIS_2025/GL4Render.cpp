#include "GL4Render.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

GL4Render::GL4Render(double w, double h): GL1Render(w, h){}

void GL4Render::setupObject(Object3D* obj)
{
	//if (!obj) return;
    
    boIDS_t bo = { 0,0,0 };

    //crear buffers objects
    glGenVertexArrays(1, &bo.id);
    glGenBuffers(1, &bo.vbo);
    glGenBuffers(1, &bo.idxbo);

    //copiar datos a GPU
    glBindVertexArray(bo.id); //activar lista de arrays
    glBindBuffer(0x8892, bo.vbo);//activar lista de vértices
    int numElements = obj->vertexList.size();
    glBufferData(GL_ARRAY_BUFFER, numElements * sizeof(vertex_t), obj->vertexList.data(), GL_STATIC_DRAW); //copiar vertices

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.idxbo);//activar lista de indices de vértices
    numElements = obj->vertexIndexList.size();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numElements * sizeof(unsigned int), obj->vertexIndexList.data(), GL_STATIC_DRAW); //copiar indices de vertices
   
    obj->GetMesh()->getMaterial()->getProgram()->setVertexAttrib("vPos", sizeof(vertex_t), (void*)offsetof(vertex_t, vPosition), 4, GL_FLOAT);

    //guardar ids de buffers
    bufferObjects[obj->objectId] = bo;
}

void GL4Render::removeObject(Object3D* obj)
{
    auto it = bufferObjects.find(obj->objectId);
    if (it != bufferObjects.end()) {
        boIDS_t bo = it->second;
        glDeleteBuffers(1, &bo.vbo);
        glDeleteBuffers(1, &bo.idxbo);
        glDeleteVertexArrays(1, &bo.id);
        bufferObjects.erase(it);
    }
}

void GL4Render::drawObjects(std::list<Object3D*>* objs)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);

    for (auto& obj : *objs) 
    {
        // Calcular matriz modelo
        auto model = obj->computeModelMatrix();

        // Guardar la matriz actual en la pila
        glPushMatrix();
        glLoadIdentity(); // Cargar matriz identidad
        glMultMatrixf(&model[0][0]); // Multiplicar por la matriz modelo del objeto

        // Activar buffers de datos
        auto bo = bufferObjects[obj->objectId];
        glBindVertexArray(bo.id);
        glBindBuffer(GL_ARRAY_BUFFER, bo.vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.idxbo);

        // Describir los buffers
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(4, GL_FLOAT, sizeof(vertex_t), (void*)offsetof(vertex_t, vPosition));


        drawObject(obj);
    }

    if (this->getWindow()) {
        glfwSwapBuffers(this->getWindow());
        glfwPollEvents();
    }
}

void GL4Render::drawObject(Object3D* obj)
{
    // Dibujar los elementos
    glDrawElements(GL_TRIANGLES, obj->vertexIndexList.size(), GL_UNSIGNED_INT, nullptr);

    // Restaurar la matriz anterior
    glPopMatrix();

    // Deshabilitar los estados de cliente
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}
