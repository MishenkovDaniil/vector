#include "coord_system.h"

Coord_system::Coord_system (double x_start, double y_start, double x_len, double y_len, double x_shift, double y_shift, sf::VideoMode videomode) :
    x_start_ (x_start + videomode.width / 2),
    y_start_ (y_start + videomode.height / 2),
    x_shift_ (x_shift),
    y_shift_ (y_shift),
    x_len_ (x_len),
    y_len_ (y_len)
    {};

Coord_system:: ~Coord_system ()
{};

void Coord_system::draw (sf::RenderWindow &window)
{
    sf::VertexArray lines(sf::Lines, 4);

    lines[0].position = sf::Vector2f(this->x_start_ - this->x_len_ / 2, this->y_start_);
    lines[1].position = sf::Vector2f(this->x_start_ + this->x_len_ / 2, this->y_start_);
    lines[2].position = sf::Vector2f(this->x_start_, this->y_start_ - this->y_len_ / 2);
    lines[3].position = sf::Vector2f(this->x_start_, this->y_start_ + this->y_len_ / 2);

    lines[0].color = lines[1].color = lines[2].color = lines[3].color = sf::Color::White;

    window.draw (lines);
}