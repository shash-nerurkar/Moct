#include<iostream.h>
#include<conio.h>
#include<graphics.h>

int main()
{
clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	int namebox[10]={139,10,489,10,489,60,139,60,139,10};
	setlinestyle(0,0,3);
	drawpoly(5,namebox);
	settextstyle(0,0,2);
	outtextxy(145,30,"WHAT SHOULD ALTAN DO?");
	getch();
	setfillstyle(1,0);
	fillpoly(5,namebox);
	setlinestyle(0,0,3);
	drawpoly(5,namebox);
	outtextxy(145,30,"WHAT SHOULD ANA DO?");
	getch();
	cleardevice();
	closegraph();
	return 0;
}