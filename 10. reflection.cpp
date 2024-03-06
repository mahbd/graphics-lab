#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int n = 3, x[100], y[100], i;

void draw() {
    for (i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}

void reflection() {
    setcolor(WHITE);
    draw();
    for (i = 0; i < n; i++) {
        x[i] = x[i];
        y[i] = -y[i] + 500;
    }
    setcolor(GREEN);
    draw();
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    x[0]=200,y[0]=300,x[1]=500,y[1]=300,x[2]=350,y[2]=400;
    reflection();
    getch();
    return 0;
}
