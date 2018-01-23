#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
void main()
{
	int gm;
	int gd=DETECT;
	int x1,x2,x3,y1,y2,y3,x4,y4,c;
	int xt,yt,r;
	float t,sx,sy,nx1,nx2,nx3,ny1,ny2,ny3,nx4,ny4;
	printf("\t Program for basic transactions");
	printf("\n\t Enter the points of Rectangle");
	setcolor(1);
	scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	printf("\n 1.Transaction\n 2.Rotation\n 3.Scalling\n 4.exit");
	printf("Enter your choice:");
	scanf("%d",&c);
	if(c==1)
	{
		printf("\n Enter the translation factor");
		scanf("%d%d",&xt,&yt);
	}
	else if(c==2)
	{
		printf("\n Enter the angle of rotation");
		scanf("%d",&r);
	}
	else
	{
		printf("\n Enter the scalling factor");
		scanf("%f%f",&sx,&sy);
	}
	initgraph(&gd,&gm," ");
	setbkcolor(15);
	switch(c)
	{
		case 1:
			outtextxy(10,10,"Before Translation Rectangle");
			setcolor(0);
			line(x1,y1,x2,y2);
			line(x2,y2,x3,y3);
			line(x3,y3,x4,y4);
			line(x4,y4,x1,y1);
			delay(4000);
			cleardevice();
			outtextxy(10,10,"After Translation Rectangle");
			nx1=x1+xt;
			ny1=y1+yt;
			nx2=x2+xt;
			ny2=y2+yt;
			nx3=x3+xt;
			ny3=y3+yt;
			nx4=x4+xt;
			ny4=y4+yt;
			line(nx1,ny1,nx2,ny2);
			line(nx2,ny2,nx3,ny3);
			line(nx3,ny3,nx4,ny4);
			line(nx4,ny4,nx1,ny1);
			getch();

		case 2:
			outtextxy(10,10,"Before Rotation Rectangle");
			setcolor(0);
			line(x1,y1,x2,y2);
			line(x2,y2,x3,y3);
			line(x3,y3,x4,y4);
			line(x4,y4,x1,y1);
			delay(1000);
			cleardevice();
			outtextxy(10,10,"After Rotation Rectangle");
			t=3.14*r/180;
			nx1=abs(x1*cos(t)-y1*sin(t));
			ny1=abs(x1*sin(t)+y1*cos(t));
			nx2=abs(x2*cos(t)-y2*sin(t));
			ny2=abs(x2*sin(t)+y2*cos(t));
			nx3=abs(x3*cos(t)-y3*sin(t));
			ny3=abs(x3*sin(t)+y3*cos(t));
			nx4=abs(x4*cos(t)-y4*sin(t));
			ny4=abs(x4*sin(t)+y4*cos(t));
			line(nx1,ny1,nx2,ny2);
			line(nx2,ny2,nx3,ny3);
			line(nx3,ny3,nx4,ny4);
			line(nx4,ny4,nx1,ny1);
			getch();

		case 3:
			outtextxy(10,10,"Before Scalling Rectangle");
			setcolor(0);
			line(x1,y1,x2,y2);
			line(x2,y2,x3,y3);
			line(x3,y3,x4,y4);
			line(x4,y4,x1,y1);
			delay(1000);
			cleardevice();
			outtextxy(10,10,"After Scalling Rectangle");
			nx1=x1*sx;
			ny1=y2*sy;
			nx2=x2*sx;
			ny2=y2*sy;
			nx3=x3*sx;
			ny3=y3*sy;
			nx4=x4*sx;
			ny4=y4*sy;
			line(nx1,ny1,nx2,ny2);
			line(nx2,ny2,nx3,ny3);
			line(nx3,ny3,nx4,ny4);
			line(nx4,ny4,nx1,ny1);
			getch();

		case 4:
			break;
		default:
			printf("Enter the correct choice");
	}
	closegraph();
}
