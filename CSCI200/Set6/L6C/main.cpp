#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    RenderWindow window(VideoMode(640, 640), "SFML Test");

    // handle files

    Event event;

    while (window.isOpen())
    {
        window.clear();

        // draw stuff

        window.display();
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
    }

    return 0;
}
