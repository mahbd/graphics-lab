#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

int n = 3, x[100], y[100], i;
double angle;

void draw() {
    for (i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}

void rotation() {
    setcolor(WHITE);
    draw();
    double c = cos(angle *M_PI/180);
    double s = sin(angle *M_PI/180);

    for (i = 0; i < n; i++) {
        x[i] = floor(x[i] * c - y[i] * s);
        y[i] = floor(x[i] * s + y[i] * c);
    }

    setcolor(GREEN);
    draw();
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    x[0] = 100, y[0] = 150, x[1] = 150, y[1] = 200, x[2] = 200, y[2] = 100;
    angle = 20;
    rotation();
    getch();
    return 0;
}
