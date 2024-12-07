#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void drawcircle(int x0, int y0, int r) {
	int x = 0;
	int y = r;
	putpixel(x0, y0+r, 7);
	putpixel(x0, y0-r, 7);
	putpixel(x0-r, y0, 7);
	putpixel(x0+r, y0, 7);
	int p = 1-r;
	while(x<=y){
		if(p<0)
			p += (2*x)+1;
		else {
			p += (2*(x-y))+5;
			y--;
		}
		x++;
		putpixel(x0+x, y0+y, 7);
		putpixel(x0-x, y0+y, 7);
		putpixel(x0+x, y0-y, 7);
		putpixel(x0-x, y0-y, 7);
		putpixel(x0+y, y0+x, 7);
		putpixel(x0-y, y0+x, 7);
		putpixel(x0+y, y0-x, 7);
		putpixel(x0-y, y0-x, 7);
	}
}

void main() {
	int gd=DETECT, gm, x, y, r;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter co-ordinates of center(x and y): ");
	scanf("%d%d", &x, &y);
	printf("Enter radius of circle: ");
	scanf("%d", &r);
	drawcircle(x, y, r);
	getch();
	closegraph();
}