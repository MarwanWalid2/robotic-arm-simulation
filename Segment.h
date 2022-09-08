#ifndef SEGMENT_H_INCLUDED
#define SEGMENT_H_INCLUDED
#include <iostream>
using namespace std;

class Segment {

private:

    Point start;
    Point end;
    double length,x,y;
    float angle;

public:
//constructor of the class
  Segment(){
    x=0;
    y=0;
    angle=0;
    }
//main getters and setters
    Point getStart() {return(start); }
    void setStart (Point value) {start = value; }
    double getlength (){return (length);}
    void setlength (double value){length=value;
    for(double i = length; i<=0; i=length)
        {cout << "error length, enter again: "; cin>>length;}
    }
    void setangle (double value){
        angle=value; x=length*cos(angle)+start.getX(); y=length*sin(angle)+start.getY();
        end.setX(x); end.setY(y);

    }
    double getangle (){return (angle);}
    double getX() { return (x); }
    void setX(double value) { x = value; }
    double getY() { return (y); }
    void setY(double value) { y = value; }
    Point getEnd () {return (end); }
    //print the info of the segment
    void printSegmentInfo() {
        cout << "-------------------"<<endl;
     cout << "start: "; start.printPosition();
     cout << "end: "; end.printPosition();
      cout<< "angle: "<<getangle()<<endl<<"length: "<<getlength()<<endl;
    }

};

#endif // SEGMENT_H_INCLUDED
