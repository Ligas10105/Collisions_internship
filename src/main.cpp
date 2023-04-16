#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Triangle.h"
#include "SAT.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(600, 800), "Triangles collisions");
    window.setFramerateLimit(60);
    Triangle t1(0, 0);
    Triangle t2(300, 400);

    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }

        }

        t1.update();
        if (SAT::isColliding(t1.getVertices(), t2.getVertices())) {
            t1.collissionColor();
        } else {
            t1.noCollissionColor();
        }
        window.draw(t1);
        window.draw(t2);
        window.display();
    }

    return EXIT_SUCCESS;
}



