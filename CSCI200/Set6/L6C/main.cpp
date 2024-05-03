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
    string mazeInput = "1.maze";
    cout << "Enter the file name of the maze you would like to view: ";
    cin >> mazeInput;

    /*------ File Input ------*/
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

    /*-------------*/

    // Print maze
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    RenderWindow window(VideoMode(cols*scale, rows*scale), "SFML Test");

    Event event;

    while (window.isOpen())
    {
        window.clear();

        // draw stuff
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
