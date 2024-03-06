#include <graphics.h>
#include <math.h>

void drawCircle(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int p = 3 - 2 * radius;
    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;
        if (p > 0) {
            y--;
            p = p + 4 * (x - y) + 10;
        } else {
            p = p + 4 * x + 6;
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
