#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x1,y1,x2,y2,x3,y3;
    double s,c, angle;
    cout<<"Enter coordinates of triangle: ";
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    line(x2,y2, x3,y3);
    line(x3, y3, x1, y1);
    cout<<"Enter rotation angle: ";
    cin>>angle;
    c = cos(angle *M_PI/180);
    s = sin(angle *M_PI/180);

    x1 = floor(x1 * c - y1 * s);
    y1 = floor(x1 * s + y1 * c);
    x2 = floor(x2 * c - y2 * s);
    y2 = floor(x2 * s + y2 * c);
    x3 = floor(x3 * c - y3 * s);
    y3 = floor(x3 * s + y3 * c);
    setcolor(GREEN);
    line(x1, y1,x2, y2);
    line(x2,y2, x3,y3);
    line(x3, y3, x1, y1);
    getch();
    return 0;
}
