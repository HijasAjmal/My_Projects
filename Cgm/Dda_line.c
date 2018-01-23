//DDA LINE
#include<stdio.h>
#include<graphics.h>
#include<math.h>       
void line1(int,int,int,int);
main()
{
	int gd=DETECT,gm,i;
	int x1,y1,x2,y2,k,j;
	printf("\n Enter the co-ordinates \n");
	scanf("\n%d\n%d\n%d\n%d",&x1,&y1,&x2,&y2);
	initgraph(&gd,&gm,"");
	setbkcolor(15);
	j = x2;
	for(k=x1;k<500;k++){
			j+=1;
			line1(k,y1,j,y2);
			delay(10);
	}
	getch();
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
	putpixel(x1,y1,0);
	x=x1;
	y=y1;
	for(i=0;i<=l;i++)
	{
		x=x+xinc;
		y=y+yinc;
		putpixel(round(x),round(y),0);
	}
	cleardevice();
}

