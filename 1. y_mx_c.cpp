#include <graphics.h>
#include <bits/stdc++.h>


void ymxc(int x1, int y1, int x2, int y2) {
    double m = double (y2 - y1) / (x2 - x1);
    double c = y1 - m * x1;
    for (int x = x1; x <= x2; x++) {
        int y = round(m * x + c);
        putpixel(x, y, WHITE);
    }
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	ymxc(20, 50, 100, 300);
	getch();
	return 0;
}
