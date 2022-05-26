#include<iostream.h>
#include<conio.h>
#include<graphics.h>

int main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
	for(int i=0;i<90;i++)
	{
		setcolor(15);
		line(395,365+i,675,365+i);
	}
	setcolor(1);
	line(400,370,633,370);
	line(400,370,400,450);
	line(633,370,633,450);
	line(633,450,400,450);
	setcolor(0);

	outtextxy(410,385,"ALTAN ATTACKED!");
	outtextxy(410,400,"ANA ATTACKED!");
	outtextxy(410,415,"ADUM ATTACKED!");
	outtextxy(410,430,"BOSS ATTACKED!");

	getch();
	cleardevice();
	closegraph();
	return 0;
}