#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>
#include "Maze.h"

using namespace sf;
using namespace std;

Maze::Maze()
{
    _rows = 0;
    _cols = 0;
    scale = 40;
}

Maze::Maze(int setScale)
{
    _rows = 0;
    _cols = 0;
    scale = setScale;
}

void Maze::loadMaze(std::string filename)
{
    ifstream mazeFile("./mazePack/" + filename);
    if (mazeFile.fail())
    {
        cerr << "Failed to open file";
        return;
    }

    mazeFile >> _rows >> _cols;

    _maze = vector<vector<char>>(_rows, vector<char>(_cols, '.'));
    _visited = vector<vector<bool>>(_rows, vector<bool>(_cols, false));

    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            mazeFile >> _maze[i][j];
            if (_maze[i][j] == 'S')
            {
                _start = make_pair(i, j);
            }
            if (_maze[i][j] == 'E')
            {
                _end = make_pair(i, j);
            }
        }
    }

    _stack.push(_start);
    _queue.push(_start);
}

void Maze::drawMaze(RenderWindow &window)
{
    // Iterate through 2D maze vector and draw rectangles for each cell
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            RectangleShape rect(Vector2f(scale, scale));
            rect.setPosition(j * scale, i * scale);

            // Set tile color based on cell type
            switch (_maze[i][j])
            {
            case '#': // wall
                rect.setFillColor(Color::Black);
                break;
            case '.': // unvisited
                rect.setFillColor(Color::White);
                break;
            case 'x': // visited
                rect.setFillColor(Color::Magenta);
                break;
            case 'S': // start
                rect.setFillColor(Color::Green);
                break;
            case 'E': // end
                rect.setFillColor(Color::Red);
                break;
            default:
                rect.setFillColor(Color::Black);
                break;
            }

            window.draw(rect);
        }
    }
}

void Maze::stepDepthFirstSearch()
{
    if (!_stack.empty())
    {
        pair<int, int> current = _stack.top();
        _stack.pop();

        // Only process if not visited
        if (!_visited[current.first][current.second])
        {
            _visited[current.first][current.second] = true; // Mark as visited

            if (_maze[current.first][current.second] == 'E')
            {
                cout << "End has been reached" << endl;
                _stack = stack<pair<int, int>>(); // Clear stack
                return;
            }
            // Update visited for animation, avoiding S and E
            else if (_maze[current.first][current.second] != 'S')
            {
                _maze[current.first][current.second] = 'x';
            }

            // Push adjacent cells that are not walls and not visited
            pushIfAccessible(current.first - 1, current.second); // Up
            pushIfAccessible(current.first + 1, current.second); // Down
            pushIfAccessible(current.first, current.second - 1); // Left
            pushIfAccessible(current.first, current.second + 1); // Right
        }
    }
}

void Maze::stepBreadthFirstSearch()
{
    if (!_queue.empty())
    {
        pair<int, int> current = _queue.front();
        _queue.pop();

        // Only process if not visited
        if (!_visited[current.first][current.second])
        {
            _visited[current.first][current.second] = true; // Mark as visited
            _maze[current.first][current.second] = 'x';

            if (_maze[current.first][current.second] == 'E')
            {
                cout << "End has been reached" << endl;
                _queue = queue<pair<int, int>>(); // Clear queue
                return;
            }
            // Update visited for animation, avoiding S and E
            else if (_maze[current.first][current.second] != 'S')
            {
                _maze[current.first][current.second] = 'x';
            }

            // Push adjacent cells that are not walls and not visited
            pushIfAccessible(current.first - 1, current.second); // Up
            pushIfAccessible(current.first + 1, current.second); // Down
            pushIfAccessible(current.first, current.second - 1); // Left
            pushIfAccessible(current.first, current.second + 1); // Right
        }
    }
}

void Maze::printMaze()
{
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            cout << _maze[i][j];
        }
        cout << endl;
    }
}

void Maze::pushIfAccessible(int row, int col)
{
    if (row >= 0 && row < _rows && col >= 0 && col < _cols && _maze[row][col] != '#' && !_visited[row][col])
    {
        _stack.push(make_pair(row, col)); // Use this line in DFS
        _queue.push(make_pair(row, col)); // Use this line in BFS
    }
}

int Maze::getRows() { return _rows; }
int Maze::getCols() { return _cols; }
