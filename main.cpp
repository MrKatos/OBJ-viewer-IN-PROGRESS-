#include "stdafx.h"

void Blur(std::vector<sf::CircleShape>& vector, sf::RenderWindow& window, float precision, int R, int G, int B, float visibility)
{
    if (precision > 100)
    {
        precision = 100;
    }
    else if (precision < 0)
    {
        precision = 1;
    }

    if (visibility > 1)
    {
        visibility = 1;
    }
    else if (visibility < 0)
    {
        visibility = 0;
    }

    float blur_diff = visibility / precision;
    for (float i = 0; i < precision; ++i)
    {
        // Tworzymy kształt koła
        sf::CircleShape circle;
        circle.setRadius(100.f); // Ustawiamy promień koła
        circle.setOrigin(sf::Vector2f(100.f, 100.f));
        circle.setScale(window.getSize().x/200.f - (window.getSize().x / 200.f)*i*(1/precision) + 0.8f, window.getSize().y / 200.f - (window.getSize().y / 200.f) * i * (1 / precision) + 0.6f); // Szerokość 50%, wysokość 100% window.getSize().y/ 10.f
        circle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f); // Ustawiamy pozycję koła
        circle.setFillColor(sf::Color(R, G, B, 255*visibility - 255*blur_diff*i)); // Ustawiamy kolor wypełnienia koła
        vector.push_back(circle);
    }   
}


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    
    // Background
    std::vector<sf::CircleShape> blur;
    Blur(blur, window, 100, 110, 110, 110, 0.04);

    // Tworzymy kwadrat
    // create an array of 3 vertices that define a triangle primitive
    sf::VertexArray a(sf::LineStrip, 5);

    // define the position of the triangle's points
    a[0].position = sf::Vector2f(10.f, 10.f);
    a[1].position = sf::Vector2f(100.f, 10.f);
    a[2].position = sf::Vector2f(100.f, 100.f);
    a[3].position = sf::Vector2f(10.f, 100.f);
    a[4].position = sf::Vector2f(10.f, 10.f);

    // define the color of the triangle's points
    a[0].color = sf::Color::Red;
    a[1].color = sf::Color::Blue;
    a[2].color = sf::Color::Green;
    a[3].color = sf::Color::Black;
    a[4].color = sf::Color::Cyan;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color(59, 59, 59));

        // draw everything here...
        for (size_t i = 0; i < blur.size(); ++i)
        {
            window.draw(blur[i]);
        }
        window.draw(a);

        // end the current frame
        window.display();
    }

    return 0;
}