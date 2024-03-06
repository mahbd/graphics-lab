#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int xmin, xmax, ymin, ymax;

struct lines {
    int x1, y1, x2, y2;
};


void clip(struct lines mylines) {
    int bits1 = 0, bits2 = 0, i, var;
    setcolor(YELLOW);
    bits1 |= (ymax < mylines.y1) << 3;
    bits2 |= (ymax < mylines.y2) << 3;
    bits1 |= (ymin > mylines.y1) << 2;
    bits2 |= (ymin > mylines.y2) << 2;
    bits1 |= (xmax < mylines.x1) << 1;
    bits2 |= (xmax < mylines.x2) << 1;
    bits1 |= (xmin > mylines.x1) << 0;
    bits2 |= (xmin > mylines.x2) << 0;

    if (bits1 == bits2 && bits1 == 0) {
        line(mylines.x1, mylines.y1, mylines.x2, mylines.y2);
        return;
    }

    if ((bits1 & bits2) != 0) {
        return;
    }

    float m = (mylines.y2 - mylines.y1) / (float)(mylines.x2 - mylines.x1);
    float c = mylines.y1 - m * mylines.x1;
    if ((bits1 & (1 << 0)) != (bits2 & (1 << 0))) {
        if ((bits1 & (1 << 0)) != 0) {
            var = round(m * xmin + c);
            mylines.y1 = var;
            mylines.x1 = xmin;
        }
        if ((bits2 & (1 << 0)) != 0) {
            var = round(m * xmin + c);
            mylines.y2 = var;
            mylines.x2 = xmin;
        }
    }

    if ((bits1 & (1 << 1)) != (bits2 & (1 << 1))) {
        // Case when initial point is in right of xmax
        if ((bits1 & (1 << 1)) != 0) {
            var = round(m * xmax + c);
            mylines.y1 = var;
            mylines.x1 = xmax;
        }
        // Case when final point is in right of xmax
        if ((bits2 & (1 << 1)) != 0) {
            var = round(m * xmax + c);
            mylines.y2 = var;
            mylines.x2 = xmax;
        }
    }
    if ((bits1 & (1 << 2)) != (bits2 & (1 << 2))) {
            cout << "3rd bit" << endl;
        // Case when initial point is in top of ymin
        if ((bits1 & (1 << 2)) != 0) {
            var = round((float)(ymin - c) / m);
            mylines.y1 = ymin;
            mylines.x1 = var;
        }
        // Case when final point is in top of ymin
        if ((bits2 & (1 << 2)) != 0) {
            var = round((float)(ymin - c) / m);
            mylines.y2 = ymin;
            mylines.x2 = var;
        }
    }
    if ((bits1 & (1 << 3)) != (bits2 & (1 << 3))) {
        // Case when initial point is in bottom of ymax
        if ((bits1 & (1 << 3)) != 0) {
            var = round((float)(ymax - c) / m);
            mylines.y1 = ymax;
            mylines.x1 = var;
        }
        // Case when final point is in bottom of ymax
        if ((bits2 & (1 << 3)) != 0) {
            var = round((float)(ymax - c) / m);
            mylines.y2 = ymax;
            mylines.x2 = var;
        }
    }
    line(mylines.x1, mylines.y1, mylines.x2, mylines.y2);
}

// Driver Function
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Setting values of Clipping window
    xmin = 40;
    xmax = 100;
    ymin = 40;
    ymax = 80;

    // initialize the graph

    // Drawing Window using Lines
    line(xmin, ymin, xmax, ymin);
    line(xmax, ymin, xmax, ymax);
    line(xmax, ymax, xmin, ymax);
    line(xmin, ymax, xmin, ymin);

    // Assume 4 lines to be clipped
    struct lines mylines[4];

    // Setting the coordinated of 4 lines
    mylines[0].x1 = 30;
    mylines[0].y1 = 65;
    mylines[0].x2 = 55;
    mylines[0].y2 = 30;

    mylines[1].x1 = 60;
    mylines[1].y1 = 20;
    mylines[1].x2 = 100;
    mylines[1].y2 = 90;

    mylines[2].x1 = 60;
    mylines[2].y1 = 100;
    mylines[2].x2 = 80;
    mylines[2].y2 = 70;

    mylines[3].x1 = 85;
    mylines[3].y1 = 50;
    mylines[3].x2 = 120;
    mylines[3].y2 = 75;

    // Drawing Initial Lines without clipping
    for (int i = 0; i < 4; i++) {
        line(mylines[i].x1, mylines[i].y1,
             mylines[i].x2, mylines[i].y2);
        delay(1000);
    }

    // Drawing clipped Line
    for (int i = 0; i < 4; i++) {
        // Calling clip() which in term clip the line as per window and draw it
        clip(mylines[i]);
        delay(1000);
    }
    delay(4000);
    getch();
    // For Closing the graph.
    closegraph();
    return 0;
}
