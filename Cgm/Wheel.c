//WHEEL
#include<stdio.h>
#include<graphics.h>
#include<math.h>
main()
{
	double angle=0,theta;
	int i,a;
        int xc=50,yc=200,r=60;
        int x[15],y[15];
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	setbkcolor(15);
	a=xc+r;
	while(!kbhit())
	{
		while(a<=630)
		{
			theta=3.14*angle/180;
			cleardevice();
			setcolor(0);
	                circle(xc,yc,r);
                        setcolor(0);
                        circle(xc,yc,r+5);
			for(i=0;i<7;i++)
			{
				theta=M_PI*angle/180;
				x[i]=xc+r*cos(theta);
				y[i]=yc+r*sin(theta);
				angle+=60;
				line(xc,yc,x[i],y[i]);
			}
			angle+=2; xc+=2; a=xc+r;
			delay(100);
		}
		xc=50;	
                r=35; 
                a=xc+r;
	}
	getch();
}
