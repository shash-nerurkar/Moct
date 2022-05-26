#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>


void polyfack(int x, int y, int z)
{
 int a[]={50+x,50+y,65+x,50+y,65+x,65+y,50+x,65+y};
 setfillstyle(1,z);
 fillpoly(4,a);
}


void main()
{
clrscr();
int gdriver = DETECT,gmode;
int x,y,i,k;
	initgraph(&gdriver,&gmode,"C:\\turboc3\\BGI");
	setbkcolor(15);
	x=getmaxx()/2;
	y=getmaxy()/2;
	k=getmaxy();
	delay(1000);
	for(i=k;i>=y;i--)
	{
	setcolor(2);
	outtextxy(x,i,"DEVELOPED BY");
	outtextxy(x,i+20,"SHASH N SAND");
	outtextxy(x,i+70,"PLAYED BY");
	outtextxy(x,i+90,"YOU");
	delay(50);
	setcolor(15);
	outtextxy(x,i+1,"DEVELOPED BY");
	outtextxy(x,i+21,"SHASH N SAND");
	outtextxy(x,i+71,"PLAYED BY");
	outtextxy(x,i+91,"YOU");
	}
	cleardevice();
	setbkcolor(15);
		polyfack(10,30,0);
		polyfack(80,80,0);
		polyfack(30,150,0);
		polyfack(250,300,0);
		polyfack(350,350,0);

	delay(100);
	cleardevice();
	setbkcolor(15);
	outtextxy(x-25,y-25,"DEVELOPED BY");
	outtextxy(x-25,y+20-25,"SHASH N SAND");
	outtextxy(x-25,y+70-25,"PLAYED BY");
	outtextxy(x-25,y+90-25,"YOU");
	delay(100);
	cleardevice();
	       polyfack(150,200,2);
	       polyfack(100,150,2);
	       polyfack(70,250,2);
	       polyfack(290,331,2);

	delay(100);
	cleardevice();
	setbkcolor(15);
	outtextxy(x+25,y+25,"DEVELOPED BY");
	outtextxy(x+25,y+20+25,"SHASH N SAND");
	outtextxy(x+25,y+70+25,"PLAYED BY");
	outtextxy(x+25,y+90+25,"YOU");
	delay(100);
	cleardevice();
	setbkcolor(15);
	outtextxy(x,y,"DEVELOPED BY");
	outtextxy(x+40,y+20,"SHASH N SAND");

	polyfack(10,30,2);
	polyfack(150,200,2);
	polyfack(80,80,2);
	polyfack(100,150,2);
	polyfack(30,150,2);
	polyfack(70,250,2);
	polyfack(250,300,2);
	polyfack(290,331,2);
	polyfack(350,350,2);

	getch();
	cleardevice();
	closegraph();

}