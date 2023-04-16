//
// Created by ligas on 15.04.2023.
//

#include "Triangle.h"


Triangle::Triangle(float t_X, float t_Y) {
    shape.setPointCount(3);
    shape.setPosition(t_X, t_Y);
    shape.setOrigin(160.f, 140.f);
    shape.setPoint(0, sf::Vector2f(100.0f, 100.0f));
    shape.setPoint(1, sf::Vector2f(220.0f, 100.0f));
    shape.setPoint(2, sf::Vector2f(160.0f, 180.0f));
    shape.setFillColor(sf::Color::Red);


}


void Triangle::update() {
    shape.move(velocity);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0) {
        velocity.x = -triangleVelocity;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < 600) {
        velocity.x = triangleVelocity;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && top() > 0) {
        velocity.y = -triangleVelocity;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && bottom() < 600) {
        velocity.y = triangleVelocity;
    } else {
        velocity.x = 0;
        velocity.y = 0;
    }
}

float Triangle::left() {
    return shape.getPosition().x + (shape.getGlobalBounds().getSize().x / 2.f);
}

float Triangle::right() {
    return shape.getPosition().x - (shape.getGlobalBounds().getSize().x / 2.f);
}

float Triangle::top() {
    return shape.getPosition().y - (shape.getGlobalBounds().getSize().y / 2.f);
}

float Triangle::bottom() {
    return shape.getPosition().y - (shape.getGlobalBounds().getSize().y / 2.f);
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
    shape.setFillColor(sf::Color::Yellow);
}


void Triangle::setNoCollissionColor() {
    shape.setFillColor(sf::Color::Red);
}



