//MIDPOINT CIRCLE
#include<stdio.h>
#include<graphics.h>
void circle1(int,int,int);
void circlepoint(int,int,int,int);
void line1(int,int,int,int);
main()
{
	int gd=DETECT,gm;
	int r1,c1,c2,i,l=0;
	printf("\n Enter the radius \n");
	scanf("\n %d",&r1);
	printf("\n Enter the center co-ordinates \n");
	scanf("\n %d \n %d",&c1,&c2);
	initgraph(&gd,&gm,"");
	setbkcolor(0);
		for(i=c2;i>10;i--){
			l++;
			setcolor(14);
			circle(150,100,l);
			floodfill(150,100,14);
			circle1(r1,c1,i);
			line1(30,150,90,50);
			line1(90,50,150,120);
			line1(150,120,210,50);
			line1(210,50,270,150);
			delay(80);
		}
	getch();
}
void circle1(int r2,int c1,int c2)
{
	int x,y,d,q,w;
	x=0;
	y=r2;
	d=1-r2;
	q=c1;
	w=c2;
	circlepoint(x,y,q,w);
	while(y>x)
	{
		if(d<0)
		{
			d=(d+(2*x+3));
		}
		else
		{
			d=(d+(2*(x-y))+5);
			y--;
		}
		x++;
		circlepoint(x,y,q,w);
	}
	x=0;
	y=r2;
	d=1-r2;
	q=c1;
	w=c2;
	circlepoint1(x,y,q,w);
	while(y>x)
	{
		if(d<0)
		{
			d=(d+(2*x+3));
		}
		else
		{
			d=(d+(2*(x-y))+5);
			y--;
		}
		x++;
		circlepoint1(x,y,q,w);
	}
}
void circlepoint(int x,int y,int c1,int c2)
{
	putpixel((x+c1),(y+c2),5);
	putpixel((y+c1),(x+c2),5);
	putpixel((y+c1),(-x+c2),5);
	putpixel((x+c1),(-y+c2),5);
	putpixel((-x+c1),(-y+c2),5);
	putpixel((-y+c1),(-x+c2),5);
	putpixel((-y+c1),(x+c2),5);
	putpixel((-x+c1),(y+c2),5);
}
void circlepoint1(int x,int y,int c1,int c2)
{
	putpixel((x+c1),(y+c2),13);
	putpixel((y+c1),(x+c2),13);
	putpixel((y+c1),-x+c2,13);
	putpixel((x+c1),-y+c2,13);
	putpixel(-x+c1,-y+c2,13);
	putpixel(-y+c1,-x+c2,13);
	putpixel(-y+c1,(x+c2),13);
	putpixel(-x+c1,(y+c2),13);
}
void line1(int x1,int y1,int x2,int y2)
{
	double xinc,yinc,dx,dy,l,x,y;
	int i=0;
	dx=x2-x1;
	dy=y2-y1;
	if(dx>dy)
	{
		l=dx;
	}
	else
	{
		l=dy;
	}
	xinc=dx/l;
	yinc=dy/l;
	putpixel(x1,y1,15);
	x=x1;
	y=y1;
	for(i=0;i<=l;i++)
	{
		x=x+xinc;
		y=y+yinc;
		putpixel(round(x),round(y),15);
	}
}
