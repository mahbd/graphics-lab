#include<iostream>
#include<graphics.h>
using namespace std;


void midPointCircleDraw(int x_centre, int y_centre, int r) {
    int x = 0, y = r;
    int P = 1 - r;
    while (y > x) {
        x++;
        if (P <= 0) {
            P = P + 2*x + 1;
        } else {
            y--;
            P = P + 2*x - 2*y + 1;
        }

        putpixel(x + x_centre, y + y_centre, WHITE);
        putpixel(-x + x_centre, y + y_centre, WHITE);
        putpixel(x + x_centre, -y + y_centre, WHITE);
        putpixel(-x + x_centre, -y + y_centre, WHITE);
        putpixel(y + x_centre, x + y_centre, WHITE);
        putpixel(-y + x_centre, x + y_centre, WHITE);
        putpixel(y + x_centre, -x + y_centre, WHITE);
        putpixel(-y + x_centre, -x + y_centre, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    midPointCircleDraw(60, 60, 50);
    getch();
    return 0;
}
