#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main() {
    int a = 500, b = 500;
    cout << "Bienvenue dans la simulation de sable !" << endl;
    cout << "Please enter the width of the sand simulation: " << endl;
    cin >> a;
    cout << "Please enter the height of the sand simulation: " << endl;
    cin >> b;
    // Create a window and a circle shape
    sf::RenderWindow window(sf::VideoMode(a, b), "Sand Simulation");
    window.setFramerateLimit(60); // Set the frame rate limit to 60 FPS
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}