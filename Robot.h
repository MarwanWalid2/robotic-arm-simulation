#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED
#include <iostream>
using namespace std;
class Robot{

private:

int segs;
double x,y,length;
float angle;
int num, newnum;
Point start, end;
Segment s[];

public:
    //constructor of the class
    Robot(){
    segs=0;
    }
    Robot(Segment se[], int size){
    segs=size;
    for (int i=0; i<segs; i++){
    s[i]=se[i];
    }
    }
    //main getters and setters
   void setdefault(){
   for (int i =0; i<segs; i++){

        s[i].setangle(0);
        s[i+1].setStart(s[i].getEnd());
        s[i].printSegmentInfo();

   }

    cout << "done resetting"<<endl;
   }
    void setsegs (int value){segs=value;}
   void addseg(){
    cout << "how many segs you wanna add?: ";
    cin>>num;
    newnum=num+getsegs();
    Segment * s2 = new Segment [newnum];
    for (int i = 0; i<getsegs(); i++){
        s2[i]=s[i];
    }
    for (int i = getsegs(); i<newnum; i++){
   cout << "enter new end point: "<<endl;
    s2[i].setStart(s2[i-1].getEnd());
   cout << "length: "; cin>>length;
   cout << "angle: "; cin>>angle;
   s2[i].setlength(length);
   s2[i].setangle(angle);
    }
     for (int i = 0; i<newnum; i++){
        s[i]=s2[i];
        s[i].printSegmentInfo();
    }
    cout << "done"<<endl;
    setsegs(newnum);
    delete [] s2;
   }

   void removeseg(){

   cout << "how many segs you wanna remove?: ";
    cin>>num;
    newnum=segs-num;
    Segment * s3 = new Segment [newnum];
    for (int i = 0; i<newnum; i++){
        s3[i]=s[i];
        s[i]=s3[i];
        s[i].printSegmentInfo();
    }
    cout << "done"<<endl;
    setsegs(newnum);
    delete [] s3;
    }

    Point changeangles ( float angles[]){

        for (int i=0; i<getsegs(); i++){
        s[i].setangle(angles[i]);
        s[i+1].setStart(s[i].getEnd());
        s[i].printSegmentInfo();
        }
        Point end =s[getsegs()-1].getEnd();
        cout << "done: "<< "end: ";
         end.printPosition(); cout <<endl;
         return end;

    }
    int getsegs(){return (segs);}
    //graphing and printing the position of the robot
    void prntpose (){
        Point end, start;

        int gd=DETECT, gm;
            initgraph(&gd, &gm, (char*)"");
            int enlarger = 6;
            int x = 300 ;
            int y = 250 ;
            setcolor(8);
            setlinestyle(2, 0, 1);
            line(0,250,700,250);
            line(300,0,300,500);
            setcolor(15);
            setlinestyle(0, 0, 2);
          //  line(100,100,100,100);
            moveto(x,y);
           for(int i = 0; i < getsegs(); i++){
               start = s[i].getStart();
                end = s[i].getEnd();
                 int dx = (end.getX() - start.getX()  );
                int dy = ( end.getY() - start.getY()  );
                linerel(dx * enlarger, dy * (-1* enlarger) );

            }
             printrobotInfo();
            outtextxy(100,20, "Marwan");
            getch();
            closegraph;

    }

     void printrobotInfo() {
    for (int i = 0; i < getsegs(); i++){
    start = s[i].getStart();
    end = s[i].getEnd();
     cout << "-------------------"<<endl;
     cout << "start: "; start.printPosition();
     cout << "end: "; end.printPosition();
    }
    }
    void zeroseg (){

    cout << "no segments!"<<endl;
    s[0].setangle(0);
    Point zero (0,0);
    s[0].setStart(zero);
    }
   };

#endif // ROBOT_H_INCLUDED
