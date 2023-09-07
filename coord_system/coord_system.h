#ifndef COORD_SYSTEM_H
#define COORD_SYSTEM_H

#include <SFML/Graphics.hpp>

class Coord_system
{
public:
    double y_len_   = 0;
    double x_len_   = 0;
    double y_shift_ = 0;
    double x_shift_ = 0;
    double x_start_ = 0;
    double y_start_ = 0;
    
public:
    Coord_system (double x_start, double y_start, double x_len, double y_len, double x_shift, double y_shift, sf::VideoMode videomode = sf::VideoMode (0,0));
    ~Coord_system ();
    void draw (sf::RenderWindow &window);
};

#endif /* COORD_SYSTEM_H */