#include<iostream.h>
#include<conio.h>
#include<graphics.h>

int main()
{
	clrscr();
	int gd=DETECT,gm,c=1;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	for(int i=0;i<421;i+=35)
	{
	setfillstyle(c,15);
	int poly[10]={0,i,150,i,150,i+25,0,i+25,0,0};
	fillpoly(5,poly);
	c++;
	}
	getch();
	cleardevice();
	closegraph();
	return 0;
}