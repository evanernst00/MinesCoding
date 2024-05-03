#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int rows;
int cols;

const int scale = 40;

int main()
{
    // Select maze
    string mazeInput = "1.maze";
    cout << "Enter the file name of the maze you would like to view (1.maze, 2.maze, etc.): ";
    cin >> mazeInput;

    // Select search method
    int searchMethod;
    cout << "Enter the search method you would like to use: \n1. Depth First Search \n2. Breadth First Search";
    while(true)
    {
        cin >> searchMethod;
        if(searchMethod == 1 || searchMethod == 2)
        {
            break;
        }
        cout << "Invalid search method. Please enter 1 or 2: ";
    }

    /////////////////////////////////////
    // FILE INPUT
    ifstream mazeFile("./mazePack/" + mazeInput);
    if(mazeFile.fail())
    {
        cerr << "Failed to open file";
        return -1;
    }

    mazeFile >> rows;
    mazeFile >> cols;

    vector<vector<char>> maze(rows, vector<char>(cols));

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            mazeFile >> maze[i][j];
    
        }
    }
    // END FILE INPUT
    /////////////////////////////////////

    // Print maze
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    /////////////////////////////////////
    // SFML

    RenderWindow window(VideoMode(cols*scale, rows*scale), "SFML Test");

    Event event;

    while (window.isOpen())
    {
        window.clear();

        /////////////////////////////////////
        // DRAW MAZE

        // Iterate through 2D maze vector and draw rectangles for each cell
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                RectangleShape rect(Vector2f(scale, scale));
                rect.setPosition(j * scale, i * scale);
                switch(maze[i][j])
                {
                    case '#':
                        rect.setFillColor(Color::Black);
                        break;
                    case '.':
                        rect.setFillColor(Color::White);
                        break;
                    case 'S':
                        rect.setFillColor(Color::Green);
                        break;
                    case 'E':
                        rect.setFillColor(Color::Red);
                        break;
                    default:
                        rect.setFillColor(Color::Black);
                        break;
                }
                window.draw(rect);
            }
        }

        //  END DRAWING MAZE
        /////////////////////////////////////

        /////////////////////////////////////
        // SEARCH ALGORITHM

        if(searchMethod == 1)
        {
            // Depth First Search
        }
        else
        {
            // Breadth First Search
        }

        // END SEARCH ALGORITHM
        /////////////////////////////////////



        window.display();
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
    }
    // SFML END
    /////////////////////////////////////

    return 0;
}
