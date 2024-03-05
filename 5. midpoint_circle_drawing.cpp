// C++ program for implementing
// Mid-Point Circle Drawing Algorithm
#include<iostream>
#include<graphics.h>
using namespace std;

// Implementing Mid-Point Circle Drawing Algorithm
void midPointCircleDraw(int x_centre, int y_centre, int r) {
    int x = r, y = 0;
    int P = 1 - r;
    while (x > y) {
        y++;

        // Mid-point is inside or on the perimeter
        if (P <= 0)
            P = P + 2*y + 1;
        // Mid-point is outside the perimeter
        else {
            x--;
            P = P + 2*y - 2*x + 1;
        }

        // All the perimeter points have already been printed
        if (x < y)
            break;

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

// Driver code
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    midPointCircleDraw(60, 60, 30);
    getch();
    return 0;
}
