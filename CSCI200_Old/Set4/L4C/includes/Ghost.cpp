#include "ghost.h"

Ghost::Ghost()
{

}
Ghost::Ghost(Vector2f setPos, Color setCol, int setHeight)
{
    pos = setPos;
    col = setCol;
    height = setHeight;
}
void Ghost::setPosition(Vector2f newPos)
{
    pos = newPos;
}
void Ghost::draw(RenderWindow& window)
{
    window.draw(head);
}