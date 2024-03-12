#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int xmin = 40, xmax = 100, ymin = 40, ymax = 80;

void clip(int x[], int y[]) {
    int bits[] = {0, 0}, i, var;
    setcolor(YELLOW);
    for (int i = 0; i < 2; i++) {
        bits[i] |= (ymax < y[i]) << 3;
        bits[i] |= (ymin > y[i]) << 2;
        bits[i] |= (xmax < x[i]) << 1;
        bits[i] |= (xmin > x[i]) << 0;
    }

    if (bits[0] == bits[1] && bits[0] == 0) {
        line(x[0], y[0], x[1], y[1]);
        return;
    }

    if ((bits[0] & bits[1]) != 0) {
        return;
    }

    float m = (y[1] - y[0]) / (float)(x[1] - x[0]);
    float c = y[0] - m * x[0];

    for (int i = 0; i < 4; i++) {
        if ((bits[0] & (1 << i)) != (bits[1] & (1 << i))) {
            int onBit = (bits[1] & (1 << i)) != 0;

            switch (i) {
            case 0:
                y[onBit] = round(m * xmin + c);
                x[onBit] = xmin;
                break;
            case 1:
                y[onBit] = round(m * xmax + c);
                x[onBit] = xmax;
                break;
            case 2:
                y[onBit] = ymin;
                x[onBit] = round((ymin - c) / m);
                break;
            case 3:
                y[onBit] = ymax;
                x[onBit] = round((ymax - c) / m);
                break;
            }
        }
    }
    line(x[0], y[0], x[1], y[1]);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(xmin, ymin, xmax, ymax);

    setcolor(RED);
    line(60, 20, 100, 90);
    delay(1000);


    int x[] = {60, 100};
    int y[] = {20, 90};
    clip(x, y);

    getch();
    return 0;
}
