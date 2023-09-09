#ifndef VECTOR_H
#define VECTOR_H 

#include <cmath>
#include <SFML/Graphics.hpp>

class Coord_system;
#include "../coord_system/coord_system.h"

class Point 
{
public:
 
    double x_ = 0;
    double y_ = 0;

public:
    Point (double x, double y);
    ~Point ();
};

class Vector 
{
    public://
    double x_coord = 0;
    double y_coord = 0;
    sf::Color color_ = sf::Color ();

public:
    Vector (double x, double y, sf::Color color);
    ~Vector ();

    void draw (const Coord_system &coord_system, sf::RenderWindow &window, const Point start = Point (0, 0));
    Vector operator + (const Vector &vec_a);
    Vector operator - (const Vector &vec_a);
    Vector operator = (const Vector &vec_a);
    Vector operator - ();
private:
    void draw_line (const Coord_system &coord_system, sf::RenderWindow &window, const Point start);
};



#endif /* VECTOR_H */  