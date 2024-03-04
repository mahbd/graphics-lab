#include <graphics.h>
#include <math.h>

void drawCircle(int xc, int yc, int radius) {
    int x = radius;
    int y = 0;
    int p = 1 - radius;
    putpixel(xc + x, yc - y, WHITE);
    if (radius > 0) {
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
    }
    int two_x = 2 * x;
    int two_y = 2 * y;

    while (x > y) {
        y++;
        if (p <= 0)
            p = p + two_y + 1;
        else {
            x--;
            p = p + two_y - two_x + 1;
        }
        if (x < y)
            break;
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        if (x != y) {
            putpixel(xc + y, yc - x, WHITE);
            putpixel(xc - y, yc - x, WHITE);
            putpixel(xc + y, yc + x, WHITE);
            putpixel(xc - y, yc + x, WHITE);
        }
    }
}


int main() {
    int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	drawCircle(200, 200, 100);
	getch();
    return 0;
}
