#ifndef GHOST_H
#define GHOST_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Ghost
{
private:
    // Declare shapes that make up the ghost
    CircleShape head;
    RectangleShape body;
    CircleShape eye1;
    CircleShape eye2;
    CircleShape frill1;
    CircleShape frill2;
    CircleShape frill3;

    Vector2f pos;
    Color col;
    int height;
public:
    Ghost();
    Ghost(Vector2f setPos, const Color setCol, const int setHeight);
    void setPosition(Vector2f);
    void draw(RenderWindow& window);
};

#endif