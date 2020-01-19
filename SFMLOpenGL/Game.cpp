#include <Game.h>

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}

void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}

		}
			update();
			render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	glTranslatef(0, 0, -8.0f);
	glEnable(GL_CULL_FACE);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	Matrix3 usableMatrix;
	int reverse{ 1 };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
	{
		reverse = -1; // go backwards on rotations if shift is held
	}
	else
	{
		reverse = 1;
	}

	// Rotating

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{

		usableMatrix = usableMatrix.RotationZ(0.6 * reverse);

		for (int index = 0; index < 8; index++)
		{
			points[index] = usableMatrix * points[index];
		}

		for (int index = 0; index < 24; index += 3)
		{
			if (index != 0)
			{
				vertices[index] = points[index / 3].getX();
				vertices[index + 1] = points[index / 3].getY();
				vertices[index + 2] = points[index / 3].getZ();
			}
			else
			{
				vertices[index] = points[index].getX();
				vertices[index + 1] = points[index].getY();
				vertices[index + 2] = points[index].getZ();
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		usableMatrix = usableMatrix.RotationX(0.6 * reverse);

		for (int index = 0; index < 8; index++)
		{
			points[index] = usableMatrix * points[index];
		}

		for (int index = 0; index < 24; index += 3)
		{
			if (index != 0)
			{
				vertices[index] = points[index / 3].getX();
				vertices[index + 1] = points[index / 3].getY();
				vertices[index + 2] = points[index / 3].getZ();
			}
			else
			{
				vertices[index] = points[index].getX();
				vertices[index + 1] = points[index].getY();
				vertices[index + 2] = points[index].getZ();
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		usableMatrix = usableMatrix.RotationY(0.6 * reverse);

		for (int index = 0; index < 8; index++)
		{
			points[index] = usableMatrix * points[index];
		}

		for (int index = 0; index < 24; index += 3)
		{
			if (index != 0)
			{
				vertices[index] = points[index / 3].getX();
				vertices[index + 1] = points[index / 3].getY();
				vertices[index + 2] = points[index / 3].getZ();
			}
			else
			{
				vertices[index] = points[index].getX();
				vertices[index + 1] = points[index].getY();
				vertices[index + 2] = points[index].getZ();
			}
		}
	}

	// Scaling

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{

		usableMatrix = usableMatrix.Scale(101.0, 101.0);

		for (int index = 0; index < 8; index++)
		{
			points[index] = usableMatrix * points[index];
		}

		for (int index = 0; index < 24; index += 3)
		{
			if (index != 0)
			{
				vertices[index] = points[index / 3].getX();
				vertices[index + 1] = points[index / 3].getY();
				vertices[index + 2] = points[index / 3].getZ();
			}
			else
			{
				vertices[index] = points[index].getX();
				vertices[index + 1] = points[index].getY();
				vertices[index + 2] = points[index].getZ();
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{

		usableMatrix = usableMatrix.Scale(99.9, 99.9);

		for (int index = 0; index < 8; index++)
		{
			points[index] = usableMatrix * points[index];
		}

		for (int index = 0; index < 24; index += 3)
		{
			if (index != 0)
			{
				vertices[index] = points[index / 3].getX();
				vertices[index + 1] = points[index / 3].getY();
				vertices[index + 2] = points[index / 3].getZ();
			}
			else
			{
				vertices[index] = points[index].getX();
				vertices[index + 1] = points[index].getY();
				vertices[index + 2] = points[index].getZ();
			}
		}
	}

	// Translating

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{

		usableMatrix = usableMatrix.Translate(0, -0.1);

		for (int index = 0; index < 8; index++)
		{
			points[index] = usableMatrix * points[index];
		}

		for (int index = 0; index < 24; index += 3)
		{
			if (index != 0)
			{
				vertices[index] = points[index / 3].getX();
				vertices[index + 1] = points[index / 3].getY();
				vertices[index + 2] = points[index / 3].getZ();
			}
			else
			{
				vertices[index] = points[index].getX();
				vertices[index + 1] = points[index].getY();
				vertices[index + 2] = points[index].getZ();
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{

		usableMatrix = usableMatrix.Translate(0, 0.1);

		for (int index = 0; index < 8; index++)
		{
			points[index] = usableMatrix * points[index];
		}

		for (int index = 0; index < 24; index += 3)
		{
			if (index != 0)
			{
				vertices[index] = points[index / 3].getX();
				vertices[index + 1] = points[index / 3].getY();
				vertices[index + 2] = points[index / 3].getZ();
			}
			else
			{
				vertices[index] = points[index].getX();
				vertices[index + 1] = points[index].getY();
				vertices[index + 2] = points[index].getZ();
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

		usableMatrix = usableMatrix.Translate(0.1, 0);

		for (int index = 0; index < 8; index++)
		{
			points[index] = usableMatrix * points[index];
		}

		for (int index = 0; index < 24; index += 3)
		{
			if (index != 0)
			{
				vertices[index] = points[index / 3].getX();
				vertices[index + 1] = points[index / 3].getY();
				vertices[index + 2] = points[index / 3].getZ();
			}
			else
			{
				vertices[index] = points[index].getX();
				vertices[index + 1] = points[index].getY();
				vertices[index + 2] = points[index].getZ();
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{

		usableMatrix = usableMatrix.Translate(-0.1, 0);

		for (int index = 0; index < 8; index++)
		{
			points[index] = usableMatrix * points[index];
		}

		for (int index = 0; index < 24; index += 3)
		{
			if (index != 0)
			{
				vertices[index] = points[index / 3].getX();
				vertices[index + 1] = points[index / 3].getY();
				vertices[index + 2] = points[index / 3].getZ();
			}
			else
			{
				vertices[index] = points[index].getX();
				vertices[index + 1] = points[index].getY();
				vertices[index + 2] = points[index].getZ();
			}
		}
	}

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 8);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

