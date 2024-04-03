#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

#include <vector>

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

        // Pacman - *coords are of center
        int pacmanX = 100;
        int pacmanY = 100;
        int pacmanRadius = 40;
        int pacmanMouthSize = pacmanRadius*2;
        CircleShape pacman_body;
        pacman_body.setPosition(pacmanX-pacmanRadius, pacmanY-pacmanRadius);
        pacman_body.setRadius(pacmanRadius);
        pacman_body.setFillColor(Color::Yellow);
        window.draw(pacman_body);
        ConvexShape pacman_mouth;
        pacman_mouth.setPointCount(3);
        pacman_mouth.setPoint(0, Vector2f(pacmanX, pacmanY));
        pacman_mouth.setPoint(1, Vector2f(pacmanX+pacmanMouthSize, pacmanY+pacmanMouthSize));
        pacman_mouth.setPoint(2, Vector2f(pacmanX+pacmanMouthSize, pacmanY-pacmanMouthSize));
        pacman_mouth.setFillColor(Color::Black);
        window.draw(pacman_mouth);

        // Red Ghost - *coords are of center
        int ghostX = 400;
        int ghostY = 100;
        int ghostRadius = pacmanRadius;
        int ghostEyeRadius = ghostRadius/3;
        int ghostEyeOffsetX = ghostRadius/2;
        int ghostEyeOffsetY = ghostRadius*2/7;
        int ghostPupilRadius = ghostRadius/5;
        int ghostPupilOffset = ghostPupilRadius/2;
        CircleShape ghostHead;
        ghostHead.setPosition(ghostX-ghostRadius, ghostY-ghostRadius);
        ghostHead.setRadius(ghostRadius);
        ghostHead.setFillColor(Color::Red);
        window.draw(ghostHead);
        RectangleShape ghostBody;
        ghostBody.setPosition(ghostX-ghostRadius, ghostY);
        ghostBody.setSize(Vector2f(ghostRadius*2, ghostRadius));
        ghostBody.setFillColor(Color::Red);
        window.draw(ghostBody);
        CircleShape ghostEye1;
        CircleShape ghostEye2;
        ghostEye1.setPosition((ghostX-ghostEyeRadius)-ghostEyeOffsetX, (ghostY-ghostEyeRadius)-ghostEyeOffsetY);
        ghostEye2.setPosition((ghostX-ghostEyeRadius)+ghostEyeOffsetX, (ghostY-ghostEyeRadius)-ghostEyeOffsetY);
        ghostEye1.setRadius(ghostEyeRadius);
        ghostEye2.setRadius(ghostEyeRadius);
        ghostEye1.setFillColor(Color::White);
        ghostEye2.setFillColor(Color::White);
        window.draw(ghostEye1);
        window.draw(ghostEye2);
        CircleShape ghostPupil1;
        CircleShape ghostPupil2;
        ghostPupil1.setPosition((ghostX-ghostPupilRadius)-ghostEyeOffsetX-ghostPupilOffset, (ghostY-ghostPupilRadius)-ghostEyeOffsetY);
        ghostPupil2.setPosition((ghostX-ghostPupilRadius)+ghostEyeOffsetX-ghostPupilOffset, (ghostY-ghostPupilRadius)-ghostEyeOffsetY);
        ghostPupil1.setRadius(ghostPupilRadius);
        ghostPupil2.setRadius(ghostPupilRadius);
        ghostPupil1.setFillColor(Color::Blue);
        ghostPupil2.setFillColor(Color::Blue);
        window.draw(ghostPupil1);
        window.draw(ghostPupil2);

        int smallDotRadius = pacmanRadius/6;
        CircleShape smallDot1;
        smallDot1.setPosition(150-smallDotRadius, 100-smallDotRadius);
        smallDot1.setRadius(smallDotRadius);
        smallDot1.setFillColor(Color::White);
        window.draw(smallDot1);
        CircleShape smallDot2;
        smallDot2.setPosition(200-smallDotRadius, 100-smallDotRadius);
        smallDot2.setRadius(smallDotRadius);
        smallDot2.setFillColor(Color::White);
        window.draw(smallDot2);
        CircleShape smallDot3;
        smallDot3.setPosition(250-smallDotRadius, 100-smallDotRadius);
        smallDot3.setRadius(smallDotRadius);
        smallDot3.setFillColor(Color::White);
        window.draw(smallDot3);

        int bigDotRadius = pacmanRadius/3;
        CircleShape bigDot1;
        bigDot1.setPosition(300-bigDotRadius, 100-bigDotRadius);
        bigDot1.setRadius(bigDotRadius);
        bigDot1.setFillColor(Color::White);
        window.draw(bigDot1);

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
