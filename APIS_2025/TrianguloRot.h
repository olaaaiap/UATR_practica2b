#pragma once
#include "Object3D.h"
#include <glm/glm.hpp>


class TrianguloRot : public Object3D
{
public:
    TrianguloRot();

    // Update por frame (deltaTime se usa para física/animación)
    void step(double deltaTime) override;
};

