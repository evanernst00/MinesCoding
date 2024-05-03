#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>
using namespace std;

#include "Maze.h"

int scale = 40;

int main()
{
    // Select maze
    string mazeInput = "1.maze";
    cout << "Enter the file name of the maze you would like to view (1.maze, 2.maze, etc.): ";
    cin >> mazeInput;

    // Make life easier
    int searchMethod;
    if (mazeInput == "auto")
    {
        searchMethod = 1;
        mazeInput = "3.maze";
    }
    else
    {
        cout << "Enter the search method you would like to use: \n1. Depth First Search \n2. Breadth First Search\n";
        while (true)
        {
            cin >> searchMethod;
            if (searchMethod == 1 || searchMethod == 2)
            {
                break;
            }
            cout << "Invalid search method. Please enter 1 or 2: ";
        }
    }

    Maze maze(scale);
    maze.loadMaze(mazeInput);
    maze.printMaze();

    ///////////////////////////////////// SFML /////////////////////////////////////

    // Create window scaled to size of maze
    RenderWindow window(VideoMode(maze.getCols() * maze.scale, maze.getRows() * maze.scale), "SFML Test");
    Event event;

    while (window.isOpen())
    {
        sleep(milliseconds(50));

        window.clear();

        if(searchMethod == 1) maze.stepDepthFirstSearch();
        else if(searchMethod == 2) maze.stepBreadthFirstSearch();

        // Draw maze
        maze.drawMaze(window);

        window.display();
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if(Keyboard::isKeyPressed(sf::Keyboard::Escape) || Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                window.close();
            }
        }
    }

    return 0;
}
