#include<iostream>
#include<graphics.h>

using namespace std;

void ellipse(int rx, int ry, int xc, int yc) {
    float dx, dy, p1, p2, x, y;
    x = 0;
    y = ry;

    p1 = (ry * ry) - (rx * rx * ry) +
         (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // Region 1
    while (dx < dy) {

        putpixel(x + xc, y + yc, WHITE);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(x + xc, -y + yc, WHITE);
        putpixel(-x + xc, -y + yc, WHITE);
        dx = dx + (2 * ry * ry);
        if (p1 < 0) {
            x++;
            p1 = p1 + dx + (ry * ry);
        } else {
            x++;
            y--;
            dy = dy - (2 * rx * rx);
            p1 = p1 + dx + (ry * ry) - dy;
        }
    }

    // Region 2
    p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
         ((rx * rx) * ((y - 1) * (y - 1))) -
         (rx * rx * ry * ry);
    while (y >= 0) {

        putpixel(x + xc, y + yc, WHITE);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(x + xc, -y + yc, WHITE);
        putpixel(-x + xc, -y + yc, WHITE);
        if (p2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            p2 = p2 + (rx * rx) - dy;
        } else {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            p2 = p2 + dx - dy + (rx * rx);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    ellipse(30, 60, 70, 70);
    getch();
    return 0;
}
