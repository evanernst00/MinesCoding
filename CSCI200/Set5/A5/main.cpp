#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "Coordinate.hpp"
#include "Polygon.h"
#include "./polygons/Triangle.h"
#include "./polygons/Quadrilateral.h"
#include "./polygons/triangles/IsoscelesTriangle.h"
#include "./polygons/triangles/EquilateralTriangle.h"
#include "./polygons/triangles/ScaleneTriangle.h"
#include "./polygons/quadrilaterals/Rhombus.h"

int main() 
{

    vector<Polygon*> polygons;

    ifstream polygonData("polygons.dat");
    if(polygonData.fail())
    {
        cerr << "Failed to open polygons.dat";
        return -1;
    }

    char fileReader;
    while(polygonData >> fileReader)
    {
        char c = fileReader;
        if (c == 'I') 
        {
            polygons.push_back(new IsoscelesTriangle());
        } 
        else if (c == 'E') 
        {
            polygons.push_back(new EquilateralTriangle());
        } 
        else if (c == 'S')
        {
            polygons.push_back(new ScaleneTriangle());
        }
        else if (c == 'R')
        {
            polygons.push_back(new Rhombus());
        }

        for(int i=0; i<3; i++)
        {
            double x, y;
            polygonData >> x >> y;
            polygons.back()->setCoordinate(i, Coordinate(x, y));
        }

        if(c == 'R')
        {
            double x, y;
            polygonData >> x >> y;
            polygons.back()->setCoordinate(3, Coordinate(x, y));
        }

        double r, g, b;
        polygonData >> r >> g >> b;
        polygons.back()->setColor(Color(r, g, b));

        if(!polygons.back()->validate())
        {
            sf::Color tempColor = polygons.back()->getColor();
            cout << "Polygon is invalid - " 
            << fileReader << " " // I, E, S, R (Polygon type)
            << polygons.back()->getCoordinate(0).x << " " // Coordinates
            << polygons.back()->getCoordinate(0).y << " " 
            << polygons.back()->getCoordinate(1).x << " " 
            << polygons.back()->getCoordinate(1).y << " " 
            << polygons.back()->getCoordinate(2).x << " " 
            << polygons.back()->getCoordinate(2).y << " "
            << (short int)tempColor.r << " " // Color
            << (short int)tempColor.g << " "
            << (short int)tempColor.b << endl;

            polygons.pop_back();
        }
    }

    polygonData.close();

    RenderWindow window( VideoMode(640, 640), "Polygon Land" );

    Event event;


    while( window.isOpen() ) 
    {
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        for(auto& p : polygons)
        {
            p->draw(window);
        }

        //  END  DRAWING HERE
        /////////////////////////////////////



        window.display();

        // Event handling
        while( window.pollEvent(event) ) 
        {
            if(event.type == Event::Closed) 
            {

                window.close();
            }
        }
    }

    return 0;
}
