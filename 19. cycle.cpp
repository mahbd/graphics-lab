#include<graphics.h>
#include<bits/stdc++.h>

using namespace std;

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

void mid_circle(int x_centre, int y_centre, int r) {
    int x = 0, y = r;
    int P = 1 - r;

    putpixel(x + x_centre, y + y_centre, WHITE);
    putpixel(-x + x_centre, y + y_centre, WHITE);
    putpixel(x + x_centre, -y + y_centre, WHITE);
    putpixel(-x + x_centre, -y + y_centre, WHITE);
    putpixel(y + x_centre, x + y_centre, WHITE);
    putpixel(-y + x_centre, x + y_centre, WHITE);
    putpixel(y + x_centre, -x + y_centre, WHITE);
    putpixel(-y + x_centre, -x + y_centre, WHITE);
    while (y > x) {
        x++;
        if (P <= 0) {
            P = P + 2*x + 1;
        } else {
            y--;
            P = P + 2*x + 1 - 2*y;
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

void cycle(int offset) {
    // wheels
    mid_circle(100 + offset, 300, 20);
    mid_circle(100 + offset, 300, 3);
    mid_circle(200 + offset, 300, 20);
    mid_circle(200 + offset, 300, 3);
    // padel
    mid_circle(150 + offset, 300, 10);
    dda(150 + offset, 300, 152 + offset, 320);
    rectangle(148 + offset, 320, 160 + offset, 335);
    // frame
    dda(200 + offset, 300, 190 + offset, 230);
    dda(150 + offset, 300, 190 + offset, 250);
    dda(150 + offset, 300, 100 + offset, 300);
    dda(100 + offset, 300, 110 + offset, 240);
    dda(150 + offset, 300, 110 + offset, 250);
    dda(190 + offset, 250, 90 + offset, 250);
    rectangle(105 + offset, 230, 115 + offset, 240);
    dda(200 + offset, 250, 180 + offset, 215);

}

int main() {
    int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	cycle(0);
	for (int i = 0; i < 500; i += 4) {
        cleardevice();
        cycle(i);
        delay(200);
	}
	getch();
	return 0;
}
