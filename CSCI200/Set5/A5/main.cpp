#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

int main() 
{
    RenderWindow window( VideoMode(640, 640), "Polygon Land" );

    Event event;


    while( window.isOpen() ) 
    {
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE



        //  END  DRAWING HERE
        /////////////////////////////////////



        window.display();

        // Event handling
        while( window.pollEvent(event) ) 
        {
            if(event.type == Event::Closed) 
            {

                window.close();
            }
        }
    }

    return 0;
}
