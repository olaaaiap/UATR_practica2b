#include "GLSLMaterial.h"


void GLSLMaterial::addTriangle(glm::uint32 vldx1, glm::uint32 vldx2, glm::uint32 vldx3)
{
    if (vTriangleIdxlist == nullptr)
        vTriangleIdxlist = new std::vector<glm::uint32>();
    vTriangleIdxlist->push_back(vldx1);
    vTriangleIdxlist->push_back(vldx2);
	vTriangleIdxlist->push_back(vldx3);
}

void GLSLMaterial::loadPrograms(const std::vector<std::string>& files)
{
    if (!program) {
        program = new GLSLProgram();
    }

    for (auto& f : files)
        program->addProgram(f);

    program->linkProgram();
}

void GLSLMaterial::prepare()
{
    program->use();
}
