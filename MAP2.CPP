#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void b1eye(int x,int y)
{
	int i[]={x,y,x+2,y,x+2,y+2,x,y+2,x,y};
	setfillstyle(1,11);
	setcolor(11);
	fillpoly(5,i);
}

int main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	int path[]={30,200,60,200,90,150,110,150,140,200,290,200,190,139,208,115,340,200,580,200,580,230,340,230,208,315,190,291,290,230,140,230,110,280,90,280,60,230,30,230,30,200};
	setfillstyle(1,8);
	setcolor(8);
	fillpoly(21,path);
	setfillstyle(1,0);
	setcolor(0);
	fillellipse(100,215,21,35);
	int start[]={550,170,600,170,620,190,620,240,600,260,550,260,530,240,530,190,550,170};
	setfillstyle(1,7);
	setcolor(7);
	fillpoly(9,start);
	setfillstyle(1,4);
	setcolor(4);
	fillellipse(400,215,25,25);
	int b1head[]={410,230,385,230,388,200,410,200,410,230};
	setcolor(2);
	setfillstyle(1,2);
	fillpoly(5,b1head);
	int b1hood[]={410,230,410,203,407,200,387,200,387,198,411,198,415,202,415,230,410,230};
	setcolor(0);
	setfillstyle(1,0);
	fillpoly(9,b1hood);
	b1eye(395,207);
	b1eye(393,212);
	b1eye(397,212);
	b1eye(391,217);
	b1eye(395,217);
	b1eye(399,217);
	setfillstyle(1,4);
	setcolor(4);
	fillellipse(190,215,25,25);
	int b2cane[]={175,201,171,205,203,229,207,225,175,201};
	setfillstyle(1,0);
	setcolor(0);
	fillpoly(5,b2cane);
	int canediatop[]={177,207,177,201,171,201,171,207,177,207};
	int canediabot[]={201,223,207,223,207,229,201,229,201,223};
	setcolor(2);
	setfillstyle(1,6);
	fillpoly(5,canediatop);
	fillpoly(5,canediabot);
	setfillstyle(1,4);
	setcolor(4);
	fillellipse(25,215,25,25);
	int hatbot[]={45,225,5,225,5,215,10,215,10,220,40,220,40,215,45,215,45,225};
	setcolor(0);
	setfillstyle(1,0);
	fillpoly(9,hatbot);
	int hattop[]={35,220,15,220,15,195,35,195,35,220};
	setcolor(0);
	setfillstyle(1,0);
	fillpoly(5,hattop);
	int hatstrap[]={35,220,15,220,15,217,35,217,35,220};
	setcolor(4);
	setfillstyle(1,4);
	fillpoly(5,hatstrap);
	setcolor(1);
	setfillstyle(1,9);
	fillellipse(575,215,10,10);
	int a;
	int x1,y1;
	do
	{
		a=getch();
		x1=getx();
		y1=gety();
		switch(a)
		{
			case 97:
				if(x1>=10&&y1==215)
					moverel(-10,0);
				break;
			case 100:
				if(x1<=565&&y1==215)
					moverel(10,0);
				break;
			case 13:
				continue;
			default:
				break;
		}
		setcolor(7);
		setfillstyle(1,7);
		fillellipse(x1,y1,10,10);
		setcolor(1);
		setfillstyle(1,9);
		fillellipse(getx(),gety(),10,10);
	}while(a!=13);
	getch();
	cleardevice();
	closegraph();
	return 0;
}