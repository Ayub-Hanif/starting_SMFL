#include <SFML/Graphics.hpp>

void Control();
int main()
{
   Control();




    return 0;
}
void Control()
{
    sf::RenderWindow window(sf::VideoMode(1800, 1000), "LoL", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player1(sf::Vector2f(100.0f, 100.0f));
    sf::RectangleShape player2(sf::Vector2f(100.0f, 100.0f));
    sf::RectangleShape player3(sf::Vector2f(100.0f, 100.0f));
    player2.setFillColor(sf::Color::Red);
    player1.setFillColor(sf::Color::Blue);
    player3.setFillColor(sf::Color::Green);
    player2.setOrigin(-250.0f, -250.0f);
    player3.setOrigin(-500.0f, -500.0f);
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

            case sf::Event::MouseButtonPressed:
                player1.move(100.0f, 100.0f);
                break;
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            player1.move(-0.5f, 0.0f);
            exit;
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
        window.draw(player1);
        window.draw(player2);
        window.draw(player3);
        window.display();
    }
}