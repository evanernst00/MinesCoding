#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "SFML Test" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        // Draw a circle object called face and color it yellow
        CircleShape face;
        face.setPosition( 15, 15 );
        face.setRadius( 300 );
        face.setFillColor( Color::Yellow );
        window.draw( face );
                
        // Draw a rectangle object called eye and color it blue
        RectangleShape eye;
        eye.setSize( Vector2f( 45, 150 ) );
        eye.setPosition( 200, 150 );
        eye.setFillColor( Color(0, 0, 255));
        window.draw( eye );
        eye.setPosition(400, 150);
        window.draw(eye);
                
        // Draw a text object called label
        // place in file loading section
        Font myFont;
        if( !myFont.loadFromFile( "data/arial.ttf" ) )
            return -1;
        // place in drawing section
        Text label;
        label.setFont( myFont );
        label.setString( "Hello World!" );
        label.setPosition( 250, 520 );
        label.setFillColor( Color::Black );
        window.draw( label );


        
        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}
