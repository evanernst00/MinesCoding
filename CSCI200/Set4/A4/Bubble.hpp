#ifndef BUBBLE_HPP
#define BUBBLE_HPP

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Bubble
{
private:
    CircleShape _bubble;
    double _xDir;
    double _yDir;
    const double _defaultXDir = 1;
    const double _defaultYDir = 2;
    const int _defaultRadius = 50;
    const Color _defaultColor = Color::White;
public:
    Bubble();
    Bubble(int x, int y);
    Bubble(int x, int y, double xDir, double yDir, int rad, Color color);
    void updatePosition(int winHeight, int winWidth);
    void draw(RenderWindow&);

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

/* ---------- Method Definitions ---------- */

Bubble::Bubble()
{
    _bubble.setPosition(100, 100);
    _bubble.setRadius(_defaultRadius);
    _bubble.setFillColor(_defaultColor);
    _xDir = _defaultXDir;
    _yDir = _defaultYDir;
}

Bubble::Bubble(int x, int y)
{
    _bubble.setPosition(x, y);
    _bubble.setRadius(_defaultRadius);
    _bubble.setFillColor(_defaultColor);
    _xDir = _defaultXDir;
    _yDir = _defaultYDir;
}

Bubble::Bubble(int x, int y, double xDir, double yDir, int rad, Color color)
{
    _bubble.setPosition(x, y);
    _bubble.setRadius(rad);
    _bubble.setFillColor(color);
    _xDir = xDir;
    _yDir = yDir;
}

void Bubble::updatePosition(int winHeight, int winWidth)
{
    if(winHeight) _xDir = _xDir + 1 - 1;
    if(((_bubble.getPosition().x + _bubble.getRadius()*2) >= winWidth) || // If the right edge of the bubble is greater than the right edge of the window
        (_bubble.getPosition().x <= 0))                                   // If the left edge of the bubble is less than the left edge of the window
    {
        _xDir = -_xDir;
    }
    if(((_bubble.getPosition().y + _bubble.getRadius()*2) >= winHeight) || // Check bottom edge of bubble is in bounds
         _bubble.getPosition().y <= 0)                                     // Check if bubble hits top
    {
        _yDir = -_yDir;
    }
    _bubble.move(_xDir, _yDir);
}

void Bubble::draw(RenderWindow& window)
{
    window.draw(_bubble);
}

// Getters
inline double Bubble::getXDir() { return _xDir; }
inline double Bubble::getYDir() { return _yDir; }
inline int Bubble::getX() { return _bubble.getPosition().x; }
inline int Bubble::getY() { return _bubble.getPosition().y; }

// Setters
inline void Bubble::setXDir(double x) { _xDir = x; }
inline void Bubble::setYDir(double y) { _yDir = y; }
inline void Bubble::setX(int x) { _bubble.setPosition( x, _bubble.getPosition().y ); }
inline void Bubble::setY(int y) { _bubble.setPosition( _bubble.getPosition().x, y ); }

#endif//BUBBLE_HPP
