#include <iostream>
#include <fstream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Polygon.h"
#include "ScaleneTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Rhombus.h"


// Function to parse the input file and create Polygon objects
std::vector<Polygon*> parseFile(const std::string& filename) {
    std::vector<Polygon*> polygons;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return polygons;
    }

    char type;
    double x1, y1, x2, y2, x3, y3, x4 = 0, y4 = 0; // Initialize x4 and y4
    int r, g, b;
    while (file >> type >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> g >> b) {
        if (type == 'R') { // If the type is 'R', read x4 and y4
            file >> x4 >> y4;
        }

        Polygon* poly = nullptr;
        if (type == 'S') {
            poly = new ScaleneTriangle();
        } else if (type == 'I') {
            poly = new IsoscelesTriangle();
        } else if (type == 'E') {
            poly = new EquilateralTriangle();
        } else if (type == 'R') {
            poly = new Rhombus();
        }

        if (poly) {
            poly->setColor(sf::Color(r, g, b));
            poly->setCoordinate(0, {x1, y1});
            poly->setCoordinate(1, {x2, y2});
            poly->setCoordinate(2, {x3, y3});
            if (type == 'R') {
                poly->setCoordinate(3, {x4, y4});
            }
            if (poly->validate()) {
                polygons.push_back(poly);
            } else {
                std::cerr << "polygon is invalid - ";
                std::cerr << type << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " "
                          << x3 << " " << y3 << " " << x4 << " " << y4 << " " << r << " " << g << " " << b << std::endl;
                delete poly;
            }
        }
    }

    file.close();
    return polygons;
}

int main() {
    const std::string filename = "polygons.dat";
    std::vector<Polygon*> polygons = parseFile(filename);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Polygon Drawing");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (Polygon* poly : polygons) {
            poly->draw(window);
        }
        window.display();
    }

    // Cleanup
    for (Polygon* poly : polygons) {
        delete poly;
    }

    return 0;
}
