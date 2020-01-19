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

	Vector3 points[8] = {
		{ vertices[0], vertices[1], vertices[2]},
		{ vertices[3], vertices[4], vertices[5]},
		{ vertices[6], vertices[7], vertices[8]},
		{ vertices[9], vertices[10], vertices[11]},
		{ vertices[12], vertices[13], vertices[14]},
		{ vertices[15], vertices[16], vertices[17]},
		{ vertices[18], vertices[19], vertices[20]},
		{ vertices[21], vertices[22], vertices[23]},
	};

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
	unsigned int vertex_index[36] = { 
		2, 3, 0, 
		0, 1, 2, 
		7, 6, 5, 
		5, 4, 7, 
		6, 7, 3, 
		3, 2, 6, 
		1, 0, 4, 
		4, 5, 1, 
		3, 7, 4, 
		4, 0, 3, 
		6, 2, 1, 
		1, 5, 6 };
};