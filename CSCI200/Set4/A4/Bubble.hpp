#ifndef BUBBLE_HPP
#define BUBBLE_HPP

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Bubble
{
private:
    CircleShape bubble;
    double xDir;
    double yDir;
public:
    Bubble();
    Bubble(double, double);
    double getXDir();
    double getYDir();
    void setXDir(double);
    void setYDir(double);
    void draw(RenderWindow&);
};

Bubble::Bubble()
{
    bubble.setPosition(100, 100);
    bubble.setFillColor(Color::White);
    bubble.setRadius(100);
    xDir = 0;
    yDir = 0;
}

Bubble::Bubble(double x, double y)
{
    bubble.setPosition(100, 100);
    bubble.setRadius(100);
    bubble.setFillColor(Color::White);
    xDir = x;
    yDir = y;
}

inline double Bubble::getXDir() {return xDir;}

inline double Bubble::getYDir() {return yDir;}

inline void Bubble::setXDir(double x) 
{
    if(x>0) xDir = x;
}

inline void Bubble::setYDir(double y)
{
    if(y>0) yDir = y;
}

void Bubble::draw(RenderWindow& window)
{
    window.draw(bubble);
}

#endif//BUBBLE_HPP
