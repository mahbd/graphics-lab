#include<bits/stdc++.h>
#include<graphics.h>

void boundary(int x, int y, int fill_color,int boundary_color) {
    if(getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
        putpixel(x, y, fill_color);
        boundary(x + 1, y, fill_color, boundary_color);
        boundary(x, y + 1, fill_color, boundary_color);
        boundary(x - 1, y, fill_color, boundary_color);
        boundary(x, y - 1, fill_color, boundary_color);
    }
}

int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    setcolor(RED);
    rectangle(50,50,250,250);
    boundary(55,55,GREEN,RED);
    getch();
    return 0;
}
