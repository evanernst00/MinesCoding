#ifndef BUBBLE_H
#define BUBBLE_H

#include <SFML/Graphics.hpp>

class Bubble
{
private:
    sf::CircleShape _bubble;
    double _xDir;
    double _yDir;
    const double _defaultXDir = 1;
    const double _defaultYDir = 2;
    const int _defaultRadius = 50;
    const sf::Color _defaultColor = sf::Color::White;
public:
    Bubble();
    Bubble(int x, int y);
    Bubble(int x, int y, double xDir, double yDir, int rad, sf::Color color);
    void updatePosition(int winHeight, int winWidth);
    void draw(sf::RenderWindow&);

    // Getters
    double getXDir();
    double getYDir();
    int getX();
    int getY();

    // Setters
    void setXDir(double x);
    void setYDir(double y);
    void setX(int x);
    void setY(int y);
};

#endif//BUBBLE_H
