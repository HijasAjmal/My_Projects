//BOUNCING BALL
#include<stdio.h>
#include<graphics.h>
void circle1(int,int,int);
void circlepoint(int,int,int,int);
main()
{
 int x,y,flag=1,y1;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"");
 setbkcolor(15);
 x=getmaxx()/4;
 y=getmaxy()/2;
 y1=100;
 while(x<590)
 {
  flag=!(flag);
  setcolor(0);
  circle1(30,x,y);
  floodfill(x,y,0);
  if(flag)
  {
    y=y-y1;
    x=x+50;
    y1=y1-10;
  }
  else
  {
    y=y+y1+10;
  }
  delay(200);
  cleardevice();
 }
  setcolor(0);
  circle1(30,x,y+y1);
  floodfill(x,y+y1,0);
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
}
void circlepoint(int x,int y,int c1,int c2)
{
  putpixel((x+c1),(y+c2),0);
  putpixel((y+c1),(x+c2),0);
  putpixel((y+c1),-x+c2,0);
  putpixel((x+c1),-y+c2,0);
  putpixel(-x+c1,-y+c2,0);
  putpixel(-y+c1,-x+c2,0);
  putpixel(-y+c1,(x+c2),0);
  putpixel(-x+c1,(y+c2),0);
}
