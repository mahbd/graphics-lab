#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int n = 3, x[100], y[100], i;

int xoff = 640 / 2, yoff = 480 / 2;

void draw() {
    for (i = 0; i < n; i++) {
        line(x[i] + xoff, y[i] + yoff, x[(i + 1) % n] + xoff, y[(i + 1) % n] + yoff);
    }
}

void reflection() {
    setcolor(WHITE);
    draw();
    for (i = 0; i < n; i++) {
        x[i] = x[i];
        y[i] = -y[i];
    }
    setcolor(GREEN);
    draw();
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    cout << getmaxx() << " " << getmaxy() << endl;

    x[0]=50,y[0]=75,x[1]=125,y[1]=75,x[2]=90,y[2]=100;
    reflection();
    getch();
    return 0;
}
