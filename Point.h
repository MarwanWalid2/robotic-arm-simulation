#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <iostream>
using namespace std;
class Point {

private:
    double x;
    double y;
public:
//constructor of the class
    Point()
     {
     x = 0;
     y = 0;
     }

     Point(double a, double b)
     {
     x = a;
     y = b;
     }
//main getters and setters
     double getX() { return (x); }
     void setX(double value) { x = value; }
     double getY() { return (y); }
     void setY(double value) { y = value; }
     void printPosition()
         {
         cout << "X = " << x << ", Y = " << y << endl;
         }

    };



#endif // POINT_H_INCLUDED
