#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	recmid.setSize(sf::Vector2f(40, 40));
	recmid.setPosition(105,105);
	recmid.setFillColor(sf::Color::Green);

	rectop.setSize(sf::Vector2f(30, 30));
	rectop.setPosition(110,110);
	rectop.setFillColor(sf::Color::Blue);

	lowright.setFillColor(sf::Color::Green);
	lowright.setSize(sf::Vector2f(75, 75));
	
	circle.setRadius(50);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);

	if (f.loadFromFile("M:/CMP105/Week1/CMP105App/font/arial.ttf"))
	{
		std::cout << "Font load successful" << std::endl;
	}

	t.setFont(f);
	t.setCharacterSize(32);
	t.setString("r");
	t.setPosition(450,450);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u ws = window->getSize();
	circle.setPosition(ws.x / 2, ws.y / 2 - 50);
	lowright.setPosition(ws.x-lowright.getSize().x, ws.y-lowright.getSize().y);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	window->draw(recmid);
	window->draw(rectop);

	window->draw(circle);

	window->draw(t);

	window->draw(lowright);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}