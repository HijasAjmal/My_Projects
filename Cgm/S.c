
#include<stdio.h>
#include<math.h>
#include<graphics.h>
//void circle_points(int int int int);
int x,y,d,xt,yt,r,gd=DETECT,gm;
void main()
{ 
				//initialize the graphics
				initgraph(&gd,&gm," ");
				setbkcolor(15);
                        setcolor(7);
				//main circle
            		circle_cal(100,100,100);
			   	floodfill(110,110,5);
				//eye creation
                        setcolor(0);
				circle(60,60,25);
                        floodfill(60,60,0);
                        setcolor(0);
                  	circle(150,60,25);
                        floodfill(150,60,0);
				setcolor(BLACK);
				delay(1000);
				//angry
                        line(60,60,60,100);
                        line(150,60,150,100);
				arc(100,150,180,360,40);
				delay(1000);
				//hide the previous one
				setcolor(7);
                        line(60,85,60,100);
                        line(150,85,150,100);
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
				
            putpixel(xt+y,yt+x,5);
				
            putpixel(xt-y,yt+x,5);
				
            putpixel(xt-x,yt+y,5);
				
            putpixel(xt-x,yt-y,5);
				
            putpixel(xt-y,yt-x,5);
				
            putpixel(xt+y,yt-x,5);
				
            putpixel(xt+x,yt-y,5);
				
}



//eye creation function
void circle_cal1(int xt, int yt, int r)
{
				
            x=0;
            y=r;
            d=1-r;
	    
	    circle_points2(xt,yt,x,y);
	    
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
				
            putpixel(xt+y,yt+x,5);
				
            putpixel(xt-y,yt+x,5);
				
            putpixel(xt-x,yt+y,5);
            putpixel(xt-x,yt-y,5);
				
            putpixel(xt-y,yt-x,5);
				
            putpixel(xt+y,yt-x,5);
				
            putpixel(xt+x,yt-y,5);
}
