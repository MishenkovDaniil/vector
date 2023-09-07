#include <iostream>
#include <cmath>

#include "vector/vector.h"
#include "coord_system/coord_system.h"

int main ()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Vectors");// sf::Style::Fullscreen);//, sf::Style::Fullscreen);
    
    // sf::VertexArray lines(sf::Lines, 4);
    // lines[0].position = sf::Vector2f(100, 100);
    // lines[1].position = sf::Vector2f(300, 150);
    // lines[2].position = sf::Vector2f(700, 550);
    // lines[3].position = sf::Vector2f(40, 50);
    // lines[3].color = sf::Color::Blue;
    Coord_system coord_system (0, 0, 600, 600, 1, 1, sf::VideoMode(800, 600));
    sf::Color blue_color(sf::Color::Blue);
    sf::Color red_color(sf::Color::Red);

    Vector vec1 (100, 150, blue_color);
    Vector vec2 (-50, 100, red_color);

    Vector vec3 = vec1 + vec2; 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        window.clear();
        coord_system.draw(window);
        vec1.draw(coord_system, window);
        vec2.draw(coord_system, window);
        vec3.draw(coord_system, window);
        window.display();
    }

    vec1.~Vector ();
    vec2.~Vector ();
    vec3.~Vector ();

    // std::cout << vec3.x_coord << std::endl;
    // std::cout << vec3.y_coord << std::endl;
    return 0;
}

///to do
// рисовка окна 
// функция рисовки плоскости с заданными параметрами 
// рисовка вектора 
// кручение вектора 
// стрелочка на векторе 
