                    ///* Marwan AbdElhameed *///

#include <iostream>
#include <cmath>
#include <graphics.h>
#include "Point.h"
#include "Segment.h"
#include "Robot.h"
using namespace std;

int main (){
    //variables declaration
   double length,x,y;
    double angle;
    int segs,choice;

    cout << "num of segs: ";
    cin >> segs;
    Robot r0;
    //check if number of segments is equal to zero
    if (segs == 0){

        r0.zeroseg();
        exit(0);
    }
    for(int i = segs; i<0; i=segs)
        {cout << "error num of segs, enter again: "; cin>>segs;}
   //declare arrays of points and segemnts
    Point * p = new Point [segs+1];
    Segment s [segs+1];
     //enter start point
    cout << "enter start point: "<<"x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    p[0].setX(x);
    p[0].setY(y);
//create segments
    for (int i =0; i<segs; i++){
        s[i].setStart(p[i]);
        cout << "length: "; cin>>length;
        s[i].setlength(length);
        cout << "angle: "; cin>>angle;
        s[i].setangle(angle);
        p[i+1]=s[i].getEnd();
    }
    //declare a robot s=object
    Robot r1 (s, segs);
    cout << "move the robot?"<<endl;
    bool repeat = true;
 while (repeat){
    cout << "0 = exit, 1 = move the robot, 2 = add segments, 3 = remove segments, 4 = reset to default, 5 = current pose: ";
    cin >> choice;
    switch (choice){
        //close the program
        case 0:{
            repeat = false;
            cout << "exitting";
            exit (0);
        }
        //change angles of segments
        case 1:{
             float angles [r1.getsegs()];
            for (int i=0; i<r1.getsegs(); i++){
                cout << "enter angle of segment: ";
                cin >> angles[i];
            }

            r1.changeangles(angles);
            break;
        }
        //add segments
        case 2:{
            r1.addseg();
            break;
        }
        //remove segments
        case 3:{
            r1.removeseg();
            break;
        }
        //set segments to default
        case 4:{
            r1.setdefault();
            break;
        }
        //print robot position
        case 5:{
            r1.prntpose();
            break;
        }
        }}
        //deallocate the memory of the pointer
    delete [] p;
return 0;
}
