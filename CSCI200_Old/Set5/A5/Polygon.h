#include <SFML/Graphics.hpp>
#include "Coordinate.h"
using namespace sf;
using namespace std;

class Polygon
{
public:
    Polygon();
    virtual ~Polygon();
    void setColor(Color& color);
    void draw(RenderTarget& window);
    void setCoordinate(int idx, Coordinate coord);

protected:
    int numVertices;
    Coordinate* vertices;

private:
    Color color;
};

Polygon::Polygon()
{
    Color color = Color::White;
    numVertices = 0;
    vertices = nullptr;
}

Polygon::~Polygon()
{
    delete vertices;
}