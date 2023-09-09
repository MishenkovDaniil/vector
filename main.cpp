#include <iostream>
#include <cmath>

#include "vector/vector.h"
#include "coord_system/coord_system.h"

const int WINDOW_WIDTH  = 800;
const int WINDOW_HEIGHT = 600;

int main ()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Vectors"); //sf::Style::Fullscreen);
    
    Coord_system coord_system (WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT, 1, 1, sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT));

    Vector mouse (0, 0, sf::Color::Black);

    sf::Color blue_color(sf::Color::Blue);
    sf::Color red_color (sf::Color::Red);

    Vector vec1 (0, 100, blue_color);
    Vector vec2 (100, 0, red_color);
    Vector vec3 = vec1 + vec2; 

    while (window.isOpen())
    {
        sf::Event event;
        window.clear();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            else if (event.mouseButton.button == sf::Mouse::Left && (event.mouseButton.x || event.mouseButton.y))
            {
               mouse = Vector (event.mouseButton.x - coord_system.x_start_, -(event.mouseButton.y - coord_system.y_start_), sf::Color::Green);
               break;
            }
        }

        coord_system.draw(window);
        mouse.draw (coord_system, window);
        
        vec1.draw(coord_system, window);
        vec2.draw(coord_system, window);
        vec3.draw(coord_system, window);

        window.display();
    }

    vec1.~Vector ();
    vec2.~Vector ();
    vec3.~Vector ();

    coord_system.~Coord_system ();

    return 0;
}

