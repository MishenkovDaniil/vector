#ifndef VECTOR_H
#define VECTOR_H 

#include <cmath>
#include <SFML/Graphics.hpp>

#include "../coord_system/coord_system.h"

class Vector 
{
    double x_coord = 0;
    double y_coord = 0;
    sf::Color color_ = sf::Color ();

public:
    Vector (double x, double y, sf::Color color);
    ~Vector ();

    void draw (Coord_system &coord_system, sf::RenderWindow &window);
    Vector operator + (const Vector &vec_a);
};



#endif /* VECTOR_H */  