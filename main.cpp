// Sample program main.cpp
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape character(5);
    character.setPosition(200,390);
    character.setFillColor(sf::Color::Red);
    vector<sf::RectangleShape> squares;
    for(int x = 0; x < 40;x ++)
    {
        for(int y=0; y<40;y++)
        {
            sf::RectangleShape cell(sf::Vector2f(10,10));
            cell.setPosition(x*10, y*10);
            //cell.setOutlineThickness(1);
            //cell.setOutlineColor(sf::Color::Black);
            squares.push_back(cell);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyReleased)
            {
                int x = character.getPosition().x;
                int y = character.getPosition().y;
                if(event.key.code == sf::Keyboard::Up)
                {
                    if(y> 0)
                        character.setPosition(x, y-10);
                }
                if(event.key.code == sf::Keyboard::Down)
                {
                    if(y<390 )
                        character.setPosition(x, y+10);
                }
                if(event.key.code == sf::Keyboard::Left)
                {
                    if(x> 0)
                        character.setPosition(x-10, y);
                }
                if(event.key.code == sf::Keyboard::Right)
                {
                    if(x<390)
                        character.setPosition(x+10, y);
                }
                if(event.key.code == sf::Keyboard::Space)
                {
                    for(sf::RectangleShape &sh:squares)
                    {
                       if(x == sh.getPosition().x
                         && y ==sh.getPosition().y )
                       {
                           sh.setFillColor(sf::Color::Green);
                       }
                    }
                }


            }
            if(event.type == sf::Event::MouseButtonReleased)
            {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;

                for(sf::RectangleShape &sh:squares)
                {
                    if(x >= sh.getPosition().x&&x < sh.getPosition().x+10
                       && y >=sh.getPosition().y&&y < sh.getPosition().y+10 )
                    {
                        sh.setFillColor(sf::Color::Green);
                    }
                }
            }

        }


        window.clear(sf::Color::White);
        for(sf::RectangleShape sh:squares)
        {
            window.draw(sh);
        }
        window.draw(character);
        window.display();

    }

    return 0;
}
