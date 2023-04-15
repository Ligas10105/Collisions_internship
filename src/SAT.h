//
// Created by ligas on 15.04.2023.
//

#ifndef COLLISIONS_INTERNSHIP_SAT_H
#define COLLISIONS_INTERNSHIP_SAT_H
#include <cstdlib>
#include <array>


class SAT {
public:

    struct vec2 {
        float x, y;
    };
    struct triangle {
        std::array<vec2, 3> points;
    };

    vec2 normalVector(const vec2& p1, const vec2& p2);
    void projectVertices(const std::array<vec2, 3>& points, const vec2& axis, float& min, float& max);
    bool overlap(float min1, float max1, float min2, float max2);
    bool isColliding(const triangle& triangle1, const triangle& triangle2);
};


#endif //COLLISIONS_INTERNSHIP_SAT_H
