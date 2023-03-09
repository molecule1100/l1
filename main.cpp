#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;


int main()
{
    int c = 0;
    bool Flag = false;
    setlocale(LC_ALL, "RU");
    string str1 = "Hello World!";
    string str2 = "";

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Window", sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    sf::Font font;
    font.loadFromFile("lab1font.ttf");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(100);
    text.setString(str2);
    text.setPosition(350, 250);
    text.setFillColor(sf::Color::Yellow);

    sf::Clock clock;

    while (window.isOpen())
    {
        int time = clock.getElapsedTime().asSeconds();
        cout << time << endl;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
   
        if (time == c && Flag == false)
        {
            str2 += str1[time];
            text.setString(str2);
            if (str1[time] == 32)
            {
                time += 1;
                
            }
            Flag = true;
        }
        
        if (time > c)
        {
            Flag = false;
            c = time;
        }
       
        window.draw(text);
        window.display();
    }

    return 0;
}