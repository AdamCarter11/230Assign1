//Always include these headers *******
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
// ************************************ 
//using namespace std;

int main()
{
    //creating a render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::Texture texture;
    texture.create(window.getSize().x, window.getSize().y);

    //create and fill circle
    sf::CircleShape shape;
    shape.setRadius(50.0f);
    shape.setFillColor(sf::Color::Green);

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(50, 50));
    rect.setFillColor(sf::Color::Green);

    bool canDraw = false;
    int whatShape = 0;
    int size = 50;

    //copy paste into every project (it's used for quitting)
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            canDraw = !canDraw;
        }
        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Num0) {
                shape.setFillColor(sf::Color::Green);
                rect.setFillColor(sf::Color::Green);
            }
            if (event.key.code == sf::Keyboard::Num1) {
                shape.setFillColor(sf::Color::Red);
                rect.setFillColor(sf::Color::Red);
            }
            if (event.key.code == sf::Keyboard::Num2) {
                shape.setFillColor(sf::Color::Blue);
                rect.setFillColor(sf::Color::Blue);
            }
            if (event.key.code == sf::Keyboard::Q) {
                whatShape = 0;
            }
            if (event.key.code == sf::Keyboard::W) {
                whatShape = 1;
            }
            if (event.key.code == sf::Keyboard::P) {
                texture.copyToImage().saveToFile("screenshot.jpg");
            }
            //For whatever reason, it always increases its size and I can't figure out why
            /*
            if (event.key.code == sf::Keyboard::Up) {
                size = size + 10;
                rect.setSize(sf::Vector2f(size, size));
            }
            if (event.key.code == sf::Keyboard::Down) {
                size = size - 10;
                rect.setSize(sf::Vector2f(size, size));
            }
            */
        }
        //used for updating the window
        //window.clear();
        if (canDraw) {
            if (whatShape == 0) {
                shape.setPosition(sf::Mouse::getPosition(window).x - shape.getRadius(), sf::Mouse::getPosition(window).y - shape.getRadius());
                window.draw(shape);
            }
            if (whatShape == 1) {
                rect.setPosition(sf::Mouse::getPosition(window).x - rect.getSize().x, sf::Mouse::getPosition(window).y - rect.getSize().y);
                window.draw(rect);
            }

        }

        window.display();
        texture.update(window);
    }
    

    return 0;
}