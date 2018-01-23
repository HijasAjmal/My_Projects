//SMILEY
#include<stdio.h>
#include<graphics.h>
void line1(int,int,int,int);
main()
{
	int gd=DETECT,gm,e,f,c,h,i;
	initgraph(&gd,&gm,"");
	setbkcolor(15);
	setcolor(7); 
	e=getmaxy();
	f=getmaxx();
	circle(f/2,e/2,100);
	c=(f/2);
	h=(e/2);
	floodfill(c+50,h+50,7);
	setcolor(BLACK);
	circle(c-50,h-40,20);
	floodfill(c-50,h-40,BLACK);
	setcolor(BLACK);
	circle(c+50,h-40,20);
	floodfill(c+50,h-40,BLACK);
	line(c-50,h+40,c+50,h+40);  // : |
	//  line(c-50,h-10,c-50,h);    // :'
	// line(c-50,h+50,c-50,h+100);
	//line(c-50,h+40,c-40,h+50);  
	// line(c-40,h+50,c-30,h+60);
	delay(1000);
	cleardevice();
	setcolor(7); 
	e=getmaxy();
	f=getmaxx();
	circle(f/2,e/2,100);
	c=(f/2);
	h=(e/2);
	floodfill(c+50,h+50,7);
	setcolor(BLACK);
	circle(c-50,h-40,20);
	floodfill(c-50,h-40,BLACK);
	setcolor(BLACK);
	circle(c+50,h-40,20);
	floodfill(c+50,h-40,BLACK);
	setcolor(BLUE);
	line(c-50,h-10,c-50,h); 
	line(c+50,h-10,c+50,h); 
	line(c-50,h+5,c-50,h+10); 
	line(c+50,h+5,c+50,h+10); 
	setcolor(BLACK);
	arc(c,h+30,180,0,25);
	getch();
}
