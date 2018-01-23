//MIDPOINT LINE
#include<stdio.h>
#include<graphics.h>
void line1(int,int,int,int);
main()
{
  int gd=DETECT,gm;
  int x1,y1,x2,y2;
  printf("\n Enter the co-ordinates \n");
  scanf("\n %d \n %d \n %d \n %d",&x1,&y1,&x2,&y2);
  initgraph(&gd,&gm,"");
  setbkcolor(15);
  line1(x1,y1,x2,y2);
  getch();
}
void line1(int x1,int y1,int x2,int y2)
{
  int d,ince,incn,dx,dy,x,y;
  dx=x2-x1;
  dy=y2-y1;
  d=2*dx-dy;
  ince=2*dx;
  incn=2*(dx-dy);
  x=x1;
  y=y1;
  putpixel(x1,y1,0);
  while(y<y2)
  {
    if(d<=0)
    {
      d=d+ince;
      y++;
    }
    else
    {
      d=d+incn;
      x++;
      y++;
    }
   putpixel(x,y,0);
  }
}