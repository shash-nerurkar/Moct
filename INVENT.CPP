#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void box(int x,int y,int col=15)
{
	int b1[]={x,y,x+70,y,x+70,y+35,x,y+35,x,y};
	setlinestyle(0,0,3);
	setcolor(col);
	drawpoly(5,b1);
}

int main()
{
	clrscr();
	int gd=DETECT,gm,mpx;
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	settextstyle(1,0,5);
	mpx=getmaxx()/2-155;
	outtextxy(mpx,15,"INVENTORY");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<endl<<"CURRENT BALANCE: "<<5000<<" coins"<<endl<<endl;
	cout<<endl<<"MEAT AVAILABLE: "<<2000<<" steaks"<<endl<<endl;
	cout<<endl<<"VITO:ARMS IN-HAND: "<<"bserb"<<endl<<endl;
	cout<<endl<<"ANA:ARMS IN-HAND: "<<"frgbsetbd"<<endl<<endl;
	cout<<endl<<"MOTOG:ARMS IN-HAND: "<<"sragserbbwargregfdrgd"<<endl<<endl;
	settextstyle(0,0,2);
	outtextxy(400,100,"CHANGE WEAPONS?:");
	box(420,145);
	box(515,145);
	outtextxy(430,155,"YES");
	outtextxy(535,155,"NO");
	moveto(420,155);
	box(420,145,14);
	int a,x1;
	do
	{
		a=getch();
		x1=getx();
		switch(a)
		{
			case 97:
				if(x1==515)
					moverel(-95,0);
				break;
			case 100:
				if(x1==420)
					moverel(95,0);
				break;
			case 13:
				continue;
			default:
				continue;
		}
		box(x1,145);
		box(getx(),145,14);
	}while(a!=13);
	settextstyle(0,0,1);
	if(x1==515)
		outtextxy(200,400,"PRESS ANY KEY TO CONTINUE");
	getch();
	cleardevice();
	closegraph();
	return 0;
}