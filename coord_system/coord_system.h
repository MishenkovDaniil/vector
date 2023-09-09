#ifndef COORD_SYSTEM_H
#define COORD_SYSTEM_H

#include <SFML/Graphics.hpp>

class Vector;
class Point;
#include "../vector/vector.h"

class Coord_system
{
    int y_shift_ = 0;
    int x_shift_ = 0;
    int y_len_   = 0;
    int x_len_   = 0;
    int window_len_x = 0;
    int window_len_y = 0;
    int x_start_ = 0;
    int y_start_ = 0;

private:
    Vector *abscissa = nullptr;
    Vector *ordinate = nullptr;
    
    friend void draw_line (const Vector &vec, const Coord_system &coord_system, sf::RenderWindow &window, const Point start);
    
public:
    Coord_system (int x_start, int y_start, int x_len, int y_len, int x_shift, int y_shift, sf::VideoMode videomode);
    ~Coord_system ();
    
    void start (Point &point);

    void draw (sf::RenderWindow &window);
};

#endif /* COORD_SYSTEM_H */