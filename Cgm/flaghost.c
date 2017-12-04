#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main()
{
	int gd,gm;
	int r,i,j,a,b,x,y;
	float PI=3.14;
	
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"");
	setcolor(WHITE);
        line(100,100,100,800);
         for(i=0;i<250;)
        {
	setcolor(WHITE);
        circle(400-i,450,25);
        line(400-i,475,400-i,550);
        line(400-i,500,350-i,470);
        line(400-i,500,450-i,480);
        line(400-i,550,350-i,600);
        line(400-i,550,450-i,600);
        i=i+10;
         delay(150);
        cleardevice();
        setcolor(WHITE);
        line(100,100,100,800);
        }
       for(i=0;i<200;)
        {
        setcolor(WHITE);
        line(100,100,100,800);
        setcolor(WHITE);
        circle(150,450,25);
        line(150,475,150,550);
        line(150,500,100,470);
        line(150,500,200,480);
        line(150,550,100,600);
        line(150,550,200,600);
        setcolor(WHITE);
        line(100,100,100,800);
        setcolor(RED);
	rectangle(100,300-i,450,350-i);//t
	floodfill(101,301-i,RED);
	setcolor(WHITE);
	rectangle(100,350-i,450,400-i);//m
	floodfill(101,351-i,WHITE);
	setcolor(GREEN);
	rectangle(100,400-i,450,450-i);//b
	floodfill(101,401-i,GREEN);
	a=275;	//center
	b=375-i;	//center
	r=25;	//radius
	setcolor(BLUE);
	circle(a,b,r);
	for(j=0;j<=660-i;j=j+15)
	{
		x=r*cos(j*PI/180);//spokes
		y=r*sin(j*PI/180);
		line(a,b,a+x,b-y);
	}
        i=i+10;
         delay(150);
        cleardevice();
       }
         setcolor(WHITE);
        line(100,100,100,800);
        setcolor(WHITE);
        circle(150,450,25);
        line(150,475,150,550);
        line(150,500,100,470);
        line(150,500,200,480);
        line(150,550,100,600);
        line(150,550,200,600);
        setcolor(WHITE);
        line(100,100,100,800);
        setcolor(RED);
	rectangle(100,100,450,150);//t
	floodfill(101,101,RED);
	setcolor(WHITE);
	rectangle(100,150,450,200);//m
	floodfill(101,151,WHITE);
	setcolor(GREEN);
	rectangle(100,200,450,250);//b
	floodfill(101,201,GREEN);
	a=275;	//center
	b=175;	//center
	r=25;	//radius
	setcolor(BLUE);
	circle(a,b,r);
	for(j=0;j<=360;j=j+15)
	{
		x=r*cos(j*PI/180);//spokes
		y=r*sin(j*PI/180);
		line(a,b,a+x,b-y);
	}
	getch();
	closegraph();
	return 0;
}
