#include <cmath>

#include "vector.h"


Vector::Vector (double x, double y, sf::Color color) :
    x_coord (x), 
    y_coord (y),
    color_  (color)
    {};

Vector::~Vector ()
{
    this->x_coord = NAN;
    this->y_coord = NAN;  
};

Vector Vector::operator + (const Vector &vec_a)
{
    sf::Color new_color ((this->color_.r + vec_a.color_.r) / 2, (this->color_.g + vec_a.color_.g) / 2,
                        (this->color_.b + vec_a.color_.b) / 2,(this->color_.a + vec_a.color_.a) / 2);
    return Vector (this->x_coord + vec_a.x_coord, this->y_coord + vec_a.y_coord, new_color); 
}

void Vector::draw (Coord_system &coord_system, sf::RenderWindow &window)
{
    sf::VertexArray lines(sf::Lines, 2);

    lines[0].position = sf::Vector2f(coord_system.x_start_, coord_system.y_start_);
    lines[1].position = sf::Vector2f(coord_system.x_start_ + this->x_coord, coord_system.y_start_ + this->y_coord);
    
    lines[0].color = lines[1].color = this->color_;

    window.draw (lines);
}