//
// Created by ligas on 15.04.2023.
//

#ifndef COLLISIONS_INTERNSHIP_TRIANGLE_H
#define COLLISIONS_INTERNSHIP_TRIANGLE_H
#include <SFML/Graphics.hpp>
#include "SAT.h"

class Triangle : public sf::Drawable {
public:
    Triangle(float t_X, float t_Y);
    Triangle() = delete;
    ~Triangle() = default;

    void update();

    float left();
    float right();
    float top();
    float bottom();

    SAT::triangle getVertices();
    void changeColor();


private:
    sf::ConvexShape shape;
    void draw(sf::RenderTarget& target,sf::RenderStates state) const override;
    const float triangleVelocity {5.0f};
    sf::Vector2f velocity {triangleVelocity, triangleVelocity};
};



#endif //COLLISIONS_INTERNSHIP_TRIANGLE_H
