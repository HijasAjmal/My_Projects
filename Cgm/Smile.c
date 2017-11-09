
#include<stdio.h>
#include<math.h>
#include<graphics.h>
//void circle_points(int int int int);
int x,y,d,xt,yt,r,gd=DETECT,gm;
void main()
{ 
				//initialize the graphics
				initgraph(&gd,&gm," ");
				setcolor(14);
				//main circle
            			circle_cal(100,100,100);
			   	floodfill(110,110,5);
				//eye creation
				circle_cal1(60,60,25);
				circle_cal1(150,60,25);
				setcolor(BLACK);
				delay(1000);
				//angry
				arc(100,150,180,360,40);
				delay(1000);
				//hide the previous one
				setcolor(14);
				arc(100,150,180,360,40);
				setcolor(BLACK);
				delay(1000);
				//smiling
				arc(100,120,0,180,40);
				delay(1000);
				//happy
				line(60,120,140,120);
				getch();
            closegraph();
}

//main circle drawing function
void circle_cal(int xt, int yt, int r)
{
				
            x=0;
            y=r;
            d=1-r;
				circle_points1(xt,yt,x,y);
            while(x<y)
            {
                        if(d<0)
                        {
                                    x=x+1;
                                    d=d+(2*x)+1;
                        }
                        else
                        {
                                    x=x+1;
                                    y=y-1;
                                    d=d+(2*x)-(2*y)+1;
                        }
                        circle_points1(xt,yt,x,y);
		
            }
				
            
}
void circle_points1(int xt,int yt,int x,int y)
{
            putpixel(xt+x,yt+y,5);
				delay(10);
            putpixel(xt+y,yt+x,5);
				delay(10);
            putpixel(xt-y,yt+x,5);
				delay(10);
            putpixel(xt-x,yt+y,5);
				delay(10);
            putpixel(xt-x,yt-y,5);
				delay(10);
            putpixel(xt-y,yt-x,5);
				delay(10);
            putpixel(xt+y,yt-x,5);
				delay(10);
            putpixel(xt+x,yt-y,5);
				delay(10);
}



//eye creation function
void circle_cal1(int xt, int yt, int r)
{
				
            x=0;
            y=r;
            d=1-r;
	    
	    circle_points2(xt,yt,x,y);
	    //floodfill(xt+100,yt+100,BLACK);
            while(x<y)
            {
                        if(d<0)
                        {
                                    x=x+1;
                                    d=d+(2*x)+1;
                        }
                        else
                        {
                                    x=x+1;
                                    y=y-1;
                                    d=d+(2*x)-(2*y)+1;
                        }
                        circle_points2(xt,yt,x,y);
		
            }
				
            
}
void circle_points2(int xt,int yt,int x,int y)
{
            putpixel(xt+x,yt+y,5);
				//delay(10);
            putpixel(xt+y,yt+x,5);
				//delay(10);
            putpixel(xt-y,yt+x,5);
				//delay(10);
            putpixel(xt-x,yt+y,5);
				//delay(10);
            putpixel(xt-x,yt-y,5);
				//delay(10);
            putpixel(xt-y,yt-x,5);
				//delay(10);
            putpixel(xt+y,yt-x,5);
				//delay(10);
            putpixel(xt+x,yt-y,5);
				//delay(10);
}
