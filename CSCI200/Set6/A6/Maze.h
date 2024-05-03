#ifndef MAZE_H
#define MAZE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

class Maze
{
public:
    Maze();
    Maze(int setScale);
    void loadMaze(std::string filename);
    void drawMaze(sf::RenderWindow &window);
    void stepDepthFirstSearch();
    void stepBreadthFirstSearch();
    void printMaze();

    int getRows();
    int getCols();

    int scale;
private:
    void pushIfAccessible(int row, int col);

    int _rows;
    int _cols;
    std::pair<int, int> _start;
    std::pair<int, int> _end;
    std::stack<std::pair<int, int>> _stack; // for DFS
    std::queue<std::pair<int, int>> _queue; // for BFS
    std::vector<std::vector<char>> _maze; // Contains the maze
    std::vector<std::vector<bool>> _visited;  // Tracks visited cells
};

#endif // MAZE_H