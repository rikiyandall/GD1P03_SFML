#include <SFML/Graphics.hpp>

void InputChecking(sf::RectangleShape &rectShape, sf::Vector2f moveVector) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		moveVector.x = -5.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		moveVector.x = 5.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		moveVector.y = -5.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		moveVector.y = 5.0f;
	}

	rectShape.move(moveVector);
}


int main()
{
	std::vector<sf::Shape*> shapes;


	sf::RenderWindow window(sf::VideoMode(1024, 720), "SFML works!");

	//-- Circle Shape --//
	sf::CircleShape circShape(100.f);
	sf::Vector2f shapePos = sf::Vector2f(400, 300);
	circShape.setPosition(shapePos);
	circShape.setOrigin(circShape.getRadius(), circShape.getRadius());

	circShape.setFillColor(sf::Color::Green);
	circShape.setOutlineThickness(10);
	circShape.setOutlineColor(sf::Color::Magenta);

	shapes.push_back(&circShape);

	//-- Rect Shape --//
	sf::RectangleShape rectShape;
	sf::Vector2f rectDimensions(100, 50);
	rectShape.setSize(rectDimensions);
	rectShape.setOrigin(rectShape.getSize() / 2.0f);
	rectShape.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

	rectShape.setFillColor(sf::Color::Blue);
	rectShape.setOutlineThickness(10);
	rectShape.setOutlineColor(sf::Color::Magenta);

	shapes.push_back(&rectShape);


	bool counter = true;
	sf::Vector2f moveVector;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			moveVector.x = 0;
			moveVector.y = 0;

			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Space) {
					counter = !counter;
					if (counter) {
						circShape.setFillColor(sf::Color::Green);
					}
					else {
						circShape.setFillColor(sf::Color::Cyan);
					}
				}

			}





			InputChecking(rectShape, moveVector);

			window.clear();

			for (int i = 0; i < (int)shapes.size(); i++) {
				window.draw(*shapes[i]);
			}
			window.display();

		}
	}
	return 0;
}