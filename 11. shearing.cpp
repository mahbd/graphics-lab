#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int n = 4,x[100],y[100],i;
float shx,shy;

void draw() {
    for(i=0; i<n; i++)
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
}

void shearAlongX() {
    for(i=0; i<n; i++)
        x[i]= x[i] + shx * y[i];
}

void shearAlongY() {
    for(i=0; i<n; i++)
        y[i]= y[i] + shy * x[i];
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    x[0] = 50, y[0] = 50, x[1] = 150, y[1] = 50, x[2] = 150, y[2] = 100, x[3] = 50, y[3] = 100;
    shx = 0.5;
    shy = 0;

    setcolor(RED);
    draw();
    shearAlongX();
    shearAlongY();
    setcolor(BLUE);
    draw();
    getch();
    return 0;

}
