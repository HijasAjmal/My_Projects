#include<graphics.h>
#include<stdio.h>
#include<math.h>
void main()
{
int gd=DETECT,gm,option,xref,yref;
int i,maxx,maxy,x1,y1,x2,y2,x3,y3,x4,y4,gap=50;
float shx=0.0,shy=0.0;
char str[5];
printf("enter the  endpoints of the top of the rectangle (x1,y1) & (x2,y2):");
 scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
 printf("enter the endpoints of bottom of the rectangle (x3,y3) & (x4,y4)");
 scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
 printf(" Enter the axis to shear\n");
 printf(" 1 - X axis Shear\n");
 printf(" 2 - Y axis shear\n");
 scanf("%d",&option );
 if(option==1)
 {
 printf("enter the value for x-axis shear( can be fraction too):");
 scanf("%f",&shx);
 }
 else
 {
 printf("enter the value for y-axis shear( can be fraction too):");
 scanf("%f",&shy);
 }
initgraph(&gd,&gm," ");
setbkcolor(15);
maxx= getmaxx();
maxy=getmaxy();
/*line(3,maxy-1,maxx-5,maxy-1);
line(5,5,5,maxy-3);

 setcolor(50);*/
 setcolor(0);            
 line(x1,maxy-y1,x2,maxy-y2);
 line(x3,maxy-y3,x4,maxy-y4);
 line(x1,maxy-y1,x3,maxy-y3);
 line(x2,maxy-y2,x4,maxy-y4);
 outtextxy(10,10,"hit any key to see the shearing effect" );
 getch();
 setcolor(15);    // to hide the rectangle drawn
  line(x1,maxy-y1,x2,maxy-y2);
  line(x3,maxy-y3,x4,maxy-y4);
  line(x1,maxy-y1,x3,maxy-y3);
  line(x2,maxy-y2,x4,maxy-y4);

   setcolor(0);    // to redraw the rectangle
 if(option==1)
  {
  // shearing about x axis so only  points x1 and x2 need to be recomputed
  line(x1+shx*y1,maxy-y1,x2+shx*y2,maxy-y2);
  line(x3,maxy-y3,x4,maxy-y4);
  line(x1+shx*y1,maxy-y1,x3,maxy-y3);
  line(x2+shx*y2,maxy-y2,x4,maxy-y4);

 }
 else
 {
   // shearing about y axis so only  points y2 and y4 need to be recomputed
  line(x1,maxy-y1,x2,maxy-(y2+shy*x2));
  line(x3,maxy-y3,x4,maxy-(y4+shy*x4));
  line(x1,maxy-y1,x3,maxy-y3);
  line(x2,maxy-(y2+shy*x2),x4,maxy-(y4+shy*x4));

 }
 getch();
 closegraph();
}