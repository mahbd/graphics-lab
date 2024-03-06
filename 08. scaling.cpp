#include <graphics.h>
#include <bits/stdc++.h>

int n, x[100], y[100], i;
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
    cout << "Enter no. of sides in polygon: ";
    cin >> n;
    cout << "Enter coordinates x, y for each vertex: ";
    for (i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << "Enter scale factors: sfx and sfy : ";
    cin >> sfx >> sfy;
    scale();
    getch();
    return 0;
}
