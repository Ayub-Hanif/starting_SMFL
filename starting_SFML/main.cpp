#include <SFML/Graphics.hpp>
#include <iostream>

void Control();
int main()
{
 
   Control();
  
    return 0;
}
void Control()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "LoL", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player1(sf::Vector2f(100.0f, 100.0f));
    sf::RectangleShape line(sf::Vector2f(100.0f,580.0f));
    
    // create an array of 3 vertices that define a triangle primitive
    sf::VertexArray lines(sf::LinesStrip, 5);
    lines[0].position = sf::Vector2f(900,10);
    lines[1].position = sf::Vector2f(900, 900);
    lines[2].position = sf::Vector2f(10, 900);
    lines[3].position = sf::Vector2f(10, 10);
    lines[4].position = sf::Vector2f(900, 10);
    lines[0].color = sf::Color::Red;
    lines[1].color = sf::Color::Blue;
    lines[2].color = sf::Color::Yellow;
    lines[3].color = sf::Color::Green;
    lines[4].color = sf::Color::White;

    player1.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            player1.move(-0.5f, 0.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            player1.move(0.5f,0.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            player1.move(0.0f, -0.5f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            player1.move(0.0f, 0.5f);
        }
       
        window.clear();
        window.draw(lines);
        window.draw(player1);
        
        window.display();
    }
}
