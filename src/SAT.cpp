//
// Created by ligas on 15.04.2023.
//

#include "SAT.h"


SAT::vec2 SAT::normalVector(const vec2 &p1, const vec2 &p2) {

        float edge_coordinate_x = p2.x - p1.x;
        float edge_coordinate_y = p2.y - p1.y;
        return {-edge_coordinate_y, edge_coordinate_x};

}

void SAT::projectVertices(const triangle &tr, const vec2 &axis, float &min, float &max) {
    min = max = axis.x * tr.points[0].x + axis.y * tr.points[0].y;
    for (int i = 1; i < 3; i++){
        const float vertice  = axis.x * tr.points[i].x + axis.y * tr.points[i].y;
        if (vertice < min) min = vertice;
        if (vertice > max) max = vertice;
    }
}

bool SAT::overlap(float min1, float max1, float min2, float max2) {
    return (max1 >= min2) && (max2 >= min1);
}

bool SAT::isColliding(const triangle& triangle1, const triangle& triangle2) {
    //Sprawdzamy dla każdej krawędzi pierwszego trójkąta czy ich projekcje na siebie zachodzą
    for (int i = 0; i < 3; i++) {
        const vec2 &p1 = triangle1.points[i];
        const vec2 &p2 = triangle1.points[(i + 1) % 3];
        const vec2 axis = normalVector(p1, p2);

        float min1, max1, min2, max2;
        projectVertices(triangle1, axis, min1, max1);
        projectVertices(triangle2, axis, min2, max2);

        if (!overlap(min1, max1, min2, max2)) {
            return false;
        }

    }
    for (int i = 0; i < 3; i++) {
        const vec2 &p1 = triangle2.points[i];
        const vec2 &p2 = triangle2.points[(i + 1) % 3];
        const vec2 axis = normalVector(p1, p2);

        float min1, max1, min2, max2;
        projectVertices(triangle1, axis, min1, max1);
        projectVertices(triangle2, axis, min2, max2);

        if (!overlap(min1, max1, min2, max2)) {
            return false;
        }
    }

    return true;


}