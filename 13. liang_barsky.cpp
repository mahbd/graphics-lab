#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

int xmin = 40, xmax = 100, ymin = 40, ymax = 80;


void liangBarsky(int x1, int y1, int x2, int y2) {
    setcolor(RED);
    line(x1, y1, x2, y2);
    int p[4], q[4];
    int dx = x2 - x1;
    int dy = y2 - y1;

    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;

    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0 && q[i] < 0) {
            cout << "Line is parallel to one of the clipping boundaries and outside the window." << endl;
            return;
        }
    }

    double u1 = 0, u2 = 1;

    for (int i = 0; i < 4; i++) {
        double r = (q[i]) / (double) p[i];
        if (p[i] < 0) {
            u1 = max(u1, r);
        } else if (p[i] > 0) {
            u2 = min(u2, r);
        }
    }

    if (u1 <= u2) {
        int clippedX1 = x1 + u1 * dx;
        int clippedY1 = y1 + u1 * dy;
        int clippedX2 = x1 + u2 * dx;
        int clippedY2 = y1 + u2 * dy;

        delay(1000);
        setcolor(WHITE);
        line(clippedX1, clippedY1, clippedX2, clippedY2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(xmin, ymin, xmax, ymax);
    int x1 = 30, y1 = 65, x2 = 55, y2 = 30;
    delay(1000);
    liangBarsky(x1, y1, x2, y2);
    getch();

    return 0;
}
