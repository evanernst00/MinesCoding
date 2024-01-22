#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

#include "includes/Ghost.h"

int main() {
    // create a window
    RenderWindow window( VideoMode(1280, 720), "Lab 4 C" );

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
        
        /*
        Creating pacman
        */
        Vector2f pacPos(100, 200); // position of center of pacman
        int pacRadius = 40;

        // Body
        CircleShape pacman;
        pacman.setPosition(pacPos.x-pacRadius, pacPos.y-pacRadius);
        pacman.setFillColor(Color::Yellow);
        pacman.setRadius(pacRadius);
        window.draw(pacman);

        // Mouth
        ConvexShape mouth; // Add black triangle cut out for mouth
        mouth.setFillColor(Color::Black);
        mouth.setPointCount(3);
        mouth.setPoint(0, Vector2f(pacPos.x, pacPos.y)); // center of pacman
        mouth.setPoint(1, Vector2f(pacPos.x+pacRadius, pacPos.y+pacRadius)); // top corner
        mouth.setPoint(2, Vector2f(pacPos.x+pacRadius, pacPos.y-pacRadius)); // bottom corner
        window.draw(mouth);


        /*
        Creating ghost
        */
        Vector2f ghostPos(200, 200);
        Color ghostColor(Color::Red);
        int ghostWidth = 10;
        int numGhostFeet = 3;

        CircleShape ghostHead;
        ghostHead.setFillColor(ghostColor);
        ghostHead.setRadius(ghostWidth/2);

        RectangleShape ghostBody;
        ghostBody.setFillColor(ghostColor);
        ghostBody.setSize(Vector2f(ghostWidth, 10));

        CircleShape ghostEye;
        ghostEye.setFillColor(Color::White);
        ghostEye.setRadius(ghostWidth*2/5);

        CircleShape ghostFoot;
        ghostFoot.setFillColor(ghostColor);
        ghostFoot.setRadius(ghostWidth/2*numGhostFeet);


        /*
        ghost head radius + ghost body height + ghost foot radius = pacman radius * 2
        */



        
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
