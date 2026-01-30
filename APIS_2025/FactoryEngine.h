#pragma once

// los tipos de backends disponibles
enum class GraphicsBackend 
{
	GL1_0, // por ahora solo GL1.0
};

enum class InputBackend
{
	None,
	Default, // placeholder; ampliar según necesidades
};

// lo declaro aquí, no sé si es mejor arriba
class IRender;
class InputManager;

class FactoryEngine
{
public:

	using GBackend = GraphicsBackend;
	using IBackend = InputBackend;

	// aqui los atrib. estáticos que te dice que backend está seleccionado
	inline static GBackend selectedGraphicsBackend = GBackend::GL1_0;
	inline static IBackend selectedInputBackend = IBackend::None;

	//Getters y setters
	static void SetGraphicsBackend(GBackend backend) noexcept { selectedGraphicsBackend = backend; }
	static GBackend GetGraphicsBackend() noexcept { return selectedGraphicsBackend; }

	static void SetInputBackend(IBackend backend) noexcept { selectedInputBackend = backend; }
	static IBackend GetInputBackend() noexcept { return selectedInputBackend; }

	//aqui se devuelven las instancias de los backends que escogemos
	// se liberan las instancias
	static IRender* getNewRender();
	static InputManager* getNewInputManager();

	static bool isClosed() noexcept; //si glfw está cerrado da true 
};