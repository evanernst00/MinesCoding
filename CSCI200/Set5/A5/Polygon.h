#ifndef POLYGON_H
#define POLYGON_H

#include <SFML/Graphics.hpp>

class Polygon
{
public:
    /**
     * @brief Sets the color to white, specifies the number of vertices as 0, sets the vertices array to be a nullptr
     * 
     */
    Polygon();

    /**
     * @brief Deallocates the vertices array
     * 
     */
    virtual ~Polygon();
    
    /**
     * @brief Sets the private color data member
     * 
     * @param color 
     */
    void setColor(const sf::Color color);

    /**
     * @brief Creates a ConvexShape, sets the points for each coordinate, sets the fill color, draws it to the provided window
     * 
     * @param window 
     */
    void draw(sf::RenderTarget& window);

    /**
     * @brief Sets the corresponding coordinate in the vertices array
     * 
     * @param idx 
     * @param coord 
     */
    void setCoordinate(int idx, Coordinate coord);

    /**
     * @brief Returns true if the set coordinates form the intended polygon
     * 
     * @return true 
     * @return false 
     */
    virtual bool validate() = 0;

protected:
    short int _numVertices;
    Coordinate* _vertices;

private:
    sf::Color _color;
};

#endif//POLYGON_H