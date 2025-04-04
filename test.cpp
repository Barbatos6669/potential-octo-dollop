#include <SFML/Graphics.hpp>

int main() {
    // Create a window with a valid VideoMode
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}