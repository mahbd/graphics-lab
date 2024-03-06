#include <graphics.h>
#include <bits/stdc++.h>

int n = 3, x[100], y[100], i;
float sfx, sfy;
using namespace std;

void draw() {
    for (i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}

void scale() {
    setcolor(RED);
    draw();
    for (i = 0; i < n; i++) {
        x[i] = x[i] * sfx;
        y[i] = y[i] * sfy;
    }
    setcolor(YELLOW);
    draw();
}

int main() {
    int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
    x[0] = 100, y[0] = 150, x[1] = 150, y[1] = 200, x[2] = 200, y[2] = 100;
    sfx = 1.5, sfy = 1.5;
    scale();
    getch();
    return 0;
}
