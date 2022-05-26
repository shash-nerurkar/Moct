#include<iostream.h>
#include<conio.h>
#include<graphics.h>

int main()
{
	clrscr();
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	for(int i=0;i<16;i++)
	{
	cout<<i<<endl<<endl;
	setcolor(i);
	line(50,50+25*i,150,50+25*i);
	}
	getch();
	cleardevice();
	closegraph();
	return 0;
}