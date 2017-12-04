
#include<stdio.h>
#include<graphics.h>
void displayMan(int x,int y)
{
	setbkcolor(15);
	setcolor(0);
	circle(x,y,10);         //face
	line(x,y+10,x,y+30);        //neck
	line(x,y+30,x-20,y+40);    //left hand
	line(x,y+30,x+20,y+40);    //right hand
	line(x+20,y+40,x+30,y+30);
	line(x,y+30,x,y+70);        //body
	setcolor(7);
	line(x+30,y+30,x+30,y-90);  //umbrella
	pieslice(x+30,y-90,180,360,55);       

}


void main()
{
	int gd=DETECT, gm,i,d=0,x=50,y=340,s=1;
	int rx,ry;
	initgraph(&gd,&gm,"");
	while(1)
	{
		cleardevice();
		displayMan(x,340);
		setcolor(BROWN);
		line(0,430,639,430);

		for(i=0;i<500;i++)
		{
			setcolor(BLUE);
			rx=rand()%639;
			ry=rand()%439;
			if(rx>=(x-40)&&rx<=(x+110))
				if(ry>=(y-50)&&ry<=479)
					continue;
			line(rx-10,ry+10,rx,ry);
		}

		//legs
		if(s)
		{setcolor(0);
			if(d<20)
				d+=4;
			else
				s=0;
			line(x,y+70,x-d,y+90);
			line(x,y+70,x+d,y+90);
		}
		else
		{setcolor(WHITE);
			if(d>0)
				d-=4;
			else
				s=1;
			line(x,y+70,x-d,y+90);
			line(x,y+70,x+d,y+90);
		}
		delay(200);
		x=(x+10)%639;
	}
	getch();
}

