#ifndef COORD_SYSTEM_H
#define COORD_SYSTEM_H

#include <SFML/Graphics.hpp>

class Vector;
#include "../vector/vector.h"

class Coord_system
{
public:
    int y_shift_ = 0;
    int x_shift_ = 0;
    int x_start_ = 0;
    int y_start_ = 0;
    int y_len_   = 0;
    int x_len_   = 0;
    int window_len_x = 0;
    int window_len_y = 0;

private:
    Vector *abscissa = nullptr;
    Vector *ordinate = nullptr;
    
public:
    Coord_system (int x_start, int y_start, int x_len, int y_len, int x_shift, int y_shift, sf::VideoMode videomode);
    ~Coord_system ();
    void draw (sf::RenderWindow &window);
};

#endif /* COORD_SYSTEM_H */