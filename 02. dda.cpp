#include <graphics.h>
#include <math.h>

void dda(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps;
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }
    double x_incr = (double)dx / steps;
    double y_incr = (double)dy / steps;
    double x = x0, y = y0;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += x_incr;
        y += y_incr;
    }
}

int main() {
    int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
    dda(-100, -100, 180, 160);
    getch();
    return 0;
}
