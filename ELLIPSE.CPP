#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void drawEllipse(int xc, int yc, int a, int b) {
    int x = 0, y = b;
    long a2 = a * a;
    long b2 = b * b;
    long twoA2 = 2 * a2;
    long twoB2 = 2 * b2;
    long d;

    // Region 1
    d = b2 - a2 * b + 0.25 * a2;
    while (twoB2 * x <= twoA2 * y) {
        putpixel(xc + x, yc + y, 15);
        putpixel(xc - x, yc + y, 15);
        putpixel(xc + x, yc - y, 15);
	putpixel(xc - x, yc - y, 15);
        if (d < 0) {
            x++;
            d += twoB2 * x + b2;
        } else {
            x++;
            y--;
            d += twoB2 * x - twoA2 * y + b2;
        }
    }

    // Region 2
    d = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y >= 0) {
        putpixel(xc + x, yc + y, 15);
        putpixel(xc - x, yc + y, 15);
        putpixel(xc + x, yc - y, 15);
	putpixel(xc - x, yc - y, 15);
        if (d > 0) {
	    y--;
	    d -= twoA2 * y + a2;
	} else {
	    x++;
	    y--;
	    d += twoB2 * x - twoA2 * y + a2;
	}
    }
}

void main() {
    int gd=DETECT, gm, xc, yc, a, b;
    clrscr();
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("Enter xCentre and yCentre: ");
    scanf("%d%d", &xc, &yc);
    printf("Enter xRadius and yRadius: ");
    scanf("%d%d", &a, &b);
    drawEllipse(xc, yc, a, b);
    getch();
    closegraph();
}
