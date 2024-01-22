#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

int main()
{
    RenderWindow window(VideoMode(720, 480), "Polygon");
    Event event;

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
        }

        window.clear(); // clear before drawing

        window.display(); // update window
    }
    
    return 0;
}