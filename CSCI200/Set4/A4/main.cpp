#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

#include <vector>
#include <cstdlib>
#include <ctime>

#include "./Bubble.hpp"


int main() {
    // create a window
    const int winWidth = 640;
    const int winHeight = 640;
    RenderWindow window( VideoMode(winWidth, winHeight), "SFML Test" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    srand(time(NULL));

    // Create the bubble object
    const int startingBubbles = 5;
    const int minPos = 100;
    const int maxPos = 400;
    const double minDir = -4;
    const double maxDir = 4;
    const int minRad = 10;
    const int maxRad = 50;
    vector<Bubble> bubbles;
    for(int i=0; i<startingBubbles; i++)
    {
        // Generate a random bubble
        bubbles.push_back(
            Bubble(
                rand() % (maxPos-minPos) + minPos,                      // x
                rand() % (maxPos-minPos) + minPos,                      // y
                ((double)rand() / RAND_MAX) * (maxDir-minDir) + minDir, // xDir
                ((double)rand() / RAND_MAX) * (maxDir-minDir) + minDir, // yDir
                rand() % (maxRad-minRad) + minRad,                      // Radius
                Color(                                                  // Color
                    rand() % 256, // R
                    rand() % 256, // G
                    rand() % 256  // B
                )
            )
        );
    }

    // For tracking elapsed time
    Clock clock;

    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE



        for(size_t i=0; i<bubbles.size(); i++)
        {
            bubbles.at(i).draw(window);
        }



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
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                
                int tempRadius = rand() % (maxRad-minRad) + minRad;
                bubbles.push_back(
                    Bubble(
                        event.mouseButton.x - tempRadius,                       // x = where user clicked
                        event.mouseButton.y - tempRadius,                       // y = where user clicked
                        ((double)rand() / RAND_MAX) * (maxDir-minDir) + minDir, // xDir
                        ((double)rand() / RAND_MAX) * (maxDir-minDir) + minDir, // yDir
                        tempRadius,                                             // Radius
                        Color(                                                  // Color
                            rand() % 256, // R
                            rand() % 256, // G
                            rand() % 256  // B
                        )
                    )
                );
            }

            if (event.type == sf::Event::KeyPressed) {
                // D removes last bubble
                if (event.key.code == sf::Keyboard::D) {
                    if(bubbles.size() > 0) bubbles.pop_back();
                }

                // Escape and Q close the window
                if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Q) {
                    window.close();
                }
            }
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////

        // Every 1/60th of a second, update the bubbles
        Time elapsedTime = clock.getElapsedTime();
        if(elapsedTime.asSeconds() >= 1.0/60) {

            for(size_t i=0; i<bubbles.size(); i++)
            {
                bubbles.at(i).updatePosition(winWidth, winHeight);
            }

            clock.restart();
        }

    }

    return 0;
}
