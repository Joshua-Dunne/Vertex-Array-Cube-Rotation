#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "Vector3.h"
#include "Matrix3.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	sf::Clock clock;
	sf::Time elapsed;

	float rotationAngle = 0.0f;
	int current{ 1 };

	// Vertices for one Triangle
	float vertices[24] = { -1.0f, -1.0f, 1.0f,
						1.0f, -1.0f, 1.0f,
						1.0f, 1.0f, 1.0f,
						-1.0f, 1.0f, 1.0f,

						-1.0f, -1.0f, -1.0f,
						1.0f, -1.0f, -1.0f,
						1.0f, 1.0f, -1.0f,
						-1.0f, 1.0f, -1.0f };

	// Colors for those vertices
	float colors[24] = { 1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f };

	// Index to be drawn
	unsigned int vertex_index[36] = { 2, 3, 0, 0, 1, 2, 7, 6, 5, 5, 4, 7, 6, 7, 3, 3, 2, 6, 1, 0, 4, 4, 5, 1, 
									  3, 7, 4, 4, 0, 3, 6, 2, 1, 1, 5, 6 };
};