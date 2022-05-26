#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void trap(int x,int y,int col=0)
{
	int trape[]={x,y,40+x,y,30+x,30+y,10+x,30+y,x,y};
	setfillstyle(1,col);
	setcolor(col);
	fillpoly(5,trape);
}

int main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	settextstyle(0,0,2);
	outtextxy(295,150,"MAP");
	outtextxy(250,200,"INVENTORY");
	outtextxy(260,250,"DATABASE");
	outtextxy(265,300,"GIVE UP");
	int x1,y1;
	char a;
	moveto(240,140);
	trap(getx()-45,gety(),15);
	trap(getx()+175,gety(),15);
	setcolor(10);
	line(getx()-45,gety(),getx()+175,gety());
	line(getx()-35,gety()+30,getx()+205,gety()+30);
	do
	{
		a=getch();
		x1=getx();
		y1=gety();
		switch(a)
		{
			case 'w':
				if(gety()>=190)
					moverel(0,-50);
				break;
			case 's':
				if(gety()<=240)
					moverel(0,50);
				break;
			case 'e':
				exit(1);
			default:
				continue;
		}
		trap(x1-45,y1);
		trap(x1+175,y1);
		setcolor(0);
		line(x1-45,y1,x1+175,y1);
		line(x1-35,y1+30,x1+205,y1+30);
		trap(getx()-45,gety(),15);
		trap(getx()+175,gety(),15);
		switch(getx()+gety())
		{
			case 380:
				setcolor(10);
				break;
			case 430:
				setcolor(9);
				break;
			case 480:
				setcolor(11);
				break;
			case 530:
				setcolor(12);
		}
		line(getx()-45,gety(),getx()+175,gety());
		line(getx()-35,gety()+30,getx()+205,gety()+30);
	}while(a!='e');
	cleardevice();
	closegraph();
	return 0;
}