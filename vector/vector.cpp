#include <cmath>
#include <iostream>

#include "vector.h"

 
Point::Point (double x, double y) : 
        x_(x), y_ (y) {};
    
Point::~Point ()
{
    this->x_ = NAN;
    this->y_ = NAN;  
};

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

Vector Vector::operator = (const Vector &vec_a)
{
    this->x_coord = vec_a.x_coord;
    this->y_coord = vec_a.y_coord;
    this->color_ = vec_a.color_;
    return *this; 
}

Vector Vector::operator - (const Vector &vec_a)
{
    sf::Color new_color ((this->color_.r + vec_a.color_.r) / 2, (this->color_.g + vec_a.color_.g) / 2,
                        (this->color_.b + vec_a.color_.b) / 2,(this->color_.a + vec_a.color_.a) / 2);
    return Vector (this->x_coord - vec_a.x_coord, this->y_coord - vec_a.y_coord, new_color); 
}

Vector Vector::operator - ()
{
    return Vector (-this->x_coord, -this->y_coord, this->color_); 
}

void Vector::draw (const Coord_system &coord_system, sf::RenderWindow &window, const Point start)
{
    int len = sqrt (this->y_coord*this->y_coord + this->x_coord*this->x_coord);

    Vector normal   (-(this->y_coord) / (len >> 1), this->x_coord / (len >> 1), this->color_);
    Vector opposite (  this->x_coord / (len >> 2), this->y_coord / (len >> 2), this->color_);
    Vector arrow_l = normal - opposite;
    Vector arrow_r = -normal - opposite;

    Point arrow_start(start.x_ + this->x_coord, start.y_ + this->y_coord);

    draw_line (*this, coord_system, window, start);
    draw_line (arrow_l, coord_system, window, arrow_start);
    draw_line (arrow_r, coord_system, window, arrow_start);
    
    normal.~Vector ();
    opposite.~Vector ();
    arrow_l.~Vector ();
    arrow_r.~Vector ();
    arrow_start.~Point ();
}

void draw_line (const Vector &vec, const Coord_system &coord_system, sf::RenderWindow &window, const Point start)
{
    sf::VertexArray lines(sf::Lines, 2);

    Point real_start (start.x_ + coord_system.x_start_, -start.y_ + coord_system.y_start_);

    lines[0].position = sf::Vector2f(real_start.x_, real_start.y_);
    lines[1].position = sf::Vector2f(real_start.x_ + vec.x_coord, real_start.y_ - vec.y_coord);
    lines[0].color = lines[1].color = vec.color_;

    window.draw (lines);
}