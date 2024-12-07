#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main(){
	int gd=DETECT, gm, x1, y1, x2, y2, x, y, k, dy, dx, s, xi, yi;
	clrscr();
	initgraph(&gd, &gm, "C://TURBOC3//BGI");
	printf("Enter starting coordinates: ");
	scanf("%d%d", &x1, &y1);
	printf("Enter ending coordinates: ");
	scanf("%d%d", &x2, &y2);
	dx = x2-x1;
	dy = y2-y1;
	x = x1;
	y = y1;
	if(abs(dx) > abs(dy))
		s = abs(dx);
	else
		s = abs(dy);
	xi = dx/s;
	yi = dy/s;
	putpixel(x, y, WHITE);
	for(k=0; k<s; k++) {
		x += xi;
		y += yi;
		putpixel(x, y, WHITE);
	}
	getch();
	closegraph();
}



