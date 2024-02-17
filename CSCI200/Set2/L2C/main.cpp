#include <iostream>
#include "coordinate_conversion.hpp"

using namespace std;

int main()
{
    int conversionType;
    cout << "Input 1 or 2 to convert between polar coordinates and cartesian coordinates: " << endl 
    << "1: (r, θ) -> (x, y)" << endl 
    << "2: (x, y) -> (r, θ)" << endl;
    cin >> conversionType;

    double x, y, r, angle;
    if(conversionType == 1)
    {
        cout << "Input an angle: ";
        cin >> angle;
        cout << "Input a radius: ";
        cin >> r;

        polar_to_cartesian(r, angle, &x, &y);

        cout << "x: " << x << ", y: " << y << endl;
    }
    else
    {
        cout << "Input x: ";
        cin >> x;
        cout << "Input y: ";
        cin >> y;

        cartesian_to_polar(x, y, &r, &angle);

        cout << "Radius: " << r << ", Angle: " << angle << endl;
    }


    return 0;
}
