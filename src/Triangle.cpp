//
// Created by ligas on 15.04.2023.
//

#include "Triangle.h"
#include <math.h>


Triangle::Triangle(float t_X, float t_Y) {
    shape.setPointCount(3);
    shape.setPosition(t_X, t_Y);
    shape.setOrigin(100 + 100 / 2.f, 100 + 100 * std::sqrt(3) / 2.f / 2.f);
    shape.setPoint(0, sf::Vector2f(100, 100));
    shape.setPoint(1, sf::Vector2f(200, 100));
    shape.setPoint(2, sf::Vector2f(150, 100 + 100 * std::sqrt(3) / 2));
    shape.setFillColor(sf::Color::Green);


}


void Triangle::update() {
    velocity.x = 0;
    velocity.y = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0) {
        velocity.x = -triangleVelocity;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < 800) {
        velocity.x = triangleVelocity;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && top() > 0) {
        velocity.y = -triangleVelocity;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && bottom() < 600) {
        velocity.y = triangleVelocity;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        shape.rotate(-10.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        shape.rotate(10.f);
    }

    shape.move(velocity);


}

float Triangle::left() {
    return shape.getPosition().x - (shape.getGlobalBounds().getSize().x / 2.f);
}

float Triangle::right() {
    return shape.getPosition().x + (shape.getGlobalBounds().getSize().x / 2.f);
}

float Triangle::top() {
    return shape.getPosition().y - (shape.getGlobalBounds().getSize().y / 2.f);
}

float Triangle::bottom() {
    return shape.getPosition().y + (shape.getGlobalBounds().getSize().y / 2.f);
}


void Triangle::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}

SAT::triangle Triangle::getVertices() {
    return {{{{shape.getTransform().transformPoint(shape.getPoint(0)).x,
               shape.getTransform().transformPoint(shape.getPoint(0)).y},
              {shape.getTransform().transformPoint(shape.getPoint(1)).x,
               shape.getTransform().transformPoint(shape.getPoint(1)).y},
              {shape.getTransform().transformPoint(shape.getPoint(2)).x,
               shape.getTransform().transformPoint(shape.getPoint(2)).y}}}};

}

void Triangle::setCollissionColor() {
    shape.setFillColor(sf::Color::Red);
}


void Triangle::setNoCollissionColor() {
    shape.setFillColor(sf::Color::Green);
}



