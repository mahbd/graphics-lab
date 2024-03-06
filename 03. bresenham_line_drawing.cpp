#include<bits/stdc++.h>
#include <graphics.h>

using namespace std;

void bresenham(int x1, int y1, int x2, int y2) {
    int delY2 = 2 * (y2 - y1);
    int p0 = delY2 - (x2 - x1);
    for (int x = x1, y = y1; x <= x2; x++) {
        putpixel(x, y, WHITE);
        p0 += delY2;
        if (p0 >= 0) {
            y++;
            p0 -= 2 * (x2 - x1);
        }
    }
}

int main() {
    int gd = DETECT, gm, x= 300,y=300;
	initgraph(&gd, &gm, "");
    int x0 = 100, y0 = 100, x1 = 180, y1 = 160;
    bresenham(x0, y0, x1, y1);
    getch();
    return 0;
}
