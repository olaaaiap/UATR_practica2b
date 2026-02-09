#pragma once
//#include "GraphicsBackend.h"
#include "IRender.h"
#include "GL4Render.h"
#include "GLSLMaterial.h"

// tipos de backend gráficos disponibles
enum class GraphicsBackend
{
    GL1_0, // por ahora solo GL1.0
    GL4    // NUEVO backend moderno
};

enum class InputBackend
{
    None,
    Default,
};

// Forward declarations
class IRender;
class InputManager;
class Material;

class FactoryEngine
{
public:

    using GBackend = GraphicsBackend;
    using IBackend = InputBackend;

    // Backends seleccionados
    inline static GBackend selectedGraphicsBackend = GBackend::GL1_0;
    inline static IBackend selectedInputBackend = IBackend::None;

    // Gets/Sets
    static void SetGraphicsBackend(GBackend backend) noexcept { selectedGraphicsBackend = backend; }
    static GBackend GetGraphicsBackend() noexcept { return selectedGraphicsBackend; }

    static void SetInputBackend(IBackend backend) noexcept { selectedInputBackend = backend; }
    static IBackend GetInputBackend() noexcept { return selectedInputBackend; }

    // Factories
    static IRender* getNewRender();
    static InputManager* getNewInputManager();

    // NUEVO: crear materiales
    static Material* getNewMaterial();

    // utilidad
    static bool isClosed() noexcept;
};
